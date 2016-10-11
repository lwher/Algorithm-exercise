#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
int v[100010];
int sz,to[1000010],pre[1000010],last[100010];
int SZ,TO[1000010],PRE[1000010],LAST[100010];
int dmax[100010],dmin[100010],dui[1000010];
bool mark[100010];
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void INS(int a,int b)
{
	SZ++;TO[SZ]=b;PRE[SZ]=LAST[a];LAST[a]=SZ;
}
void spfa1()
{
	int tou=1,wei=1,i,now;
	memset(dmin,127,sizeof(dmin));
	dui[1]=1;dmin[1]=v[1];
	while(tou<=wei)
	{
		now=dui[tou];tou++;
		i=last[now];
		while(i>0)
	    {
			if(dmin[to[i]]>min(dmin[now],v[to[i]]))
			{
				dmin[to[i]]=min(dmin[now],v[to[i]]);
				if(!mark[to[i]]) {wei++;dui[wei]=to[i];mark[to[i]]=1;}
			}
			i=pre[i];
		}
		mark[now]=0;
	}
}
void spfa2()
{
	int tou=1,wei=1,i,now;
	memset(mark,0,sizeof(mark));
	memset(dmax,-1,sizeof(dmax));
	dui[1]=n;dmax[n]=v[n];
	while(tou<=wei)
	{
		now=dui[tou];tou++;
		i=LAST[now];
		while(i>0)
	    {
			if(dmax[TO[i]]<max(dmax[now],v[TO[i]]))
			{
				dmax[TO[i]]=max(dmax[now],v[TO[i]]);
				if(!mark[TO[i]]) {wei++;dui[wei]=TO[i];mark[TO[i]]=1;}
			}
			i=PRE[i];
		}
		mark[now]=0;
	}
}
void init()
{
	int i,a,b,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)  scanf("%d",&v[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&k);
		Ins(a,b);INS(b,a);
		if(k==2) {Ins(b,a);INS(a,b);}
	}
}
void solve()
{
	int i;
	init();
	spfa1();
	spfa2();
	int ans=0;
	for(i=1;i<=n;i++)
	{if(dmax[i]-dmin[i]>ans) ans=dmax[i]-dmin[i];}
	cout<<ans<<endl;
	
}
int main()
{
	solve();
	//system("pause");
	return 0;
}
