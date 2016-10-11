#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<algorithm> 
#include<cstring> 
using namespace std; 
struct sth 
{ 
    int from,to,v; 
}lu[30010]; 
int fa[2010],n,m; 
inline bool comp(sth a,sth b) 
{ 
    return a.v<b.v; 
} 
int getfa(int x) 
{ 
    if(fa[x]==0)  return x; 
    else return fa[x]=getfa(fa[x]); 
} 
int main() 
{ 
    int i,j=0,x,y,ans; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=m;i++) 
    scanf("%d%d%d",&lu[i].from,&lu[i].to,&lu[i].v); 
    sort(lu+1,lu+1+m,comp); 
    i=1; 
    while(j<n-1) 
    { 
        x=getfa(lu[i].from); 
        y=getfa(lu[i].to); 
        if(x!=y) 
        { 
            j++;ans=lu[i].v; 
            fa[x]=y; 
        } 
        i++; 
    } 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}