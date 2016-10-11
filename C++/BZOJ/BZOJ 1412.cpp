#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 0x7fffffff
#define T 10001
using namespace std;
int head[10005],q[10005],h[10005];
int cnt=1,ans,n,m;
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0},mp[105][105];
struct data{int to,next,v;}e[500001];
void ins(int u,int v,int w)
{e[++cnt].to=v;e[cnt].next=head[u];e[cnt].v=w;head[u]=cnt;}
void insert(int u,int v,int w)
{ins(u,v,w);ins(v,u,0);}
bool bfs()
{
     int t=0,w=1,i,now;
     memset(h,-1,sizeof(h));
     q[0]=0;h[0]=0;
     while(t<w)
     {
               now=q[t];t++;i=head[now];
               while(i)
               {
                       if(e[i].v&&h[e[i].to]==-1)
                       {
                                                 h[e[i].to]=h[now]+1;
                                                 q[w++]=e[i].to;
                                                 }
                       i=e[i].next;
                       }
               }
    return h[T]==-1? 0:1;
 }
int dfs(int x,int f)
{
    if(x==T)return f;
    int w,used=0,i;
    i=head[x];
    while(i)
    {
            if(e[i].v&&h[e[i].to]==h[x]+1)
            {
                                          w=f-used;
                                          w=dfs(e[i].to,min(w,e[i].v));
                                          e[i].v-=w;
                                          e[i^1].v+=w;
                                          used+=w;
                                          if(used==f)return f;
                                          }
            i=e[i].next;
            }
    if(!used)h[x]=-1;
    return used;
}
void dinic(){while(bfs())ans+=dfs(0,inf);}
void ini()
{
     scanf("%d%d",&n,&m);
     for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++)
             scanf("%d",&mp[i][j]);
     }
void build()
{
     for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++)
         {
             if(mp[i][j]==1)insert(0,(i-1)*m+j,inf);
             else if(mp[i][j]==2)insert((i-1)*m+j,T,inf);
             for(int k=0;k<4;k++)
             {
                     int nowx=i+xx[k],nowy=j+yy[k];
                     if(nowx<1||nowx>n||nowy<1||nowy>m||mp[i][j]==2)continue;
                     if(mp[i][j]!=1||mp[nowx][nowy]!=1)
                     insert((i-1)*m+j,(nowx-1)*m+nowy,1);
                     }
             }
     }
int main()
{
    ini();
    build();
    dinic();
    printf("%d",ans);
    system("pause");
    return 0;
}
