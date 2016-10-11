#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
struct sth 
{ 
    int fo,to; 
    int v; 
}lu[1010]; 
int fa[110],f[110],f1[110]; 
bool mark[1010]; 
int gs[1010],xu[1010]; 
int bian[1010][1010]; 
int answer,ks; 
bool o; 
int n,m,l; 
int sz,sz1; 
long long ans; 
int getfa(int x) 
{ 
    if(fa[x]==0) return x; 
    else
    return fa[x]=getfa(fa[x]); 
} 
inline bool comp(sth a,sth b) 
{ 
    return a.v<b.v; 
} 
void Ins(int a,int b,int c) 
{ 
    sz++; 
    lu[sz].fo=a; 
    lu[sz].to=b; 
    lu[sz].v=c; 
} 
void solve() 
{ 
    int x,y; 
    int j=0; 
    int i=1; 
    sort(lu+1,lu+1+m,comp); 
    while(j<n-1) 
    { 
        x=getfa(lu[i].fo); 
        y=getfa(lu[i].to); 
        if(x!=y) 
        { 
            sz1++; 
            xu[sz1]=i; 
            mark[i]=1; 
            j++; 
            ans+=lu[i].v; 
            fa[x]=y; 
        } 
        i++; 
        if(i>m) 
        {break;} 
    } 
    if(j<n-1) 
    o=1; 
} 
void doing(int x) 
{ 
    int xx,y; 
    bian[sz][0]=0; 
    bian[sz][0]++;bian[sz][bian[sz][0]]=x; 
    gs[sz]=1; 
    int i=x-1; 
    while(i>0 && lu[i].v==lu[x].v) 
    { 
    xx=getfa(lu[i].fo); 
    y=getfa(lu[i].to); 
    if(xx!=y) 
    { 
    bian[sz][0]++;bian[sz][bian[sz][0]]=i; 
    if(mark[i]) 
    gs[sz]++; 
    } 
    i--; 
    } 
    i=x+1; 
    while(i<=m && lu[i].v==lu[x].v) 
    { 
    xx=getfa(lu[i].fo); 
    y=getfa(lu[i].to); 
    if(xx!=y) 
    { 
    bian[sz][0]++;bian[sz][bian[sz][0]]=i; 
    if(mark[i]) 
    gs[sz]++; 
    } 
    i++; 
    } 
} 
void build() 
{ 
    int i,j; 
    int x,y; 
    sz=0; 
    memset(fa,0,sizeof(fa)); 
    for(i=1;i<=sz1;i++) 
    { 
        if(lu[xu[i]].v!=lu[xu[i-1]].v) 
        { 
           sz++; 
           doing(xu[i]); 
           if(bian[sz][0]==1) 
           { 
             x=getfa(lu[bian[sz][1]].fo); 
             y=getfa(lu[bian[sz][1]].to); 
             if(x!=y) 
             fa[x]=y; 
             sz--; 
           } 
        } 
     } 
} 
bool check() 
{ 
    int i,j; 
    for(j=1;j<=n;j++) 
    fa[j]=f[j]; 
    int x,y; 
    for(i=1;i<=l;i++) 
    { 
        x=getfa(lu[xu[i]].fo); 
        y=getfa(lu[xu[i]].to); 
        if(x==y) return 0; 
        fa[x]=y; 
    } 
    for(j=1;j<=n;j++) 
    f1[j]=fa[j]; 
    return 1; 
} 
void dfs(int top,int now) 
{ 
    if(l==gs[top]) 
    { 
        if(check()) 
        ks++; 
        return; 
    } 
    if(now==bian[top][0]+1) 
    return; 
      
    l++; 
    xu[l]=bian[top][now]; 
    dfs(top,now+1); 
    l--; 
      
    dfs(top,now+1); 
} 
int main() 
{ 
    int i,j; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=m;i++) 
    scanf("%d%d%d",&lu[i].fo,&lu[i].to,&lu[i].v); 
    solve(); 
    ans=0; 
    if(!o) 
    { 
    build();     
    ans=1; 
    for(j=1;j<=n;j++) 
    f1[j]=fa[j]; 
    for(i=1;i<=sz;i++) 
    { 
    for(j=1;j<=n;j++) 
    f[j]=f1[j]; 
    ks=0; 
    l=0; 
    dfs(i,1); 
    ans=(ans*ks)%31011; 
    } 
    } 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}