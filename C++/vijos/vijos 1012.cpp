#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 1e40
using namespace std;
struct point
{
       double x,y;
}p[100010],np[100010];
int n,top;
double dist(point a,point b) {return  sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
inline double min(double a,double b) {if(a<b) return a; return b;}
inline bool comp(point a,point b)  {if(a.x==b.x) return a.y<b.y; return a.x<b.x;}
inline bool cmp(point a,point b)  {return a.y<b.y;}
double getmindist(int l,int r)
{
    if(l>r || l==r)  return INF;
    if(l+1==r)  return dist(p[l],p[r]);
    int mid=(l+r)>>1;
    double mindist=min(getmindist(l,mid),getmindist(mid,r));
    int i,j;top=0;
    for(i=l;i<=r;i++)  if(fabs(p[i].x-p[mid].x)<mindist)  np[++top]=p[i];
    sort(np+1,np+1+top,cmp);
    for(i=1;i<=top;i++)  for(j=i+1;j<=top;j++)
    {
        if(np[j].y-np[i].y>mindist)  break;
        mindist=min(mindist,dist(np[i],np[j]));
    }
    return mindist;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)  scanf("%lf%lf",&p[i].x,&p[i].y);
    sort(p+1,p+1+n,comp);
    printf("%.3lf\n",getmindist(1,n));
    system("pause");
    return 0;
}
