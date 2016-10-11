#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long f[110][110];
int pre[110][110];
int w[110];
int n;
void print(int i,int j)
{
     if(i>j)  return;
     if(i==j)  {printf("%d ",i);return;}
     printf("%d ",pre[i][j]);
     print(i,pre[i][j]-1);
     print(pre[i][j]+1,j);
}
int main()
{
    int i,j,k,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    scanf("%d",&w[i]);
    f[i][i]=w[i];
    }
    for(l=2;l<=n;l++)
    for(i=1;i+l-1<=n;i++)
    {
      j=i+l-1;
      for(k=i;k<=j;k++)
      {
         if(f[i][k-1]*f[k+1][j]+w[k]>f[i][j])
         {
            if(k-1<i)  f[i][k-1]=1;
            if(k+1>j)  f[k+1][j]=1;
            f[i][j]=f[i][k-1]*f[k+1][j]+w[k];
            pre[i][j]=k;
         }
      }
    }
    cout<<f[1][n]<<endl;
    print(1,n);
    cout<<endl;
    system("pause");
    return 0;
}
