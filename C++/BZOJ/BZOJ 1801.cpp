#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define mod 9999973
using namespace std;
int n,m,ans;
long long f[101][101][101];
int c[101][3];
void getc()
{
     int i,j;c[0][0]=1;c[1][0]=1;c[1][1]=1;
     
     for(i=2;i<=100;i++)
     {
        c[i][0]=1;
        for(j=1;j<=2;j++)  c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
     }
}
void add(long long &a,int k)
{
     a+=k;  if(a>=mod)  a-=mod;
}
int main()
{
    int i,j,k;
    getc();
    scanf("%d%d",&n,&m);
    f[0][m][0]=1;
    for(i=0;i<=n-1;i++)
    for(j=0;j<=m;j++)  
    for(k=0;k<=m-j;k++)
    {                         
        add(f[i+1][j][k],f[i][j][k]);
        if(j>0)  add(f[i+1][j-1][k+1],(f[i][j][k]*j)%mod);
        if(k>0)  add(f[i+1][j][k-1],(f[i][j][k]*k)%mod);
        if(j>1)  add(f[i+1][j-2][k+2],(f[i][j][k]*c[j][2])%mod);
        if(j>0 && k>0)  add(f[i+1][j-1][k],(f[i][j][k]*j*k)%mod);
        if(k>1)  add(f[i+1][j][k-2],(f[i][j][k]*c[k][2])%mod);
    }
    for(j=0;j<=m;j++)  for(k=0;k<=m-j;k++)   ans=(ans+f[n][j][k])%mod;
    printf("%d\n",ans);
    system("pause");
    return 0;
}
