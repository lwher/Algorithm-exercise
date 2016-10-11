#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define INF 1e8
using namespace std;
int f[1510][3],v[1510];
int sz,fa[1510],to[1510],pre[1510],last[1510];
int n,m;
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void treedp(int x)
{
     int i=last[x];
     f[x][0]=v[x];f[x][2]=0;f[x][1]=INF;
     while(i>0)
     {
          treedp(to[i]);
          i=pre[i];
     }
     i=last[x];
     while(i>0)
     {
         f[x][0]+=min(f[to[i]][0],min(f[to[i]][1],f[to[i]][2]));
         f[x][2]+=min(f[to[i]][0],f[to[i]][1]);
         i=pre[i];
     }
     int tmp=0;
     i=last[x];
     while(i>0)
     {
          tmp+=min(f[to[i]][0],f[to[i]][1]);
          i=pre[i];
     }
     i=last[x];
     while(i>0)
     {
         f[x][1]=min(f[x][1],tmp-min(f[to[i]][0],f[to[i]][1])+f[to[i]][0]);
         i=pre[i];
     }
}
int main()
{
    int i,j,k,bh;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&bh);
        scanf("%d%d",&v[bh],&m);
        for(j=1;j<=m;j++)
        {
            scanf("%d",&k);
            fa[k]=bh;Ins(bh,k);
        }
    }
    k=1;
    while(fa[k]!=0)  k=fa[k];
    treedp(k);
    printf("%d\n",min(f[k][0],f[k][1]));
    system("pause");
    return 0;
}
