#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
struct sth
{ 
       double x,y;
}dian[410];
int s,A,B,dui[30010];
int sz,to[300010],pre[300010],last[410];
double v[300010],d[410],ans;
double t,k,x4,y4;
bool mark[410];
double juli(double x1,double y1,double x2,double y2)
{
       return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void Ins(int a,int b,double c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void spfa()
{
     int i,now,tou=1,wei=0;
     for(i=1;i<=4*s;i++)  d[i]=1e9;
     d[A]=0;wei++;dui[wei]=A;mark[A]=1;
     d[A+s]=0;wei++;dui[wei]=A+s;mark[A+s]=1;
     d[A+s*2]=0;wei++;dui[wei]=A+s*2;mark[A+s*2]=1;
     d[A+s*3]=0;wei++;dui[wei]=A+s*3;mark[A+s*3]=1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         i=last[now];
         while(i>0)
         {
                   if(d[now]+v[i]<d[to[i]])
                   {
                         d[to[i]]=d[now]+v[i];
                         if(!mark[to[i]])
                         {wei++;dui[wei]=to[i];mark[to[i]]=1;}
                   }
                   i=pre[i];
         }
         mark[now]=0;
     }
     ans=1e9;
     if(d[B]<ans)  ans=d[B];
     if(d[B+s]<ans)  ans=d[B+s];
     if(d[B+s*2]<ans)  ans=d[B+s*2];
     if(d[B+s*3]<ans)  ans=d[B+s*3];
}
void getlast(double x1,double y1,double x2,double y2,double x3,double y3)
{
     double p; 
     if(juli(x2,y2,x3,y3)>juli(x1,y1,x2,y2)&& juli(x2,y2,x3,y3)>juli(x1,y1,x3,y3))
     {
         p=x1;x1=x2;x2=p;p=y1;y1=y2;y2=p;
     }else
     if(juli(x2,y2,x1,y1)>juli(x3,y3,x2,y2)&& juli(x2,y2,x1,y1)>juli(x1,y1,x3,y3))
     {
         p=x2;x2=x3;x3=p;p=y2;y2=y3;y3=p;
     }
     x4=x3+x1-x2;y4=y3+y1-y2;
}
int main()
{
    double x1,y1,x2,y2,x3,y3,k;
    int i,j,l;
    cin>>s>>t>>A>>B;
    for(i=1;i<=s;i++)
    {
       scanf("%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&k);
       getlast(x1,y1,x2,y2,x3,y3);
       dian[i].x=x1;dian[i].y=y1;dian[i+s].x=x2;dian[i+s].y=y2;
       dian[i+2*s].x=x3;dian[i+2*s].y=y3;
       dian[i+3*s].x=x4;dian[i+3*s].y=y4;
       for(j=0;j<=3;j++)  for(l=0;l<=3;l++)
       if(l!=j)
       Ins(i+j*s,i+l*s,juli(dian[i+j*s].x,dian[i+j*s].y,dian[i+l*s].x,dian[i+l*s].y)*k);
    }
    for(i=1;i<=4*s;i++)
    for(j=1;j<=4*s;j++)
    if(i%s!=j%s)
    Ins(i,j,juli(dian[i].x,dian[i].y,dian[j].x,dian[j].y)*t);
    spfa();
    printf("%.2lf\n",ans);
    
    system("pause");
    return 0;
}
