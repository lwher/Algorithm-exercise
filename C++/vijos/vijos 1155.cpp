#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define eps 1e-6
using namespace std;
int n,m;
double x[210],y[210];
int sz,to[50010],pre[50010],last[210];
double v[50010];
double d[210];
int sum[210];
bool mark[210],vv[50010];
double juli(int a,int b)
{
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];v[sz]=
	juli(a,b);last[a]=sz;
	sz++;to[sz]=a;pre[sz]=last[b];v[sz]=juli(a,b);last[b]=sz;
}
void init()
{
	int i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)  scanf("%lf%lf",&x[i],&y[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		Ins(a,b);
	}
}
void dij(int qi)
{
	int i,j,now;
	double nmax;
	memset(mark,0,sizeof(mark));
	for(i=1;i<=n;i++)  d[i]=1e9;
	d[qi]=0;sum[qi]=1;
	for(i=1;i<=n;i++)
	{
		nmax=1e9;
		for(j=1;j<=n;j++)
		{
			if(!mark[j] && d[j]<nmax)
			{
				nmax=d[j];
				now=j;
			}
		}
		mark[now]=1;
		j=last[now];
		while(j>0)
		{
			if(vv[j]) {j=pre[j]; continue;}
			if(!mark[to[j]] && d[to[j]]>d[now]+v[j])
			{
				d[to[j]]=d[now]+v[j];
				sum[to[j]]=sum[now];
			}
			else
			if(!mark[to[j]] && fabs(d[to[j]]-d[now]-v[j])<eps)
			{
				sum[to[j]]+=sum[now];
			}
			j=pre[j];
		}
	}
}
void dij2(int qi)
{
	int i,j,now;
	double nmax;
	memset(mark,0,sizeof(mark));
	for(i=1;i<=n;i++)  d[i]=1e9;
	d[qi]=0;
	for(i=1;i<=n;i++)
	{
		nmax=1e9;
		for(j=1;j<=n;j++)
		{
			if(!mark[j] && d[j]<nmax)
			{
				nmax=d[j];
				now=j;
			}
		}
		mark[now]=1;
		j=last[now];
		while(j>0)
		{
			if(vv[j]) {j=pre[j]; continue;}
			if(!mark[to[j]] && d[to[j]]>d[now]+v[j])
			{
				d[to[j]]=d[now]+v[j];
			}
			j=pre[j];
		}
	}
}
double Min(double a,double b)
{
	if(a>b) return b; return a;
}
int main()
{
	init();
	dij(1);
	int i,j;
	double nans,ans;
	ans=d[n];nans=1e9;
	if(sum[n]>1) nans=ans;
	else
	{
		for(i=1;i<=n;i++)
		{
			j=last[i];
			while(j>0)
			if(fabs(d[i]+v[j]-d[to[j]])<eps)
			{
			vv[j]=1;
			dij2(1);
			if(d[n]>ans && d[n]<nans)  nans=d[n];
			vv[j]=0;
			j=pre[j];
		    }
		    else
		    j=pre[j];
		}
	}
	if(nans!=1e9)
	printf("%.2lf\n",nans);
	else
	printf("-1\n");
	//system("pause");
	return 0;
}
