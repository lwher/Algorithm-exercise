#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,belong[100010],ans[100010],t[100010];
int sz,to[200010],pre[200010],last[100010];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
int lowbit(int x)
{
    return x & (-x);
}
void updata(int x,int num)
{
    for(int i=x;i<=n;i+=lowbit(i))  t[i]+=num;
}
int ask(int x)
{
    int sum=0,i;
    for(i=x;i>0;i-=lowbit(i))  sum+=t[i];
    return sum;
}
void dfs(int x,int fa)
{
    updata(belong[x],1);
    ans[belong[x]]=ask(belong[x]-1);
    for(int i=last[x];i;i=pre[i])
    {
        if(to[i]==fa)  continue;
        dfs(to[i],x);
    }
    updata(belong[x],-1);
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
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        belong[a]=i;
    }
    dfs(1,0);
    for(i=1;i<=n;i++)  printf("%d\n",ans[i]);
    return 0;
}