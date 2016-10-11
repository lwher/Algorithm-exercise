#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define N 10010
using namespace std;
int n,m;
int sz;
int to1[N],pre1[N],last1[N];
int to2[N],pre2[N],last2[N];
int ys[2][N];
int zb[N],wei[N];
int men[2][N];
bool mark[N];
int num[N],fenliang[N];
void Ins(int a,int b)
{
	sz++;
	to1[sz]=b;pre1[sz]=last1[a];last1[a]=sz;
	to2[sz]=a;pre2[sz]=last2[b];last2[b]=sz;
}
void dfs1(int x)
{
	mark[x]=1;  int i=last1[x];
	while(i>0)
	{
		if(!mark[to1[i]])   dfs1(to1[i]);
	    i=pre1[i];
	}
	num[0]++;
	num[num[0]]=x;
}
void dfs2(int x)
{
	mark[x]=1;
	int i=last2[x];
	while(i>0)
	{
		if(!mark[to2[i]])
		{fenliang[to2[i]]=fenliang[x];dfs2(to2[i]);}
		i=pre2[i];
	}
}
bool check(int x)
{
	int i,siz;
	int a,b;
	sz=0;
	memset(last1,0,sizeof(last1));
	memset(last2,0,sizeof(last2));
	for(i=1;i<=x;i++)
	{
		a=2*n-1+i*2-1;
		b=men[0][i];
		Ins(a,b);
		b=ys[1-wei[b]][zb[b]];
		Ins(b,a+1);
		a=2*n-1+i*2;
		b=men[1][i];
		Ins(a,b);
		b=ys[1-wei[b]][zb[b]];
		Ins(b,a-1);
	}
	num[0]=0;
	memset(mark,0,sizeof(mark));
	for(i=0;i<=2*n+2*x-1;i++)
	{if(!mark[i]) dfs1(i);}
	siz=0;
	memset(mark,0,sizeof(mark));
	for(i=num[0];i>=1;i--)
	{
		if(!mark[num[i]])
		{siz++;fenliang[num[i]]=siz;dfs2(num[i]);}
	}
	for(i=1;i<=n;i++)
	{
		a=ys[0][i];b=ys[1][i];
		if(fenliang[a]==fenliang[b])
		return 0;
	}
	return 1;
}
void solve()
{
	int l,r,mid;
	l=0;r=m;
	while(l<r)
	{
		if(l+1==r)  break;
		mid=(l+r)>>1;
		if(check(mid))   l=mid;
		else  r=mid;
	}
	if(check(r))  
	cout<<r<<endl;
	else
	cout<<l<<endl;
}
int main()
{
	int i,j;
	int a,b;
	while(scanf("%d%d",&n,&m) && n && m)
	{
		for(i=1;i<=n;i++)
		{
		   scanf("%d%d",&a,&b);
		   ys[0][i]=a;ys[1][i]=b;
		   zb[a]=i;zb[b]=i;wei[a]=0;wei[b]=1;
	    }
	    for(i=1;i<=m;i++)
	    {
			scanf("%d%d",&a,&b);
			men[0][i]=a;men[1][i]=b;
		}		
		solve();
	}
	//system("pause");
	return 0;
}

