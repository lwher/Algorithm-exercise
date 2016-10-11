#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
    int w,bh,p,k,o;
}xw[200010];
int n,m,sz,num[100010],sum[10010];
int f[110][110],ans[100010];
inline bool comp(sth a,sth b) {return a.w<b.w;}
int main()
{
    int i,j,l,r,p,k,now=1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&l,&r,&p,&k);
        xw[++sz].w=l-1;xw[sz].bh=i;xw[sz].o=-1;xw[sz].p=p;xw[sz].k=k;
        xw[++sz].w=r;xw[sz].bh=i;xw[sz].o=1;xw[sz].p=p;xw[sz].k=k;
    }
    sort(xw+1,xw+1+sz,comp);
    while(now<=sz && !xw[now].w) now++;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=100;j++) f[j][num[i]%j]++;
        sum[num[i]]++;
        while(now<=sz && xw[now].w==i)
        {
            p=xw[now].p;k=xw[now].k;
            if(p<=100) ans[xw[now].bh]+=xw[now].o*f[p][k];
            else  for(j=k;j<=10000;j+=p)  ans[xw[now].bh]+=xw[now].o*sum[j];
            now++;
        }
    }
    for(i=1;i<=m;i++) printf("%d\n",ans[i]);
    system("pause");
    return 0;
}
