#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int dfn[1010],low[1010],cnt[1010];
int sz,to[1000010],pre[1000010],last[1010];
int dmin,dmax,tt;
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void Tarjan(int x)
{
	int i=last[x],son=0;
	tt++;dfn[x]=tt;low[x]=tt;
	while(i>0)
	{
		if(dfn[to[i]]==0)  
		{
			son++;Tarjan(to[i]);low[x]=min(low[x],low[to[i]]);
			if((x!=dmin && low[to[i]]>=dfn[x]) || (x==dmin && son>1))  cnt[x]++;
		}
		else  low[x]=min(low[x],dfn[to[i]]);
		i=pre[i];
	}
}
int main()
{
	int a,b,i,T=0;
	bool o;
	while(cin>>a && a)
	{
		T++;
		
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(cnt,0,sizeof(cnt));
		memset(last,0,sizeof(last));
		cin>>b;
		dmin=min(a,b);dmax=max(a,b);
		Ins(a,b);Ins(b,a);
		while(cin>>a && a)
		{
			cin>>b;
			dmin=min(dmin,b);dmax=max(dmax,b);
			dmin=min(dmin,a);dmax=max(dmax,a);
			Ins(a,b);Ins(b,a);
		}
		tt=0;
		Tarjan(dmin);
		o=0;
		printf("Network #%d\n",T);
		for(i=dmin;i<=dmax;i++)
		if(cnt[i])
		{
			o=1;
			printf("  SPF node %d leaves %d subnets\n",i,cnt[i]+1);
		}
		if(!o) printf("  No SPF nodes\n");
		printf("\n");
	}
	//system("pause");
	return 0;
}

