#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x7fffffff;
int n,m,tt,A[200010],B[200010],C[200010],tag[200010];
int dist[4010],fa[4010][13],deep[4010],pl[4010],belong[4010],size[4010];
int sz,to[200010],pre[200010],v[200010],id[200010],last[4010];
bool type[200010],mark[4010];
void Ins(int a,int b,int c,int i)
{
	sz++;to[sz]=b;v[sz]=c;id[sz]=i;pre[sz]=last[a];last[a]=sz;
}
void dfs1(int x)
{
	size[x]=1;
	for(int i=1;i<=12;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=last[x];i;i=pre[i])
	{
		if(to[i]==fa[x][0]) continue;
		fa[to[i]][0]=x;
		deep[to[i]]=deep[x]+1;
		dist[to[i]]=dist[x]+v[i];
		dfs1(to[i]);
		size[x]+=size[to[i]];
	}
}
void dfs2(int x,int chain)
{
    pl[x]=++tt;belong[x]=chain;
    int i,k=0,maxx=0;
    for(i=last[x];i;i=pre[i]) 
    {
		if(to[i]==fa[x][0]) continue;
		if(maxx<size[to[i]]) {maxx=size[to[i]];k=to[i];}
	}
	if(!k) return;
	dfs2(k,chain);
	for(i=last[x];i;i=pre[i])
	{
		if(to[i]==fa[x][0] || to[i]==k) continue;
		dfs2(to[i],to[i]);
	}
}
inline void swap(int &a,int &b)
{
	int t=a;a=b;b=t;
}
int LCA(int a,int b)
{
	if(deep[a]<deep[b]) swap(a,b);
	int c=deep[a]-deep[b],i;
	for(i=12;i>=0;i--) if(c>=(1<<i)) {c-=(1<<i);a=fa[a][i];}
	for(i=12;i>=0;i--) if(fa[a][i]!=fa[b][i]) {a=fa[a][i];b=fa[b][i];}
	if(a==b) return a; return fa[a][0];
}
void updata(int k,int l,int r,int zuo,int you,int z)
{
	if(l>=zuo && r<=you) 
	{
		if(tag[k]>z) tag[k]=z;
		return;
	}
	int mid=(l+r)>>1;
	if(zuo<=mid) updata(k<<1,l,mid,zuo,you,z);
	if(you>mid) updata(k<<1|1,mid+1,r,zuo,you,z);
}
int ask(int k,int l,int r,int w)
{
	if(l==r) return tag[k];
	int mid=(l+r)>>1;
	if(w<=mid) return min(ask(k<<1,l,mid,w),tag[k]);
	else return min(ask(k<<1|1,mid+1,r,w),tag[k]);
}
void domax(int a,int b,int z)
{
	int x,l,r;
	while(belong[a]!=belong[b])
	{
		x=belong[a];l=pl[x];r=pl[a];
		if(l<=r) updata(1,1,n,l,r,z);
		a=fa[x][0];
	}
	l=pl[b]+1;r=pl[a];
	if(l<=r) updata(1,1,n,l,r,z);
}
void solve(int x,int y,int z)
{
	int c=LCA(x,y);
	domax(y,c,dist[x]+z+dist[y]);
}
int main()
{
	int i,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&A[i],&B[i],&C[i],&type[i]);
		if(type[i]) 
		{
			Ins(A[i],B[i],C[i],i);Ins(B[i],A[i],C[i],i);
		}
	}
	dfs1(1);			
	dfs2(1,1);	
	for(i=1;i<=n*5;i++) tag[i]=INF;
	for(i=1;i<=m;i++)
	if(!type[i])
	{
		solve(A[i],B[i],C[i]);
		solve(B[i],A[i],C[i]);
	}
	for(i=2;i<=n;i++)
	{
		k=ask(1,1,n,pl[i]);
		if(k==INF) printf("-1 ");
		else printf("%d ",k-dist[i]);
	}
	printf("\n");
	return 0;
}
