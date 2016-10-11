#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
#define INF 0x7fffffff 
using namespace std; 
int n,m,s,t; 
long long ans; 
int wk[110][110],lk[110][110],map[110][110],tw[110][110][4],tl[110][110][4]; 
int sz=1,to[500010],pre[500010],v[500010],last[10010]; 
int h[10010],gap[10010],dui[10010]; 
int dx[4]={0,0,1,-1}; 
int dy[4]={1,-1,0,0}; 
void Ins(int a,int b,int c) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz; 
    sz++;to[sz]=a;pre[sz]=last[b];v[sz]=0;last[b]=sz; 
} 
int get(int x,int y) 
{ 
    return (x-1)*m+y; 
} 
void bfs() 
{ 
    memset(h,-1,sizeof(h)); 
    int tou=1,wei=1,now,i; 
    dui[1]=t;h[t]=1;gap[1]=1; 
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
    if(x==t)  return F; 
    int w,i,used=0; 
    i=last[x]; 
    while(i>0) 
    { 
        if(v[i]>0 && h[x]-1==h[to[i]]) 
        { 
            w=min(F-used,v[i]); 
            w=dfs(to[i],w); 
            v[i]-=w; 
            v[i^1]+=w; 
            used+=w; 
            if(F==used)   return F; 
        } 
        i=pre[i]; 
    } 
    gap[h[x]]--; 
    if(gap[h[x]]==0)  h[s]=n*m+3; 
    gap[++h[x]]++; 
    return used; 
} 
void init() 
{ 
    int i,j,k,nx,ny; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++) {scanf("%d",&wk[i][j]);ans+=wk[i][j]<<1;} 
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++) {scanf("%d",&lk[i][j]);ans+=lk[i][j]<<1;} 
    for(i=1;i<n;i++)  for(j=1;j<=m;j++) 
    { 
        scanf("%d",&map[i][j]); 
        ans+=map[i][j]<<1; 
        if(i<n)  {tw[i][j][2]=map[i][j];tw[i+1][j][3]=map[i][j];}   
    } 
    for(i=1;i<n;i++)  for(j=1;j<=m;j++) 
    { 
        scanf("%d",&map[i][j]); 
        ans+=map[i][j]<<1; 
        if(i<n)  {tl[i][j][2]=map[i][j];tl[i+1][j][3]=map[i][j];}   
    } 
    for(i=1;i<=n;i++)  for(j=1;j<m;j++) 
    { 
        scanf("%d",&map[i][j]); 
        ans+=map[i][j]<<1; 
        if(j<m)  {tw[i][j][0]=map[i][j];tw[i][j+1][1]=map[i][j];}   
    } 
    for(i=1;i<=n;i++)  for(j=1;j<m;j++) 
    { 
        scanf("%d",&map[i][j]); 
        ans+=map[i][j]<<1; 
        if(j<m)  {tl[i][j][0]=map[i][j];tl[i][j+1][1]=map[i][j];}   
    } 
    s=n*m+1;t=s+1; 
    for(i=1;i<=n;i++) for(j=1;j<=m;j++)  for(k=0;k<4;k++) 
    { 
        nx=i+dx[k];ny=j+dy[k]; 
        if(nx<1 || nx>n || ny<1 || ny>m)  continue; 
        Ins(s,get(i,j),tw[i][j][k]);Ins(get(i,j),t,tl[i][j][k]); 
        Ins(get(i,j),get(nx,ny),tw[i][j][k]+tl[i][j][k]); 
    } 
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  
    { 
        Ins(s,get(i,j),wk[i][j]<<1);Ins(get(i,j),t,lk[i][j]<<1); 
    } 
} 
void SAP() 
{ 
    long long now=0; 
    bfs(); 
    while(h[s]<n*m+3)  now+=dfs(s,INF); 
    cout<<((ans-now)>>1)<<endl; 
} 
int main() 
{ 
    init(); 
    SAP(); 
    //system("pause"); 
    return 0; 
}