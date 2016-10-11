#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int sr,sg,sb,m,p,n,sz;
int to[65],wt[65];
int f[25][25][25];
bool vis[65];
int ans;
int calc()
{
    int i,j,k,l;sz=0;
    memset(vis,0,sizeof(vis));
    memset(wt,0,sizeof(wt));
    memset(f,0,sizeof(f));
    for(i=1;i<=n;i++)
    if(!vis[i])
    {
        l=0;j=i;
        while(!vis[j])  {l++;vis[j]=1;j=to[j];}
        wt[++sz]=l;
    }
    f[0][0][0]=1;
    for(l=1;l<=sz;l++)
    for(i=sr;i>=0;i--)
    for(j=sb;j>=0;j--)
    for(k=sg;k>=0;k--)
    {
        if(i>=wt[l])   f[i][j][k]=(f[i][j][k]+f[i-wt[l]][j][k])%p;
        if(j>=wt[l])   f[i][j][k]=(f[i][j][k]+f[i][j-wt[l]][k])%p;
        if(k>=wt[l])   f[i][j][k]=(f[i][j][k]+f[i][j][k-wt[l]])%p;
    }
    return f[sr][sb][sg];
}
int qpow(int a,int b)
{
    int now=1;a%=p;
    while(b>0)
    {
        if(b & 1)  now=(now*a)%p;
        a=(a*a)%p;
        b=b>>1;
    }
    return now;
}
int main()
{
    int i,j;
    scanf("%d%d%d%d%d",&sr,&sb,&sg,&m,&p);
    n=sr+sb+sg;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)  scanf("%d",&to[j]);
        ans=(ans+calc())%p;
    }
    for(i=1;i<=n;i++)  to[i]=i;  ans=(ans+calc())%p;
    ans=(ans*qpow(m+1,p-2))%p;
    printf("%d\n",ans);
    system("pause");
    return 0;
}
