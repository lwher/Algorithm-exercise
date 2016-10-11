#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#define INF 0x7fffffff 
using namespace std; 
int n,m,S,s,t,ans; 
int U[60],D[60]; 
int sz=1,to[510],pre[510],v[510],cost[510],last[60]; 
int d[510],dui[500010]; 
bool mark[510],K; 
void Ins(int a,int b,int c,int d) 
{ 
    sz++;to[sz]=b;v[sz]=c;cost[sz]=d;pre[sz]=last[a];last[a]=sz; 
    sz++;to[sz]=a;v[sz]=0;cost[sz]=-d;pre[sz]=last[b];last[b]=sz; 
} 
bool spfa() 
{ 
    memset(d,127,sizeof(d)); 
    memset(mark,0,sizeof(mark)); 
    int i,now,tou=1,wei=1,k=d[0]; 
    dui[1]=t;d[t]=0;mark[t]=1; 
    while(tou<=wei) 
    { 
        now=dui[tou];tou++; 
        i=last[now]; 
        while(i>0) 
        { 
            if(v[i^1]>0 && d[now]+cost[i^1]<d[to[i]]) 
            { 
                d[to[i]]=d[now]+cost[i^1]; 
                if(!mark[to[i]])  dui[++wei]=to[i],mark[to[i]]=1; 
            } 
            i=pre[i]; 
        } 
        mark[now]=0; 
    } 
    if(d[s]!=k)  return 1;  return 0; 
} 
int dfs(int x,int F) 
{ 
    if(x==t) {K=1;return F;} 
    int i=last[x],used=0,w; 
    mark[x]=1; 
    while(i>0) 
    { 
        if(v[i]>0 && !mark[to[i]] && d[x]-cost[i]==d[to[i]]) 
        { 
            w=F-used; 
            w=dfs(to[i],min(w,v[i])); 
            v[i]-=w; 
            v[i^1]+=w; 
            used+=w; 
            ans+=w*cost[i]; 
            if(F==used)  return F; 
        } 
        i=pre[i]; 
    } 
    return used; 
} 
void mincostflow() 
{    
    while(spfa()) 
    { 
        K=1;   
        while(K)   
        { 
            K=0;memset(mark,0,sizeof(mark)); 
            dfs(s,INF); 
        } 
    } 
} 
int main() 
{ 
    int i,j; 
    scanf("%d%d%d",&n,&m,&S); 
    for(i=1;i<=n;i++)  scanf("%d",&U[i]); 
    for(i=1;i<=n;i++)  scanf("%d",&D[i]); 
    s=n+1;t=s+1; 
    for(i=1;i<=n;i++)  Ins(s,i,100000000,D[i]); 
    for(i=1;i<=n;i++)  Ins(i,t,U[i],0); 
    for(i=1;i<n;i++)   Ins(i,i+1,S,m); 
    mincostflow(); 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}