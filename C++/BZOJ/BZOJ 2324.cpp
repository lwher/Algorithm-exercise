#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#define N 500 
#define M 100010 
#define INF 0x7fffffff 
using namespace std; 
int n,m,sz=1,ans,p; 
int to[M],pre[M],last[N],v[M],cost[M]; 
int dui[3010],d[N]; 
int map[160][160]; 
int s,t; 
bool mark[N]; 
void Ins(int a,int b,int c,int d) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;v[sz]=c;cost[sz]=d; 
    sz++;to[sz]=a;pre[sz]=last[b];last[b]=sz;v[sz]=0;cost[sz]=-d; 
} 
bool spfa() 
{ 
    int tou=1,wei=1; 
    memset(d,127,sizeof(d)); 
    int k=d[0]; 
    memset(mark,0,sizeof(mark)); 
    dui[1]=t; 
    mark[t]=1; 
    d[t]=0; 
    int now,i; 
    while(tou<=wei) 
    { 
        now=dui[tou]; 
        i=last[now]; 
        while(i>0) 
        { 
            if(v[i^1]>0 && d[now]-cost[i]<d[to[i]]) 
            { 
                d[to[i]]=d[now]-cost[i]; 
                if(!mark[to[i]]) 
                {wei++;dui[wei]=to[i];mark[to[i]]=1;} 
            } 
            i=pre[i]; 
        } 
        tou++; 
        mark[now]=0; 
    } 
    if(d[s]<k)  return 1; 
    else  return 0; 
} 
int dfs(int x,int F) 
{ 
    if(x==t) {mark[t]=1;return F;} 
    int i,used=0,w; 
    mark[x]=1; 
    i=last[x]; 
    while(i>0) 
    { 
        if(!mark[to[i]] && v[i]>0 && d[x]-cost[i]==d[to[i]]) 
        { 
            w=F-used; 
            w=dfs(to[i],min(v[i],w)); 
            ans+=w*cost[i]; 
            v[i]-=w; 
            v[i^1]+=w; 
            used+=w; 
            if(used==F)  return F; 
        } 
        i=pre[i]; 
    } 
    return used; 
} 
void ZKW() 
{ 
    while(spfa()) 
    { 
        mark[t]=1; 
        while(mark[t]) 
        { 
            memset(mark,0,sizeof(mark)); 
            dfs(s,INF); 
        } 
    } 
} 
void floyd() 
{ 
    int i,j,k; 
    for(k=0;k<=n;k++) 
    for(i=0;i<=n;i++) 
    if(map[i][k]<INF) 
    for(j=0;j<=n;j++) 
    if((k<=i || k<=j) && map[j][k]<INF && map[i][j]>map[i][k]+map[k][j]) 
    map[i][j]=map[i][k]+map[k][j]; 
} 
void build() 
{ 
    scanf("%d%d%d",&n,&m,&p); 
    int i,j,k; 
    int a,b,c; 
    for(i=0;i<=n;i++) 
    for(j=0;j<=n;j++) 
    map[i][j]=INF; 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d%d",&a,&b,&c); 
        map[a][b]=min(map[a][b],c); 
        map[b][a]=min(map[b][a],c); 
    } 
    s=n+n+1;t=s+1; 
    Ins(s,0,p,0); 
    floyd(); 
    for(i=1;i<=n;i++) 
    { 
        if(map[0][i]<INF)  Ins(0,i,1,map[0][i]); 
        Ins(s,i+n,1,0); 
        Ins(i,t,1,0); 
        for(j=i+1;j<=n;j++) 
        if(map[i][j]<INF) 
        Ins(i+n,j,1,map[i][j]); 
    } 
} 
int main() 
{ 
    build(); 
    ZKW(); 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}