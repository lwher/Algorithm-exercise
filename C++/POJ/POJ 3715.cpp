#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,sum,now,ans[210];
int sz,to[30010],pre[30010],last[210];
int color[210],pipei[210];
bool del[210],d[210];
void swap(int &a,int &b)  {int t=a;a=b;b=t;}
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
bool find(int x)
{
	int i=last[x];
	while(i>0)
	{
		if(!d[to[i]] && !del[to[i]])
		{
			d[to[i]]=1;
			if(pipei[to[i]]==-1 || find(pipei[to[i]]))
			{
				pipei[to[i]]=x;return 1;
			}
		}
		i=pre[i];
	}
	return 0;
}
int main()
{
	int i,j,a,b,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)  scanf("%d",&color[i]);
		sz=0;memset(last,0,sizeof(last));
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			a++;b++;
			if(color[a]!=color[b])
			{
				if(color[b]==1)  swap(a,b);
				Ins(a,b);
			}
		}
		memset(del,0,sizeof(del));		
		sum=0;memset(pipei,-1,sizeof(pipei));
		for(i=1;i<=n;i++)
		if(color[i]==1)
		{
		    memset(d,0,sizeof(d));
		    if(find(i))  sum++;
		}
		now=sum;
		for(i=1;i<=n;i++)
		{
			del[i]=1;
			memset(pipei,-1,sizeof(pipei));
			sum=0;
			for(j=1;j<=n;j++)
			if(!del[j] && color[j]==1)
			{
				memset(d,0,sizeof(d));
				if(find(j))  sum++;
			}
			if(sum==now)  del[i]=0;
			now=sum;
		}
		ans[0]=0;
		for(i=1;i<=n;i++)   if(del[i])  ans[++ans[0]]=i-1;
		for(i=0;i<ans[0];i++)  printf("%d ",ans[i]);   printf("%d\n",ans[ans[0]]);		
	}
	//system("pause");
	return 0;
}