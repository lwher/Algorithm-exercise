#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int a[70][70],b[70][70],n,k,m;
void jzchen(int A[][70],int B[][70],int C[][70])
{
     int i,j,k,ans[70][70]={0};
     for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  for(k=1;k<=n;k++)   ans[i][j]=(ans[i][j]+(A[i][k]*B[k][j])%m)%m;
     for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  C[i][j]=ans[i][j];
}
int main()
{
    int i,j;
    scanf("%d%d%d",&n,&k,&m);
    for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)  {a[i+n][i+n]=1;a[i+n][i]=1;b[i][i]=1;b[i+n][i+n]=1;}    
    n=n<<1;k++;
    while(k>0)
    {
        if(k & 1)  jzchen(b,a,b);
        k=k>>1;
        jzchen(a,a,a);
    }
    n=n>>1;
    for(i=1;i<=n;i++)  {b[i+n][i]-=1;if(b[i+n][i]<0)  b[i+n][i]+=m;}
    for(i=1;i<=n;i++)
    {
       for(j=1;j<n;j++)  printf("%d ",b[i+n][j]);
       printf("%d\n",b[i+n][n]);
    }
    system("pause");
    return 0;
}
