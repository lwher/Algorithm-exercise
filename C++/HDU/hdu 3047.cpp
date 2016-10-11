#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,fa[50010],d[50010],ans;
int getfa(int x)
{
    if(fa[x]==0)  return x;
    getfa(fa[x]);
    d[x]+=d[fa[x]];
    if(fa[fa[x]])  fa[x]=fa[fa[x]];
    return fa[x];
}
int main()
{
    int a,b,v,i,x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
         memset(fa,0,sizeof(fa));
         memset(d,0,sizeof(d));
         ans=0;
         for(i=1;i<=m;i++)
         {
             scanf("%d%d%d",&a,&b,&v);
             x=getfa(a);y=getfa(b);
             if(x!=y)
             {
                     fa[x]=y;
                     d[x]=d[b]+v-d[a];
             }
             else
             {
                 if(d[a]-d[b]!=v)  ans++;
             }
         }
         printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
