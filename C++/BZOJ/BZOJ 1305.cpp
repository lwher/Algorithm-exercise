#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
using namespace std; 
int to[10010],pre[10010],v[10010],last[210]; 
int n,k,sz=1; 
int s,t; 
int boy[51],girl[51]; 
int h[210],gap[210]; 
void Ins(int a,int b,int c) 
{ 
    sz++; 
    to[sz]=b; 
    pre[sz]=last[a]; 
    v[sz]=c; 
    last[a]=sz; 
    sz++; 
    to[sz]=a; 
    pre[sz]=last[b]; 
    v[sz]=0; 
    last[b]=sz; 
} 
void init() 
{ 
    int i,j; 
    char ch; 
    scanf("%d%d",&n,&k); 
    for(i=1;i<=n;i++) 
    { 
        for(j=1;j<=n;j++) 
        { 
           cin>>ch; 
           if(ch=='Y') 
           {boy[i]++;girl[j]++;} 
        } 
    } 
      
    s=0;t=2*n+1; 
    for(i=1;i<=n;i++)  Ins(s,i,boy[i]+k); 
    for(i=n+1;i<=n+n;i++)  Ins(i,t,girl[i-n]+k); 
    for(i=1;i<=n;i++) 
    for(j=n+1;j<=n+n;j++) 
    Ins(i,j,1); 
} 
int dfs(int x,int F) 
{ 
    if(x==t)  return F; 
    int i=last[x]; 
    int used=0,w; 
    while(i>0) 
    { 
        if(v[i]>0 && h[x]-1==h[to[i]]) 
        { 
        w=F-used; 
        w=dfs(to[i],min(w,v[i])); 
        used+=w; 
        v[i]-=w; 
        v[i^1]+=w; 
        if(used==F) 
        return F; 
        } 
        i=pre[i]; 
    } 
    if(h[x]<2*n+2) 
    h[x]++; 
    return used;     
} 
void SAP() 
{ 
    while(h[s]<2*n+2) 
    dfs(s,2147483647); 
} 
int main() 
{ 
    int i; 
    init(); 
    SAP(); 
    int ans=n; 
    for(i=3;i<=4*n+2;i+=2) 
    ans=min(ans,v[i]); 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}