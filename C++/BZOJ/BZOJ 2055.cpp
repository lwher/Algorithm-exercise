#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#define INF 0x7f7f7f7f 
using namespace std; 
int n,m; 
int s,t; 
bool K; 
int to[40010],last[210],dis[210],pre[40010],dui[80020],cost[40010]; 
bool mark[210]; 
int v[40010]; 
int sz=1; 
int tou=1,wei=1; 
long long ans=0; 
void Ins(int a,int b,int c,int vv) 
{ 
     sz++; 
     to[sz]=b; 
     v[sz]=c; 
     pre[sz]=last[a]; 
     last[a]=sz; 
     cost[sz]=vv; 
     sz++; 
     to[sz]=a; 
     v[sz]=0; 
     pre[sz]=last[b]; 
     last[b]=sz; 
     cost[sz]=-vv; 
} 
bool spfa() 
{ 
    int i,now; 
    dis[t]=INF; 
    memset(mark,0,sizeof(mark)); 
    for(i=0;i<=2*n;i++) 
    dis[i]=INF; 
    tou=40000;wei=40000; 
    dui[40000]=s; 
    dis[s]=0; 
    mark[s]=1; 
    while(tou<=wei) 
    { 
       now=dui[tou]; 
       tou++; 
       i=last[now]; 
       while(i>0) 
       { 
         if(v[i]>0 && dis[now]+cost[i]<dis[to[i]]) 
         { 
           dis[to[i]]=dis[now]+cost[i]; 
           if(!mark[to[i]]) 
            { 
            if(dis[to[i]]<dis[dui[tou]])  
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
    if(dis[t]==INF) 
    return 0; 
    else 
    return 1; 
} 
int dfs(int x,int F) 
{ 
    if(x==t) {K=1;return F;} 
    int i=last[x]; 
    mark[x]=1; 
    int used=0,w; 
    while(i>0) 
    { 
       if(!mark[to[i]] && v[i]>0 && dis[x]+cost[i]==dis[to[i]]) 
       { 
       w=dfs(to[i],min(v[i],F-used)); 
       v[i]-=w; 
       v[i^1]+=w; 
       if(abs(cost[i])!=10000000)
       ans+=(long long)(w)*cost[i]; 
       used+=w; 
       if(used==F) return F; 
       } 
       i=pre[i]; 
    } 
    return used; 
} 
void  mincostflow() 
{ 
    while(1) 
    { 
       if(!spfa())   break; 
       K=1; 
       while(K) 
       { 
            K=0; 
            memset(mark,0,sizeof(mark)); 
            dfs(s,INF); 
        } 
    } 
} 
int main() 
{ 
    int i,j,a,b,c,vv; 
    scanf("%d%d",&n,&m); 
    s=2*n+1;t=2*n+2; 
    for(i=1;i<=n;i++) 
    { 
        scanf("%d",&a); 
        if(a!=-1) 
        Ins(i,i+n,a,-10000000); 
    } 
    for(i=1;i<=n-1;i++) 
    for(j=1;j<=n-i;j++) 
    { 
        scanf("%d",&vv); 
        if(vv!=-1) 
        { 
            Ins(i+n,i+j,INF,vv); 
        } 
    } 
    Ins(s,0,m,0); 
    for(i=1;i<=n;i++) 
    { 
        Ins(0,i,INF,0); 
        Ins(i+n,t,INF,0); 
    } 
    mincostflow(); 
    cout<<ans<<endl; 
    system("pause"); 
    return 0; 
}
