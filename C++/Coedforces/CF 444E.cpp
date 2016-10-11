#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
    int x,y,v;
}lu[3010];
int n,ans,sum,fa[3010],sz[3010],need[3010];
bool oh;
int getfa(int x)
{
    if(fa[x]==0) return x;
    return fa[x]=getfa(fa[x]); 
}
inline bool comp(sth a,sth b)
{
    return a.v<b.v;
}
void link(int a,int b)
{
    int x=getfa(a),y=getfa(b);
    if(x!=y)
    {
        fa[x]=y;
        sz[y]+=sz[x];
        need[y]+=need[x];
        if(need[y]>sum-sz[y]) oh=1;
    }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<n;i++) scanf("%d%d%d",&lu[i].x,&lu[i].y,&lu[i].v);
    sort(lu+1,lu+n,comp);
    for(i=1;i<=n;i++) scanf("%d",&sz[i]),sum+=sz[i],need[i]=1;     
    ans=lu[1].v;       
    for(i=1;i<n;i++)
    {
       j=i;
       if(!oh) ans=lu[i].v;
       while(j<n && lu[j].v==lu[i].v) 
       {
           link(lu[j].x,lu[j].y);
           j++;
       }
       if(oh) break;
       i=j-1;
    } 
    printf("%d\n",ans);
    system("pause");
    return 0;
}
