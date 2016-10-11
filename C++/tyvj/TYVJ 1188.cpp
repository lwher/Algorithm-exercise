#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int f[21][21],pre[21][21];
int sum[21],num[21];
int ans[31];
int n;
void print(int l,int r)
{
     if(l==r)  {printf("%d",num[l]);return;}
     printf("(");
     print(l,pre[l][r]);
     printf("+");
     print(pre[l][r]+1,r);
     printf(")");
     ans[0]++;
     ans[ans[0]]=sum[r]-sum[l-1];
}
int main()
{
    int i,j,k,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    f[i][j]=100000000;
    for(i=1;i<=n;i++)
    {
    scanf("%d",&num[i]);
    sum[i]=sum[i-1]+num[i];
    f[i][i]=0;
    }
    for(l=2;l<=n;l++)
    for(i=1;i+l-1<=n;i++)
    {
    j=i+l-1;
    for(k=i;k<j;k++)
    {
      if(f[i][k]+f[k+1][j]+sum[j]-sum[i-1]<=f[i][j])
      {
         f[i][j]=f[i][k]+f[k+1][j]+sum[j]-sum[i-1];
         pre[i][j]=k;
      }
    }
    }
    print(1,n);
    cout<<endl;
    cout<<f[1][n]<<endl;
    for(i=1;i<=ans[0];i++)
    cout<<ans[i]<<" ";
    cout<<endl;
    system("pause");
    return 0;
}
