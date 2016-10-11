#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#define N 50010 
#define M 20000010 
using namespace std; 
int n,m,ans,tt; 
int deep[N],dfn[N],low[N],lu[N],f[N],fa[N]; 
int sz,to[M],pre[M],last[N]; 
int a[N<<1],q[N<<1]; 
void Ins(int a,int b) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz; 
} 
void DP(int root,int p) 
{ 
    int tot=deep[p]-deep[root]+1,i,l=1,r=1; 
    i=p; 
    while(i!=root)  {a[tot--]=f[i];i=fa[i];} 
    a[tot]=f[root]; 
    tot=deep[p]-deep[root]+1; 
    for(i=tot+1;i<=tot+tot;i++)  a[i]=a[i-tot]; 
    q[1]=1; 
    for(i=2;i<=tot+tot;i++) 
    { 
        while(l<=r && i-q[l]>tot/2)  l++; 
        ans=max(ans,a[i]+a[q[l]]+i-q[l]); 
        while(l<=r && a[q[r]]-q[r]<=a[i]-i)  r--; 
        q[++r]=i; 
    } 
    for(i=2;i<=tot;i++) 
    f[root]=max(f[root],a[i]+min(i-1,tot-i+1)); 
} 
void Tarjan(int x) 
{ 
    dfn[x]=++tt;low[x]=tt; 
    int i=last[x]; 
    while(i>0) 
    { 
        if(to[i]!=fa[x]) 
        { 
            if(dfn[to[i]]==0)  {fa[to[i]]=x;deep[to[i]]=deep[x]+1;Tarjan(to[i]);low[x]=min(low[x],low[to[i]]);} 
            else low[x]=min(low[x],dfn[to[i]]); 
            if(dfn[x]<low[to[i]])  {ans=max(ans,f[x]+f[to[i]]+1);f[x]=max(f[x],f[to[i]]+1);} 
        } 
        i=pre[i]; 
    } 
    i=last[x]; 
    while(i>0) 
    { 
        if(fa[to[i]]!=x && dfn[x]<dfn[to[i]])  DP(x,to[i]); 
        i=pre[i]; 
    } 
} 
int main() 
{ 
    int i,j,k; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d",&k); 
        for(j=1;j<=k;j++)  scanf("%d",&lu[j]); 
        for(j=1;j<k;j++)  Ins(lu[j],lu[j+1]),Ins(lu[j+1],lu[j]); 
    } 
    Tarjan(1); 
    printf("%d\n",ans); 
    //system("pause"); 
    return 0; 
}