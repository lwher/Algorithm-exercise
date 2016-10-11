#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,T,s,t;
int sz1,to1[3000010],pre1[3000010],v1[3000010],last1[1510];
int sz,to[2000010],pre[2000010],v[2000010],last[1510];
int d[1510],dui[100010],h[1510],gap[1510];
bool mark[1510];
void Ins(int a,int b,int c)
{
     sz1++;to1[sz1]=b;v1[sz1]=c;pre1[sz1]=last1[a];last1[a]=sz1;
     sz1++;to1[sz1]=a;v1[sz1]=c;pre1[sz1]=last1[b];last1[b]=sz1;
}
void add(int a,int b)
{
     sz++;to[sz]=b;v[sz]=1;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void spfa()
{
     memset(mark,0,sizeof(mark));
     memset(d,127,sizeof(d));
     d[1]=0;mark[1]=1;
     int tou=1,wei=1,now,i;
     dui[1]=1;
     while(tou<=wei)
     {
        now=dui[tou];
        tou++;
        i=last1[now];
        while(i>0)
        {
                  if(d[to1[i]]>d[now]+v1[i])
                  {
                    d[to1[i]]=d[now]+v1[i];
                    if(!mark[to1[i]])
                    {wei++;dui[wei]=to1[i];mark[to1[i]]=1;}
                  }
                  i=pre1[i];
        }
        mark[now]=0;
     }
}
void init()
{
     int i,j;
     int a,b,c;
     sz1=0;sz=1;
     memset(last1,0,sizeof(last1));
     memset(last,0,sizeof(last));
     scanf("%d",&n);
     while(scanf("%d%d%d",&a,&b,&c))
     {
        if(a==0 && b==0 && c==0)  break;
        if(a==0 || b==0)  continue;
        Ins(a,b,c);
     }
     spfa();
     for(i=1;i<=n-1;i++)
     {
        j=last1[i];
        while(j>0)
        {
            if(d[to1[j]]==d[i]+v1[j])
            add(i,to1[j]);      
            j=pre1[j];
        }
     }
}
void bfs()
{
     memset(h,-1,sizeof(h));
     memset(gap,0,sizeof(gap));
     int tou=1,wei=1,now,i;
     dui[1]=t;
     h[t]=0;gap[0]=1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         i=last[now];
         while(i>0)
         {
             if(h[to[i]]==-1)
             {
                      h[to[i]]=h[now]+1;
                      gap[h[now]+1]++;
                      wei++;dui[wei]=to[i];   
             }
             i=pre[i];
         }
     }
}
int dfs(int x,int F)
{
    if(x==t)  return F;
    int used=0,w,i;
    i=last[x];
    while(i>0)
    {
       if(v[i] && h[to[i]]==h[x]-1)
       {
          w=min(v[i],F-used);
          w=dfs(to[i],w);
          v[i]-=w;
          v[i^1]+=w;
          used+=w;
          if(used==F)
          return F;
       }
       i=pre[i];
    }
    gap[h[x]]--;
    if(gap[h[x]]==0)
    h[s]=n+2;
    gap[++h[x]]++;
    return used;
}
int SAP()
{
    int ans=0;
    while(h[s]<n+1)
    {
           ans+=dfs(s,INF);     
    }
    return ans;
}
void solve()
{
     init();
     if(n==1)  {printf("0\n");return;}
     s=1;t=n;
     bfs();
     if(h[s]==-1)   printf("0\n");
     else
     printf("%d\n",SAP());;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
    system("pause");
    return 0;
}
