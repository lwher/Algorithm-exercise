#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
	int d,bh;
}x,y;
struct cmp  
{  
    bool operator()(const node& a,const node& b)  
    {  
        return a.d>b.d;
    }  
}; 
int n,m,s,t,k,d[1010],vis[1010];
int sz,to[100010],pre[100010],v[100010],last[1010];
int sz1,to1[100010],pre1[100010],v1[100010],last1[1010];
bool mark[1010];
void Ins(int a,int b,int c)
{
	sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
	sz1++;to1[sz1]=a;pre1[sz1]=last1[b];v1[sz1]=c;last1[b]=sz1;
}
void init()
{
	int i,a,b,c;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		Ins(a,b,c);
	}
	scanf("%d%d%d",&s,&t,&k);
	if(s==t)  k++;
}
void Dijkstra()
{	
	int i,j,now;
	for(i=1;i<=n;i++) d[i]=1e9;
	d[t]=0;
	priority_queue<node,vector<node>,cmp> q;  
	x.d=0;x.bh=t;
	q.push(x);
	while(!q.empty())
	{
		x=q.top();
		q.pop();
		if(!mark[x.bh])
		{
			mark[x.bh]=1;
			now=x.bh;
			i=last1[now];
			while(i>0)
			{
				if(!mark[to1[i]] && d[to1[i]]>d[now]+v1[i])
				{
					d[to1[i]]=d[now]+v1[i];
					y.d=d[to1[i]];y.bh=to1[i];
					q.push(y);
				}
				i=pre1[i];
			}
		}
	}
}
int A_star()
{
	int now,i;
	priority_queue<node,vector<node>,cmp> q;
	if(d[s]==1e9)  return -1;
	x.d=d[s];x.bh=s;
	q.push(x);
	while(!q.empty())
	{
		x=q.top();
		q.pop();
		vis[x.bh]++;
		if(x.bh==t && vis[t]==k)  return x.d;
		now=x.bh;
		i=last[now];
		if(vis[now]<=k)
		{
		while(i>0)
		{
			y.d=x.d-d[now]+v[i]+d[to[i]];
			y.bh=to[i];
			q.push(y);
			i=pre[i];
		}
	    }
	}  
	return -1;
}
int main()
{
	init();
    Dijkstra();
	printf("%d\n",A_star());
	//system("pause");
	return 0;
}

