#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#define INF 0x7fffffff 
#define N 100010 
#define M 200010 
#define max(aa,bb) ((aa)>(bb)?(aa):(bb)) 
using namespace std; 
int n,q; 
int fa[N][17],quan[N],deep[N],sum[N]; 
int last[N],pre[M],to[M],sz,segsz; 
int pl[N],belong[N]; 
int tl[300000],tsum[300000],tr[300000]; 
int sm,rig; 
bool mark[300000],o; 
void Ins(int a,int b) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz; 
    sz++;to[sz]=a;pre[sz]=last[b];last[b]=sz; 
} 
void init() 
{ 
    int i,a,b; 
    scanf("%d%d",&n,&q); 
    for(i=1;i<=n;i++) 
    scanf("%d",&quan[i]); 
    for(i=1;i<n;i++) 
    {scanf("%d%d",&a,&b);Ins(a,b);} 
} 
void dfs1(int x) 
{ 
    int i;  
    sum[x]=1;mark[x]=1; 
    for(i=1;i<=16;i++) 
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
    for(i=16;i>=0;i--) 
    { 
        if(t>=(1<<i)) 
        { 
            a=fa[a][i]; 
            t-=(1<<i); 
        } 
    } 
    for(i=16;i>=0;i--) 
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
void change(int l,int r,int k,int zuo,int you,int x) 
{ 
    if(l==r) {tsum[k]=1;tl[k]=x;tr[k]=x;return;} 
    if(l>=zuo && r<=you)  {tsum[k]=1;tl[k]=x;tr[k]=x;mark[k]=1;return;} 
    if(mark[k]) 
    { 
        mark[k]=0; 
        tsum[k+k]=1;tl[k+k]=tl[k];tr[k+k]=tr[k]; 
        mark[k+k]=1; 
        tsum[k+k+1]=1;tl[k+k+1]=tl[k];tr[k+k+1]=tr[k]; 
        mark[k+k+1]=1; 
    } 
    int mid=(l+r)>>1; 
    if(zuo<=mid)  change(l,mid,k+k,zuo,you,x); 
    if(you>mid)  change(mid+1,r,k+k+1,zuo,you,x); 
    if(tr[k+k]==tl[k+k+1])  tsum[k]=tsum[k+k]+tsum[k+k+1]-1; 
    else   tsum[k]=tsum[k+k]+tsum[k+k+1]; 
    tl[k]=tl[k+k];tr[k]=tr[k+k+1]; 
} 
int getse(int l,int r,int k,int w) 
{ 
    if(l==r)  
    {return tl[k];} 
    if(mark[k]) 
    { 
        mark[k]=0; 
        tsum[k+k]=1;tl[k+k]=tl[k];tr[k+k]=tr[k]; 
        mark[k+k]=1; 
        tsum[k+k+1]=1;tl[k+k+1]=tl[k];tr[k+k+1]=tr[k]; 
        mark[k+k+1]=1; 
    } 
    int mid=(l+r)>>1; 
    if(w<=mid)  return getse(l,mid,k+k,w); 
    if(w>mid)  return getse(mid+1,r,k+k+1,w); 
} 
void getsum(int l,int r,int k,int zuo,int you) 
{ 
    if(l>=zuo && r<=you) 
    { 
        if(!o) 
        {o=1;sm=tsum[k];rig=tr[k];} 
        else
        { 
            if(tl[k]==rig) 
            sm+=tsum[k]-1; 
            else
            sm+=tsum[k]; 
            rig=tr[k]; 
        } 
        return; 
    } 
    if(mark[k]) 
    { 
        mark[k]=0; 
        tsum[k+k]=1;tl[k+k]=tl[k];tr[k+k]=tr[k]; 
        mark[k+k]=1; 
        tsum[k+k+1]=1;tl[k+k+1]=tl[k];tr[k+k+1]=tr[k]; 
        mark[k+k+1]=1; 
    } 
    int mid=(l+r)>>1; 
    if(zuo<=mid)  getsum(l,mid,k+k,zuo,you); 
    if(you>mid)   getsum(mid+1,r,k+k+1,zuo,you); 
} 
void solvechange(int x,int f,int p) 
{ 
    int a,b; 
    while(belong[x]!=belong[f]) 
    { 
        a=pl[belong[x]];b=pl[x]; 
        change(1,n,1,a,b,p); 
        x=fa[belong[x]][0]; 
    } 
    a=pl[f];b=pl[x]; 
    change(1,n,1,a,b,p); 
} 
int solvesum(int x,int f) 
{ 
    int a,b,nsum=0; 
    while(belong[x]!=belong[f]) 
    { 
        a=pl[belong[x]]; 
        b=pl[x]; 
        o=0; 
        getsum(1,n,1,a,b); 
        nsum+=sm; 
        if(getse(1,n,1,pl[belong[x]])==getse(1,n,1,pl[fa[belong[x]][0]])) 
        nsum--; 
        x=fa[belong[x]][0]; 
    } 
    a=pl[f];b=pl[x]; 
    o=0; 
    getsum(1,n,1,a,b); 
    nsum+=sm; 
    return nsum; 
} 
void solve() 
{ 
    int i,c,a,b,k,d; 
    char ch[1]; 
    for(i=1;i<=n;i++) 
    change(1,n,1,pl[i],pl[i],quan[i]); 
      
    for(i=1;i<=q;i++) 
    { 
        scanf("%s%d%d",ch,&a,&b); 
        if(ch[0]=='C') 
        { 
            scanf("%d",&d); 
            c=LCA(a,b); 
            solvechange(a,c,d); 
            solvechange(b,c,d); 
        } 
        else
        { 
            c=LCA(a,b); 
            k=solvesum(a,c)+solvesum(b,c)-1; 
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
    memset(mark,0,sizeof(mark)); 
    dfs2(1,1);   
    solve(); 
    //system("pause"); 
    return 0; 
}