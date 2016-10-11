#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 1000000001
using namespace std;
int x[20010],y[20010];
int n,xx[2],yy[2];// xx[0]=maxx,xx[1]=minx,yy[0]=maxy,yy[1]=miny
int xxx[2],yyy[2];// xxx[0]=maxx,xxx[1]=minx,yyy[0]=maxy,yyy[1]=miny
int maxx,minx,maxy,miny;
bool mark[20010];
bool check(int mid)
{
     int i,j,k,ii,jj,sum=0,sum2;
     int nx,ny;
     for(i=0;i<2;i++) for(j=0;j<2;j++)
     {
         memset(mark,0,sizeof(mark));
         sum=0;nx=xx[i];ny=yy[j];
         for(k=1;k<=n;k++)  if(abs(x[k]-nx)<=mid && abs(y[k]-ny)<=mid) mark[k]=1,sum++;
         if(sum==n)  return 1;
         xxx[0]=-INF;xxx[1]=INF;yyy[0]=-INF;yyy[1]=INF;
         for(k=1;k<=n;k++)
         if(!mark[k])
         {
              xxx[0]=max(xxx[0],x[k]);xxx[1]=min(xxx[1],x[k]);
              yyy[0]=max(yyy[0],y[k]);yyy[1]=min(yyy[1],y[k]);
         }
         for(ii=0;ii<2;ii++)  for(jj=0;jj<2;jj++)
         {
              sum2=sum;nx=xxx[ii];ny=yyy[jj];
              maxx=-INF;minx=INF;maxy=-INF;miny=INF;
              for(k=1;k<=n;k++)
              if(!mark[k])
              {  
                  if(abs(x[k]-nx)<=mid && abs(y[k]-ny)<=mid) sum2++;
                  else
                  {
                       maxx=max(maxx,x[k]);maxy=max(maxy,y[k]);
                       minx=min(minx,x[k]);miny=min(miny,y[k]);
                  }
              }
              if(sum2==n)  return 1;
              if(maxx-minx<=mid && maxy-miny<=mid)  return 1;
         }
     }
     return 0;
}
int main()
{
    int i;
    scanf("%d",&n);
    xx[0]=-INF;yy[0]=-INF;xx[1]=INF;yy[1]=INF;
    for(i=1;i<=n;i++)  
    {
        scanf("%d%d",&x[i],&y[i]);
        xx[0]=max(xx[0],x[i]);xx[1]=min(xx[1],x[i]);
        yy[0]=max(yy[0],y[i]);yy[1]=min(yy[1],y[i]);
    }
    int l=0,r=INF,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(check(mid))  r=mid;
        else l=mid;
    }
    if(check(l))  cout<<l<<endl;
    else  cout<<r<<endl;
    system("pause");
    return 0;
}
