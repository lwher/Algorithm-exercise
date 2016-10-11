#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1000010
#define INF 0x7fffffff
using namespace std;
int n,m,sz=1;
int s,t;
int S,T;
int to[N],pre[N],last[2000],v[N],low[N];
int in[2000],h[2000],gap[2000],d[1010],need[366];
int dui[2000];
int sum,ans,ss;
void Ins(int a,int b,int c,int d)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;low[sz]=c;v[sz]=d-c;
	in[a]-=low[sz];in[b]+=low[sz];
	sz++;to[sz]=a;pre[sz]=last[b];last[b]=sz;v[sz]=0;
}
void bfs(int x)
{
	int i,now,tou=1,wei=1;
	h[x]=1;
	gap[1]++;
	dui[1]=x;
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
int dfs(int x,int F,int kk)
{
	int i,used=0,w;
	if(x==kk)  return F;
	i=last[x];
	while(i>0)
	{
		if(v[i]>0 && h[x]-1==h[to[i]])
		{
			w=F-used;
			w=dfs(to[i],min(w,v[i]),kk);
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
	h[s]=n+m+5;
	gap[++h[x]]++;
	return used;
}
int SAP(int x,int y)
{
	int now=0;
	while(h[x]<=n+m+4)
	{
		now+=dfs(x,INF,y);
	}
	return now;
}
void solve()
{
	int i;
	for(i=1;i<=n+m+2;i++)
	{
		if(in[i]>0) 
		{Ins(S,i,0,in[i]);sum+=in[i];}
		else
		if(in[i]<0)
		{Ins(i,T,0,(-1)*in[i]);}
	}
	
	Ins(t,s,0,INF);
	memset(h,0,sizeof(h));
	memset(gap,0,sizeof(gap));
	bfs(T);
	ans=SAP(S,T);
	if(ans!=sum) {printf("-1\n");return;}
	ans=v[sz];
	last[s]=pre[last[s]];
	last[t]=pre[last[t]];
	i=last[S];
	while(i>0)
	{v[i]=0;v[i^1]=0;i=pre[i];}
	i=last[T];
	while(i>0)
	{v[i]=0;v[i^1]=0;i=pre[i];}
	memset(h,0,sizeof(h));
	memset(gap,0,sizeof(gap));
	bfs(t);
	ans+=SAP(s,t);
	printf("%d\n",ans);
	for(i=2;i<=ss*2+1;i+=2)
	printf("%d\n",v[i^1]+low[i]);
}
void init()
{
	int i,j;
	int a,b,c,l,r,k;
	memset(last,0,sizeof(last));
	memset(in,0,sizeof(in));
	sz=1;
	ss=0;
	ans=0;
	sum=0;
	for(i=1;i<=m;i++)
	scanf("%d",&need[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&k,&d[i]);
		ss+=k;
		for(j=1;j<=k;j++)
		{
			scanf("%d%d%d",&a,&l,&r);
			a++;
			Ins(i,n+a,l,r);
		}
	}
	s=n+m+1;t=s+1;
	S=t+1;T=S+1;
	for(i=1;i<=n;i++)   Ins(s,i,0,d[i]);
	for(j=1;j<=m;j++)   Ins(n+j,t,need[j],INF);
	
}
int main()
{
	while(cin>>n>>m)
	{
	init();
	solve();
	cout<<endl;
    }
	//system("pause");
	return 0;
}

