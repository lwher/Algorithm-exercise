#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 155
#define P 451
#define mod 123456789
using namespace std;
int n,m,p;
int g[N][N][P],f[P+P][P];
inline void ret(int x,int y,int aim[P])
{
    for(int i=1;i<=p;i++)
    {
        aim[i]=g[x+2][y+1][i];
        aim[i]^=g[x+2][y-1][i];
        aim[i]^=g[x+1][y+2][i];
        aim[i]^=g[x-1][y+2][i];
        aim[i]^=g[x][y][i];
        if(x>1) 
        {
            aim[i]^=g[x-2][y-1][i];
            aim[i]^=g[x-2][y+1][i];
        }
        if(y>1)
        {
            aim[i]^=g[x-1][y-2][i];
            aim[i]^=g[x+1][y-2][i];
        }
    }
}
int guass()
{
    int i,j,k,t,now=1;
    for(i=1;i<=p;i++)
    {
       for(j=now;j<=p;j++) if(f[j][i]) break;
       if(j>p) continue;
       if(j!=now) for(k=1;k<=p;k++) swap(f[now][k],f[j][k]);
       for(j=1;j<=p;j++) 
       if(j!=now && f[j][i])
       {
           for(k=1;k<=p;k++) f[j][k]^=f[now][k];
       } 
       now++;
    }
    int ans=1;
    for(i=1;i<=p-now+1;i++)  ans=(ans<<1)%mod;
    return ans;
}
int main()
{
    int i,j,k,s,q,u,t=0;
    scanf("%d%d",&n,&m);
    p=n+m+m-2;q=p;
    if(n==1) {printf("1\n");return 0;}
    for(i=1;i<=m;i++) g[1][i][i]=1,g[2][i][i+m]=1;
    for(i=3;i<=n;i++) g[i][1][i+m+m-2]=1;
    for(i=3;i<=n;i++) for(j=2;j<=m;j++) ret(i-2,j-1,g[i][j]);
    for(i=1;i<=m;i++) {ret(n-1,i,f[i]);ret(n,i,f[i+m]);}
    for(i=1;i<=n-2;i++) ret(i,m,f[i+m+m]);
    printf("%d\n",guass());
    //system("pause");
    return 0;
}
