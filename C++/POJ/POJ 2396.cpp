#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 300010
#define INF 0x7fffffff
using namespace std;
int n,m,sz=1,TT;
int s,t;
int S,T;
int dayu[210][210],xiaoyu[210][210],dengyu[210][210];
int to[N],pre[N],last[5010],v[N],low[N];
int shuju[40010];
int in[5010],h[5010],gap[5010];
int dui[5010];
int hang[210],lie[210];
bool dayu1[210][210],xiaoyu1[210][210],dengyu1[210][210],o;
int sum,nm;
void Ins(int a,int b,int c,int d)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;low[sz]=c;v[sz]=d-low[sz];
	in[a]-=low[sz];in[b]+=low[sz];
	sz++;to[sz]=a;pre[sz]=last[b];last[b]=sz;v[sz]=0;
}
void bfs()
{
	int i,now,tou=1,wei=1;
	h[t]=1;
	gap[1]++;
	dui[1]=t;
	while(tou<=wei)
	{
		now=dui[tou];
		i=last[now];
		while(i>0)
		{
			if(!h[to[i]])
			{
				h[to[i]]=h[now]+1;gap[h[to[i]]]++;wei++;dui[wei]=to[i];
			}
			i=pre[i];
		}
		tou++;
	}
}
int dfs(int x,int F)
{
	int i,used=0,w;
	if(x==t)  return F;
	i=last[x];
	while(i>0)
	{
		if(v[i]>0 && h[x]-1==h[to[i]])
		{
			w=F-used;
			w=dfs(to[i],min(w,v[i]));
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
	h[s]=n*m+n+m+5;
	gap[++h[x]]++;
	return used;
}
void SAP()
{
	bfs();
	while(h[s]<=n*m+n+m+4)
	{
		dfs(s,INF);
	}
}
void build()
{
	int i;
	int j;
	int up,down;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(dayu1[i][j])   down=dayu[i][j]+1;  else down=0;
		if(xiaoyu1[i][j])  up=xiaoyu[i][j]-1; else up=INF;
		if(dengyu1[i][j])  {up=dengyu[i][j];down=dengyu[i][j];} 
	    Ins(n*m+i,m*(i-1)+j,down,up);
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	Ins(m*(i-1)+j,m*n+n+j,0,INF);
	S=n*m+n+m+1;
	T=S+1;
	s=0;
	t=T+1;
	for(i=1;i<=n;i++)
	Ins(S,n*m+i,hang[i],hang[i]);
	for(j=1;j<=m;j++)
	Ins(n*m+n+j,T,lie[j],lie[j]);
	Ins(T,S,0,INF);
}
void solve()
{
	int i,j;
    build();    
	for(i=1;i<=n*m+n+m+2;i++)
	{
		if(in[i]>0) 
		{Ins(s,i,0,in[i]);sum+=in[i];}
		else
		if(in[i]<0)
		{Ins(i,t,0,(-1)*in[i]);}
	}
	SAP();
	i=last[s];
	while(i>0)
	{
		if(v[i])
		{
			printf("IMPOSSIBLE\n");return;
		}
		i=pre[i];
	}
	shuju[0]=0;
	
	for(i=2;i<=n*m*2+1;i+=2)
	{
		shuju[0]++;shuju[shuju[0]]=v[i^1]+low[i];
	}
	
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=m;j++)
	printf("%d ",shuju[m*(i-1)+j]);
	printf("\n");
    }
}
bool pd(int x,int y,char ch,int num)
{
	if(o) return 1;
	if(ch=='=')
	{
		if(num<0)  return 0;
		if(dengyu1[x][y] && num!=dengyu[x][y]) return 0;
		if(dayu1[x][y] && dayu[x][y]>=num)  return 0;
		if(xiaoyu1[x][y] && xiaoyu[x][y]<=num)  return 0;
		dengyu[x][y]=num;dengyu1[x][y]=1;
	}
	else
	if(ch=='>')
	{
		if(num<0)
		num=-1;
		if(dengyu1[x][y] && dengyu[x][y]<=num)  return 0;
		if(xiaoyu1[x][y] && xiaoyu[x][y]<=num)  return 0;
		dayu1[x][y]=1;dayu[x][y]=max(dayu[x][y],num);
	}
	else
	if(ch=='<')
	{
		if(num<=0)  return 0;
		if(dengyu1[x][y] && dengyu[x][y]>=num) return 0;
		if(dayu1[x][y] && dayu[x][y]>=num)  return 0;
		if(!xiaoyu1[x][y])
		{xiaoyu1[x][y]=1;xiaoyu[x][y]=num;}
		else
		xiaoyu[x][y]=min(xiaoyu[x][y],num);
	}
	return 1;
}
void init()
{
	int i,j,k,l;
	int a,b,d;
	char c;
	scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  scanf("%d",&hang[i]);
    for(i=1;i<=m;i++)  scanf("%d",&lie[i]);
    scanf("%d",&k);
    for(i=1;i<=k;i++)
    {
		scanf("%d %d %c %d",&a,&b,&c,&d);
		if(o) continue;
		if(a>0 && b>0)
		{
			if(!pd(a,b,c,d))
			{printf("IMPOSSIBLE\n");o=1;}
		}
		else
		if(a==0 && b==0)
		{
			if(o) continue;
			for(j=1;j<=n;j++)
			for(l=1;l<=m;l++)
			if(!pd(j,l,c,d))
			{printf("IMPOSSIBLE\n");o=1;}
		}
		else
		if(a>0 && b==0)
		{
			if(o) continue;
			for(j=1;j<=m;j++)
			if(!pd(a,j,c,d))
			{printf("IMPOSSIBLE\n");o=1;}
		}
		else
		{
			if(o) continue;
			for(j=1;j<=n;j++)
			if(!pd(j,b,c,d))
			{printf("IMPOSSIBLE\n");o=1;}
		}
	}
}
int main()
{
	//freopen("budget.in","r",stdin);
	//freopen("budget.out","w",stdout);
	scanf("%d",&TT);
	while(TT--)
	{
	  memset(dayu,0,sizeof(dayu));
	  memset(dayu1,0,sizeof(dayu1));
	  memset(xiaoyu,0,sizeof(xiaoyu));
	  memset(xiaoyu1,0,sizeof(xiaoyu1));
	  memset(dengyu,0,sizeof(dengyu));
	  memset(dengyu1,0,sizeof(dengyu1));
	  memset(dayu,0,sizeof(dayu));
	  memset(last,0,sizeof(last));
	  memset(gap,0,sizeof(gap));
	  memset(h,0,sizeof(h));
	  memset(in,0,sizeof(in));
	  sz=1;o=0;
	  
	  init();
	  if(!o)   solve();
	  printf("\n");    
	}
	//system("pause");
	return 0;
}

