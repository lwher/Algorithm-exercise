#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x[1010],y[1010],x1[1010],y1[1010],x2[1010],y2[1010],pipei[1010];
int ans,zm[1010],sz[1010];
bool map[1010][1010],d[1010];
bool find(int x)
{
	int i;
	for(i=n+1;i<=n+n;i++)
	{
		if(map[x][i] && !d[i])
		{
			d[i]=1;
			if(pipei[i]==-1 || find(pipei[i]))
			{
				pipei[i]=x;return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int i,j,a,b,now,tmp=0,p;
	while(scanf("%d",&n) && n)
	{
		for(i=1;i<=n;i++)  scanf("%d%d%d%d",&x1[i],&x2[i],&y1[i],&y2[i]);
		for(i=1;i<=n;i++)  scanf("%d%d",&x[i],&y[i]);
	    memset(map,0,sizeof(map));
	    for(i=1;i<=n;i++)  for(j=1;j<=n;j++)
		{
			if(x[j]>x1[i] && x[j]<x2[i] && y[j]>y1[i] && y[j]<y2[i])  map[j][i+n]=1;
		}  
		memset(pipei,-1,sizeof(pipei));
		for(i=1;i<=n;i++)  
		{
			memset(d,0,sizeof(d));  find(i);
		}
		ans=0;
		for(i=n+1;i<=n+n;i++)
		{
			p=pipei[i]; 
			if(p!=-1)
			{
				pipei[i]=-1;map[p][i]=0;
				memset(d,0,sizeof(d));
				if(!find(p))
				{
					pipei[i]=p;
					zm[++ans]=i-n-1;sz[ans]=p;
				}
				map[p][i]=1;
			}
		}
		printf("Heap %d\n",++tmp);
		if(ans==0)  printf("none\n");
		else
		{for(i=1;i<ans;i++)   printf("(%c,%d) ",'A'+zm[i],sz[i]); printf("(%c,%d)\n",'A'+zm[ans],sz[ans]);}  
		printf("\n");
	}
	//system("pause");
	return 0;
}