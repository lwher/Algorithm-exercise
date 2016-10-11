#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[2001],f[2001],c[2001][2001];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
       scanf("%d",&a[i]);
    f[0]=1;
    for(int i=1;i<=n;i++)
       for(int j=m;j>=a[i];j--)
       {
          f[j]+=f[j-a[i]];
          f[j]%=10;
      }
    for(int i=1;i<=n;i++)
    {
       c[i][0]=1;
       for(int j=1;j<=m;j++)
       {
           if(j>=a[i])c[i][j]=(f[j]-c[i][j-a[i]]+10)%10;
           else c[i][j]=f[j];
           printf("%d",c[i][j]);
       }
    printf("\n");
    }
    return 0; 
}