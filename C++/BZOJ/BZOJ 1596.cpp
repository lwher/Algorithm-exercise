#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define inf 1000000
using namespace std;
int n,f[10010][3];
int sz,to[20010],pre[20010],last[10010];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dp(int x,int fa)
{
    int i,tmp=0;
    f[x][0]=0;f[x][1]=1;f[x][2]=inf;
    for(i=last[x];i;i=pre[i])
    {
        if(to[i]==fa)  continue;
        dp(to[i],x);
        f[x][0]+=min(f[to[i]][1],f[to[i]][2]);
        f[x][1]+=min(f[to[i]][1],min(f[to[i]][2],f[to[i]][0]));
        tmp+=min(f[to[i]][1],f[to[i]][2]);
    }
    for(i=last[x];i;i=pre[i])
    {
        if(to[i]==fa)  continue;
        f[x][2]=min(f[x][2],tmp-min(f[to[i]][1],f[to[i]][2])+f[to[i]][1]);
    }
}
int main()
{
    int i,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++)  
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
    dp(1,0);
    cout<<min(f[1][2],f[1][1])<<endl;
    return 0;
}