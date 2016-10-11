#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<algorithm> 
#include<cstring> 
#define eps 1e-15 
using namespace std; 
struct sth 
{ 
       double x,y,xx,yy; 
       double jijiao; 
       int id; 
}bpm[200010]; 
struct kkk 
{ 
       double x,y1,y2; 
}xian[100010]; 
long long  bj=1e15; 
int n,sz,tou,wei; 
int ans[200010];double jx[200010],jy[200010]; 
double calc(double x1,double a,double yy1) 
{ 
       return  (-x1)*a+yy1/(x1); 
} 
void addline(kkk a) 
{ 
     sz++;bpm[sz].id=sz; 
     bpm[sz].x=0;bpm[sz].y=calc(a.x,0,a.y1); 
     bpm[sz].xx=-1;bpm[sz].yy=calc(a.x,-1,a.y1); 
     bpm[sz].jijiao=atan2(bpm[sz].yy-bpm[sz].y,bpm[sz].xx-bpm[sz].x); 
     sz++;bpm[sz].id=sz; 
     bpm[sz].x=-1;bpm[sz].y=calc(a.x,-1,a.y2); 
     bpm[sz].xx=0;bpm[sz].yy=calc(a.x,0,a.y2); 
     bpm[sz].jijiao=atan2(bpm[sz].yy-bpm[sz].y,bpm[sz].xx-bpm[sz].x); 
} 
double guaixiang(double a,double b,double c,double d,double e,double f) 
{ 
       double q=e-a,w=f-b,r=c-a,u=d-b; 
       return q*u-w*r; 
} 
inline bool comp(sth a,sth b) 
{ 
       if(fabs(a.jijiao-b.jijiao)<eps)   
       { 
           if(guaixiang(a.x,a.y,a.xx,a.yy,b.x,b.y)>-eps)  return 0; 
           else return 1; 
       } 
       return a.jijiao<b.jijiao; 
} 
void init() 
{ 
     int i; 
     scanf("%d",&n); 
     for(i=1;i<=n;i++)  scanf("%lf%lf%lf",&xian[i].x,&xian[i].y1,&xian[i].y2);   
} 
void build() 
{ 
     int i;sz=0; 
     sz++;bpm[sz].x=-bj;bpm[sz].y=bj;bpm[sz].xx=bj;bpm[sz].yy=bj; bpm[sz].jijiao=atan2(bpm[sz].yy-bpm[sz].y,bpm[sz].xx-bpm[sz].x); 
     bpm[sz].id=sz; 
     sz++;bpm[sz].x=bj;bpm[sz].y=bj;bpm[sz].xx=bj;bpm[sz].yy=-bj;bpm[sz].jijiao=atan2(bpm[sz].yy-bpm[sz].y,bpm[sz].xx-bpm[sz].x); 
     bpm[sz].id=sz; 
     sz++;bpm[sz].x=bj;bpm[sz].y=-bj;bpm[sz].xx=-bj;bpm[sz].yy=-bj;bpm[sz].jijiao=atan2(bpm[sz].yy-bpm[sz].y,bpm[sz].xx-bpm[sz].x); 
     bpm[sz].id=sz; 
     sz++;bpm[sz].x=-bj;bpm[sz].y=-bj;bpm[sz].xx=-bj;bpm[sz].yy=bj;bpm[sz].jijiao=atan2(bpm[sz].yy-bpm[sz].y,bpm[sz].xx-bpm[sz].x); 
     bpm[sz].id=sz; 
     for(i=1;i<=n;i++)  addline(xian[i]); 
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
void work(int mid) 
{ 
     int i;tou=1;wei=0; 
     bool oo=0; 
     memset(jx,0,sizeof(jx));memset(jy,0,sizeof(jy)); 
     sth o,shang; 
     for(i=1;i<=sz;i++) 
     { 
          o=bpm[i]; 
          if(o.id-4>mid*2)  continue; 
          if(oo && fabs(o.jijiao-shang.jijiao)<eps)  continue; 
          while(tou<wei && guaixiang(o.x,o.y,o.xx,o.yy,jx[wei-1],jy[wei-1])<-eps)  wei--; 
          while(tou<wei && guaixiang(o.x,o.y,o.xx,o.yy,jx[tou],jy[tou])<-eps)      tou++; 
          oo=1;wei++;ans[wei]=i;if(wei>1) qiujiao(wei-1);shang=o; 
     } 
     int zuo=-1,you=10000000; 
     while(zuo<tou || you>wei) 
     { 
          zuo=tou;you=wei; 
          o=bpm[ans[tou]]; 
          while(tou<wei && guaixiang(o.x,o.y,o.xx,o.yy,jx[wei-1],jy[wei-1])<-eps)  wei--; 
          o=bpm[ans[wei]]; 
          while(tou<wei && guaixiang(o.x,o.y,o.xx,o.yy,jx[tou],jy[tou])<-eps)      tou++; 
     } 
} 
void solve() 
{ 
     int l=1,r=n,mid; 
     build(); 
     while(l<r) 
     { 
        if(l+1==r)  break; 
        mid=(l+r)>>1; 
        work(mid); 
        if(wei-tou+1>=3)  l=mid; 
        else r=mid; 
     } 
     work(r); 
     if(wei-tou+1>=3)  cout<<r<<endl; 
     else 
     cout<<l<<endl; 
} 
int main() 
{ 
    init(); 
    solve(); 
   // system("pause"); 
    return 0; 
}