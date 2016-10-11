#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
    int l,r;
}cow[2510];
int n,L,ans,sum[1010];
inline bool comp(sth a,sth b)
{
    return a.r<b.r;
}
int main()
{
    int i,j,a,b;
    scanf("%d%d",&n,&L);
    for(i=1;i<=n;i++)  scanf("%d%d",&cow[i].l,&cow[i].r);
    for(i=1;i<=L;i++)
    {
        scanf("%d%d",&a,&b);
        sum[a]+=b;
    }
    sort(cow+1,cow+1+n,comp);
    for(i=1;i<=n;i++)
    {
        for(j=cow[i].l;j<=cow[i].r;j++)
        if(sum[j]>0)  {ans++;sum[j]--;break;}
    }
    printf("%d\n",ans);
    return 0;
}