#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define eps 1e-13
using namespace std;
struct point 
{
	double x,y;
}jd[20010];
struct line
{
	point p1,p2;double jijiao;
}bpm[20010];
int n,sz;
int dui[20010],tou,wei;
point read()
{
	point a;scanf("%lf%lf",&a.x,&a.y);return a;
}
void addline(point a,point b)
{
	sz++;bpm[sz].p1=a;bpm[sz].p2=b;
	bpm[sz].jijiao=atan2(a.y-b.y,a.x-b.x);
}
double chaji(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}
point jian(point a,point b)
{
	point c;c.x=a.x-b.x;c.y=a.y-b.y;return c;
}
double turnto(point a,point b,point c)
{
	return chaji(jian(b,a),jian(c,a));
}
inline bool comp(line a,line b)
{
	if(fabs(a.jijiao-b.jijiao)<eps)  
	{
		if(turnto(a.p1,a.p2,b.p1)<eps) return 0; else return 1;
	}
	return a.jijiao<b.jijiao;
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
void work()
{
	int i;tou=1,wei=1;line k;
	dui[1]=1;
	for(i=2;i<=n;i++)
	{
		if(fabs(bpm[i].jijiao-bpm[i-1].jijiao)<eps)  continue;
		k=bpm[i];
		while(tou<wei && turnto(k.p1,k.p2,jd[wei-1])>-eps)  wei--;
		while(tou<wei && turnto(k.p1,k.p2,jd[tou])>-eps)  tou++;
		dui[++wei]=i;jd[wei-1]=qiujiao(bpm[dui[wei-1]],k);
	}
	int l=-1,r=n+2;
	while(l<tou || r>wei)
	{
		l=tou;r=wei;
		k=bpm[dui[tou]];
		while(tou<wei && turnto(k.p1,k.p2,jd[wei-1])>-eps)  wei--;
		k=bpm[dui[wei]];
		while(tou<wei && turnto(k.p1,k.p2,jd[tou])>-eps)  tou++; 
	}
}
void init()
{
	int i;point a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		b=read();a=read();addline(a,b);
	}
	a.x=0;a.y=0;b.x=0;b.y=10000;addline(a,b);
	a.x=0;a.y=10000;b.x=10000;b.y=10000;addline(a,b);
	a.x=10000;a.y=10000;b.x=10000;b.y=0;addline(a,b);
	a.x=10000;a.y=0;b.x=0;b.y=0;addline(a,b);
	n=sz;sort(bpm+1,bpm+1+n,comp);
}
void getans()
{
	if(wei-tou+1<3) {printf("0.0\n");return;}
	dui[++wei]=dui[tou];jd[wei-1]=qiujiao(bpm[dui[wei]],bpm[dui[wei-1]]);
	int i;double ans=0;
	for(i=tou;i<wei-1;i++)  ans+=chaji(jd[i+1],jd[i]);
	ans+=chaji(jd[tou],jd[wei-1]);
	ans*=0.5;
	if(ans<0) ans=-ans;
	printf("%.1lf\n",ans);
}
int main()
{
	init();	
	work();
	getans();
	return 0;
}