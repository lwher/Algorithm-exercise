#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
using namespace std; 
int sz,to[500010],pre[500010],last[250010]; 
int n,m,tt,top; 
int d[250010],ft[250010],sd[250010],fa[250010],zhan[250010],sc[250010]; 
bool mark[250010]; 
int t[1000000],xg[1000000]; 
void Ins(int a,int b) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz; 
    sz++;to[sz]=a;pre[sz]=last[b];last[b]=sz; 
} 
void dfs() 
{ 
    int i,x,g; 
    for(i=1;i<=n;i++)  sc[i]=last[i]; 
    top++;zhan[top]=1;   
    while(top>0) 
    { 
        x=zhan[top]; 
        if(!mark[x]){tt++;ft[x]=tt;} 
        mark[x]=1;g=sc[x]; 
        if(g>0)   
        { 
        g=to[g]; 
        if(g!=fa[x]) 
        { 
            top++;zhan[top]=g; 
            fa[g]=x;d[g]=d[x]+1; 
        } 
        sc[x]=pre[sc[x]]; 
        } 
        else{top--;sd[x]=tt;} 
    } 
} 
void downgo(int l,int r,int k) 
{ 
    xg[k+k]+=xg[k];xg[k+k+1]+=xg[k]; 
    int mid=(l+r)>>1; 
    t[k+k]+=xg[k]*(mid-l+1); 
    t[k+k+1]+=xg[k]*(r-mid); 
    xg[k]=0; 
} 
void add(int l,int r,int k,int zuo,int you,int x) 
{ 
    if(l==r)  {t[k]+=x;return;} 
    if(l>=zuo && r<=you)  {t[k]+=x*(r-l+1);xg[k]+=x;return;} 
    if(xg[k]!=0)  downgo(l,r,k); 
    int mid=(l+r)>>1; 
    if(zuo<=mid)  add(l,mid,k+k,zuo,you,x); 
    if(you>mid)   add(mid+1,r,k+k+1,zuo,you,x); 
    t[k]=t[k+k]+t[k+k+1]; 
} 
int ask(int l,int r,int k,int x) 
{ 
    if(l==r)  return t[k]; 
    int mid=(l+r)>>1; 
    if(xg[k]!=0)  downgo(l,r,k); 
    if(x<=mid)  return ask(l,mid,k+k,x); 
    else        return ask(mid+1,r,k+k+1,x); 
} 
void init() 
{ 
    int i,a,b,x; 
    scanf("%d",&n); 
    for(i=1;i<n;i++)  {scanf("%d%d",&a,&b);Ins(a,b);} 
    fa[1]=-1; 
    dfs(); 
    for(i=1;i<=n;i++)  add(1,n,1,ft[i],ft[i],d[i]); 
    char ch; 
    scanf("%d",&m); 
    for(i=1;i<=n+m-1;i++) 
    { 
        ch=getchar(); 
        while (ch!='A' && ch!='W') ch=getchar(); 
        if(ch=='W')   
        { 
            scanf("%d",&x); 
            printf("%d\n",ask(1,n,1,ft[x])); 
        } 
        else
        { 
            scanf("%d%d",&a,&b); 
            if(fa[a]==b)  x=a; 
            else  x=b; 
            add(1,n,1,ft[x],sd[x],-1); 
        } 
    } 
} 
int main() 
{ 
    init(); 
    //system("pause"); 
    return 0; 
}