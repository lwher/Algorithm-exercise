#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,fa[100010];
bool mark[100010];
int getfa(int x)
{
    if(fa[x]==0) return x;
    return fa[x]=getfa(fa[x]);
}
int main()
{
    int i,a,b,x,y;
    bool o=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        x=getfa(a);y=getfa(b);
        if(x!=y)  
        {
           if(mark[x])  mark[y]=1;
           fa[x]=y;
        }
        else  mark[x]=1;
    }
    for(i=1;i<=n;i++)  
    {
       x=getfa(i);
       if(!mark[x])  {o=1;break;}
    }
    if(o) printf("NIE\n"); else  printf("TAK\n");
    system("pause");
    return 0;
}
