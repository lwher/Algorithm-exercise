#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,k,len,d[100010],dui[100010];
int sz,to[200010],pre[200010],last[100010];
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void init()
{
     int i,a,b;sz=0;
     memset(last,0,sizeof(last));
     scanf("%d%d",&n,&m);
     for(i=1;i<n;i++)
     {
        scanf("%d%d",&a,&b);Ins(a,b);Ins(b,a);
     }
}
void bfs(int x)
{
     int now,i,tou=1,wei=1;
     memset(d,-1,sizeof(d));
     dui[1]=x;d[x]=0;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         i=last[now];
         while(i>0)
         {
             if(d[to[i]]==-1)
             {d[to[i]]=d[now]+1;wei++;dui[wei]=to[i];}
             i=pre[i];
         }
     }
}
void solve()
{
     bfs(1);
     int i,qi,nd=0;
     for(i=1;i<=n;i++)  if(d[i]>nd) {qi=i;nd=d[i];}
     bfs(qi);len=0;
     for(i=1;i<=n;i++)  len=max(len,d[i]);
     len++;
     for(i=1;i<=m;i++)
     {
        scanf("%d",&k);
        if(k<=len) printf("%d\n",k-1);
        else  printf("%d\n",len+2*(k-len)-1);
     }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        solve();
    }
    system("pause");
    return 0;
}
