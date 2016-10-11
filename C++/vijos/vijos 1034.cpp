#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int fa[5010];
int n,m,p;
int getfa(int x)
{
	if(fa[x]==0) return x;
	else return fa[x]=getfa(fa[x]);
}
int main()
{
	int i,x,y,a,b;
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		x=getfa(a);y=getfa(b);
		if(x!=y)  fa[x]=y;
	}
	for(i=1;i<=p;i++)
	{
		scanf("%d%d",&a,&b);
		x=getfa(a);y=getfa(b);
		if(x==y)  printf("Yes\n");
		else      printf("No\n");
	}
	//system("pause");
	return 0;
}
