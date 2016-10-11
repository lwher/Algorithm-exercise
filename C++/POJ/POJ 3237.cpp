#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 100010
#define M 500010
#define INF 0x7fffffff
using namespace std;
int n,tot,deep[N],fa[N][18],quan[N],belong[N],pl[N],bpl[N],sum[N];
//bpl 该边对应的节点  quan 该点对应边 
int sz,to[N<<1],pre[N<<1],v[N<<1],bh[N<<1],last[N];
int minn[M],maxx[M];
bool mark[M];
int read()
{
	bool o=0;
	char ch=getchar();
	if(ch=='-')  o=1;
	while(!(ch>='0' && ch<='9'))  {ch=getchar();if(ch=='-') o=1;}
	int x=0;
	while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
	if(o) x=-x;
	return x;
}
void Ins(int a,int b,int c,int d)
{ 
	sz++;to[sz]=b;v[sz]=c;bh[sz]=d;pre[sz]=last[a];last[a]=sz; 
}
void swap(int &a,int &b)
{
	int t=a;a=b;b=t;
}
void dfs1(int x)
{
	 int i;sum[x]=1;
	 for(i=1;i<=17;i++)
	 {
			if(deep[x]<(1<<i))  break;
			fa[x][i]=fa[fa[x][i-1]][i-1];
	 }
	 i=last[x];
	 while(i>0)
	 {
			if(to[i]!=fa[x][0])
			{
				deep[to[i]]=deep[x]+1;
				fa[to[i]][0]=x;
				bpl[bh[i]]=to[i];
				quan[to[i]]=v[i];
				dfs1(to[i]);
				sum[x]+=sum[to[i]];
			}
			i=pre[i];
	 }
}
void dfs2(int x,int chain)
{
	tot++;belong[x]=chain;pl[x]=tot;
	int i=last[x],k=0;
	while(i>0)
	{
		if(to[i]!=fa[x][0])
		{
			if(sum[to[i]]>sum[k])  k=to[i];
		}
		i=pre[i];
	}
	if(k==0)  return;
	dfs2(k,chain);
	i=last[x];
	while(i>0)
	{
		if(to[i]!=fa[x][0] && to[i]!=k)  dfs2(to[i],to[i]);
		i=pre[i];
	}
}
void downgo(int k)
{
	mark[k+k]^=1;mark[k+k+1]^=1;
	swap(maxx[k+k],minn[k+k]);maxx[k+k]*=-1;minn[k+k]*=-1;
	swap(maxx[k+k+1],minn[k+k+1]);maxx[k+k+1]*=-1;minn[k+k+1]*=-1;
	mark[k]=0;
}
void updata(int k)
{
	maxx[k]=max(maxx[k+k],maxx[k+k+1]);
	minn[k]=min(minn[k+k],minn[k+k+1]);
}
void change(int k,int l,int r,int x,int num)
{
	if(l>r)  return;
	if(l==r) {maxx[k]=minn[k]=num;return;}
	int mid=(l+r)>>1;
	if(mark[k]) downgo(k);
	if(x<=mid)  change(k+k,l,mid,x,num);
	else  change(k+k+1,mid+1,r,x,num);
	updata(k);
}
void qufang(int k,int l,int r,int zuo,int you)
{
	if(l>r) return;
	if(l>=zuo && r<=you)
	{
		mark[k]^=1;swap(maxx[k],minn[k]);maxx[k]*=-1;minn[k]*=-1;
		return;
	}
	if(mark[k]) downgo(k);
	int mid=(l+r)>>1;
	if(zuo<=mid)  qufang(k+k,l,mid,zuo,you);
	if(you>mid)   qufang(k+k+1,mid+1,r,zuo,you);
	updata(k);
}
int ask(int k,int l,int r,int zuo,int you)
{
	if(l>r || l>you || r<zuo)  return -INF;
	if(l>=zuo && r<=you)  return maxx[k];
	if(mark[k]) downgo(k);
	int mid=(l+r)>>1;
	return max(ask(k+k,l,mid,zuo,you),ask(k+k+1,mid+1,r,zuo,you));
}
int LCA(int a,int b)
{
	int i,t;
	if(deep[a]<deep[b]) swap(a,b);
	t=deep[a]-deep[b];
	for(i=17;i>=0;i--)
	{
		if(t>=(1<<i))  {a=fa[a][i];t-=(1<<i);}
	}
	for(i=17;i>=0;i--)
	{
		if(deep[a]>=(1<<i) && fa[a][i]!=fa[b][i])  {a=fa[a][i];b=fa[b][i];}
	}
	if(a==b) return a; return fa[a][0];
}
void ljqf(int x,int f)
{
	int a,b;
	while(belong[x]!=belong[f])
	{
		a=pl[belong[x]];b=pl[x];
		qufang(1,1,n,a,b);
		x=fa[belong[x]][0];
	}
	a=pl[f]+1;b=pl[x];
	qufang(1,1,n,a,b);
}
int solvemax(int x,int f)
{
	int a,b,ans=-INF;
	while(belong[x]!=belong[f])
	{
		a=pl[belong[x]];b=pl[x];
		ans=max(ans,ask(1,1,n,a,b));
		x=fa[belong[x]][0];
	}
	a=pl[f]+1;b=pl[x];
	ans=max(ans,ask(1,1,n,a,b));
	return ans;
}
void solve()
{
	int i,a,b,c;char ch[10];
	for(i=1;i<=n;i++)
	{
		change(1,1,n,pl[i],quan[i]);
	}	
	while(scanf("%s",ch))
	{
		if(ch[0]=='D')  break;
		if(ch[0]=='C')
		{
			a=read();b=read();//scanf("%d%d",&a,&b);
			change(1,1,n,pl[bpl[a]],b);
		}  
		else
		if(ch[0]=='N')
		{
			a=read();b=read();//scanf("%d%d",&a,&b);
			c=LCA(a,b);
			ljqf(a,c);ljqf(b,c);
		}
		else
		{
			a=read();b=read();//scanf("%d%d",&a,&b);
			c=LCA(a,b);
			printf("%d\n",max(solvemax(a,c),solvemax(b,c)));
		}
	}
}
int main()
{
	int T;
    scanf("%d",&T);
    while(T--)
    {
        sz=0;tot=0;
        memset(last,0,sizeof(last)); 
        memset(mark,0,sizeof(mark));
        memset(deep,0,sizeof(deep));
        memset(fa,0,sizeof(fa));
    	int i,a,b,c;
    	n=read();//scanf("%d",&n);
    	for(i=1;i<n;i++)
    	{
    		a=read();b=read();c=read();//scanf("%d%d%d",&a,&b,&c);
    		Ins(a,b,c,i);Ins(b,a,c,i);
    	}
    	deep[1]=1;
    	dfs1(1);
    	dfs2(1,1);
    	solve();
    }
	//system("pause");
	return 0;
}
