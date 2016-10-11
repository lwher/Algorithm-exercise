#include<iostream>
#include<stdio.h>
#include<cmath>
#define eps 1e-8
using namespace std;
struct sth
{
	double x1,y1,y2;
}xd[30];
struct xxx
{
	double xx,yy,x,y;
}zx[60];
double sx[30],sy[30];
int n;
int sz; 
bool q;
double ans;
void jiaodian(double a,double b,double c,double d)
{
    double k;
    double s1,s2;
    double a1,a2;
	bool o=0;
    int i,j;
    for(i=1;i<=n;i++)
    {
	   if(((xd[i].x1-c)*(b-d)-(xd[i].y1-d)*(a-c))*((xd[i].x1-c)*(b-d)-(xd[i].y2-d)*(a-c))>eps)
	   {o=1;j=i;break;}
	}
	if(!o)  {q=1;return;}
	if(j==1) return;
    if(((zx[j*2-1].xx-c)*(b-d)-(zx[j*2-1].yy-d)*(a-c))*((zx[j*2-1].x-c)*(b-d)-(zx[j*2-1].y-d)*(a-c))<eps)
	{
	   s1=(c-zx[j*2-1].x)*(zx[j*2-1].yy-zx[j*2-1].y)-(zx[j*2-1].xx-zx[j*2-1].x)*(d-zx[j*2-1].y);
	   s2=(zx[j*2-1].xx-zx[j*2-1].x)*(b-zx[j*2-1].y)-(a-zx[j*2-1].x)*(zx[j*2-1].yy-zx[j*2-1].y);
	   k=s1/(s1+s2);
	   a1=c+(a-c)*k;
	   if(a1-ans>eps)  ans=a1;
	}
	if(((zx[j*2-2].xx-c)*(b-d)-(zx[j*2-2].yy-d)*(a-c))*((zx[j*2-2].x-c)*(b-d)-(zx[j*2-2].y-d)*(a-c))<eps)
	{
	   s1=(c-zx[j*2-2].x)*(zx[j*2-2].yy-zx[j*2-2].y)-(zx[j*2-2].xx-zx[j*2-2].x)*(d-zx[j*2-2].y);
	   s2=(zx[j*2-2].xx-zx[j*2-2].x)*(b-zx[j*2-2].y)-(a-zx[j*2-2].x)*(zx[j*2-2].yy-zx[j*2-2].y);
	   k=s1/(s1+s2);
	   a2=c+(a-c)*k;
	   if(a2-ans>eps)  ans=a2;
	
    }
}
int main()
{
	int i,j;
	while(scanf("%d",&n))
	{
		if(n==0)  break;
		sz=1;q=0;
		scanf("%lf%lf",&sx[1],&sy[1]);
		xd[1].x1=sx[1];
		xd[1].y1=sy[1];
		xd[1].y2=sy[1]-1;
		for(i=2;i<=n;i++)
		{
		  scanf("%lf%lf",&sx[i],&sy[i]);
		   xd[i].x1=sx[i];
		   xd[i].y1=sy[i];
		   xd[i].y2=sy[i]-1;
		   sz++;
		   zx[sz].x=sx[i-1]; zx[sz].y=sy[i-1]; zx[sz].xx=sx[i]; zx[sz].yy=sy[i];
		   sz++;
		   zx[sz].x=sx[i-1]; zx[sz].y=sy[i-1]-1; zx[sz].xx=sx[i]; zx[sz].yy=sy[i]-1;
		}
		if(n<3)  q=1;
		ans=-1000000;
		for(i=1;i<=n-1;i++)
		{
         if(q) break;
          for(j=i+1;j<=n;j++)
		{
		  jiaodian(sx[i],sy[i]-1,sx[j],sy[j]);
		  if(q) break;
		  jiaodian(sx[i],sy[i],sx[j],sy[j]-1);
		  if(q) break;		
        }
        }
		if(q)
		printf("Through all the pipe.\n");
		else
		printf("%.2lf\n",ans);
	}
	system("pause");
	return 0;
}
