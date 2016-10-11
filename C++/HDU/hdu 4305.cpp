#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define mod 10007
using namespace std;
struct point 
{
    int x,y;
}p[310];
int n,R,du[310],Inv[10010];
int A[310][310];
bool vis[310];
int sqr(int x) {return x*x;}
inline void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
inline  int dist(point a,point b)
{
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}
point jian(point a,point b)
{
    point c;
    c.x=a.x-b.x;c.y=a.y-b.y;
    return c;
}
inline int chaji(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
inline int dianji(point a,point b)
{
    return a.x*b.x+a.y*b.y;
}
inline bool online(point a,point b,point c)
{
    if(chaji(jian(c,a),jian(b,a))==0 && dianji(jian(a,b),jian(c,b))<=0) return 1;
    return 0;
}
inline bool OK(point a,point b,int i,int j)
{
    for(int k=1;k<=n;k++) if(k!=i && k!=j && online(a,p[k],b)) return 0;
    return 1;
}
void dfs(int x)
{
    if(vis[x]) return;
    vis[x]=1;
    for(int i=1;i<=n;i++) if(i!=x && A[x][i]!=0) dfs(i); 
}
int calc(int N)
{
    int i,j,k,res=1,p;
    bool flag=0;
    for(i=1;i<=N;i++)
    {
        if(!A[i][i])
        {
           for(j=i+1;j<=N;j++) if(A[j][i])
           {
              flag^=1;
              for(k=1;k<=N;k++) swap(A[i][k],A[j][k]);
              break;
           }
        }
        res=(res*A[i][i])%mod;
        for(j=i+1;j<=N;j++)
        if(A[j][i])
        {
            p=(A[j][i]*Inv[A[i][i]])%mod;
            for(k=1;k<=N;k++) A[j][k]=((A[j][k]-(A[i][k]*p)%mod)%mod+mod)%mod;
        }
    }
    if(flag) res=mod-res;
    return res;
}
void solve()
{
    int i,j;
    for(i=1;i<=n;i++) if(!vis[i]) {printf("-1\n");return;}
    for(i=1;i<=n;i++)
    {
        du[i]=0;
        for(j=1;j<=n;j++) du[i]-=A[i][j];
        A[i][i]+=du[i];
    } 
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) A[i][j]=(A[i][j]%mod+mod)%mod;
    printf("%d\n",calc(n-1));
}
int main()
{
    int i,j,k,T;
    Inv[1]=1;
    for(i=2;i<mod;i++) Inv[i]=(Inv[mod%i]*(mod-mod/i))%mod;
    scanf("%d",&T);
    while(T--)
    {
        memset(A,0,sizeof(A));
        scanf("%d%d",&n,&R);
        R*=R;
        for(i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
        for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) if(dist(p[i],p[j])<=R && OK(p[i],p[j],i,j))
        {
            A[i][j]--;A[j][i]--;
        }
        memset(vis,0,sizeof(vis));
        dfs(1);
        solve();
    }
    return 0;
}