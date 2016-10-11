#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,sum,root,dist[100010],size[100010],f[100010];
int sz,to[200010],pre[200010],v[200010],last[100010];
int cnt[200010],num1[200010],num2[200010];
int stack[200010],top;
long long ans;
bool mark[100010];
void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void getroot(int x,int fa)
{
    size[x]=1;f[x]=0;
    for(int i=last[x];i;i=pre[i])
    {
        if(to[i]==fa || mark[to[i]]) continue;
        getroot(to[i],x);
        if(size[to[i]]>f[x]) f[x]=size[to[i]];
        size[x]+=size[to[i]];
    }
    if(sum-size[x]>f[x]) f[x]=sum-size[x];
    if(f[x]<f[root]) root=x;
}
void getsize(int x,int fa)
{
    size[x]=1;
    for(int i=last[x];i;i=pre[i])
    {
        if(to[i]==fa || mark[to[i]]) continue;
        getsize(to[i],x);
        size[x]+=size[to[i]];
    }
}
void init()
{
    int i,a,b,c;
    scanf("%d",&n);
    for(i=1;i<n;i++) 
    {
        scanf("%d%d%d",&a,&b,&c);
        if(!c) c=-1;
        Ins(a,b,c);Ins(b,a,c);
    }
}
void dfsans(int x,int fa)
{
    int i,d=dist[x]+100000,d2=100000-dist[x];
    if(dist[x]==0)
    {
       ans+=num1[d];
       if(cnt[d]>0) ans++;
    }
    else
    {
       if(cnt[d]>0) ans+=num1[d2]+num2[d2];
       else ans+=num1[d2];
    }
    cnt[d]++;
    for(i=last[x];i;i=pre[i]) 
    {
        if(to[i]==fa || mark[to[i]]) continue;
        dist[to[i]]=dist[x]+v[i];
        dfsans(to[i],x);
    }
    cnt[d]--;
}
void dfshash(int x,int fa)
{
    int i,d=dist[x]+100000;
    if(dist[x]==0) num1[d]++; else
    {
        if(cnt[d]>0) num1[d]++;
        else num2[d]++;
    }
    stack[++top]=d;
    cnt[d]++;
    for(i=last[x];i;i=pre[i])
    {
        if(to[i]==fa || mark[to[i]]) continue;
        dfshash(to[i],x);
    }
    cnt[d]--;
}
void calc(int x)
{
    int i;
    dist[x]=0;top=0;
    for(i=last[x];i;i=pre[i]) 
    {
       if(mark[to[i]]) continue;
       dist[to[i]]=dist[x]+v[i];
       dfsans(to[i],x);
       dfshash(to[i],x);
    }
    while(top>0) 
    {
        num1[stack[top]]=num2[stack[top]]=0;
        top--;
    }
}
void work(int x)
{
     calc(x);
     mark[x]=1;
     for(int i=last[x];i;i=pre[i])
     {
         if(mark[to[i]]) continue;
         getsize(to[i],x);
         sum=size[to[i]];f[0]=sum;root=0;
         getroot(to[i],x);
         work(root);
     }
}
void solve()
{
    sum=n;root=0;f[0]=sum;
    getroot(1,0);
    work(root);
    cout<<ans<<endl;
}
int main()
{
    init();
    solve();
    //system("pause");
    return 0;
} 
