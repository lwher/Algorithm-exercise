#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define eps 1e-8
using namespace std;
struct line
{
       double x1,x2,y1,y2;
}xd[100010];
int n,ans[100010];
bool mark[100010];
bool kspc(line a,line b)
{
     if(max(a.x1,a.x2)<min(b.x1,b.x2))  return 1;
     if(max(a.y1,a.y2)<min(b.y1,b.y2))  return 1;
     if(max(b.x1,b.x2)<min(a.x1,a.x2))  return 1;
     if(max(b.y1,b.y2)<min(a.y1,a.y2))  return 1;
     return 0;
}
double chaji(double x,double y,double xx,double yy)
{
     return x*yy-y*xx;
}
bool xj(line a,line b)
{
     if(kspc(a,b))  return 0;
     if(chaji(a.x2-a.x1,a.y2-a.y1,b.x1-a.x1,b.y1-a.y1)*chaji(a.x2-a.x1,a.y2-a.y1,b.x2-a.x1,b.y2-a.y1)>-eps)  return 0;
     if(chaji(b.x1-b.x2,b.y1-b.y2,a.x1-b.x2,a.y1-b.y2)*chaji(b.x1-b.x2,b.y1-b.y2,a.x2-b.x2,a.y2-b.y2)>-eps)  return 0;
     return 1;
}
int main()
{
    int i,j;
    while(scanf("%d",&n) && n)
    {
        for(i=1;i<=n;i++)  scanf("%lf%lf%lf%lf",&xd[i].x1,&xd[i].y1,&xd[i].x2,&xd[i].y2);
        memset(mark,0,sizeof(mark));
        for(i=1;i<n;i++)  for(j=i+1;j<=n;j++)  if(xj(xd[i],xd[j]))  {mark[i]=1;break;}
        ans[0]=0;
        for(i=1;i<=n;i++)  if(!mark[i])  ans[++ans[0]]=i;
        printf("Top sticks:");
        for(i=1;i<ans[0];i++)  printf(" %d,",ans[i]);
        printf(" %d.\n",ans[ans[0]]);
    }
    system("pause");
    return 0;
}
