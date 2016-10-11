#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m;
int sz,to[310],pre[310],last[110],v[310],d[110];
bool mark[110];
void Ins(int a,int b,int c)
{
	sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
bool spfa(int x)
{
	int i=last[x];
	mark[x]=1;
	while(i>0)
	{
		if(d[x]+v[i]<d[to[i]])
		{
			if(mark[to[i]])  return 1;
			d[to[i]]=d[x]+v[i];
			if(spfa(to[i]))  return 1;
		}
		i=pre[i];
	}
	mark[x]=0;
	return 0;
}
int main()
{
	int a,b,c,i;
	char s[5];
	while(scanf("%d",&n) && n)
	{
		scanf("%d",&m);
		sz=0;
		memset(last,0,sizeof(last));
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			getchar();
			scanf("%s",s);
			scanf("%d",&c);
			if(s[0]=='g')
			{
				Ins(a+b,a-1,-c-1);
			}
			else
			{
				Ins(a-1,a+b,c-1);
			}
		}
		for(i=0;i<=n;i++)  Ins(n+1,i,0);
		memset(d,127,sizeof(d));
		memset(mark,0,sizeof(mark));
		d[n+1]=0;
		if(spfa(n+1))   printf("successful conspiracy\n");
		else  printf("lamentable kingdom\n");    
	}
	//system("pause");
	return 0;
}

