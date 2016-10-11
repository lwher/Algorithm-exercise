#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,s,t;
int sz,to[30010],pre[30010],v[30010],last[110];
int h[110],gap[110],dui[110];
int zx[51],hj[51];
void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
    sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void bfs()
{
    memset(h,-1,sizeof(h));
    memset(gap,0,sizeof(gap));
    int tou=1,wei=1,now,i;
    dui[1]=t;h[t]=1;gap[1]=1;
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        for(i=last[now];i;i=pre[i])
        {
            if(h[to[i]]==-1)
            {
                h[to[i]]=h[now]+1;
                gap[h[to[i]]]++;
                dui[++wei]=to[i];
            }
        }
    }
}
int dfs(int x,int F)
{
    if(x==t) return F;
    int used=0,w,i;
    for(i=last[x];i;i=pre[i])
    {
        if(v[i]>0 && h[x]-1==h[to[i]])
        {
            w=min(v[i],F-used);
            w=dfs(to[i],w);
            used+=w;
            v[i]-=w;
            v[i^1]+=w;
            if(F==used) return F;
        }
    }
    gap[h[x]]--;
    if(!gap[h[x]])  h[s]=t+2;
    gap[++h[x]]++;
    return used;
}
int sap()
{
    int tmp=0;
    bfs();
    while(h[s]<t+2)  tmp+=dfs(s,INF);
    return tmp;
}
int main()
{
    int T,i,j,tot,x;
    scanf("%d",&T);
    while(T--)
    {
        sz=1;memset(last,0,sizeof(last));
        scanf("%d",&n);
        s=n+n+1;t=s+1;tot=0;
        for(i=1;i<=n;i++)  scanf("%d",&zx[i]);
        for(i=1;i<=n;i++) 
        {
            scanf("%d",&hj[i]);
            if(!(zx[i]==1 && hj[i]==1))  {Ins(s,i,1);tot++;}
            if(zx[i]==1) Ins(i+n,t,1);
            if(zx[i]==1 && hj[i]==0)  Ins(i,i+n,1);
        }
        for(i=1;i<=n;i++) for(j=1;j<=n;j++)
        {
            scanf("%d",&x);
            if(x==1)  Ins(i,j+n,1);
        }
        if(sap()==tot)  printf("%c%c%c\n",94,95,94);
        else printf("%c%c%c\n",84,95,84);
    } 
    return 0;
}