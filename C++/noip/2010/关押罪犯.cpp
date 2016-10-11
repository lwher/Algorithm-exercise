#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
	int a,b;
	int v;
}sj[100010];
bool o;
int fa[50010],n,m;
inline bool comp(sth a,sth b)
{
	return a.v>b.v;
}
int getfa(int x)
{
	if(fa[x]==0)  return x;
	else return fa[x]=getfa(fa[x]);
}
int main()
{
	int x,y,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)  scanf("%d%d%d",&sj[i].a,&sj[i].b,&sj[i].v);
	sort(sj+1,sj+1+m,comp);
	for(i=1;i<=m;i++)
	{
		x=getfa(sj[i].a);y=getfa(sj[i].b);
		if(x==y) 
		{o=1;cout<<sj[i].v<<endl;break;}
		x=getfa(sj[i].a);y=getfa(sj[i].b+n);
		if(x!=y)  fa[x]=y;
		x=getfa(sj[i].a+n);y=getfa(sj[i].b);
		if(x!=y)  fa[x]=y;
	}
	if(!o)  cout<<0<<endl;
	//system("pause");
	return 0;
}
