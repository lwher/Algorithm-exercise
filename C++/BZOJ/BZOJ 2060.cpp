#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,f[50010][2];
int sz,to[100010],pre[100010],last[50010];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dp(int x,int fa)
{
    int i;
    f[x][0]=0;f[x][1]=1;
    for(i=last[x];i>0;i=pre[i])
    {
        if(to[i]==fa)  continue;
        dp(to[i],x);
        f[x][0]+=max(f[to[i]][0],f[to[i]][1]);
        f[x][1]+=f[to[i]][0];
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
    cout<<max(f[1][0],f[1][1])<<endl;
    return 0;
}