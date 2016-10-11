#include<iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct sth
{
     int   v,w;
}thing[200010];
struct app
{
     int l,r;
}qj[200010];
long long int sum[200010];
int sz[200010];
int n,m;
int maxx=0;
long long int answer;
long long int s;
long long int ans;
bool o;
int main()
{
    int i,j;
    cin>>n>>m>>s;
    for(i=1;i<=n;i++)
    {
    scanf("%d%d",&thing[i].w,&thing[i].v);
    if(maxx<thing[i].w) maxx=thing[i].w;
    }
    for(i=1;i<=m;i++)
    scanf("%d%d",&qj[i].l,&qj[i].r);
    int left,right,mid;
    right=maxx;
    left=0;
    
    while(left<right)
    {
       ans=0;
       if(left+1==right)  {break;}
       mid=(left+right)>>1;
       for(i=1;i<=n;i++)
       {
         if(thing[i].w>=mid)
         {sum[i]=sum[i-1]+thing[i].v;sz[i]=sz[i-1]+1;}
         else
         {sum[i]=sum[i-1];sz[i]=sz[i-1];}
       }
       for(i=1;i<=m;i++)
       {
         ans+=(sum[qj[i].r]-sum[qj[i].l-1])*(sz[qj[i].r]-sz[qj[i].l-1]);
       }
       if(ans>s)  left=mid;
       else
       if(ans<s)  right=mid;
       else
       {o=1;cout<<0<<endl;break;}
    }
    if(!o)
    {
       ans=0;
         for(i=1;i<=n;i++)
       {
         if(thing[i].w>=left)
         {sum[i]=sum[i-1]+thing[i].v;sz[i]=sz[i-1]+1;}
         else
         {sum[i]=sum[i-1];sz[i]=sz[i-1];}
       }
       for(i=1;i<=m;i++)
       {
         ans+=(sum[qj[i].r]-sum[qj[i].l-1])*(sz[qj[i].r]-sz[qj[i].l-1]);
       }
       answer=abs(s-ans);
       ans=0;
        for(i=1;i<=n;i++)
       {
         if(thing[i].w>=right)
         {sum[i]=sum[i-1]+thing[i].v;sz[i]=sz[i-1]+1;}
         else
         {sum[i]=sum[i-1];sz[i]=sz[i-1];}
       }
       for(i=1;i<=m;i++)
       {
         ans+=(sum[qj[i].r]-sum[qj[i].l-1])*(sz[qj[i].r]-sz[qj[i].l-1]);
       }
       answer=min(answer,abs(s-ans));
       cout<<answer<<endl;
    }
    
//    system("pause");
    return 0;
}