#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
	int x,y;
}p[1000010];
int n;
long double sx,sy,sxy,sxx,syy;
long double calc2(long double k,long double b)
{
	return (k*k*sxx+syy+n*b*b-2*k*sxy+2*k*b*sx-2*b*sy)/(k*k+1);
}
long double calc(long double k)
{
	long double l=-1e9,r=1e9,mid1,mid2,x1,x2;
	for(int i=1;i<=100;i++)
	{
		mid1=l+(r-l)/3.00;mid2=l+(r-l)/3.00*2.00;
		x1=calc2(k,mid1); x2=calc2(k,mid2);
		if(x1>x2)  l=mid1;  else r=mid2;
	}
	return calc2(k,l);
}
int main()
{
	int i,T,dd=0;
	int x,y,a,b,c;
	long double l,r,x1,x2,mid1,mid2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%d%d",&x,&y);
		scanf("%d%d%d",&a,&b,&c);
		p[1].x=x;p[1].y=y;
		for(i=2;i<=n;i++)  
		{
			p[i].x =(a*p[i-1].x*p[i-1].x+b*p[i-1].x+c)%107,
            p[i].y =(a*p[i-1].y*p[i-1].y+b*p[i-1].y+c)%107;
		}
		sx=0;sy=0;sxy=0;sxx=0;syy=0;
		for(i=1;i<=n;i++)
		{
		    sx+=p[i].x;
		    sy+=p[i].y;
		    sxx+=p[i].x*p[i].x;
		    syy+=p[i].y*p[i].y;
		    sxy+=p[i].x*p[i].y;
		}
		l=-1e9;r=1e9;
		for(i=1;i<=100;i++)
		{
			mid1=l+(r-l)/3.00;mid2=l+(r-l)/3.00*2.00;
			x1=calc(mid1); x2=calc(mid2);
			if(x1>x2)  l=mid1;  else r=mid2;
		}
		double ans=double(calc(l))*acos(-1)/n;
		printf("Case %d: %.5lf\n",++dd,ans);
	}
	system("pause");
	return 0;
}
