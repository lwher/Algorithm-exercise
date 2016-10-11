#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct sth
{
	double x,y;
}dian[1100];
int X,Y;
int m;
int st;
double t;
double xx,yy;
double nx[31],ny[31],dis;
double diss[31];
double zx,zy,zdis;
double juli(double a,double b,sth c)
{
	return sqrt((a-c.x)*(a-c.x)+(b-c.y)*(b-c.y));
}
void getrand()
{
	int tt=time(NULL);
	srand(tt);
}
int main()
{
	int i,j,k;
	scanf("%d",&st);
	getrand();
	double d,now;
	while(st--)
	{
		scanf("%d%d%d",&X,&Y,&m);
		for(i=1;i<=m;i++)  scanf("%lf%lf",&dian[i].x,&dian[i].y);
		zdis=0;
		for(i=1;i<=30;i++)
		{
		nx[i]=rand()%(X+1);ny[i]=rand()%(Y+1);
		dis=INF;
		for(j=1;j<=m;j++)
		if(juli(nx[i],ny[i],dian[j])<dis)
	    dis=juli(nx[i],ny[i],dian[j]);
	    diss[i]=dis;
	    if(dis>zdis)
		{zx=nx[i];zy=ny[i];zdis=dis;}
	    }
	    t=max(X,Y)/5;
		while(t>0.01)
		{
			for(k=1;k<=30;k++)
			for(j=1;j<=30;j++)
			{
			d=rand();
			xx=nx[k]+cos(d)*t;
			yy=ny[k]+sin(d)*t;
			if(xx>=0 && yy>=0 && xx<=X && yy<=Y)
			{
			now=INF;
			for(i=1;i<=m;i++)
			if(juli(xx,yy,dian[i])<now)
	        now=juli(xx,yy,dian[i]);
	        if(diss[k]<now)
	        {nx[k]=xx;ny[k]=yy;diss[k]=now;}
			if(now>zdis)
			{zx=xx;zy=yy;zdis=now;}
		    }
		    }
			t*=0.9;
		}
		printf("The safest point is (%.1lf, %.1lf).\n",zx,zy);
	}
	//system("pause");
	return 0;
}

