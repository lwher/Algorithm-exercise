#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[100010][513],maxh[100010];
long long ans[513];
int n,fa[100010];
int sz,to[100010],pre[100010],last[100010];
inline void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dfs(int x)
{
     int i,j,k;
     maxh[x]=0;
     num[x][0]++;
     for(i=last[x];i;i=pre[i])
     {
         dfs(to[i]);
         for(j=0;j<=maxh[to[i]];j++) for(k=0;k<=maxh[x];k++) ans[(j+1)^k]+=(long long)num[to[i]][j]*num[x][k];
         maxh[x]=max(maxh[x],maxh[to[i]]+1);
         for(j=1;j<=maxh[x];j++) num[x][j]+=num[to[i]][j-1];
     }
}
int main()
{
    int i,p;
    scanf("%d",&n);
    for(i=2;i<=n;i++) 
    {
        scanf("%d",&fa[i]);
        Ins(fa[i],i);
    }    
    dfs(1);
    for(p=512;p>=0;p--) if(ans[p]>0) break;
    for(i=0;i<=p;i++) printf("%lld\n",ans[i]);
    //system("pause");
    return 0;
}
