#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int sz,bh[3010],now[3010],c[1010],up[1010];
int n,m;
void swap(int a,int b)
{
     int t;
     t=bh[a];bh[a]=bh[b];bh[b]=t;
     t=now[a];now[a]=now[b];now[b]=t;
}
void charu(int x)
{
     int w=sz;sz++;bh[sz]=x;now[sz]=c[x];
     while(now[w]<now[w/2]){
        swap(w,w/2);w/=2;
     }
}
void weihu(int x)
{
     while(1){
         if(now[x]<=now[x*2] && now[x]<=now[x*2+1])   break;
         if(now[x]>now[x*2] && now[x*2]<now[x*2+1])   {swap(x,x*2);x=x*2;}   else
         if(now[x]>now[x*2+1])   {swap(x,x*2+1);x=x*2+1;}
     }
}
int main()
{
    memset(now,127,sizeof(now));
    now[0]=-100000;
    int i;
    long long ans=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  scanf("%d%d",&c[i],&up[i]);
    for(i=1;i<=n;i++)  charu(i);
    for(i=1;i<=m;i++)
    {
        ans+=now[1];
        now[1]+=up[bh[1]];
        weihu(1);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
