#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,ans,total,k;
int last[1100],d[1100],sum[1100],get[1100],inf[1100],t[11000],a[11000],b[11000];
void init()
{
     int i;
     scanf("%d%d%d",&n,&m,&k);
     for(i=1;i<=n-1;i++) scanf("%d",&d[i]);
     for(i=1;i<=m;i++)
     {
          scanf("%d%d%d",&t[i],&a[i],&b[i]);
          last[a[i]]=max(t[i],last[a[i]]);sum[b[i]]++;
     }  
}
void work()
{
     int i,maxx=0,l,r;
     for(i=1;i<=n-1;i++)
     {
         if(maxx<sum[inf[i]]-sum[i] && d[i]>0)
         {maxx=sum[inf[i]]-sum[i];l=i;r=inf[i];}
     }
     if(r==n)  r=n-1;
     total+=maxx;
     d[l]--;
     for(i=l+1;i<=r;i++)  get[i]=max(last[i-1],get[i-1])+d[i-1];
     for(i=r;i>=l;i--)  if(last[i+1]>=get[i+1])  inf[i]=i+1;  else inf[i]=inf[i+1];
}
int main()
{
    int i;
    init();
    for(i=2;i<=n;i++)  get[i]=max(get[i-1],last[i-1])+d[i-1];
    inf[n-1]=n;inf[n]=n;
    for(i=n-2;i>=1;i--)
    {
         if(get[i+1]>last[i+1])  inf[i]=inf[i+1];
         else  inf[i]=i+1;
    }
    for(i=2;i<=n;i++)  sum[i]+=sum[i-1];
    for(i=1;i<=m;i++)  ans+=get[b[i]]-t[i];
    for(i=1;i<=k;i++)  work();
    cout<<ans-total<<endl;
    system("pause");
    return 0;
}
