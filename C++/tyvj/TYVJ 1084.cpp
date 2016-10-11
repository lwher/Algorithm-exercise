#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int ans,n,f[26][26],a[26][26],x,y;
void readdata()
{
     int i,j;
     scanf("%d",&n);
     for (i=1;i<=n;i++)
     {
         for (j=1;j<=i;j++)
         scanf("%d",&a[i][j]);
     }
     scanf("%d%d",&x,&y);
}
void solve()
{
     int i,j,maxn;
     for (i=1;i<=x;i++)
     {
        for (j=1;j<=i;j++)
        {
            if (j==1) f[i][j]=f[i-1][j]+a[i][j];
            else if (j==i) f[i][j]=f[i-1][j-1]+a[i][j];
            else
            {
                if (f[i][j]<f[i-1][j]+a[i][j])
                f[i][j]=f[i-1][j]+a[i][j];
                if (f[i][j]<f[i-1][j-1]+a[i][j])
                f[i][j]=f[i-1][j-1]+a[i][j];
            }
        }
     }
     for (i=x+1;i<=n;i++)
        for (j=y;j<=i-x+y;j++)
        {
            if (j==y) f[i][j]=f[i-1][j]+a[i][j];
            else if (j==i-x+y) f[i][j]=f[i-1][j-1]+a[i][j];
            else
            {
                if (f[i][j]<f[i-1][j]+a[i][j])
                f[i][j]=f[i-1][j]+a[i][j];
                if (f[i][j]<f[i-1][j-1]+a[i][j])
                f[i][j]=f[i-1][j-1]+a[i][j];
            }
        }
     ans=0;
     maxn=n-x+y;
     for (i=y;i<=maxn;i++)
     if (ans<f[n][i])
     ans=f[n][i];
     printf("%d\n",ans);
}
int main(int argc, char *argv[])
{
    readdata();
    solve();
    //while(1);
    return 0;
}
