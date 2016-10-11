#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,L[100010],C[100010];
int sz,to[100010],pre[100010],last[100010];
int ls[100010],rs[100010],cnt[100010],dis[100010];
long long ans,sum[100010];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
int merge(int a,int b)
{
    if(!a || !b)  return a+b;
    if(C[a]<C[b])  swap(a,b);
    rs[a]=merge(rs[a],b);
    if(dis[ls[a]]<dis[rs[a]])  swap(ls[a],rs[a]);
    dis[a]=dis[rs[a]]+1;
    sum[a]=sum[ls[a]]+sum[rs[a]]+C[a];
    cnt[a]=cnt[ls[a]]+cnt[rs[a]]+1;
    return a;
}
int work(int x)
{
    int t=x,i;
    for(i=last[x];i;i=pre[i])  t=merge(t,work(to[i]));
    while(sum[t]>m)  t=merge(ls[t],rs[t]);
    ans=max(ans,(long long)(L[x])*cnt[t]);
    return t;
}
int main()
{
    int i,a,b,c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a!=0)  Ins(a,i);
        C[i]=b;L[i]=c;cnt[i]=1;sum[i]=C[i];
    }   
    dis[0]=-1;
    work(1);
    cout<<ans<<endl;
    return 0;
}