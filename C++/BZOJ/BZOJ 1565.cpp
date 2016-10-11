#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#define N 1010 
#define M 500010 
#define inf 1e8 
#define INF 0x7fffffff 
using namespace std; 
int n,m,sz=1,s,t,ans; 
int to[M],pre[M],v[M],last[N]; 
int sz1,to1[M],pre1[M],last1[N]; 
int dui[N],h[N],gap[N],rd[N]; 
int score[30][40]; 
bool mark[N]; 
void Ins(int a,int b,int c) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz; 
    sz++;to[sz]=a;pre[sz]=last[b];v[sz]=0;last[b]=sz; 
} 
void cl(int a,int b) 
{ 
    sz1++;to1[sz1]=b;pre1[sz1]=last1[a];last1[a]=sz1; 
    rd[b]++; 
} 
void bfs() 
{ 
    int now,i,tou=1,wei=1; 
    memset(h,-1,sizeof(h)); 
    dui[1]=t;h[t]=0;gap[0]=1; 
    while(tou<=wei) 
    { 
        now=dui[tou];tou++; 
        i=last[now]; 
        while(i>0) 
        { 
            if(h[to[i]]==-1)  
            { 
                h[to[i]]=h[now]+1; 
                gap[h[to[i]]]++; 
                dui[++wei]=to[i]; 
            } 
            i=pre[i]; 
        } 
    } 
} 
int dfs(int x,int F) 
{ 
    if(x==t)  return F; 
    int i=last[x],used=0,w; 
    while(i>0) 
    { 
        if(v[i]>0 && h[x]-1==h[to[i]]) 
        { 
            w=F-used; 
            w=dfs(to[i],min(v[i],w)); 
            v[i]-=w; 
            v[i^1]+=w; 
            used+=w; 
            if(used==F)  return F; 
        } 
        i=pre[i]; 
    } 
    gap[h[x]]--; 
    if(!gap[h[x]])  h[s]=n*m+3; 
    gap[++h[x]]++; 
    return used; 
} 
void topsort() 
{ 
    int i,now,tou=1,wei=0; 
    for(i=1;i<=n*m;i++) 
    { 
        if(rd[i]==0)  {dui[++wei]=i;} 
    } 
    while(tou<=wei) 
    { 
        now=dui[tou];tou++; 
        mark[now]=1; 
        i=last1[now]; 
        while(i>0) 
        { 
            rd[to1[i]]--; 
            if(rd[to1[i]]==0)  dui[++wei]=to1[i]; 
            i=pre1[i]; 
        } 
    } 
} 
void init__build() 
{ 
    int i,j,k,x,y,w; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++) 
    { 
        scanf("%d",&score[i][j]); 
        scanf("%d",&w); 
        while(w--) 
        { 
            scanf("%d%d",&x,&y); 
            x++;y++; 
            Ins((i-1)*m+j,(x-1)*m+y,inf); 
            cl((i-1)*m+j,(x-1)*m+y); 
        } 
        if(j!=m) 
        { 
            Ins((i-1)*m+j+1,(i-1)*m+j,inf); 
            cl((i-1)*m+j+1,(i-1)*m+j); 
        } 
    } 
    s=n*m+1;t=s+1; 
    topsort(); 
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++) 
    if(mark[(i-1)*m+j]) 
    { 
        if(score[i][j]>0) 
        { 
            ans+=score[i][j];Ins((i-1)*m+j,t,score[i][j]); 
        } 
        else
        { 
            Ins(s,(i-1)*m+j,-score[i][j]); 
        } 
    } 
} 
void solve() 
{ 
    int tmp=0; 
    init__build(); 
    bfs(); 
    while(h[s]<n*m+3)  {tmp+=dfs(s,INF);} 
    printf("%d\n",ans-tmp); 
} 
int main() 
{ 
    solve(); 
    //system("pause"); 
    return 0; 
}