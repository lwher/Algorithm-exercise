#include<iostream>
#include<cstdio> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
typedef __int64 lld; 
const int MAX=1100; 
const lld MOD=1000007; 
const int INF=1000000001; 
const double PI=acos(-1.0); 
const double EPS=1.0e-8; 
struct EDGE 
{ 
    int v,f,c,next; 
}edge[11000]; 
int head[MAX],E; 
void add(int s,int t,int f,int c) 
{ 
    edge[E].v=t; 
    edge[E].f=f; 
    edge[E].c=c; 
    edge[E].next=head[s]; 
    head[s]=E++; 
} 
int dp[MAX][MAX]; 
int main() 
{ 
    int n=1,m; 
    int i,j,k,L; 
    int T,r; 
    while(scanf("%d%d%d",&L,&n,&m)!=EOF) 
    { 
        memset(head,-1,sizeof(head)); 
        E=0; 
        for(i=0;i<n;i++) 
        { 
            int s,t,f,c; 
            scanf("%d%d%d%d",&s,&t,&f,&c); 
            if(s+t<=L)add(s,s+t,f,c); 
        } 
        for(i=0;i<=L;i++)for(j=0;j<=m;j++)dp[i][j]=-1; 
        for(i=0;i<=m;i++)dp[0][i]=0; 
        for(i=0;i<=L;i++) 
        { 
            int h; 
            for(j=0;j<=m;j++) 
            { 
                if(dp[i][j]==-1)continue; 
                for(h=head[i];h!=-1;h=edge[h].next) 
                { 
                    int v=edge[h].v; 
                       
                    if(j+edge[h].c<=m&&dp[i][j]+edge[h].f>dp[v][j+edge[h].c]) 
                    { 
                        dp[v][j+edge[h].c]=dp[i][j]+edge[h].f; 
                    } 
                } 
            } 
        } 
        int ans=-1; 
        for(i=0;i<=m;i++) 
        { 
            if(dp[L][i]>ans)ans=dp[L][i]; 
        } 
        printf("%d\n",ans); 
    } 
    system("pause");
    return 0; 
} 
