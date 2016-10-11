#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct sth
{
       int a,b,v;
}road[90010];
int n,m;
int fa[310];
inline bool comp(sth a,sth b)
{
       return a.v<b.v;
}
int getfa(int x)
{
    if(fa[x]==0)  return x;
    else
    return fa[x]=getfa(fa[x]);
}
int main()
{
    int i,j,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    scanf("%d%d%d",&road[i].a,&road[i].b,&road[i].v);
    sort(road+1,road+1+m,comp);
    n--;
    cout<<n<<" ";
    for(i=1;i<=m;i++)
    {
       x=getfa(road[i].a);
       y=getfa(road[i].b);
       if(x!=y)
       {
          fa[x]=y;
          n--;
       }
       if(!n)  break;
    }
    cout<<road[i].v<<endl;
    system("pause");
    return 0;
}
