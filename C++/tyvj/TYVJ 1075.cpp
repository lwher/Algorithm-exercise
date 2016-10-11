#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int f[2010][2010];
int n;
int w[2010],sum[2010];
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n;i++)  sum[i]=sum[i-1]+w[i];
    
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
       f[i][j]=f[i][j-1];
       if(2*j-1<=n && i-2*j+1>=0)
       f[i][j]=max(f[i][j],sum[i]-f[i-2*j+1][2*j-1]);
       if(2*j<=n && i-2*j>=0)
       f[i][j]=max(f[i][j],sum[i]-f[i-2*j][2*j]);
    }
    cout<<f[n][1]<<endl;
    system("pause");
    return 0;
}
