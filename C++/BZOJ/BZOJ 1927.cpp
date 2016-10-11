#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<algorithm> 
#define INF 0x7fffffff 
using namespace std; 
int n,m,s,t; 
int sz=1,to[100010],pre[100010],v[100010],cost[100010],last[2010]; 
int dui[100010],d[2010],ans; 
bool mark[2010]; 
void Ins(int a,int b,int c,int e) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;cost[sz]=e;last[a]=sz; 
    sz++;to[sz]=a;pre[sz]=last[b];v[sz]=0;cost[sz]=-e;last[b]=sz; 
} 
bool spfa() 
{ 
    memset(d,127,sizeof(d)); 
    memset(mark,0,sizeof(mark)); 
    int tou=1,wei=1,i,now,p=d[0]; 
    dui[1]=t;mark[t]=1;d[t]=0; 
    while(tou<=wei) 
    { 
        now=dui[tou];tou++; 
        i=last[now]; 
        while(i>0) 
        { 
            if(v[i^1]>0 && d[now]-cost[i]<d[to[i]]) 
            { 
                d[to[i]]=d[now]-cost[i]; 
                if(!mark[to[i]])  {mark[to[i]]=1;dui[++wei]=to[i];} 
            } 
            i=pre[i]; 
        } 
        mark[now]=0; 
    } 
    if(d[s]==p)  return 0;  return 1; 
} 
int dfs(int x,int F) 
{ 
    if(x==t)  {mark[t]=1;return F;} 
    mark[x]=1; 
    int i=last[x],used=0,w; 
    while(i>0) 
    { 
        if(v[i]>0 && !mark[to[i]] && d[x]-cost[i]==d[to[i]]) 
        { 
            w=min(F-used,v[i]); 
            w=dfs(to[i],w); 
            used+=w; 
            v[i]-=w; 
            v[i^1]+=w; 
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
            ans+=dfs(s,INF)*d[s]; 
        } 
    } 
    printf("%d\n",ans); 
} 
void init() 
{ 
    int i,a,b,c,k; 
    scanf("%d%d",&n,&m); 
    s=n*2+1;t=s+1; 
    for(i=1;i<=n;i++) 
    { 
        scanf("%d",&a); 
        Ins(s,i+n,1,a);Ins(i+n,t,1,0);Ins(s,i,1,0); 
    } 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d%d",&a,&b,&c); 
        if(a>b)  {k=a;a=b;b=k;} 
        Ins(a,b+n,1,c); 
    } 
} 
int main() 
{ 
    init();  
    ZKW(); 
    //system("pause"); 
    return 0; 
}