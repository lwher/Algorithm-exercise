#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
#define INF 0x7fffffff 
using namespace std; 
int n,m,s,t; 
int kind[310],h[310],gap[310],dui[310]; 
int sz=1,to[300010],pre[300010],v[300010],last[310]; 
void Ins(int a,int b,int c) 
{ 
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz; 
    sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz; 
} 
void bfs() 
{ 
    memset(h,-1,sizeof(h)); 
    int i,now,tou=1,wei=1; 
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
    if(x==t) return F; 
    int i,w,used=0; 
    i=last[x]; 
    while(i>0) 
    { 
        if(v[i] && h[x]-1==h[to[i]]) 
        { 
            w=F-used; 
            w=dfs(to[i],min(v[i],w)); 
            v[i]-=w; 
            v[i^1]+=w; 
            used+=w; 
            if(used==F) return F;  
        } 
        i=pre[i]; 
    } 
    gap[h[x]]--; 
    if(!gap[h[x]])   h[s]=t+1; 
    gap[++h[x]]++; 
    return used; 
} 
int SAP() 
{ 
    int ans=0; 
    bfs(); 
    while(h[s]<t+1)  ans+=dfs(s,INF); 
    return ans; 
} 
int main() 
{ 
    int i,a,b; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++)  scanf("%d",&kind[i]); 
    s=n+1;t=s+1; 
    for(i=1;i<=n;i++)  if(kind[i]==0)  Ins(s,i,1);  else Ins(i,t,1); 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d",&a,&b); 
        Ins(a,b,1);Ins(b,a,1); 
    } 
    printf("%d\n",SAP()); 
    //system("pause"); 
    return 0; 
}