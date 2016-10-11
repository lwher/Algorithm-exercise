#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,w,s,d[510];
int sz,to[30010],pre[30010],v[30010],last[510];
bool mark[510];
void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
}
bool dfsspfa(int x)
{
    mark[x]=1;
    for(int i=last[x];i;i=pre[i])
    {
        if(d[x]+v[i]<d[to[i]])
        {
            if(mark[to[i]])  return 1;
            d[to[i]]=d[x]+v[i];
            if(dfsspfa(to[i]))  return 1;
        }
    }
    mark[x]=0;
    return 0;
}
int main()
{
    int T,i,a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&w);
        sz=0;memset(last,0,sizeof(last));
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            Ins(a,b,c);Ins(b,a,c);
        }
        for(i=1;i<=w;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            Ins(a,b,-c);
        }
        s=n+1;
        for(i=1;i<=n;i++)  Ins(s,i,0);
        memset(mark,0,sizeof(mark));
        memset(d,127,sizeof(d));
        d[s]=0;
        if(dfsspfa(s))  printf("YES\n"); else printf("NO\n");
    }
    return 0;
}