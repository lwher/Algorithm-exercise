#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct sth
{
	int x,y;
}dian[51];
struct aaa
{
	int xz,xy,ys,yx;
	bool o;
}jx[5];
int n,k,ans=1e8;
bool in(aaa a,int xx,int yy)
{
	if(xx>=a.xz && xx<=a.xy && yy>=a.yx && yy<=a.ys)  return 1;
	else return 0;
}
bool jiao(aaa a,aaa b)
{
	if(in(b,a.xz,a.yx))  return 1;
	if(in(b,a.xz,a.ys))  return 1;
	if(in(b,a.xy,a.yx))  return 1;
	if(in(b,a.xy,a.ys))  return 1;
	return 0;
}
void dfs(int top)
{
	int i,j,s=0;
	aaa tmp;
	for(i=1;i<=k;i++)
	if(jx[i].o)
	{
		s+=(jx[i].xy-jx[i].xz)*(jx[i].ys-jx[i].yx);
		for(j=i+1;j<=k;j++)
		if(jx[j].o && jiao(jx[i],jx[j])) return;
	}
	if(s>=ans)  return;
	if(top>n)
	{
		ans=s;return;
	}
	for(i=1;i<=k;i++)
	{
		tmp=jx[i];
		if(!jx[i].o)  
		{
			jx[i].xz=dian[top].x;jx[i].xy=dian[top].x;
			jx[i].ys=dian[top].y;jx[i].yx=dian[top].y;
			jx[i].o=1;
		}
		else
		{
			jx[i].xz=min(jx[i].xz,dian[top].x);jx[i].xy=max(jx[i].xy,dian[top].x);
			jx[i].yx=min(jx[i].yx,dian[top].y);jx[i].ys=max(jx[i].ys,dian[top].y);
		}
		dfs(top+1);
		jx[i]=tmp;
		if(!tmp.o)  return;
	}
}
int main()
{
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)  scanf("%d%d",&dian[i].x,&dian[i].y);
	dfs(1);
	printf("%d\n",ans);
	//system("pause");
	return 0;
}
