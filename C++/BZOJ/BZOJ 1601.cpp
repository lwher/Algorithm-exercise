#include<iostream> 
#include<cstdlib> 
#include<cstdio> 
#include<algorithm> 
using namespace std; 
struct sth 
{ 
    int from,to,v; 
}lu[130010]; 
int fa[310]; 
int n; 
int sz; 
int getfa(int x) 
{ 
    if(fa[x]==0)  return x; 
    else
    return fa[x]=getfa(fa[x]); 
} 
void Ins(int a,int b,int c) 
{ 
    sz++; 
    lu[sz].from=a; 
    lu[sz].to=b; 
    lu[sz].v=c; 
} 
inline bool comp(sth a,sth b) 
{ 
    return a.v<b.v; 
} 
int main() 
{ 
    int i,j,w; 
    long long ans=0; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) 
    {scanf("%d",&w);Ins(i,n+1,w);} 
    for(i=1;i<=n;i++) 
    for(j=1;j<=n;j++) 
    {scanf("%d",&w);Ins(i,j,w);} 
    int now=0; 
    int x;int y; 
    sort(lu+1,lu+1+sz,comp); 
    i=1; 
    while(now<n) 
    { 
        x=getfa(lu[i].from); 
        y=getfa(lu[i].to); 
        if(x!=y) 
        { 
            fa[x]=y; 
            ans+=lu[i].v; 
            now++; 
        } 
        i++; 
    } 
    cout<<ans<<endl; 
//  system("pause"); 
    return 0; 
}