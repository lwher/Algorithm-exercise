#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#define N 1010 
#define M 200010 
#define INF 0x7fffffff 
using namespace std; 
int n,m,sz=1,need[1010]; 
long long ans; 
int to[M],pre[M],last[N],v[M],cost[M]; 
int dui[200010],d[N]; 
int s,t; 
bool mark[N]; 
void Ins(int a,int b,int c,int d) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;v[sz]=c;cost[sz]=d; 
    sz++;to[sz]=a;pre[sz]=last[b];last[b]=sz;v[sz]=0;cost[sz]=-d; 
} 
bool spfa() 
{ 
    int now,i; 
    int tou=100000,wei=100000; 
    for(i=1;i<=t;i++) 
    d[i]=INF; 
    memset(mark,0,sizeof(mark)); 
    dui[tou]=t; 
    mark[t]=1; 
    d[t]=0; 
    while(tou<=wei) 
    { 
        now=dui[tou]; 
        tou++; 
        i=last[now]; 
        while(i>0) 
        { 
            if(v[i^1]>0 && d[now]-cost[i]<d[to[i]]) 
            { 
                d[to[i]]=d[now]-cost[i]; 
                if(!mark[to[i]]) 
                { 
                if(d[to[i]]<d[dui[tou]]) 
                {tou--;dui[tou]=to[i];} 
                else
                {wei++;dui[wei]=to[i];} 
                mark[to[i]]=1; 
                } 
            } 
            i=pre[i]; 
        } 
        mark[now]=0; 
    } 
    if(d[s]<INF)  return 1; 
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
void build() 
{ 
    int i,l,r,vv; 
    scanf("%d%d",&n,&m); 
    s=n+2;t=s+1; 
    for(i=1;i<=n;i++) 
    scanf("%d",&need[i]); 
    for(i=n+1;i>=1;i--) 
    { 
        need[i]=need[i]-need[i-1]; 
        Ins(i,i-1,INF,0); 
        if(need[i]>0) 
        Ins(s,i,need[i],0); 
        else
        if(need[i]<0) 
        Ins(i,t,-need[i],0); 
    } 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d%d",&l,&r,&vv); 
        Ins(l,r+1,INF,vv); 
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