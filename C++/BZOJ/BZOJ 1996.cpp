#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define mod 19650827
using namespace std;
int n,f[1010][1010][2],h[1010],ans;
int main()
{
    int i,j,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d",&h[i]);
    for(i=1;i<=n;i++)  f[i][i][0]=f[i][i][1]=1;
    for(i=1;i<n;i++)
    {
       if(h[i]<h[i+1]) f[i][i+1][0]=1;
       if(h[i+1]>h[i]) f[i][i+1][1]=1;
    }
    for(l=3;l<=n;l++)
    for(i=1;i<=n;i++)
    {
        j=i+l-1;
        if(j>n) break;
        if(h[i]<h[i+1])  f[i][j][0]=(f[i][j][0]+f[i+1][j][0])%mod;
        if(h[i]<h[j])   f[i][j][0]=(f[i][j][0]+f[i+1][j][1])%mod;
        if(h[j]>h[j-1])  f[i][j][1]=(f[i][j][1]+f[i][j-1][1])%mod;
        if(h[j]>h[i])  f[i][j][1]=(f[i][j][1]+f[i][j-1][0])%mod;
    }
    ans=(f[1][n][0]+f[1][n][1])%mod;
    printf("%d\n",ans);
    return 0;
}