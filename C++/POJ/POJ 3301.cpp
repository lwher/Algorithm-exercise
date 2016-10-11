#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
double x[35],y[35];
int n;
void init()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)  scanf("%lf%lf",&x[i],&y[i]);
}
double getans(double d)
{
	int i,j;
	double dist1=0,dist2=0;
	for(i=1;i<n;i++)  for(j=i+1;j<=n;j++)
	{
		dist1=max(dist1,fabs(cos(d)*(y[i]-y[j])-sin(d)*(x[i]-x[j])));
		dist2=max(dist2,fabs(sin(d)*(y[i]-y[j])+cos(d)*(x[i]-x[j])));
	}
	return max(dist1,dist2);
}
int main()
{
	int i,t;
	double ans,l,r,mid,a1,a2;
	scanf("%d",&t);
	while(t--)
	{
		init();
		l=0;r=asin(1.0);
		for(i=1;i<=50;i++)
		{
			a1=fabs(r-l)/3.00+l;
			a2=r-fabs(r-l)/3.00;
			if(getans(a1)>getans(a2))  l=a1;
			else r=a2;
		}
		ans=getans(l);
		ans=ans*ans;
		printf("%.2lf\n",ans);
	}
	//system("pause");
	return 0;
}

