#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define INF 0x7fffffff
using namespace std;
struct point
{
	double x,y;
}p[510],s,q1,q2;
struct line
{
	double l,r;
}xian[510],ans[510];
double r[510];
int n,xsz,asz;
double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void swap(double &x,double &y)
{
	double t=x;x=y;y=t;
}
double getx(point a,point b)
{
	double k,bb;
	if(fabs(a.x-b.x)<eps)  return a.x;
	k=(a.y-b.y)/(a.x-b.x);
	bb=a.y-k*a.x;
	return -bb/k;
}
inline bool comp(line a,line b)
{
	if(fabs(a.l-b.l)<eps)  return a.r>b.r;
	return a.l<b.l;
}
double max(double a,double b)
{
	if(a>b)  return a; else return b;
}
int main()
{
	int i;
	double B,op,x,y,ymax;
	while(scanf("%d",&n))
	{
		if(n==0)  break;
		scanf("%lf%lf",&s.x,&s.y);
		for(i=1;i<=n;i++)  scanf("%lf%lf%lf",&p[i].x,&p[i].y,&r[i]);		
		xsz=0;asz=0;
		for(i=1;i<=n;i++)
		if(fabs(r[i])>eps)
 		{
			op=dist(s,p[i]);
			B=acos(r[i]/op);
			x=s.x-p[i].x;y=s.y-p[i].y;
			x=x/op*r[i];y=y/op*r[i];
			q1.x=p[i].x+(x*cos(B)+y*sin(B));q1.y=p[i].y+(y*cos(B)-x*sin(B));
			q2.x=p[i].x+(x*cos(B)-y*sin(B));q2.y=p[i].y+(y*cos(B)+x*sin(B));
			xsz++;
			xian[xsz].l=getx(s,q2);xian[xsz].r=getx(s,q1);
			if(xian[xsz].l>xian[xsz].r)  swap(xian[xsz].l,xian[xsz].r);
		}
		sort(xian+1,xian+1+xsz,comp);
		ans[0].r=-INF;
		for(i=1;i<=xsz;i++)
		{
			if(xian[i].l>ans[asz].r+eps)  {ans[++asz].l=xian[i].l;ans[asz].r=xian[i].r;}
			else   ans[asz].r=max(ans[asz].r,xian[i].r);
		}
		for(i=1;i<=asz;i++)  printf("%.2lf %.2lf\n",ans[i].l,ans[i].r);
		printf("\n");
	}
	//system("pause");
	return 0;
}

