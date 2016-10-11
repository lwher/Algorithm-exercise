#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<algorithm> 
using namespace std; 
struct sth 
{ 
    int from,to,v; 
}lu[100010]; 
int zhi[10010],fa[10010],n,m,minn=1e20,ans; 
int getfa(int x) 
{ 
    if(fa[x]==0)  return x; 
    else return fa[x]=getfa(fa[x]); 
} 
inline bool comp(sth a,sth b) 
{ 
    return a.v<b.v; 
} 
int main() 
{ 
    //freopen("cheer.in","r",stdin); 
    //freopen("cheer.out","w",stdout); 
    int i,a,b,c; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++)   
    { 
        scanf("%d",&zhi[i]); 
        if(minn>zhi[i])  minn=zhi[i]; 
    } 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d%d",&a,&b,&c); 
        c=c*2+zhi[a]+zhi[b]; 
        lu[i].from=a;lu[i].to=b;lu[i].v=c; 
    } 
    sort(lu+1,lu+1+m,comp); 
    int sum=0,x,y;i=1; 
    while(sum<n-1) 
    { 
        x=getfa(lu[i].from);y=getfa(lu[i].to); 
        if(x!=y) 
        { 
            sum++;fa[x]=y;ans+=lu[i].v; 
        } 
        i++; 
    } 
    ans+=minn; 
    cout<<ans<<endl; 
//  system("pause"); 
    return 0; 
}