#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,p,f[2][4510];
int main()
{
    int i,j,x;
    scanf("%d%d",&n,&p);
    f[1][1]=1;
    for(i=2;i<=n;i++) for(j=1;j<=n;j++)
    {
        x=i&1;
        f[x][j]=(f[x][j-1]+f[x^1][i-j])%p;
    }
    if(n==1) printf("%d\n",1%p);
    else printf("%d\n",f[n&1][n]*2%p);
    return 0;
}