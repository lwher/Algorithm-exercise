#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m;
int to[10010],pre[10010],v[10010];
int last[110],d[110],dj[110],sz,dui[30010],ans;
bool mark[110];
void Ins(int a,int b,int c)
{
     sz++;
     to[sz]=b;
     v[sz]=c;
     pre[sz]=last[a];
     last[a]=sz;
}
void init()
{
     int i,j;
     int a,b,c,k,l;
     scanf("%d%d",&m,&n);
     for(i=1;i<=n;i++)
     {
         scanf("%d%d%d",&a,&b,&c);
         Ins(101,i,a);
         dj[i]=b;
         for(j=1;j<=c;j++)
         {
             scanf("%d%d",&k,&l);
             Ins(k,i,l);
         }
     }
     ans=v[1];
}
void spfa(int mn)
{
     memset(mark,0,sizeof(mark));
     memset(d,127,sizeof(d));
     dui[1]=101;
     d[101]=0;
     mark[101]=1;
     int tou=1,wei=1,now;
     int i;
     while(tou<=wei)
     {
          now=dui[tou];
          i=last[now];
          while(i>0)
          {
               if(dj[to[i]]>=mn && dj[to[i]]<=mn+m && d[now]+v[i]<d[to[i]])
               {
                     d[to[i]]=d[now]+v[i];
                     if(!mark[to[i]])
                     {
                         mark[to[i]]=1;wei++;dui[wei]=to[i];
                     }
               }
               i=pre[i];
          }
          mark[now]=0;
          tou++;
     }
     ans=min(ans,d[1]);
}
void solve()
{
     int i;
     for(i=dj[1]-m;i<=dj[1];i++)
     {
         spfa(i);
     }
     cout<<ans<<endl;
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
