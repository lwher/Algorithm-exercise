#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int du[10010],w[10010],n,m;
int cb[200010],scb,rb[200010],srb;
int main()
{
    int i,j,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  scanf("%d",&w[i]);
    for(i=1;i<=m;i++)  
    {
       scanf("%d%d",&a,&b);
       du[a]++;du[b]--;
    }
    for(i=1;i<=n;i++)
    if(du[i]!=0)
    {
       if(du[i]>0)  
       {
           while(du[i])   {du[i]--;scb++;cb[scb]=w[i];}
       }
       else
       {
           while(du[i]<0) {du[i]++;srb++;rb[srb]=w[i];}    
       }
    }
    sort(cb+1,cb+1+scb);
    sort(rb+1,rb+1+srb);
    long long ans=0;
    for(i=scb;i>=1;i--)
    ans+=abs(cb[i]-rb[i]);
    cout<<ans<<endl;
    system("pause");
    return 0;
}
