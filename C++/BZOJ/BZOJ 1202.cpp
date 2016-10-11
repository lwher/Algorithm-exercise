#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int t;
int n,m;
int fa[110],g[110];
int get(int x)
{
    if(fa[x]==x)
    return x;
    else
    get(fa[x]);
    g[x]+=g[fa[x]];
    return fa[x]=fa[fa[x]];
}
int main()
{
    int i,j,k,a,b;
    int x,y,dis;
    scanf("%d",&t);
    bool o;
    while(t--)
    {
              o=0;
              scanf("%d%d",&n,&m);
              for(i=0;i<=n;i++) fa[i]=i,g[i]=0;
              for(i=1;i<=m;i++)
              {
                  scanf("%d%d%d",&a,&b,&dis);a--;
                  x=get(a);y=get(b);
                  if(x!=y)
                  {
                     fa[x]=y;
                     g[x]=g[b]-g[a]-dis;
                  }
                  else
                  if(g[b]-g[a]!=dis)
                  o=1;
              }
              if(o) printf("false\n");
              else
              printf("true\n");
    }
    system("pause");
    return 0;
}
