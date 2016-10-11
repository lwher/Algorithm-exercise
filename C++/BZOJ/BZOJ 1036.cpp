#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#define INF 0x7fffffff 
#define N 30010 
#define M 60010 
#define max(aa,bb) ((aa)>(bb)?(aa):(bb)) 
using namespace std; 
int n; 
int fa[N][15],quan[N],deep[N],sum[N]; 
int last[N],pre[M],to[M],sz,segsz; 
int pl[N],belong[N]; 
int tmax[100000],tsum[100000]; 
bool mark[N]; 
void Ins(int a,int b) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz; 
    sz++;to[sz]=a;pre[sz]=last[b];last[b]=sz; 
} 
void init() 
{ 
    int i,a,b; 
    scanf("%d",&n); 
    for(i=1;i<n;i++) 
    {scanf("%d%d",&a,&b);Ins(a,b);} 
    for(i=1;i<=n;i++) 
    scanf("%d",&quan[i]); 
} 
void dfs1(int x) 
{ 
    int i; 
    sum[x]=1;mark[x]=1; 
    for(i=1;i<=14;i++) 
    { 
    if(deep[x]<(1<<i)) break; 
    fa[x][i]=fa[fa[x][i-1]][i-1]; 
    } 
    i=last[x]; 
    while(i>0) 
    { 
        if(!mark[to[i]]) 
        { 
            deep[to[i]]=deep[x]+1; 
            fa[to[i]][0]=x; 
            dfs1(to[i]); 
            sum[x]+=sum[to[i]]; 
        } 
        i=pre[i]; 
    } 
} 
void dfs2(int x,int chain) 
{ 
    int i,k=0; 
    segsz++; 
    pl[x]=segsz; 
    belong[x]=chain; 
    i=last[x]; 
    while(i>0) 
    { 
        if(deep[to[i]]>deep[x] && sum[to[i]]>sum[k]) 
        k=to[i]; 
        i=pre[i]; 
    } 
    if(k==0)  return; 
    dfs2(k,chain); 
    i=last[x]; 
    while(i>0) 
    { 
        if(deep[to[i]]>deep[x] && k!=to[i]) 
        dfs2(to[i],to[i]); 
        i=pre[i]; 
    } 
} 
int LCA(int a,int b) 
{ 
    int i,t; 
    if(deep[a]<deep[b]) 
    {i=a;a=b;b=i;} 
    t=deep[a]-deep[b]; 
    for(i=14;i>=0;i--) 
    { 
        if(t>=(1<<i)) 
        { 
            a=fa[a][i]; 
            t-=(1<<i); 
        } 
    } 
    for(i=14;i>=0;i--) 
    { 
        if(deep[a]>=(1<<i) && fa[a][i]!=fa[b][i]) 
        { 
            a=fa[a][i]; 
            b=fa[b][i]; 
        } 
    } 
    if(a==b) return a; 
    else
    return fa[a][0]; 
} 
void change(int l,int r,int k,int w,int x) 
{ 
    if(l==r) 
    {tsum[k]=x;tmax[k]=x;return;} 
    int mid=(l+r)>>1; 
    if(w<=mid) 
    change(l,mid,k+k,w,x); 
    else
    change(mid+1,r,k+k+1,w,x); 
    tmax[k]=max(tmax[k+k],tmax[k+k+1]); 
    tsum[k]=tsum[k+k]+tsum[k+k+1]; 
} 
int getmax(int l,int r,int k,int zuo,int you) 
{ 
     int a=-INF,b=-INF; 
     if(l>=zuo && r<=you)  return tmax[k]; 
     int mid=(l+r)>>1; 
     if(zuo<=mid) 
     a=getmax(l,mid,k+k,zuo,you); 
     if(you>mid) 
     b=getmax(mid+1,r,k+k+1,zuo,you); 
     return max(a,b);    
} 
int getsum(int l,int r,int k,int zuo,int you) 
{ 
    if(zuo>r || you<l)  return 0; 
    if(l>=zuo && r<=you)  return tsum[k]; 
    int mid=(l+r)>>1; 
    return getsum(l,mid,k+k,zuo,you)+getsum(mid+1,r,k+k+1,zuo,you); 
} 
int solvemax(int x,int f) 
{ 
    int a,b,maxx=-INF; 
    while(belong[x]!=belong[f]) 
    { 
        a=pl[belong[x]];b=pl[x]; 
        maxx=max(maxx,getmax(1,n,1,a,b)); 
        x=fa[belong[x]][0]; 
    } 
    a=pl[f];b=pl[x]; 
    maxx=max(maxx,getmax(1,n,1,a,b)); 
    return maxx; 
} 
int solvesum(int x,int f) 
{ 
    int a,b,nsum=0; 
    while(belong[x]!=belong[f]) 
    { 
        a=pl[belong[x]]; 
        b=pl[x]; 
        nsum+=getsum(1,n,1,a,b); 
        x=fa[belong[x]][0]; 
    } 
    a=pl[f];b=pl[x]; 
    nsum+=getsum(1,n,1,a,b); 
    return nsum; 
} 
void solve() 
{ 
    int i,c,q,a,b,k; 
    char ch[6]; 
    for(i=1;i<=n;i++) 
    change(1,n,1,pl[i],quan[i]); 
    scanf("%d",&q); 
    for(i=1;i<=q;i++) 
    { 
        scanf("%s%d%d",ch,&a,&b); 
        if(ch[0]=='C') 
        { 
            quan[a]=b; 
            change(1,n,1,pl[a],b); 
        } 
        else
        if(ch[1]=='M') 
        { 
            c=LCA(a,b); 
            k=max(solvemax(a,c),solvemax(b,c)); 
            printf("%d\n",k); 
        } 
        else
        { 
            c=LCA(a,b); 
            k=solvesum(a,c)+solvesum(b,c); 
            k-=quan[c]; 
            printf("%d\n",k); 
        } 
    } 
} 
int main() 
{    
    init(); 
    int i; 
    deep[1]=1; 
    dfs1(1); 
    dfs2(1,1);   
    solve(); 
    //system("pause"); 
    return 0; 
} 

