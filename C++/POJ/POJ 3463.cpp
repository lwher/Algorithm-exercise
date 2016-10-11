#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int T,n,m,s,t;
int sz,to[10010],v[10010],pre[10010],last[1010];
int d[1010][2],sum[1010][2];
bool mark[1010][2];
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
}
int dijkstra()
{
    memset(d,127,sizeof(d));
    memset(sum,0,sizeof(sum));
    memset(mark,0,sizeof(mark));
    int i,j,now,nmax,k;
    d[s][0]=0;sum[s][0]=1;
    for(i=1;i<=2*n-1;i++)
    {
        nmax=1e9;
        for(j=1;j<=n;j++)
        {
            if(!mark[j][0] && d[j][0]<nmax)
            {
                 nmax=d[j][0];now=j;k=0;
            }
            else
            if(!mark[j][1] && d[j][1]<nmax)
            {
                 nmax=d[j][1];now=j;k=1;
            }
        }
        mark[now][k]=1;
        j=last[now];
        while(j>0)
        {
              if(!mark[to[j]][0] && d[now][k]+v[j]<d[to[j]][0])
              {
                   d[to[j]][1]=d[to[j]][0];
                   sum[to[j]][1]=sum[to[j]][0];
                   d[to[j]][0]=d[now][k]+v[j];
                   sum[to[j]][0]=sum[now][k];
              }
              else
              if(!mark[to[j]][0] && d[now][k]+v[j]==d[to[j]][0])
              {
                   sum[to[j]][0]+=sum[now][k];
              }
              else
              if(!mark[to[j]][1] && d[now][k]+v[j]<d[to[j]][1])
              {
                    d[to[j]][1]=d[now][k]+v[j];
                    sum[to[j]][1]=sum[now][k];
              }
              else
              if(!mark[to[j]][1] && d[now][k]+v[j]==d[to[j]][1])
              {
                    sum[to[j]][1]+=sum[now][k];
              }
              j=pre[j];
        }
    }
    int ans=sum[t][0];
    if(d[t][1]==d[t][0]+1)  ans+=sum[t][1];  
    return ans;
}
int main()
{
    int i,j,a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        sz=0;
        memset(last,0,sizeof(last));
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            Ins(a,b,c);
        }
        scanf("%d%d",&s,&t);
        printf("%d\n",dijkstra());
    }
    system("pause");
    return 0;
}
