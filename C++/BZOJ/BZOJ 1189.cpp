#include<iostream>
#include<cstdio>
#include<cstring>
#define S 0
#define T 1000
#define inf 0x7fffffff
using namespace std;
int n,m,door=1,cnt,ans,tot,mn=-1;
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
int mp[21][21],head[1001],h[1001],q[1001];
int dis[401][21][21];
struct data{int x,y,s;}d[401];
struct data2{int to,next,v;}e[1000001];
bool bfs()
{
     int t=0,w=1,i,now;
     memset(h,-1,sizeof(h));
     h[S]=0;q[0]=S;
     while(t<w)
     {
               now=q[t];t++;
               i=head[now];
               while(i)
               {
                       if(h[e[i].to]==-1&&e[i].v){h[e[i].to]=h[now]+1;q[w++]=e[i].to;}
                       i=e[i].next;
                       }
               }
     if(h[T]==-1)return 0;
     return 1;
 }
int dfs(int x,int f)
{
    if(x==T)return f;
    int i=head[x];
    int w,used=0;
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
void ins(int u,int v,int w)
{e[++cnt].to=v;e[cnt].next=head[u];e[cnt].v=w;head[u]=cnt;}
void insert(int u,int v,int w)
{ins(u,v,w);ins(v,u,0);} 
void build(int x)
{
     memset(head,0,sizeof(head));
     cnt=1;
     for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
           if(mp[i][j]==1)insert(S,(i-1)*m+j,1);
     for(int i=2;i<=door;i++)insert(n*m+i,T,x);
     for(int i=2;i<=door;i++)
       for(int j=1;j<=n;j++)
          for(int k=1;k<=m;k++)
             if(dis[i][j][k]<=x)insert((j-1)*m+k,n*m+i,x);
 }
void search(int k,int x,int y) 
{
     int t=0,w=1,nowx,nowy;
     d[0].x=x;d[0].y=y;
     while(t<w)
     {
               for(int i=0;i<4;i++)
               {   
                   nowx=d[t].x+xx[i],nowy=d[t].y+yy[i];
                   if(nowx<1||nowy<1||nowx>n||nowy>m||mp[nowx][nowy]!=1)continue;
                   if(dis[k][nowx][nowy]==inf)
                   {
                       dis[k][nowx][nowy]=d[w].s=d[t].s+1;
                       d[w].x=nowx;d[w].y=nowy;
                       w++; 
                                           }
               }
               t++;
     }
}
bool judge(int x)
{ 
     build(x);
     ans=0;
     dinic();
     if(ans==tot)return 1;
     return 0; 
 }
int main()
{
    scanf("%d%d",&n,&m);
    char ch[21];
    for(int i=1;i<=n;i++)
    {
            scanf("%s",ch);
            for(int j=1;j<=m;j++)
            {
                    if(ch[j-1]=='.'){mp[i][j]=1;tot++;}
                    else if(ch[j-1]=='D')mp[i][j]=++door; 
                    }
            }
    for(int i=2;i<=door;i++)
       for(int j=1;j<=n;j++)
          for(int k=1;k<=m;k++)
             dis[i][j][k]=inf;
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
          if(mp[i][j]>1)search(mp[i][j],i,j);
    int l=0,r=400;
    while(l<=r)
    {
               int mid=(l+r)>>1;
               if(judge(mid)){mn=mid;r=mid-1;}
               else l=mid+1;
               }
    if(mn==-1)printf("impossible\n");
    else printf("%d\n",mn);
    system("pause");
    return 0;
}
