#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,f[10010][110],l[10010][110],r[10010][110],num[10010];
// l[i][j]:1-(i-1)大于j的个数  r[i][j]:(i+1)-n 小于j的个数 
int main()
{
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)  scanf("%d",&num[i]);
    num[n+1]=101;
    for(j=1;j<=k;j++)
    {
        for(i=1;i<=n+1;i++)  l[i][j]=l[i-1][j]+(num[i-1]!=-1 && num[i-1]>j);
    }
    for(j=1;j<=k;j++)
    {
        for(i=n;i>=1;i--)    r[i][j]=r[i+1][j]+(num[i+1]!=-1 && num[i+1]<j);
    }
    for(i=1;i<=n;i++)
    {
        if(num[i]!=-1)
        {
            for(j=1;j<=k;j++)  f[i][j]=f[i-1][j]+l[i][num[i]];
        }
        else
        {
            f[i][0]=1e9;
            for(j=1;j<=k;j++)  f[i][j]=min(f[i][j-1],f[i-1][j]+l[i][j]+r[i][j]);
        }
    }
    printf("%d\n",f[n][k]);
    return 0;
}