#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#define inf 0x7fffffff
#define N 100010
using namespace std;
struct data{int d,now;}x,y,q[10*N];
int n,m,s,t,k,d[2010],vis[2010],cnt,nk,ans[2100];
int sz,to[N],ne[N],v[N],head[N];
int sz1,to1[N],ne1[N],v1[N],head1[N];
bool mark[1010];
void ins(int a,int b,int c)
{
     to[++sz]=b;ne[sz]=head[a];head[a]=sz;v[sz]=c;
	 to1[++sz1]=a;ne1[sz1]=head1[b];head1[b]=sz1;v1[sz1]=c;
}
void init()
{
	int i,a,b,c;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
	    scanf("%d%d%d",&a,&b,&c);
	    if(b>a)swap(a,b);
		ins(a,b,c);
	}
	s=n,t=1;
	if(s==t)k++;
}

void down(int x)
{
	int ne;
	while((x<<1)<=cnt)
	{
		ne=x<<1;
		if(ne<cnt&&q[ne].d>q[ne+1].d)ne++;
		if(q[ne].d>q[x].d)break;
		swap(q[ne],q[x]);
		x=ne;
	}
}
data get()
{
	data t=q[1];q[1]=q[cnt];
	cnt--;down(1);
	return t;
}
void push(data t)
{
    q[++cnt]=t;
	int now=cnt,ne;
	while(now>1)
	{
	   ne=now>>1;
	   if(q[ne].d<q[now].d)break;
	   swap(q[ne],q[now]);
	   now=ne;
    }
}

void DJ()
{
	int now;
	for(int i=1;i<=n;i++)d[i]=1e9;
	d[t]=0;
	x.d=0;x.now=t;
	q[++cnt]=x;
	while(cnt)
	{
		x=get();
		if(!mark[x.now])
		{
			mark[x.now]=1;
			now=x.now;
			for(int i=head1[now];i;i=ne1[i])
			 if(!mark[to1[i]]&&d[to1[i]]>d[now]+v1[i])
			 {
			 	d[to1[i]]=d[now]+v1[i];
			 	y.now=to1[i],y.d=d[to1[i]];
			 	push(y);
			 }
		}
	}
}
void Astar()
{
	int now;
	cnt=0;
	if(d[s]==1e9)return ;
	x.now=s,x.d=d[s];
	push(x);
	while(cnt)
	{
	    x=get();
		vis[x.now]++;
		if(x.now==t&&vis[t]==nk+1){nk++;ans[nk]=x.d;}
		//if(nk==k)return;
		now=x.now;
		if(vis[now]<=k)
		for(int i=head[now];i;i=ne[i])
		{
		     y.d=x.d-d[now]+d[to[i]]+v[i];
		     y.now=to[i];
		     push(y);
		 }
	}
	return ;
}
int main()
{
	init();
        DJ();
        Astar();
	for(int i=1;i<=k;i++)
	 if(ans[i])printf("%d\n",ans[i]);
	 else printf("-1\n"); 
	//system("pause");
	return 0;
}