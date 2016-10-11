#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,mod,fa[100010];
long long f[100010][18][3];
int sz,to[200010],pre[200010],last[100010];
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void init()
{
     int i,a,b;
     scanf("%d%d%d",&n,&m,&mod);
     for(i=1;i<=m;i++) 
     {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
     } 
}
long long calc(long long x)
{
     if(x>0 && x%mod==0) return mod;
     return x%mod;
}
void DP(int x)
{
     int i,j;
     long long f1,f2;
     for(i=0;i<=17;i++) f[x][i][0]=1;
     for(j=last[x];j;j=pre[j])
     {
         if(to[j]==fa[x]) continue;
         fa[to[j]]=x;
         DP(to[j]);
         for(i=0;i<=17;i++)
         {
            f1=f[to[j]][i][0]+f[to[j]][i][1];
            if(i>0) f2=f[to[j]][i-1][0]+f[to[j]][i-1][1]+f[to[j]][i-1][2];
            else f2=0;
            f[x][i][2]=calc(f[x][i][2]*f2+f[x][i][1]*f1);
            f[x][i][1]=calc(f[x][i][0]*f1+f[x][i][1]*f2);
            f[x][i][0]=calc(f[x][i][0]*f2);
         }
     }
}
void solve()
{
     int i;
     if(m!=n-1)
     {
         printf("-1\n-1\n");
         return;
     }
     DP(1);
     for(i=0;i<=17;i++) if(f[1][i][0]+f[1][i][1]+f[1][i][2]>0) 
     {
         printf("%d\n",i);
         printf("%d\n",(f[1][i][0]+f[1][i][1]+f[1][i][2])%mod);
         return;
     }
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
