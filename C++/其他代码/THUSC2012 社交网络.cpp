#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,SH[2010],dist[2010][2],f[2010][2],q[4010][2],to[2010][2010];
inline void Ins(int a,int b)
{
    to[a][0]++;to[a][to[a][0]]=b;
}
inline int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9')) ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9') {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void bfs(int x)
{
    memset(dist,-1,sizeof(dist));
    memset(f,-1,sizeof(f));
    int tou=1,wei=0,now,nk,i,j;
    dist[x][0]=0;dist[x][1]=0;
    for(i=1;i<=to[x][0];i++)
    {
        dist[to[x][i]][0]=1;
        f[to[x][i]][0]=to[x][i];
        dist[to[x][i]][1]=0;
        q[++wei][0]=to[x][i];q[wei][1]=0;
    }
    while(tou<=wei)
    {
        now=q[tou][0];nk=q[tou][1];
        tou++;
        for(i=1;i<=to[now][0];i++)
        {
            if(dist[to[now][i]][0]==-1) 
            {
                dist[to[now][i]][0]=dist[now][nk]+1;
                f[to[now][i]][0]=f[now][nk];
                q[++wei][0]=to[now][i];q[wei][1]=0;
            }
            if(dist[to[now][i]][1]==-1 && f[to[now][i]][0]!=f[now][nk])
            {
                dist[to[now][i]][1]=dist[now][nk]+1;
                f[to[now][i]][1]=f[now][nk];
                q[++wei][0]=to[now][i];q[wei][1]=1;
            }
        }
    }
    for(i=1;i<=to[x][0];i++) for(j=1;j<=to[to[x][i]][0];j++)
    {
        if(to[to[x][i]][j]==x) continue;
        if(f[to[to[x][i]][j]][0]==to[x][i])
        SH[to[x][i]]+=dist[to[to[x][i]][j]][1]-2;
    }
}
int main()
{
    int i,a,b;
    n=read();m=read();
    for(i=1;i<=m;i++)
    {
        a=read();b=read();
        Ins(a,b);Ins(b,a);
    }
    for(i=1;i<=n;i++) bfs(i);
    for(i=1;i<=n;i++) printf("%d\n",SH[i]/2);
    return 0;
}