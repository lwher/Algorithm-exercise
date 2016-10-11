#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int P,Q,R,D,s,t,tt,node[45][45][45],fv[45][45][45];
int sz=1,to[1000010],pre[1000010],v[1000010],last[65000],cur[65000];
int dui[65000],h[65000],gap[60000];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
inline void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
    sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void bfs()
{
    memset(h,-1,sizeof(h));
    memset(gap,0,sizeof(gap));
    int tou=1,wei=1,now,i;
    dui[1]=t;h[t]=1;gap[1]=1;
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        for(i=last[now];i;i=pre[i])
        if(h[to[i]]==-1)
        {
           h[to[i]]=h[now]+1;
           gap[h[to[i]]]++;
           dui[++wei]=to[i];
        }
    }
}
int dfs(int x,int F)
{
    if(x==t) return F;
    int used=0,w,i;
    for(i=cur[x];i;i=pre[i])
    if(v[i]>0 && h[x]-1==h[to[i]])
    {
        w=min(F-used,v[i]);
        w=dfs(to[i],w);
        v[i]-=w;v[i^1]+=w;used+=w;
        if(v[i]>0) cur[x]=i;
        if(used==F) return F;
    }
    gap[h[x]]--;
    if(!gap[h[x]]) h[s]=t+2;
    cur[x]=last[x];
    gap[++h[x]]++;
    return used;
}
int SAP()
{
    int i,ans=0;
    bfs();
    for(i=1;i<=t;i++) cur[i]=last[i];
    while(h[s]<t+2) ans+=dfs(s,INF);
    return ans;
}
int main()
{
    int i,j,k,l,nx,ny;
    scanf("%d%d%d%d",&P,&Q,&R,&D);
    R++;s=P*Q*R+1;t=s+1;    
    for(i=1;i<R;i++) for(j=1;j<=P;j++) for(k=1;k<=Q;k++)  scanf("%d",&fv[i][j][k]);
    for(i=1;i<=R;i++) for(j=1;j<=P;j++) for(k=1;k<=Q;k++) node[i][j][k]=++tt;
    for(i=1;i<=P;i++) for(j=1;j<=Q;j++) {Ins(s,node[1][i][j],INF);Ins(node[R][i][j],t,INF);}
    for(i=1;i<R;i++) for(j=1;j<=P;j++) for(k=1;k<=Q;k++) Ins(node[i][j][k],node[i+1][j][k],fv[i][j][k]);    
    for(i=D+1;i<=R;i++) for(j=1;j<=P;j++) for(k=1;k<=Q;k++)
    {
        for(l=0;l<4;l++)
        {
            nx=j+dx[l];ny=k+dy[l];
            if(nx<1 || ny<1 || nx>P || ny>Q) continue;
            Ins(node[i][j][k],node[i-D][nx][ny],INF); 
        }
    }
    printf("%d\n",SAP());
    system("pause");
    return 0;
}
