#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,K;
long long f[10][1024][100];
int getsum(int x)
{
    int i,sum=0;
    for(i=9;i>=0;i--)
    {
      if(x>=(1<<i))  
      {
         sum++;
         x-=(1<<i);
      }
    }
    return sum;
}
int main()
{
    int i,j,l,k,m,p;
    scanf("%d%d",&n,&K);
    
    for(i=0;i<=(1<<n)-1;i++)
    {
      if((i & (i>>1))==0)
      f[1][i][getsum(i)]=1;
    }
    
    for(i=2;i<=n;i++)
    {
    for(j=0;j<=(1<<n)-1;j++)
    if(!(j & (j>>1)))
    for(k=0;k<=(1<<n)-1;k++)
    if(!(k & (k>>1)))
    if(((j & k)==0) && (((j>>1) & k)==0) && (((j<<1) & k)==0))
    {
         m=getsum(j);
         p=getsum(k);
         for(l=m;l<=K-p;l++)
         f[i][k][l+p]+=f[i-1][j][l];
    }
    }
    long long ans=0;
    for(i=0;i<=(1<<n)-1;i++)
    ans+=f[n][i][K];
    cout<<ans<<endl;
    system("pause");
    return 0;
}
