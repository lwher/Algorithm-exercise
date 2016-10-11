#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define M 100000
using namespace std;
int n,root,ans,sum,v[100010],size[100010],f[100010],B[100010];
int sz,to[200010],pre[200010],last[100010];
int top,allnum,num[100010],dist[100010],w[100010],cnt[200010];
bool mark[100010];
inline int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9')) ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9') x=x*10+(ch-'0'),ch=getchar();
    return x;
}
inline void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void getroot(int x,int fa)
{
     size[x]=1;f[x]=0;
     for(int i=last[x];i;i=pre[i])
     {
         if(mark[to[i]] || to[i]==fa) continue;
         getroot(to[i],x);
         size[x]+=size[to[i]];
         if(size[to[i]]>f[x]) f[x]=size[to[i]];
     }
     if(sum-size[x]>f[x]) f[x]=sum-size[x];
     if(f[root]>f[x]) root=x;
}
void dfs(int x,int fa,int d)
{
     size[x]=1;
     dist[++top]=d;w[top]=x;
     for(int i=last[x];i;i=pre[i])
     {
         if(mark[to[i]] || to[i]==fa) continue;
         dfs(to[i],x,d+v[to[i]]);
         size[x]+=size[to[i]];
     }
}
void calc(int x,int D,int dt)
{
     top=0;
     dfs(x,0,0);
     for(int i=1;i<=top;i++) cnt[dist[i]+D+M]+=dt;
     for(int i=1;i<=top;i++)
     {
         num[w[i]]+=cnt[M-dist[i]];
         allnum-=cnt[M-dist[i]];
     }
     for(int i=1;i<=top;i++) cnt[dist[i]+D+M]-=dt;
}
void work(int x)
{
     calc(x,v[x],1);
     mark[x]=1;
     for(int i=last[x];i;i=pre[i])
     {
         if(mark[to[i]]) continue;
         calc(to[i],v[x]+2*v[to[i]],-1);
         sum=size[to[i]];f[0]=sum;root=0;
         getroot(to[i],x);
         work(root);
     }
}
int main()
{
    int i,j=0,a,b;
    n=read();//scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        v[i]=read();//scanf("%d",&v[i]);
        if(!v[i]) v[i]--;
    }
    for(i=1;i<n;i++)
    {
        a=read();b=read();//scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
    sum=n;root=0;f[0]=sum;
    getroot(1,0);
    work(root);
    allnum/=2;
    for(i=1;i<=n;i++) B[i]=read();//scanf("%d",&B[i]);
    for(i=1;i<=n;i++)
    {
        while(allnum<=0 && j<n) allnum+=num[B[++j]];
        if(allnum>0) ans+=n-j+1; else break;
        allnum-=num[B[i]];
    }
    printf("%d\n",ans);
    return 0;
}