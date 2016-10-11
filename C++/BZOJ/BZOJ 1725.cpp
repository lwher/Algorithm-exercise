#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
int map[14];
int mi[14];
long long f[14][5000];
int main()
{
    int i,j,k;
    long long ans=0;
    mi[0]=1;
    for(i=1;i<=13;i++)
    mi[i]=2*mi[i-1];
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
    scanf("%d",&k);
    map[i]+=(1-k)*mi[m-j];
    }
    for(i=0;i<=mi[m]-1;i++)
    {
      if(((i>>1)& i)==0 && (i & map[1])==0)
      f[1][i]=1;
    }
    for(i=2;i<=n;i++)
    for(j=0;j<=mi[m]-1;j++)
    if(((j>>1) & j)==0 && (j & map[i-1])==0)
    for(k=0;k<=mi[m]-1;k++)
    if(((k>>1) & k)==0 && (k & map[i])==0)
    {
    if((k & j)==0)
    {f[i][k]+=f[i-1][j];f[i][k]%=100000000;}
    }
    for(i=0;i<=mi[m]-1;i++)
    {
      ans+=f[n][i];
      ans%=100000000;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
