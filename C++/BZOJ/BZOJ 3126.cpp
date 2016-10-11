#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>  
using namespace std;
#define lc x<<1
#define rc (lc)+1
const int MAXN = 333333;
int l[MAXN],r[MAXN],f[MAXN],d[MAXN << 2];
pair<int, int> a[MAXN];
void modify(int x,int f,int t,int p,int v) 
{
    if(f==t) {d[x]=v;return;}
    int mid=f+t>>1;
    if(p<=mid)  modify(lc,f,mid,p,v);
    else modify(rc,mid+1,t,p,v);
    d[x]=max(d[lc],d[rc]);
}
int query(int x,int f,int t,int qf,int qt) 
{
    if(qf<=f && t<=qt)  return d[x];
    int mid=f+t>>1,l=0,r=0;
    if(qf<=mid) l=query(lc,f,mid,qf,qt);
    if(qt>mid) r=query(rc,mid+1,t,qf,qt);
    return max(l,r);
}
int main() 
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)  scanf("%d%d",&a[i].second,&a[i].first);
    sort(a,a+m);
    for(int i=1,j=0,mx=0;i<=n+1;++i) 
    {
        for(;j<m && a[j].first<i;++j)  mx=max(mx,a[j].second);
        l[i]=mx;
    }
    r[n+1]=n;
    for(int i=n,j=m-1,mn=n;i;--i) 
    {
        for(;j>=0 && a[j].first>=i;--j) mn=min(mn,a[j].second);
        r[i]=min(i,mn)-1;
    }    
    for(int i=1;i<=n+1;++i)
    if(l[i]<=r[i]) 
    {
        f[i]=query(1,0,n,l[i],r[i]);
        if(l[i] && !f[i])  f[i]=-1;
        if(i<=n)  modify(1,0,n,i,++f[i]);
    }
    printf("%d\n",f[n+1]?f[n+1]:-1);
   // system("pause");
    return 0;
}