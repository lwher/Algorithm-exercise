#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define eps 1e-13
using namespace std;
struct sth
{
    double x,y,r;
}o[1010],tmp[1010];
inline bool comp(sth a,sth b)  {return a.x-a.r<b.x-b.r;}
struct line
{
    double l,r;
}p[1010];
inline bool cmp(line a,line b)  {return a.l<b.l;}
inline bool pbj(sth a,sth b)  {return a.r<b.r;}
int n,sz,top,st,ed;
double xl[1010],xr[1010],ans=0;
bool mark[1010];
double juli(sth a,sth b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void init()
{
    int i,j;scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%lf%lf%lf",&tmp[i].x,&tmp[i].y,&tmp[i].r);
    sort(tmp+1,tmp+1+n,pbj);
    for(i=1;i<=n;i++)  for(j=i+1;j<=n;j++)  if(tmp[j].r-tmp[i].r>=juli(tmp[i],tmp[j]))  {mark[i]=1;break;}
    for(i=1;i<=n;i++)  if(!mark[i])  o[++top]=tmp[i];
    n=top;
    sort(o+1,o+1+n,comp);
}
double getf(double w)
{
    int i,j,tmp=0;double dis,last,len=0,nr;
    sz=0;
    for(i=st;i<=ed;i++)
    {
        if(w<=xl[i] || w>=xr[i])  continue;
        dis=sqrt(o[i].r-(w-o[i].x)*(w-o[i].x));
        p[++sz].l=o[i].y-dis;p[sz].r=o[i].y+dis;
    }
    sort(p+1,p+1+sz,cmp);
    for(i=1;i<=sz;i++)
    {
        nr=p[i].r;
        for(j=i+1;j<=sz;j++)  
        {
            if(p[j].l>nr)  break;
            if(nr<p[j].r)  nr=p[j].r;
        }
        len+=nr-p[i].l;i=j-1;
    }
    return len;
}
double calc(double ba,double fl,double fr,double fmid)
{
    return (fl+fr+fmid*4)*ba/6.00;
}
double Simpson(double l,double mid,double r,double fl,double fmid,double fr,double ss)
{
    double m1=(l+mid)*0.5,m2=(mid+r)*0.5,fm1,fm2;
    fm1=getf(m1);fm2=getf(m2);
    double g1=calc(mid-l,fl,fmid,fm1),g2=calc(r-mid,fmid,fr,fm2);
    if(fabs(ss-g1-g2)<eps)  return g1+g2;
    return Simpson(l,m1,mid,fl,fm1,fmid,g1)+Simpson(mid,m2,r,fmid,fm2,fr,g2);
}
void work()
{
    int i,j;double l,r,mid,fl,fr,fmid;
    for(i=1;i<=n;i++)  {xl[i]=o[i].x-o[i].r;xr[i]=o[i].x+o[i].r;o[i].r*=o[i].r;}
    for(i=1;i<=n;i++)
    {
        l=xl[i];r=xr[i];
        for(j=i+1;j<=n;j++)
        {
            if(xl[j]>r)  break;
            if(xr[j]>r)  r=xr[j];
        }
        st=i;ed=j-1;i=j-1;
        mid=(l+r)*0.5;
        fl=getf(l);fr=getf(r);fmid=getf(mid);
        ans+=Simpson(l,mid,r,fl,fmid,fr,calc(r-l,fl,fr,fmid));
    }
}
int main()
{
    init();
    work();
    printf("%.3lf\n",ans);
    //system("pause");
    return 0;
}