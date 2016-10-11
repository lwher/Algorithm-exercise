#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int fa[30010],len[30010],before[30010];
int t,x,y,ans;
char ch[3];
int getfa(int x)
{
	if(fa[x]==0)  return x;
	getfa(fa[x]);
	before[x]+=before[fa[x]];
	if(fa[fa[x]]!=0)  fa[x]=fa[fa[x]];
	return fa[x];
}
int main()
{
	int i,j;
	scanf("%d",&t);
	for(i=1;i<=30000;i++) len[i]=1;
	while(t--)
	{
		scanf("%s%d%d",ch,&i,&j);
		if(ch[0]=='M')
		{
			x=getfa(i);y=getfa(j);
			if(x!=y) {
			fa[x]=y;
			before[x]=len[y];
			len[y]+=len[x];}
		}
		else
		{
			x=getfa(i);y=getfa(j);
			if(x!=y)  printf("-1\n");
			else 
			{ans=abs(before[i]-before[j])-1;printf("%d\n",ans);}
		}
	}
	//system("pause");
	return 0;
}
