#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
	int qi,zhong,v;
}lu[130010];
int n,m,k,tot,sum;
int SZ,PRE[130010],TO[130010],V[130010],LAST[30010];
int sz,pre[130010],to[130010],v[130010],last[30010];
int dist[30010],dui[5000010];
bool mark[30010];
int root,size[30010],d[30010],deep[30010],f[30010];
int gs[30010],hash[30010],stack[30010],top;
int ans,ansgs;
inline bool comp(sth a,sth b)
{
	return a.zhong>b.zhong;
}
void INS(int a,int b,int c)
{
	SZ++;TO[SZ]=b;PRE[SZ]=LAST[a];V[SZ]=c;LAST[a]=SZ;
}
void Ins(int a,int b,int c)
{
	sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
}
void spfa()
{
	memset(dist,127,sizeof(dist));
	memset(mark,0,sizeof(mark));
	int tou=1,wei=1,now,i;
	dui[1]=1;mark[1]=1;dist[1]=0;
	while(tou<=wei)
	{
		now=dui[tou];tou++;
		i=LAST[now];
		while(i>0)
		{
			if(dist[now]+V[i]<dist[TO[i]])
			{
				dist[TO[i]]=dist[now]+V[i];
				if(!mark[TO[i]])   {mark[TO[i]]=1;dui[++wei]=TO[i];}
			}
			i=PRE[i];
		}
		mark[now]=0;
	}
}
void dfs(int x)
{
	int i=LAST[x];
	mark[x]=1;
	while(i>0)
	{
		if(!mark[TO[i]] && dist[x]+V[i]==dist[TO[i]])
		{
			Ins(x,TO[i],V[i]);
			Ins(TO[i],x,V[i]);
			dfs(TO[i]);
		}
		i=PRE[i];
	}
}
void getroot(int x,int fa)
{
	int i=last[x];
	size[x]=1;f[x]=0;
	while(i>0)
	{
		if(!mark[to[i]] && to[i]!=fa)
		{
			getroot(to[i],x);
			f[x]=max(f[x],size[to[i]]);
			size[x]+=size[to[i]];
		}
		i=pre[i];
	}
	f[x]=max(f[x],sum-size[x]);
	if(f[x]<f[root])  root=x;
}
void getsize(int x,int fa)
{
	int i=last[x];
	size[x]=1;
	while(i>0)
	{
		if(!mark[to[i]] && to[i]!=fa)
		{
			getsize(to[i],x);
			size[x]+=size[to[i]];
		}
		i=pre[i];
	}
}
void checkans(int a,int b)
{
	if(a>ans)  {ans=a;ansgs=b;}  
	else
	if(a==ans)  ansgs+=b;
}
void dfsans(int x,int fa)
{
	int i=last[x];
	if(deep[x]+1==k)  checkans(d[x],1);  
	if(deep[x]+1<k && hash[k-1-deep[x]]!=-1)  checkans(d[x]+hash[k-1-deep[x]],gs[k-1-deep[x]]);   
	while(i>0)
	{
		if(!mark[to[i]] && to[i]!=fa)
		{
			deep[to[i]]=deep[x]+1;d[to[i]]=d[x]+v[i];
			dfsans(to[i],x);
	    }
		i=pre[i];
	} 
}
void dfshash(int x,int fa)
{
	int i=last[x];  
	if(deep[x]<k-1) 
	{
		if(hash[deep[x]]==-1)  
		{hash[deep[x]]=d[x];gs[deep[x]]=1;stack[++top]=deep[x];}
		else  
		{
			if(hash[deep[x]]<d[x])  {hash[deep[x]]=d[x];gs[deep[x]]=1;}  
			else
			if(hash[deep[x]]==d[x])  gs[deep[x]]++;
		}
	}   
	while(i>0)
	{
		if(!mark[to[i]] && to[i]!=fa)  dfshash(to[i],x);
		i=pre[i];
	} 
}
void calc(int x)
{
	int i=last[x];
	top=0;
	while(i>0)
	{
		if(!mark[to[i]])
		{
			d[to[i]]=v[i];
			deep[to[i]]=1;
			dfsans(to[i],x);
			dfshash(to[i],x);
		}
		i=pre[i];
	}
	while(top>0)  {hash[stack[top]]=-1;top--;}
}
void work(int x)
{
	calc(x);
	mark[x]=1;
	int i=last[x];
	while(i>0)
	{
		if(!mark[to[i]])
		{
			getsize(to[i],x);
			sum=size[to[i]];
			f[0]=sum;root=0;
			getroot(to[i],x);
			work(root);
		}
		i=pre[i];
	}
}
int main()
{
    int i,j,a,b,c;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		lu[++tot].qi=a;lu[tot].zhong=b;lu[tot].v=c;
		lu[++tot].qi=b;lu[tot].zhong=a;lu[tot].v=c;
	}
	sort(lu+1,lu+1+tot,comp);
	for(i=1;i<=tot;i++)  
	INS(lu[i].qi,lu[i].zhong,lu[i].v);	
	spfa();
	memset(mark,0,sizeof(mark));	
	dfs(1);	 
	f[0]=n;root=0;sum=n;
	getroot(1,0);
	memset(hash,-1,sizeof(hash));
	memset(mark,0,sizeof(mark));
	work(root);
	printf("%d %d\n",ans,ansgs);
	system("pause");
	return 0;
}
