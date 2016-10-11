#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,m,s,t,ans;
int sz=1,to[300010],pre[300010],v[300010],last[10010];
int dui[10010],h[10010],gap[10010];
int A[110][110],B[110][110],C[110][110];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
    sz++;to[sz]=a;pre[sz]=last[b];v[sz]=0;last[b]=sz;
}
void bfs()
{
    memset(h,-1,sizeof(h));
    memset(gap,0,sizeof(gap));
    int now,i,tou=1,wei=1;
    dui[1]=t;h[t]=1;gap[1]=1;
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        for(i=last[now];i;i=pre[i])
        {
            if(h[to[i]]==-1)
            {
                h[to[i]]=h[now]+1;
                gap[h[to[i]]]++;
                dui[++wei]=to[i];
            }
        }
    }
}
int dfs(int x,int F)
{
    if(x==t) return F;
    int used=0,w,i;
    for(i=last[x];i;i=pre[i])
    {
        if(v[i]>0 && h[x]-1==h[to[i]])
        {
            w=min(v[i],F-used);
            w=dfs(to[i],w);
            v[i]-=w;
            v[i^1]+=w;
            used+=w;
            if(used==F) return F;
        }
    }
    gap[h[x]]--;
    if(!gap[h[x]])  h[s]=t+2;
    gap[++h[x]]++;
    return used;
}
int sap()
{
    int tmp=0;
    bfs();
    while(h[s]<t+2)  tmp+=dfs(s,INF);
    return tmp;
}
int P(int x,int y)
{
    return (x-1)*m+y;
}
void init()
{
    int i,j,k,nx,ny;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  scanf("%d",&A[i][j]);
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  scanf("%d",&B[i][j]);
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  scanf("%d",&C[i][j]);        
    s=n*m+1;t=s+1;
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)
    {
        if((i+j) & 1)  {Ins(s,P(i,j),A[i][j]);Ins(P(i,j),t,B[i][j]);}
        else   {Ins(s,P(i,j),B[i][j]);Ins(P(i,j),t,A[i][j]);}
        ans+=A[i][j]+B[i][j];
        for(k=0;k<4;k++)
        {
            nx=i+dx[k];ny=j+dy[k];
            if(nx<1 || nx>n || ny<1 || ny>m)  continue;
            Ins(P(i,j),P(nx,ny),C[i][j]+C[nx][ny]);
            if((i+j) & 1)  ans+=C[i][j]+C[nx][ny];
        }
    }
} 
int main()
{   init();
    printf("%d\n",ans-sap());
    system("pause");
    return 0;
}
