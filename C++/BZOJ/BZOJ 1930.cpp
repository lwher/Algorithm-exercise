#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
    int x,y;
}p[2010];
int n,s,t,S,f[2010],Pre[2010];
int sz,to[4100010],pre[4100010],v[4100010],d[4010],last[4010],dui[4010];
bool used[2010],mark[4010];
inline void Inc(int &x)
{
    x++;if(x==4009) x=0;
}
inline bool comp(sth a,sth b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
inline void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
int spfa()
{
    int i,tou=0,wei=1,now;
    for(i=1;i<=t;i++) d[i]=-100000;
    dui[1]=s;mark[s]=1;d[s]=0;
    while(tou!=wei)
    {
        Inc(tou);now=dui[tou];
        for(i=last[now];i;i=pre[i])
        if(d[to[i]]<d[now]+v[i])
        {
           d[to[i]]=d[now]+v[i];
           if(!mark[to[i]])
           {
              mark[to[i]]=1;
              Inc(wei);
              dui[wei]=to[i];
           }
        }
        mark[now]=0;
    }
    return d[t];
}
int main()
{
    int i,j,Max=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
    sort(p+1,p+1+n,comp);
    for(i=1;i<=n;i++)
    {
       f[i]=1;
       for(j=1;j<i;j++) if(p[j].y<=p[i].y && f[j]+1>f[i])
       {
          f[i]=f[j]+1;
          Pre[i]=j;
       }
       if(Max<f[i]) {Max=f[i];S=i;}
    }    
    s=n*2+1;t=s+1;
    for(i=S;i;i=Pre[i]) used[i]=1;
    for(i=1;i<=n;i++) 
    {
       if(used[i]) 
       {
          Ins(i+n,i,-1);
          if(Pre[i]==0) Ins(i,s,0); else Ins(s,i,0);
          if(i==S) Ins(t,i+n,0); else Ins(i+n,t,0);
       }
       else
       {
          Ins(i,i+n,1);
          Ins(s,i,0);
          Ins(i+n,t,0);
       }
       for(j=1;j<i;j++)
       if(p[j].y<=p[i].y)
       {
           if(Pre[i]==j && used[j] && used[i]) Ins(i,j+n,0);
           else Ins(j+n,i,0);
       }
    }
    printf("%d\n",spfa()+f[S]);
    system("pause");
    return 0;
}
