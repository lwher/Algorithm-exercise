#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-3
using namespace std;
struct point 
{
   double x,y;
}A,B,C,D;
double P,Q,R;
void read(point &a) {scanf("%lf%lf",&a.x,&a.y);}
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double calc(double x,double y)
{
    point E,F; E.x=x;E.y=y;
    double lx,ly,rx,ry,mid1x,mid2x,mid1y,mid2y,tmp1,tmp2; 
    lx=C.x;ly=C.y;rx=D.x;ry=D.y;
    while(fabs(rx-lx)>eps || fabs(ry-ly)>eps)
    {
        mid1x=lx+(rx-lx)/3;mid1y=ly+(ry-ly)/3;
        mid2x=lx+(rx-lx)/3*2;mid2y=ly+(ry-ly)/3*2;
        F.x=mid1x;F.y=mid1y;
        tmp1=dist(A,E)/P+dist(E,F)/R+dist(F,D)/Q;
        F.x=mid2x;F.y=mid2y;
        tmp2=dist(A,E)/P+dist(E,F)/R+dist(F,D)/Q;
        if(tmp1>tmp2)  {lx=mid1x;ly=mid1y;}
        else {rx=mid2x;ry=mid2y;}
    }  
    F.x=lx;F.y=ly;
    return dist(A,E)/P+dist(E,F)/R+dist(F,D)/Q;
}
int main()
{
    double lx,ly,rx,ry,mid1x,mid2x,mid1y,mid2y,tmp1,tmp2;    
    read(A);read(B);read(C);read(D);
    scanf("%lf%lf%lf",&P,&Q,&R);    
    lx=A.x;ly=A.y;rx=B.x;ry=B.y;
    while(fabs(rx-lx)>eps || fabs(ry-ly)>eps)
    {
        mid1x=lx+(rx-lx)/3;mid1y=ly+(ry-ly)/3;
        mid2x=lx+(rx-lx)/3*2;mid2y=ly+(ry-ly)/3*2;
        tmp1=calc(mid1x,mid1y);tmp2=calc(mid2x,mid2y);
        if(tmp1>tmp2)  {lx=mid1x;ly=mid1y;}
        else {rx=mid2x;ry=mid2y;}
    }    
    printf("%.2lf\n",calc(lx,ly));
    return 0;
}