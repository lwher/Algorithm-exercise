#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n,p;
int sz,to[300010],pre[300010],last[510];
int d[510],fa[510];
int ans=1e8;
bool mark[510],check[510];
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void build(int x)
{
	if(mark[x]) return;
	int i=last[x];mark[x]=1;
	while(i>0)
	{
		if(!mark[to[i]])
		{
			fa[to[i]]=x;d[to[i]]=d[x]+1;
			build(to[i]);
		}
		i=pre[i];
    }
}
void init()
{
	int a,b,i;
	scanf("%d%d",&n,&p);
	for(i=1;i<=p;i++)  
	{
		scanf("%d%d",&a,&b);Ins(a,b);Ins(b,a);
	}
}
void dfs(int c,int now)
{
	bool ok=1;
	int i,j;
	if(now>ans)  return;
	for(i=1;i<=n;i++)
	if(d[i]==c && check[i])
	{
		j=last[i];
		while(j>0)
		{
			if(fa[to[j]]==i)
			{
				ok=0;check[to[j]]=1;now++;
			}
			j=pre[j];
		}
	 }
		now--;
		for(i=1;i<=n;i++)
		if(d[i]==c+1 && check[i])
		{
			check[i]=0;
			dfs(c+1,now);
			check[i]=1;
		}
		now++;
		for(i=1;i<=n;i++)
    	if(d[i]==c && check[i])
    	{
		   j=last[i];
		   while(j>0)
		   {
			  if(fa[to[j]]==i)
			  {
				check[to[j]]=0;now--;
			  }
		   	  j=pre[j];
		    }
    	 }
	if(ok==1)
	if(now<ans)  ans=now;
}
void solve()
{
	init();
	d[1]=1;build(1);
	check[1]=1;
	dfs(1,1);
	cout<<ans<<endl;
}
int main()
{
	solve();
	//system("pause");
	return 0;
}
