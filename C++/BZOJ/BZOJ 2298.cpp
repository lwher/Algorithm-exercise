#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct seg
{
    int l,r,v;
}q[100010],p[100010];
int n,tot,f[100010];
int pre[100010],last[100010];
inline bool comp(seg a,seg b)
{
    if(a.l==b.l) return a.r<b.r;
    return a.l<b.l;
}
int main()
{
    int i,j,k,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++) 
    {
        scanf("%d%d",&x,&y);
        q[i].l=y+1;q[i].r=n-x;q[i].v=0;
    }    
    sort(q+1,q+1+n,comp);
    for(i=1;i<=n;i++)
    {
        if(q[i].l>q[i].r) continue;
        for(k=i+1;k<=n && q[k].l==q[i].l && q[k].r==q[i].r;k++);
        p[++tot]=q[i];
        p[tot].v=min(q[i].r-q[i].l+1,k-i);
        i=k-1;
    }
    for(i=1;i<=tot;i++) 
    {
        pre[i]=last[p[i].r];last[p[i].r]=i;
    }
    for(i=1;i<=n;i++)
    {
        f[i]=f[i-1];
        for(j=last[i];j;j=pre[j])
        {
            f[i]=max(f[i],f[p[j].l-1]+p[j].v);
        }
    }
    printf("%d\n",n-f[n]);
    system("pause");
    return 0;
}
