#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,m,k,s,t;
int L[110],C[110],sumh[110],suml[110];
int sz=1,to[30010],pre[30010],v[30010],last[1010];
int dui[1010],h[1010],gap[1010];
bool map[110][110];
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
     sz++;to[sz]=a;pre[sz]=last[b];v[sz]=0;last[b]=sz;
}
void bfs()
{
     memset(h,-1,sizeof(h));
     int tou=1,wei=1,now,i;
     dui[1]=t;h[t]=1;gap[1]=1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         i=last[now];
         while(i>0)
         {
              if(h[to[i]]==-1)  
              {
                  h[to[i]]=h[now]+1;
                  gap[h[to[i]]]++;
                  dui[++wei]=to[i];
              }
              i=pre[i];
         }
     }
}
int dfs(int x,int F)
{
    if(x==t) return F;
    int i=last[x],used=0,w;
    while(i>0)
    {
        if(v[i]>0 && h[x]-1==h[to[i]])
        {
           w=min(v[i],F-used);
           w=dfs(to[i],w);
           used+=w;
           v[i]-=w;
           v[i^1]+=w;
           if(F==used)  return F;
        }
        i=pre[i];
    }
    gap[h[x]]--;
    if(gap[h[x]]==0)   h[s]=t+2;
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
    int i,j,x,y;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)  scanf("%d",&L[i]);
    for(i=1;i<=m;i++)  scanf("%d",&C[i]);
    for(i=1;i<=k;i++)
    {
        scanf("%d%d",&x,&y);
        sumh[x]++;suml[y]++;map[x][y]=1;
    }
    for(i=1;i<=n;i++) if(sumh[i]+L[i]>m) 
    {
        printf("JIONG!\n");
        return 0;
    }
    for(i=1;i<=m;i++) if(suml[i]+C[i]>n) 
    {
        printf("JIONG!\n");
        return 0;
    }
    s=n+m+1;t=s+1;
    for(i=1;i<=n;i++) Ins(s,i,m-sumh[i]-L[i]);
    for(i=1;i<=m;i++) Ins(i+n,t,n-suml[i]-C[i]);
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  if(!map[i][j])   Ins(i,j+n,1);    
    printf("%d\n",n*m-k-sap());
    system("pause");
    return 0;
}
