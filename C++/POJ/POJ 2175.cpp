#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define INF 0x7fffffff
using namespace std;
struct sth
{
       int x,y;
}d[301];
int n,m,s,t;
int sz,to[30000],pre[30000],v[30000],cost[30000],last[10010];
int have[301],sum[301];
int fd[301],fb[301];
int map[101][101];
int in[301],dui[300000],dis[301];
bool mark[301],vis[301];
int ans[10010];
int juli(sth a,sth b)
{
       return abs(a.x-b.x)+abs(a.y-b.y)+1;
}
void Ins(int a,int b,int c,int dd)
{
     sz++;to[sz]=b;v[sz]=c;cost[sz]=dd;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;v[sz]=0;cost[sz]=-dd;pre[sz]=last[b];last[b]=sz;
}
void init()
{
     int i,j;sz=1;
     s=n+m+1;t=s+1;
     for(i=1;i<=n;i++) {scanf("%d%d%d",&d[i].x,&d[i].y,&have[i]);}
     for(i=n+1;i<=n+m;i++)  {scanf("%d%d%d",&d[i].x,&d[i].y,&have[i]);}
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  {scanf("%d",&map[i][j]);sum[j]+=map[i][j];}
     for(i=1;i<=n;i++)   
     for(j=n+1;j<=n+m;j++)  
     {
     Ins(i,j,INF,juli(d[i],d[j]));
     if(map[i][j-n])  v[sz]=map[i][j-n];
     }
     
     for(i=n+1;i<=n+m;i++)  
     {
     Ins(i,t,have[i]-sum[i-n],0);
     v[sz]=sum[i-n];
     }
}
int spfa(int S,int N)
{
    int tou=1,wei=1,now,i;
    memset(dis,127,sizeof(dis));
    memset(mark,0,sizeof(mark));
    dis[S]=0;dui[1]=S;in[S]++;
    mark[S]=1;
    while(tou<=wei)
    {
                   now=dui[tou];tou++;
                   i=last[now];
                   while(i>0)
                   {
                        if(v[i] && dis[to[i]]>dis[now]+cost[i])
                        {
                            dis[to[i]]=dis[now]+cost[i];
                            fd[to[i]]=now;
                            fb[to[i]]=i;
                            if(!mark[to[i]])
                            {
                                wei++;dui[wei]=to[i];mark[to[i]]=1;
                                in[to[i]]++;if(in[to[i]]>N) return to[i];
                            }
                        }
                        i=pre[i];
                   }
                   mark[now]=0;
    }
    return -1;
}
void solve()
{
     int p,i,j;
     memset(last,0,sizeof(last));
     memset(sum,0,sizeof(sum));
     memset(in,0,sizeof(in));
     init();
     p=spfa(t,t);
     if(p==-1)
     printf("OPTIMAL\n");
     else
     {
         printf("SUBOPTIMAL\n");
         memset(vis,0,sizeof(vis));
         while(!vis[p])
         {vis[p]=1;p=fd[p];}
         int k=p,cc=INF;
         cc=min(v[fb[p]],cc);k=fd[p];
         while(k!=p)
         {
             cc=min(v[fb[k]],cc);k=fd[k];        
         }
         k=p;
         v[fb[p]]-=cc;v[fb[p]^1]+=cc;k=fd[p];
         while(k!=p)
         {
             v[fb[k]]-=cc;v[fb[k]^1]+=cc;k=fd[k];
         }
         ans[0]=0;
         for(i=2;i<=n*m*2+1;i+=2)
         {ans[0]++;ans[ans[0]]=v[i^1];}
         for(i=1;i<=n;i++)
         {
         for(j=1;j<=m;j++)
         {
             printf("%d ",ans[(i-1)*m+j]);  
         }
         printf("\n");
         }
     }
}
int main()
{
    while(cin>>n>>m)
    solve();
    system("pause");
    return 0;
} 
