#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
using namespace std; 
int n,m,k,p,q; 
int dp[2][210][210]; 
int queue[210],w[210]; 
char map[210][210]; 
int dx[4]={-1,1,0,0}; 
int dy[4]={0,0,-1,1}; 
void solve(int x,int y,int e,int len,int c) 
{ 
    int i,l=0,r=-1,tmp; 
    for(i=1;i<=e;i++) 
    { 
    if(map[x][y]=='.') 
    { 
        tmp=dp[p][x][y]+e-i; 
        while(l<=r && tmp>queue[r])  r--; 
        queue[++r]=tmp;w[r]=i; 
        while(i-w[l]>len)  l++; 
        dp[q][x][y]=queue[l]+i-e; 
    } 
    else 
    {dp[q][x][y]=-1e8;l=r+1;} 
    x+=dx[c];y+=dy[c]; 
    } 
} 
int main() 
{ 
    int i,j,x,y,l,r,c; 
    scanf("%d%d%d%d%d",&n,&m,&x,&y,&k); 
    for(i=1;i<=n;i++)  scanf("%s",map[i]+1); 
    p=0;q=1; 
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  dp[p][i][j]=-1e8; 
    dp[p][x][y]=0; 
    while(k--) 
    { 
        scanf("%d%d%d",&l,&r,&c); 
        if(c==1) { 
            for(i=1;i<=m;i++)   solve(n,i,n,r-l+1,c-1); 
        } 
        if(c==2) { 
            for(i=1;i<=m;i++)   solve(1,i,n,r-l+1,c-1); 
        } 
        if(c==3) { 
            for(i=1;i<=n;i++)   solve(i,m,m,r-l+1,c-1); 
        } 
        if(c==4) { 
            for(i=1;i<=n;i++)   solve(i,1,m,r-l+1,c-1); 
        } 
        p^=1;q^=1; 
    } 
    int ans=0; 
    for(i=1;i<=n;i++) for(j=1;j<=m;j++)  ans=max(ans,dp[p][i][j]); 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}