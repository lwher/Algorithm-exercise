#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#define eps 1e-8
#define bj 1e10
using namespace std;
struct sth
{
       double x,y,xx,yy;
       double jijiao;
}bpm[510];
struct kkk
{
       double x,y;
}d[510],jd[510];
int n,sz,t,tou,wei,szjd;
int ans[510];double jx[510],jy[510];
double nx,ny;
void addline(kkk a,kkk b)
{
     sz++;
     bpm[sz].x=a.x;bpm[sz].y=a.y;bpm[sz].xx=b.x;bpm[sz].yy=b.y;
     bpm[sz].jijiao=atan2((b.y-a.y),(b.x-a.x));
}
double guaixiang(double a,double b,double c,double d,double e,double f)
{
       double q=e-a,w=f-b,r=c-a,u=d-b;
       return q*u-w*r;
}
double dc(double a,double b,double c,double d,double e,double f)
{
       double q=c-a,w=d-b,r=e-a,u=f-b;
       return q*r+w*u;
}
int check(double kt)
{
    if(kt>eps)        return 1;
    else  if(kt<-eps) return -1;
    else              return 0;
}
bool onseg(double a,double b,double c,double d,double e,double f)
{
     if(check(dc(a,b,c,d,e,f))<=0)  return 1;
     else return 0;
}
inline bool comp(sth a,sth b)
{
       if(fabs(a.jijiao-b.jijiao)<eps)  
       {
           if(guaixiang(a.x,a.y,a.xx,a.yy,b.x,b.y)>0)  return 0;
           else return 1;
       }
       return a.jijiao<b.jijiao;
}
void init()
{
     int i;sz=0;
     scanf("%d",&n);
     for(i=1;i<=n;i++)  scanf("%lf",&d[i].x);
     for(i=1;i<=n;i++)  scanf("%lf",&d[i].y);
     for(i=n;i>1;i--)   addline(d[i],d[i-1]);
     d[n+1].x=-bj;d[n+1].y=bj; d[n+2].x=bj;d[n+2].y=bj; d[n+3].x=bj;d[n+3].y=-bj;  d[n+4].x=-bj;d[n+4].y=-bj;
     addline(d[n+1],d[n+2]);addline(d[n+2],d[n+3]);addline(d[n+3],d[n+4]);addline(d[n+4],d[n+1]);
     sort(bpm+1,bpm+1+sz,comp);
}
void qiujiao(int pp)
{
     int kk;
     if(pp==wei)  kk=tou;
     else kk=pp+1;
     sth p=bpm[ans[pp]],k=bpm[ans[kk]];
     double a=p.x,b=p.y,c=p.xx,d=p.yy;
     double e=k.x,f=k.y,g=k.xx,h=k.yy;
     double k1,k2,k3;
     k1=(g-a)*(d-b)-(h-b)*(c-a);
     k2=(c-a)*(f-b)-(e-a)*(d-b);
     k3=k1/(k1+k2);
     jx[pp]=g+(e-g)*k3;
     jy[pp]=h+(f-h)*k3;
}
void work()
{
     int i;
     tou=1;wei=1;
     ans[1]=1;
     memset(jx,0,sizeof(jx));
     memset(jy,0,sizeof(jy));
     sth o;
     for(i=2;i<=sz;i++)
     {
          o=bpm[i];
          if(fabs(o.jijiao-bpm[i-1].jijiao)<eps)  continue;
          while(tou<wei && guaixiang(o.x,o.y,o.xx,o.yy,jx[wei-1],jy[wei-1])<-eps)  wei--;
          while(tou<wei && guaixiang(o.x,o.y,o.xx,o.yy,jx[tou],jy[tou])<-eps)      tou++;
          wei++;ans[wei]=i; qiujiao(wei-1);
     }
     int zuo=-1,you=1000000;
     while(zuo<tou || you>wei)
     {
          zuo=tou;you=wei;
          o=bpm[ans[tou]];
          while(tou<wei && guaixiang(o.x,o.y,o.xx,o.yy,jx[wei-1],jy[wei-1])<-eps)  wei--;
          o=bpm[ans[wei]];
          while(tou<wei && guaixiang(o.x,o.y,o.xx,o.yy,jx[tou],jy[tou])<-eps)      tou++;
     }
     qiujiao(wei);
     for(i=tou;i<=wei;i++)
     {szjd++;jd[szjd].x=jx[i];jd[szjd].y=jy[i];}
     szjd++;jd[szjd].x=jd[1].x;jd[szjd].y=jd[1].y;
}
void jiaodian(double a,double b,double c,double d,double e,double f,double g,double h)
{
     double k1,k2,k3;
     k1=(g-a)*(d-b)-(h-b)*(c-a);
     k2=(c-a)*(f-b)-(e-a)*(d-b);
     k3=k1/(k1+k2);
     nx=g+(e-g)*k3;
     ny=h+(f-h)*k3;
}
int main()
{
    int i,j;
    double nans=1e20;    
    init();     
    work();
    double tx,ty;
    for(i=1;i<=n;i++)
    {
       tx=d[i].x;ty=520.253;
       for(j=1;j<szjd;j++)
       {
       if(fabs(jd[j].x-jd[j+1].x)<eps)  continue;
       jiaodian(d[i].x,d[i].y,tx,ty,jd[j].x,jd[j].y,jd[j+1].x,jd[j+1].y);
       if(onseg(nx,ny,jd[j].x,jd[j].y,jd[j+1].x,jd[j+1].y))  {nans=min(nans,fabs(ny-d[i].y));}
       }
    }
    for(i=1;i<=szjd;i++)
    {
       tx=jd[i].x;ty=520.253;
       for(j=1;j<n;j++)
       {
       jiaodian(jd[i].x,jd[i].y,tx,ty,d[j].x,d[j].y,d[j+1].x,d[j+1].y);
       if(onseg(nx,ny,d[j].x,d[j].y,d[j+1].x,d[j+1].y))  {nans=min(nans,fabs(ny-jd[i].y));}
       }
    }
    printf("%.3lf\n",nans);
    system("pause");
    return 0;
}
