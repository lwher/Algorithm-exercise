#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define inf 1<<25
using namespace std;
int n,A,B;
int num[10010],f[10010];
int dp(int x)
{
    if(f[x]!=-inf)  return f[x];
    int ans=inf;
    for(int i=x+1;i<=n;i++)
    {
         if(num[i]-num[x]>=A && num[i]-num[x]<=B)   ans=min(ans,num[x]-dp(i));
         if(num[i]-num[x]>B)  break;
    }
    if(ans==inf)  ans=num[x];
    return f[x]=ans;
}
int main()
{
    int i,T,ans;
    scanf("%d",&T);
    while(T--)
    {
       scanf("%d%d%d",&n,&A,&B);
       for(i=1;i<=n;i++)
       {
           scanf("%d",&num[i]);
           f[i]=-inf;
       }
       sort(num+1,num+1+n);
       ans=-inf;
       for(i=1;i<=n;i++)  if(num[i]>=A && num[i]<=B) ans=max(ans,dp(i));
       if(ans==-inf)  printf("0\n");  else  printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
