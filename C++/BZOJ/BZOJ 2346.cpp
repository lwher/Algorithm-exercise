#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define mod 260000
using namespace std;
int n,m,dist[260000],dui[260000];
char map[510][510];
int sz,to[3000010],pre[3000010],v[3000010],last[260000];
bool mark[260000];
inline void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
inline int P(int x,int y)
{
    return (x-1)*(m+1)+y;
}
void spfa()
{
    memset(dist,127,sizeof(dist));
    int tou=0,wei=1,now,i,next;
    dui[1]=1;dist[1]=0;mark[1]=1;
    while(tou!=wei)
    {
        tou=(tou+1)%mod;
        now=dui[tou];mark[now]=0;
        for(i=last[now];i;i=pre[i])
        if(dist[to[i]]>dist[now]+v[i])
        {
            dist[to[i]]=dist[now]+v[i];
            if(!mark[to[i]])
            {
                next=(tou+1)%mod;
                if(tou==wei || dist[to[i]]<=dist[dui[next]])
                {
                    dui[tou]=to[i];mark[to[i]]=1;tou=(tou-1+mod)%mod;
                }
                else
                {
                    wei=(wei+1)%mod;dui[wei]=to[i];mark[to[i]]=1;
                }
            }
        }
    }
}
void solve()
{
    if((n+m)&1) 
    {
        printf("NO SOLUTION\n");
        return;
    }
    spfa();
    printf("%d\n",dist[(n+1)*(m+1)]);
}
int main()
{
    int i,j,p1,p2,p3,p4;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%s",map[i]+1);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++)
    {
        p1=P(i,j);p2=P(i,j+1);p3=P(i+1,j);p4=P(i+1,j+1);
        if(map[i][j]=='/') 
        {
            Ins(p1,p4,1);Ins(p4,p1,1);
            Ins(p2,p3,0);Ins(p3,p2,0);
        }
        else
        {
            Ins(p1,p4,0);Ins(p4,p1,0);
            Ins(p2,p3,1);Ins(p3,p2,1);
        }
    }
    solve();
    system("pause");
    return 0;
}
