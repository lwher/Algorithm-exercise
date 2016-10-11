#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
struct point
{
    int x,y;
}p[1510];
struct line
{
    int x,y;
    long long len;
    point p1,p2;
}xd[2250010];
long long sqr(long long x)
{
    return x*x;
}
inline bool comp(line a,line b)
{
    if(a.x==b.x && a.y==b.y) return a.len<b.len;
    if(a.x==b.x)  return a.y<b.y;  
    return a.x<b.x;
}
int n,sz;
long long ans;
int main()
{
    int i,j;long long tmp;
    point a,b,c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d%d",&p[i].x,&p[i].y);
    for(i=1;i<=n;i++)  for(j=i+1;j<=n;j++)
    {
        ++sz;
        xd[sz].p1=p[i];xd[sz].p2=p[j];xd[sz].len=sqr(p[i].x-p[j].x)+sqr(p[i].y-p[j].y);
        xd[sz].x=p[i].x+p[j].x;xd[sz].y=p[i].y+p[j].y;
    }
    sort(xd+1,xd+1+sz,comp);
    for(i=1;i<=sz;i++)
    for(j=i+1;j<=sz;j++)
    {
        if(xd[j].x!=xd[i].x || xd[j].y!=xd[i].y || xd[j].len!=xd[i].len)  break;
        a=xd[i].p1;b=xd[j].p2;c=xd[j].p1;
        tmp=((long long)(b.x-a.x)*(c.y-a.y)-(long long)(b.y-a.y)*(c.x-a.x));
        if(tmp<0)  tmp=-tmp;
        if(tmp>ans) ans=tmp;
    }
    cout<<ans<<endl;
    return 0;
}