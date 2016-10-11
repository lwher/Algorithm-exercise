#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct node 
{
    int p,d;
};
bool operator <(node const &a,node const &b)
{
     return a.d>b.d;
}
int n,m,s,t,dist[2510];
int sz,to[30010],pre[30010],v[30010],last[2510];
bool mark[2510];
inline void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void init()
{
    int i,a,b,c;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        Ins(a,b,c);Ins(b,a,c);
    }
}
void Dij()
{
     memset(dist,127,sizeof(dist));
     priority_queue<node> q;
     dist[s]=0;
     node p={s,0};
     q.push(p);
     for(int i=1;i<=n;i++)
     {
         p=q.top();q.pop();
         if(mark[p.p]) continue;
         mark[p.p]=1;
         for(int j=last[p.p];j;j=pre[j]) if(dist[p.p]+v[j]<dist[to[j]])
         {
              dist[to[j]]=dist[p.p]+v[j];
              node now={to[j],dist[to[j]]};
              q.push(now);
         }
     }
     printf("%d\n",dist[t]);
}
int main()
{
    init();
    Dij();
    system("pause");
    return 0;
}
