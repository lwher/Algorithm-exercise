#include<iostream>
#include<stdio.h>
#include<cmath>
#define eps   1e-8
using namespace std;
struct sth 
{
       double x,y,xx,yy;
}xd[103];
int n,t;
bool  pd(double a,double b,double c,double d)
{
     if(abs(a-c)<eps && abs(b-d)<eps)
     return 0;
     int i;
     for(i=1;i<=n;i++)
     if(((xd[i].xx-a)*(d-b)-(xd[i].yy-b)*(c-a))*((xd[i].x-c)*(d-b)-(xd[i].y-d)*(c-a))>0)
     return 0;
     return 1;
}
int main()
{
    cin>>t;
    int i,j;
    while(t--)
    {
       scanf("%d",&n);
       for(i=1;i<=n;i++)
       scanf("%lf%lf%lf%lf",&xd[i].x,&xd[i].y,&xd[i].xx,&xd[i].yy);
       bool o=0;
       for(i=1;i<=n;i++)
      { for(j=i+1;j<=n;j++)
       {
           if(pd(xd[i].x,xd[i].y,xd[j].x,xd[j].y))  {o=1;break;}
           if(pd(xd[i].x,xd[i].y,xd[j].xx,xd[j].yy))  {o=1;break;}
           if(pd(xd[i].xx,xd[i].yy,xd[j].xx,xd[j].yy))  {o=1;break;}
           if(pd(xd[i].xx,xd[i].yy,xd[j].x,xd[j].y))  {o=1;break;}
       }
      if(o)  break;}
      if(n==1 || n==2)  
      printf("Yes!\n");
      else
      if(o)  printf("Yes!\n");
      else
      printf("No!\n");
    }
    
    system("pause");
    return 0;
}
