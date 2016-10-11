#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,cnt,last;
int head[1100001],q[1100001],dis[1100001];
struct data{int to,next;}e[2000001];
void insert(int u,int v)
{cnt++;e[cnt].to=v;e[cnt].next=head[u];head[u]=cnt;}
void bfs()
{
    memset(dis,-1,sizeof(dis));
    int t=0,w=1,now;
    q[0]=1;dis[1]=0;
    while(t<w)
    {
        now=q[t];t++;
        for(int i=head[now];i;i=e[i].next)
        {
            if(dis[e[i].to]==-1)
            {
                dis[e[i].to]=dis[now]+1;
                q[w++]=e[i].to;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    last=n;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(w==1)insert(u,v);
        else {insert(u,++n);insert(n,v);}
    }
    bfs();
    printf("%d",dis[last]);
    return 0;
}