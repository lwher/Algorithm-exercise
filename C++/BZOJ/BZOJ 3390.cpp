#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
    int a,b,v;
}lu[20010];
int n,m,fa[1010],ans,now;
int getfa(int x)
{
    if(fa[x]==0)  return x;
    return fa[x]=getfa(fa[x]);
}
inline bool comp(sth a,sth b)
{
    return a.v>b.v;
}
int main()
{
    int i,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)  scanf("%d%d%d",&lu[i].a,&lu[i].b,&lu[i].v);
    sort(lu+1,lu+1+m,comp);
    for(i=1;i<=m;i++)
    {
        x=getfa(lu[i].a);y=getfa(lu[i].b);
        if(x!=y)
        {
            now++;ans+=lu[i].v;fa[x]=y;
            if(now==n-1)  break;
        }
    }
    if(now==n-1)  printf("%d\n",ans);
    else  printf("-1\n");
    return 0;
}