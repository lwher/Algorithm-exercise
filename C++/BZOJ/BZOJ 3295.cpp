#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 15000000
using namespace std;
int n,m,sz,num[100010],A[30],B[30],w[100010];
long long ans;
int root[100010],sum[9500000],ls[9500000],rs[9500000];
int qian[100010],hou[100010],t[100010];
int lowbit(int x)
{
    return x & (-x);
}
void updata(int x,int k)
{
    for(int i=x;i<=n;i+=lowbit(i))  t[i]+=k;
}
int ask(int x)
{
    int i,tmp=0;
    for(i=x;i;i-=lowbit(i))  tmp+=t[i];
    return tmp;
}
void add(int &y,int l,int r,int x)
{
    if(!y)  y=++sz;
    sum[y]++;
    if(l==r)  return;
    int mid=(l+r)>>1;
    if(x<=mid)  add(ls[y],l,mid,x);
    else  add(rs[y],mid+1,r,x);
}
int askmore(int zuo,int you,int k)
{
    int i,j,mid,l=1,r=n,now=0;zuo--;A[0]=0;B[0]=0;
    for(i=zuo;i;i-=lowbit(i))  A[++A[0]]=root[i];
    for(i=you;i;i-=lowbit(i))  B[++B[0]]=root[i];
    while(l!=r)
    {
        mid=(l+r)>>1;
        if(k<=mid)
        {
            for(i=1;i<=A[0];i++)  now-=sum[rs[A[i]]];
            for(i=1;i<=B[0];i++)  now+=sum[rs[B[i]]];
            for(i=1;i<=A[0];i++)  A[i]=ls[A[i]];
            for(i=1;i<=B[0];i++)  B[i]=ls[B[i]];
            r=mid;
        }else
        {
            for(i=1;i<=A[0];i++)  A[i]=rs[A[i]];
            for(i=1;i<=B[0];i++)  B[i]=rs[B[i]];
            l=mid+1;
        }
    }
    return now;
}
int askless(int zuo,int you,int k)
{
    int i,j,mid,now=0,l=1,r=n;zuo--;A[0]=0;B[0]=0;
    for(i=zuo;i;i-=lowbit(i))  A[++A[0]]=root[i];
    for(i=you;i;i-=lowbit(i))  B[++B[0]]=root[i];
    while(l!=r)
    {
        mid=(l+r)>>1;
        if(k>mid)
        {
            for(i=1;i<=A[0];i++)  now-=sum[ls[A[i]]];
            for(i=1;i<=B[0];i++)  now+=sum[ls[B[i]]];
            for(i=1;i<=A[0];i++)  A[i]=rs[A[i]];
            for(i=1;i<=B[0];i++)  B[i]=rs[B[i]];
            l=mid+1;
        }else
        {
            for(i=1;i<=A[0];i++)  A[i]=ls[A[i]];
            for(i=1;i<=B[0];i++)  B[i]=ls[B[i]];
            r=mid;
        }
    }
    return now;
}
int main()
{
    int i,j,x;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);w[num[i]]=i;
        qian[i]=ask(n)-ask(num[i]);
        ans+=qian[i];updata(num[i],1);
    }
    memset(t,0,sizeof(t));
    for(i=n;i>=1;i--)
    {
        hou[i]=ask(num[i]-1);
        updata(num[i],1);
    }       
    for(i=1;i<=m;i++)
    {
        printf("%lld\n",ans);
        scanf("%d",&x);x=w[x];
        ans-=(qian[x]+hou[x]-askmore(1,x-1,num[x])-askless(x+1,n,num[x]));
        for(j=x;j<=n;j+=lowbit(j))  add(root[j],1,n,num[x]);
    }
    return 0;
}