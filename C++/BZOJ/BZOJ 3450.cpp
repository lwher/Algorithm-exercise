#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n;
char s[300010];
long double f[300010],g[300010];
int main()
{
    int i;
    scanf("%d",&n);scanf("%s",s+1);
    for(i=1;i<=n;i++)
    {
        if(s[i]=='x')   {f[i]=f[i-1];g[i]=0;}
        if(s[i]=='o')   {f[i]=f[i-1]+(g[i-1]+1)*2-1;g[i]=g[i-1]+1;}
        if(s[i]=='?')   {f[i]=f[i-1]+0.5*((g[i-1]+1)*2-1);g[i]=g[i-1]/2+0.5;}
    }
    printf("%.4lf\n",double(f[n]));
    //system("pause");
    return 0;
}