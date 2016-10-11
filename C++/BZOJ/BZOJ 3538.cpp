#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define inf 0x7fffffff
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct data{int to,next,v1,v2;}e[50005],ed[50005];
int head[10005],h[10005],q[10005],d1[10005],d2[10005],dis[10005];
bool inq[10005];
int n,k,cnt;
int u[50005],v[50005],w1[50005],w2[50005];
void ins(int u,int v,int w1,int w2)
{e[++cnt].next=head[u];head[u]=cnt;e[cnt].to=v;e[cnt].v1=w1;e[cnt].v2=w2;}
void spfa1()
{
	memset(d1,127/3,sizeof(d1));
	int t=0,w=1;
	q[0]=n;inq[n]=1;d1[n]=0;
	while(t!=w)
	{
		int now=q[t];t++;if(t==10001)t=0;
		for(int i=head[now];i;i=e[i].next)
			if(e[i].v1+d1[now]<d1[e[i].to])
		    {
		    	d1[e[i].to]=e[i].v1+d1[now];
		    	if(!inq[e[i].to])
				    {q[w++]=e[i].to;inq[e[i].to]=1;if(w==10001)w=0;}
		    }
		inq[now]=0;
	}
}
void spfa2()
{
	memset(d2,127/3,sizeof(d2));
	int t=0,w=1;
	q[0]=n;inq[n]=1;d2[n]=0;
	while(t!=w)
	{
		int now=q[t];t++;if(t==10001)t=0;
		for(int i=head[now];i;i=e[i].next)
			if(e[i].v2+d2[now]<d2[e[i].to])
		    {
		    	d2[e[i].to]=e[i].v2+d2[now];
		    	if(!inq[e[i].to])
				    {q[w++]=e[i].to;inq[e[i].to]=1;if(w==10001)w=0;}
		    }
		inq[now]=0;
	}
}
void spfa3()
{
	memset(dis,127/3,sizeof(dis));
	int t=0,w=1;
	q[0]=1;inq[1]=1;dis[1]=0;
	while(t!=w)
	{
		int now=q[t];t++;if(t==10001)t=0;
		for(int i=h[now];i;i=ed[i].next)
		if(ed[i].v1+dis[now]<dis[ed[i].to])
		    {
		    	dis[ed[i].to]=ed[i].v1+dis[now];
		    	if(!inq[ed[i].to])
				    {q[w++]=ed[i].to;inq[ed[i].to]=1;if(w==10001)w=0;}
		    }
		inq[now]=0;
	}
}
int main()
{
	n=read(),k=read();
	for(int i=1;i<=k;i++)
	{
		u[i]=read();v[i]=read();w1[i]=read();w2[i]=read();
		ins(v[i],u[i],w1[i],w2[i]);
	}
	spfa1();spfa2();
	for(int i=1;i<=k;i++)
	{
    	ed[i].to=v[i];ed[i].next=h[u[i]];h[u[i]]=i;
    	if(d1[v[i]]+w1[i]>d1[u[i]])ed[i].v1++;
    	if(d2[v[i]]+w2[i]>d2[u[i]])ed[i].v1++;
    }
	spfa3();
	printf("%d\n",dis[n]);
	system("pause");
	return 0;
}
