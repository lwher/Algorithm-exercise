#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
struct sth
{
	double x,y;
}dian[101];
double xx,yy;
int n;
double dis(double a,double b,sth c)
{
	return sqrt((a-c.x)*(a-c.x)+(b-c.y)*(b-c.y));
}
double getsum(double a,double b)
{
	double tmp=0;
	int i;
	for(i=1;i<=n;i++)
	tmp+=dis(a,b,dian[i]);
	return tmp;
}
double ans=1e20;
double t=10000;
int main()
{
//	freopen("in.in","r",stdin);
//	freopen("out.out","w",stdout);
	int i;
	while(scanf("%d",&n)!=EOF)
	{
	xx=0;yy=0;
	t=10000;
	ans=1e20;
	for(i=1;i<=n;i++)
	{
	    scanf("%lf%lf",&dian[i].x,&dian[i].y);
        xx+=dian[i].x;yy+=dian[i].y;
	}
	xx/=(n*1.00000);yy/=(n*1.00000);
	
	double tmp;
	double X,Y;
	while(t>0.02)
	{
		tmp=getsum(xx,yy);
		if(ans>tmp)  ans=tmp;
		X=0;Y=0;
		for(i=1;i<=n;i++)
		{
			X+=(dian[i].x-xx)/dis(xx,yy,dian[i]);
			Y+=(dian[i].y-yy)/dis(xx,yy,dian[i]);
		}
		xx+=X*t;
		yy+=Y*t;
		t*=0.5;
	}
	printf("%.0lf\n",ans);
    }
//	system("pause");
	return 0;
}

