#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#define INF 0x7fffffff 
using namespace std; 
int n,m,K,q; 
int to[400010],pre[400010],v[400010],last[20010]; 
int sz,map[30][30],zui[30]; 
int tj[30]; 
bool mark[20010]; 
int d[20010]; 
int dp[1100000][25]; 
bool used[1100000][25]; 
int dui[1000010]; 
void Ins(int a,int b,int c) 
{ 
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz; 
    sz++;to[sz]=a;v[sz]=c;pre[sz]=last[b];last[b]=sz; 
} 
void init() 
{ 
    int i,j,a,b,c; 
    scanf("%d%d%d",&n,&m,&K); 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d%d",&a,&b,&c); 
        Ins(a,b,c); 
    } 
    scanf("%d",&q); 
    for(i=1;i<=q;i++) 
    { 
       scanf("%d%d",&a,&b); 
       tj[b]+=(1<<(a-2)); 
    } 
} 
void spfa(int x) 
{ 
    int i,tou=1,wei=1; 
    int now; 
    memset(d,127,sizeof(d)); 
    memset(mark,0,sizeof(mark)); 
    mark[x]=1; 
    dui[1]=x; 
    d[x]=0; 
    while(tou<=wei) 
    { 
        now=dui[tou]; 
        i=last[now]; 
        while(i>0) 
        { 
            if(d[now]+v[i]<d[to[i]]) 
            { 
                d[to[i]]=d[now]+v[i]; 
                if(!mark[to[i]]) 
                { 
                    wei++;dui[wei]=to[i];mark[to[i]]=1; 
                } 
            } 
            i=pre[i]; 
        } 
        tou++; 
        mark[now]=0; 
    } 
} 
void build() 
{ 
    int i,j; 
    for(i=2;i<=K+1;i++) 
    { 
        spfa(i); 
        zui[i]=d[n]; 
        for(j=2;j<=K+1;j++) 
        { 
            map[i][j]=d[j]; 
        } 
    } 
} 
void dping() 
{ 
    int i,j,k,l; 
    spfa(1); 
    for(j=2;j<=K+1;j++) 
    { 
        if(tj[j]==0) 
        { 
            k=1<<(j-2);    
            if(!used[k][j]) 
            {dp[k][j]=d[j];used[k][j]=1;} 
            else
            if(d[j]<dp[k][j]) 
            {dp[k][j]=d[j];} 
        } 
    } 
      
    for(i=1;i<(1<<K);i++) 
    for(l=2;l<=K+1;l++) 
    if(used[i][l]) 
    { 
    for(j=2;j<=K+1;j++) 
    { 
        k=1<<(j-2); 
        if((i & tj[j])==tj[j]) 
        {    
            if((k & i)==0) 
            { 
            if(!used[i+k][j]) 
            {dp[i+k][j]=dp[i][l]+map[l][j];used[i+k][j]=1;} 
            else
            if(dp[i][l]+map[l][j]<dp[i+k][j]) 
            {dp[i+k][j]=dp[i][l]+map[l][j];} 
            }    
        } 
    } 
    } 
} 
int main() 
{ 
    int i,j; 
    init(); 
    build(); 
    dping(); 
    int ans=INF; 
    for(i=2;i<=K+1;i++) 
    { 
        if(used[(1<<K)-1][i]) 
        if(dp[(1<<K)-1][i]+zui[i]<ans) 
        ans=dp[(1<<K)-1][i]+zui[i]; 
    } 
    if(K==0) 
    ans=d[n]; 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}