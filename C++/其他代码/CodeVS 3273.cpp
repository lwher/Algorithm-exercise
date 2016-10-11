#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define eps 1e-6
using namespace std;
struct sth
{
	double x,y,r;
}o[3];
double juli(sth a,sth b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void swap(sth &a,sth &b)  {sth t=a;a=b;b=t;}
double gets(sth a,sth b)
{
	double l=juli(a,b),d,h,ans=0;
	d=(a.r*a.r-b.r*b.r+l*l)/(2*l);
	double w=d/a.r;w=acos(w);
	ans+=a.r*w*a.r;
	h=sqrt(a.r*a.r-d*d);
	ans-=h*l;
	d=l-d;
	w=d/b.r;w=acos(w);
	ans+=b.r*b.r*w;
	return ans;
}
void solve()
{
	int i;	
	for(i=1;i<=2;i++)  scanf("%lf%lf%lf",&o[i].x,&o[i].y,&o[i].r);
	
	if(juli(o[1],o[2])>=o[1].r+o[2].r)  {printf("0.000\n");return;}
	if(o[1].r<o[2].r)   swap(o[1],o[2]);
	if(o[1].r-o[2].r>=juli(o[1],o[2]))  {printf("%.3lf\n",o[2].r*o[2].r*acos(-1));return;}	
	double s=gets(o[1],o[2]);
	printf("%.3lf\n",s);
}
int main()
{
	solve();
	return 0;
}