#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<algorithm>
using namespace std;
struct point
{
	double x,y,z;
}p[50];
int n;
double sqr(double x)  {return x*x;}
double juli(point a,point b)
{
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z));
}
point getfarest(point a)
{
	point t=p[1];int i;
	for(i=2;i<=n;i++)  if(juli(a,p[i])>juli(t,a))  t=p[i];
	return t;
}
int main()
{
	int i;point now,far,tmp;
	double t,r,rr,k,ans;
	while(scanf("%d",&n) && n)
	{
		now.x=0;now.y=0;now.z=0;
		for(i=1;i<=n;i++) 
		{
			scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
		    now.x+=p[i].x;now.y+=p[i].y;now.z+=p[i].z;
		}
		now.x/=n;now.y/=n;now.z/=n;		
		t=100;ans=1e20;
		while(t>1e-8)
		{
			far=getfarest(now);
			r=juli(far,now);ans=min(ans,r);
			tmp.x=now.x+(far.x-now.x)/r*t;
			tmp.y=now.y+(far.y-now.y)/r*t;
			tmp.z=now.z+(far.z-now.z)/r*t;
			now=tmp;
			t*=0.98;
		}
		printf("%.5lf\n",ans);
	}
	return 0;
}