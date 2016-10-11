#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define INF 0x7fffffff
using namespace std;
int n,m;
int C[5010];
int to[500010],v[500010],pre[500010],last[60010],h[60010];
int gap[60010];
int sz=1;
int s,t;
long long answer;
void Ins(int a,int b,int c)
{
     sz++;
     to[sz]=b;
     v[sz]=c;
     pre[sz]=last[a];
     last[a]=sz;
     sz++;
     to[sz]=a;
     v[sz]=0;
     pre[sz]=last[b];
     last[b]=sz;
}
void bfs()
{
     int i,now;
     int tou=1,wei=1;
     int dui[60010];
     dui[1]=t;
     h[t]=1;
     gap[1]++;
     while(tou<=wei)
     {
            now=dui[tou];
            i=last[now];
            while(i>0)
            {
                      if(h[to[i]]!=0)
                      {
                             h[to[i]]=h[now]+1;
                             gap[h[to[i]]]++;
                             wei++;dui[wei]=to[i];
                      }
                      i=pre[i];
            }  
            tou++; 
     }
}
int dfs(int x,int F)
{
    if(x==t)  return F;
    int i=last[x];
    int used=0,w;
    while(i>0)
    {
              if(v[i]>0 && h[x]-1==h[to[i]])
              {
                        w=F-used;
                        w=dfs(to[i],min(v[i],w));
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
    h[s]=n+m+2;
    gap[++h[x]]++;
    return used;
}
long long sap()
{
     long long ans=0;
     while(h[s]<n+m+2)
     ans+=dfs(s,INF);
     return ans;
}
void init()
{
     int i,j,k;
     int a,b,co;
     scanf("%d%d",&n,&m);
     s=0;t=n+m+1;
     for(i=1;i<=n;i++)
     scanf("%d",&C[i]);
     for(i=1;i<=n;i++)
     Ins(s,i,C[i]);
     for(i=1;i<=m;i++)
     {
        scanf("%d%d%d",&a,&b,&co);
        answer+=co;
        Ins(a,n+i,INF);
        Ins(b,n+i,INF);
        Ins(n+i,t,co);
     }
     bfs();
     answer-=sap();    
}
int main()
{
    init();
    cout<<answer<<endl;
    system("pause");
    return 0;
}
