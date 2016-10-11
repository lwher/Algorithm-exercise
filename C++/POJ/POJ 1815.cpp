#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 510
#define M 1000010
#define INF 0x7fffffff
using namespace std;
int n,m,s,t;
int sz=1,to[M],pre[M],v[M],last[N];
int h[N],gap[N],dui[N];
bool del[210],map[210][210];
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
	if(gap[h[x]]==0)  h[s]=n+n+2;
	gap[++h[x]]++;
	return used;
}
int sap()
{
	int tmp=0;
	bfs();
	while(h[s]<n+n+2)  tmp+=dfs(s,INF);
	return tmp;
}
void build()
{
     sz=1;memset(last,0,sizeof(last));
     int i,j;
     for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  if(map[i][j])  Ins(i+n,j,INF);
     for(i=1;i<=n;i++)  if(!del[i])  Ins(i,i+n,1);
}
int main()
{
	int i,j,k,a,b,last;
	scanf("%d%d%d",&n,&s,&t);
	s+=n;
	for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  
    {
       scanf("%d",&map[i][j]);
       if(map[i][j])  Ins(i+n,j,INF);
    }
    for(i=1;i<=n;i++) Ins(i,i+n,1);
    if(map[s-n][t])  printf("NO ANSWER!\n");
    else
    {
        last=sap();
        printf("%d\n",last);
        for(i=1;i<=n;i++)
        {
               if(last==0)  break;
               del[i]=1;
               build();
               k=sap();
               if(last==k)  del[i]=0;  
               last=k;
               
        }
        for(i=1;i<=n;i++) if(del[i])  printf("%d ",i);
    }
    system("pause");
	return 0;
}

