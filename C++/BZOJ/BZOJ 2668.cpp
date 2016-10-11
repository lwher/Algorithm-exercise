#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,m,s0,s1,s,t,maxflow,mincost;
char CHU[21][21],MO[21][21],XIAN[21][21];
int chu[21][21],mo[21][21],xian[21][21],d[1210],dui[500010];
int sz=1,to[100010],pre[100010],v[100010],cost[100010],last[1210];
int dx[8]={0,0,1,-1,1,-1,-1,1};
int dy[8]={1,-1,0,0,1,-1,1,-1};
bool mark[1210];
void Ins(int a,int b,int c,int d)
{
    sz++;to[sz]=b;v[sz]=c;cost[sz]=d;pre[sz]=last[a];last[a]=sz;
    sz++;to[sz]=a;v[sz]=0;cost[sz]=-d;pre[sz]=last[b];last[b]=sz;
}
bool spfa()
{
    memset(mark,0,sizeof(mark));
    memset(d,127,sizeof(d));
    int tou=1,wei=1,now,i,inf=d[0];
    dui[1]=t;d[t]=0;mark[t]=1;
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        for(i=last[now];i>0;i=pre[i])
        {
            if(v[i^1] && d[now]-cost[i]<d[to[i]])
            {
                d[to[i]]=d[now]-cost[i];
                if(!mark[to[i]])  {mark[to[i]]=1;dui[++wei]=to[i];}
            }
        }
        mark[now]=0;
    }
    if(d[s]==inf)  return 0;  return 1;
}
int dfs(int x,int F)
{
    mark[x]=1;
    if(x==t) return F;
    int used=0,w,i;
    for(i=last[x];i;i=pre[i])
    {
        if(!mark[to[i]] && v[i] && d[x]-cost[i]==d[to[i]])
        {
            w=min(v[i],F-used);
            w=dfs(to[i],w);
            v[i]-=w;
            v[i^1]+=w;
            used+=w;
            if(F==used)  return F;
        }
    }
    return used;
}
void mincostflow()
{
    int tmp;    
    while(spfa())
    {
        mark[t]=1;
        while(mark[t])
        {
            memset(mark,0,sizeof(mark));
            tmp=dfs(s,INF);
            maxflow+=tmp;mincost+=tmp*d[s];
        }
    }
}
int main()
{
    int i,j,k,p0,p1,p2,nx,ny;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  scanf("%s",CHU[i]+1);
    for(i=1;i<=n;i++)  scanf("%s",MO[i]+1);
    for(i=1;i<=n;i++)  scanf("%s",XIAN[i]+1);
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)
    {
        chu[i][j]=CHU[i][j]-'0';
        mo[i][j]=MO[i][j]-'0';
        xian[i][j]=XIAN[i][j]-'0';
        if(chu[i][j]==1) s0++;
        if(mo[i][j]==1) s1++;
        if(chu[i][j]==1 && mo[i][j]==1)  {s0--;s1--;chu[i][j]=0;mo[i][j]=0;}
    }
    s=n*m*3+1;t=s+1;
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)
    {
        p0=(i-1)*m+j;p1=p0+n*m;p2=p1+n*m;
        if(chu[i][j]==1)
        {
            Ins(p1,p0,xian[i][j]/2,0);
            Ins(p0,p2,(xian[i][j]+1)/2,0);
            Ins(s,p0,1,0);
        }  else
        if(mo[i][j]==1)
        {
            Ins(p1,p0,(xian[i][j]+1)/2,0);
            Ins(p0,p2,xian[i][j]/2,0);
            Ins(p0,t,1,0);
        }  else
        {
            Ins(p1,p0,xian[i][j]/2,0);
            Ins(p0,p2,xian[i][j]/2,0);
        }
    }
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)
    {
        p2=(i-1)*m+j+n*m*2;
        for(k=0;k<8;k++)
        {
            nx=i+dx[k];ny=j+dy[k];
            if(nx<1 || nx>n || ny<1 || ny>m)  continue;
            p1=(nx-1)*m+ny+n*m;
            Ins(p2,p1,INF,1);
        }
    }   
    if(s0==s1)
    {       
        mincostflow();
        if(maxflow==s1)  printf("%d\n",mincost);
        else printf("-1\n");
    }
    else  printf("-1\n");
    //system("pause");
    return 0;
}