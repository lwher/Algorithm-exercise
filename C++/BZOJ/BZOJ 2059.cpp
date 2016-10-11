#include<stdio.h> 
#include<string.h> 
#include<algorithm> 
#define MAXN 510 
#define MAXK 10010 
#define INF 0x3f3f3f3f3f3f3f3fll 
typedef long long LL; 
struct Shop 
{ 
    int x,c,f; 
    bool operator < (const Shop &t) const
    { 
        return x<t.x; 
    } 
}shop[MAXN]; 
int N,E,K,q[MAXN]; 
LL f[MAXN][MAXK]; 
void init() 
{ 
    for(int i=0;i<N;i++) scanf("%d%d%d",&shop[i].x,&shop[i].f,&shop[i].c); 
    std::sort(shop,shop+N); 
} 
void solve() 
{ 
    for(int i=0;i<=N;i++) for(int j=0;j<=K;j++) f[i][j]=INF; 
    f[0][0]=0;shop[N].x=E; 
    for(int i=1;i<=N;i++) 
    { 
        int front=0,rear=0; 
        for(int j=0;j<=K;j++) 
        { 
            while(front<rear && j-q[front]>shop[i-1].f) ++front; 
            if(f[i-1][j]!=INF) 
            { 
                while(front<rear) 
                { 
                    int k=q[rear-1];
                    if(f[i-1][k]-(LL)k*shop[i-1].c<f[i-1][j]-(LL)j*shop[i-1].c) break; 
                    --rear; 
                } 
                q[rear++] = j; 
            } 
            if(front<rear) 
            { 
                int k=q[front];f[i][j]=f[i-1][k]+(LL)(j-k)*shop[i-1].c+(LL)j*j*(shop[i].x-shop[i-1].x); 
            } 
        } 
    } 
    printf("%lld\n",f[N][K]); 
} 
int main() 
{ 
    scanf("%d%d%d",&K,&E,&N); 
    init(); 
    solve();
    //system("pause");
    return 0; 
}