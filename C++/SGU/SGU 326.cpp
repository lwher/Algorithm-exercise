#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 510
#define M 300010
#define INF 0x7fffffff
using namespace std;
int n,m,s,t;
int sz=1,to[M],pre[M],v[M],last[N];
int h[N],gap[N],dui[N];
int map[31][31]; 
int fs[31],game[31],p[31][31];
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
		i=last[now];
		while(i>0)
		{
			if(h[to[i]]==-1)
			{
				h[to[i]]=h[now]+1;
				gap[h[now]+1]++;
				dui[++wei]=to[i];
			}
			i=pre[i];
		}
	}
}
int dfs(int x,int F)
{
	if(x==t)  return F;
	int i,used=0,w;
	i=last[x];
	while(i>0)
	{
		if(v[i] && h[x]-1==h[to[i]])
		{
			w=min(v[i],F-used);
			w=dfs(to[i],w);
			used+=w;
			v[i]-=w;
			v[i^1]+=w;
			if(used==F)  return F;
		}
		i=pre[i];
	}
	gap[h[x]]--;
	if(gap[h[x]]==0)  h[s]=t+2;
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
void solve()
{
     int i,j,tt=n,sum=0;
     fs[1]+=game[1];
     for(i=2;i<=n;i++) if(fs[i]>fs[1])  {printf("NO\n");return;}
     sz=1;memset(last,0,sizeof(last));
     for(i=2;i<=n;i++)  for(j=i+1;j<=n;j++)  
     {
         sum+=map[i][j];
         if(map[i][j]>0)  p[i][j]=++tt;
     }
     s=tt+1;t=s+1;
     for(i=2;i<=n;i++)  Ins(i,t,fs[1]-fs[i]);
     for(i=2;i<=n;i++)  for(j=i+1;j<=n;j++)  
     {
         if(map[i][j]>0)  
         {
            Ins(s,p[i][j],map[i][j]);
            Ins(p[i][j],i,INF);Ins(p[i][j],j,INF);
         }
     }
     if(sap()==sum)  printf("YES\n"); else  printf("NO\n");
}
int main()
{
	int i,j,k,a,b;
	while(scanf("%d",&n)!=EOF)
	{
       for(i=1;i<=n;i++)  scanf("%d",&fs[i]);
	   for(i=1;i<=n;i++)  scanf("%d",&game[i]);
	   for(i=1;i<=n;i++)  for(j=1;j<=n;j++) scanf("%d",&map[i][j]);
       solve();
    }
	system("pause");
	return 0;
}
