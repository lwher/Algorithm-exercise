#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
int dp[3001][3001],val[3010];
int sz,to[6010],pre[6010],last[3010],v[6010];
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void dping(int x,int fa)
{
     int i=last[x],j,k;
     while(i>0)
     {
         if(to[i]!=fa)
         {
              for(j=0;j<=m;j++)  dp[to[i]][j]=dp[x][j];
              if(to[i]>n-m) k=1; else k=0;  
              dping(to[i],x);
              for(j=1;j<=m;j++)  dp[x][j]=max(dp[x][j],dp[to[i]][j-k]+val[to[i]]-v[i]);
         }
         i=pre[i];
     }
}
int main()
{
    int i,j,k,a,w;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n-m;i++)
    {
       scanf("%d",&k);
       for(j=1;j<=k;j++)  
       {
           scanf("%d%d",&a,&w);
           Ins(i,a,w);Ins(a,i,w);
       }
    }
    for(i=n-m+1;i<=n;i++)  scanf("%d",&val[i]);
    for(i=1;i<=m;i++)  dp[1][i]=-200000000;
    dping(1,0);
    for(i=m;i>=0;i--)  if(dp[1][i]>=0)  {cout<<i<<endl;break;}
    system("pause");
    return 0;
}
