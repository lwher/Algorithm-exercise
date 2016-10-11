#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
long long f[51][110][110],v[51];
int t[51];
int sz,to[310],pre[310],last[51];
int fa[51],n,a,b,m;
long long sum,tmp;
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dp(int x)
{
     int i=last[x],j,k;
     while(i>0)
     {
         for(j=0;j<=a;j++)  for(k=0;k<=b;k++)  f[to[i]][j][k]=f[x][j][k];
         dp(to[i]);
         for(j=0;j<=a;j++)  for(k=0;k<=b;k++)
         {
             if(j-t[to[i]]>=0)   f[x][j][k]=max(f[x][j][k],f[to[i]][j-t[to[i]]][k]+v[to[i]]);
             if(k-2*t[to[i]]>=0)   f[x][j][k]=max(f[x][j][k],f[to[i]][j][k-2*t[to[i]]]+v[to[i]]);
         }
         i=pre[i];
     }
}
int main()
{
    int i,j,A,s,B;
    scanf("%d%d",&a,&b);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  {scanf("%lld%d",&v[i],&t[i]);sum+=v[i];}
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&A,&s);
        while(s--)  {scanf("%d",&B);fa[B]=A;}
    }
    for(i=1;i<=n;i++)  Ins(fa[i],i);
    dp(0);
    for(i=0;i<=a;i++)  for(j=0;j<=b;j++)  tmp=max(tmp,f[0][i][j]);
    cout<<sum-tmp<<endl;
    system("pause");
    return 0;
}
