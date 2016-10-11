#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define mod 1024523
using namespace std;
int n,m,f[510][510][510];
char s1[510],s2[510];
int main()
{
    int i,j,k,l;
    scanf("%d%d",&n,&m);
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    f[0][0][0]=1;
    for(i=0;i<=n;i++) for(j=0;j<=m;j++) for(k=0;k<=n;k++)
    {
        l=i+j-k;
        if(l<0) continue;
        if(f[i][j][k]>mod) f[i][j][k]%=mod;
        if(i<n && k<n && s1[i+1]==s1[k+1]) f[i+1][j][k+1]=f[i+1][j][k+1]+f[i][j][k];
        if(i<n && l<m && s1[i+1]==s2[l+1]) f[i+1][j][k]=f[i+1][j][k]+f[i][j][k];
        if(j<m && k<n && s2[j+1]==s1[k+1]) f[i][j+1][k+1]=f[i][j+1][k+1]+f[i][j][k];
        if(j<m && l<m && s2[j+1]==s2[l+1]) f[i][j+1][k]=f[i][j+1][k]+f[i][j][k];
    }
    printf("%d\n",f[n][m][n]);
    return 0;
}