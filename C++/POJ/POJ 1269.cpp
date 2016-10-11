#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define eps 1e-8
using namespace std;
struct point
{
	double x,y;
};
struct line
{
	point p1,p2;
}xa,xb;
point jian(point a,point b)
{
	point c;c.x=a.x-b.x;c.y=a.y-b.y;return c;
}
double chaji(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}
bool online(line a,line b)
{
	if(fabs(chaji(jian(a.p2,a.p1),jian(b.p1,a.p1)))>eps)  return 0;
	if(fabs(chaji(jian(a.p2,a.p1),jian(b.p2,a.p1)))>eps)  return 0;
	return 1;
}
bool px(line a,line b)
{
	if(fabs(chaji(jian(a.p2,a.p1),jian(b.p2,b.p1)))<eps)  return 1;
	return 0;
}
point qiujiao(line a,line b)
{
	double k1,k2,k3;
	k1=chaji(jian(a.p2,a.p1),jian(b.p1,a.p1));
	k2=chaji(jian(b.p2,a.p1),jian(a.p2,a.p1));
	k3=k1/(k1+k2);
	point c;
	c.x=b.p1.x+(b.p2.x-b.p1.x)*k3;
	c.y=b.p1.y+(b.p2.y-b.p1.y)*k3;
	return c;
}
int main()
{
	int T;
	scanf("%d",&T);
	printf("INTERSECTING LINES OUTPUT\n");
	while(T--)
	{
		scanf("%lf%lf%lf%lf",&xa.p1.x,&xa.p1.y,&xa.p2.x,&xa.p2.y);
		scanf("%lf%lf%lf%lf",&xb.p1.x,&xb.p1.y,&xb.p2.x,&xb.p2.y);
		if(online(xa,xb))  printf("LINE\n");  else
		if(px(xa,xb))  printf("NONE\n");  else 
		{
			point ans=qiujiao(xa,xb);
			printf("POINT %.2lf %.2lf\n",ans.x,ans.y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}