#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
int sz,to[30010],pre[30010],v[30010],last[10010],d[10010];
bool mark[10010];
void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
}
bool dfsspfa(int x)
{
    int i=last[x];
    mark[x]=1;
    while(i>0)
    {
        if(d[x]+v[i]<d[to[i]])
        {
            if(mark[to[i]])  return 0;
            d[to[i]]=d[x]+v[i];
            if(!dfsspfa(to[i]))  return 0;
        }
        i=pre[i];
    }
    mark[x]=0;
    return 1;
}
int main()
{
    int i,a,b,c,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k);
        if(k==1)
        {
            scanf("%d%d%d",&a,&b,&c);
            Ins(a,b,-c);
        } else
        if(k==2)
        {
            scanf("%d%d%d",&a,&b,&c);
            Ins(b,a,c);
        }
        else
        {
            scanf("%d%d",&a,&b);
            Ins(a,b,0);Ins(b,a,0);
        }
    }
    k=n+1;
    for(i=1;i<=n;i++) Ins(k,i,0);
    memset(d,127,sizeof(d));d[k]=0;
    if(dfsspfa(k))  printf("Yes\n");  else printf("No\n");
    //system("pause");
    return 0;
}