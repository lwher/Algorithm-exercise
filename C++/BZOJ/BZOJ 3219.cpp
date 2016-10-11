#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 1e9
using namespace std;
int n,L,R,sum,root,ans=1,size[100010],f[100010],deep[100010],d[100010];
int sz,to[200010],pre[200010],v[200010],last[100010];
int fmax[100010],dui[100010],q[100010],from[100010],Q[100010],Q2[100010];
int shu[100010],tt,shuzi[100010],tot;
bool mark[100010],flag;
void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
inline int max(int a,int b)
{
    if(a>b) return a; return b;
}
void getroot(int x,int fa)
{
    size[x]=1;f[x]=0;
    for(int i=last[x];i;i=pre[i])
    {
        if(mark[to[i]] || to[i]==fa)  continue;
        getroot(to[i],x);
        f[x]=max(f[x],size[to[i]]);
        size[x]+=size[to[i]];
    }
    f[x]=max(f[x],sum-size[x]);
    if(f[x]<f[root])  root=x;
}
void getsize(int x,int fa)
{
    size[x]=1;
    for(int i=last[x];i;i=pre[i])
    {
        if(mark[to[i]] || to[i]==fa)  continue;
        getsize(to[i],x);
        size[x]+=size[to[i]];
    }
}
bool check(int x,int mid)
{
    int tou,wei,now,top=0,i,j;flag=0;
    for(j=last[x];j;j=pre[j])
    {
        if(mark[to[j]])  continue;
        tou=1;wei=0;
        dui[++wei]=to[j];
        deep[to[j]]=1;from[to[j]]=x;
        if(v[j]<mid) d[to[j]]=-1; else d[to[j]]=1;
        while(tou<=wei)
        {
            now=dui[tou];tou++;
            for(i=last[now];i;i=pre[i])
            {
                if(mark[to[i]] || from[now]==to[i])  continue;
                dui[++wei]=to[i];
                deep[to[i]]=deep[now]+1;from[to[i]]=now;
                if(v[i]<mid)  d[to[i]]=d[now]-1; else d[to[i]]=d[now]+1;
            }
        }
        int tmp=wei,l=1,r=0;
        int wei=top;
        for(i=1;i<=tmp;i++)
        {
            while(wei>=1 && deep[dui[i]]+deep[Q[wei]]>=L)  
            {
                while(l<=r && d[q[r]]<d[Q[wei]])  r--;
                q[++r]=Q[wei];
                wei--;
            } 
            while(l<=r && deep[dui[i]]+deep[q[l]]>R)  l++;
            if(l<=r && d[q[l]]+d[dui[i]]>=0)  return 1;
            if(deep[dui[i]]>=L && deep[dui[i]]<=R && d[dui[i]]>=0)  return 1;   
        }
        int top1=0;
        l=1;r=1;
        while(l<=tmp && r<=top)
        {
            top1++;
            if(deep[Q[r]]<=deep[dui[l]])  {Q2[top1]=Q[r];r++;}
            else  {Q2[top1]=dui[l];l++;}
        }
        while(l<=tmp)
        {
            Q2[++top1]=dui[l];l++;
        }
        while(r<=top)
        {
            Q2[++top1]=Q[r];r++;
        }
        top=top1;
        for(i=1;i<=top;i++)  Q[i]=Q2[i];
    }
    return 0;
}
void calc(int x)
{
    int l=ans,r=tot,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(check(x,shuzi[mid])) l=mid;
        else r=mid;
    }
    if(check(x,shuzi[r]))  ans=r; else ans=l;
}
void work(int x)
{
    calc(x);
    mark[x]=1;
    for(int i=last[x];i;i=pre[i])
    {
        if(mark[to[i]])  continue;
        getsize(to[i],x);
        if(size[to[i]]<L)  continue; 
        sum=size[to[i]];f[0]=sum;root=0;
        getroot(to[i],x);
        work(root);
    }
}
int main()
{
    int i,a,b,c;
    scanf("%d%d%d",&n,&L,&R);
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        Ins(a,b,c);Ins(b,a,c);
        shu[++tt]=c;
    }
    shu[++tt]=-1;
    sort(shu+1,shu+1+tt);
    shuzi[++tot]=shu[1];
    for(i=2;i<=tt;i++)  if(shu[i]!=shu[i-1])  shuzi[++tot]=shu[i];
    for(i=0;i<=n;i++) fmax[i]=-INF;
    sum=n;f[0]=n;root=0;    
    getroot(1,0);   
    work(root);
    printf("%d\n",shuzi[ans]);
   // system("pause");
    return 0;
}