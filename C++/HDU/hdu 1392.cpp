#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
    int x,y;
}dian[110];
int n;
int tb[110],top;
double juli(sth a,sth b)
{
       return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int chaji(int a,int b,int c,int d)
{
    return a*d-b*c;
}
int guaixiang(sth a,sth b,sth c)
{
    return chaji(c.x-a.x,c.y-a.y,b.x-a.x,b.y-a.y);
}
inline bool comp(sth a,sth b)
{
    if(a.x==b.x)  return a.y<b.y;  return a.x<b.x;
}
inline bool cmp(sth a,sth b)
{
       if(guaixiang(dian[1],a,b)<0)  return 1; else
       if(guaixiang(dian[1],a,b)>0)  return 0; else
       return juli(dian[1],a)<juli(dian[1],b);
}
void solve()
{
     int i;top=2;
     tb[1]=1;tb[2]=2;
     for(i=3;i<=n;i++)
     {
          while(top>1 && guaixiang(dian[tb[top-1]],dian[tb[top]],dian[i])>=0)  top--;
          top++; tb[top]=i;            
     }
}
int main()
{
    int i;
    while(scanf("%d",&n) && n)
    {
       for(i=1;i<=n;i++)  scanf("%d%d",&dian[i].x,&dian[i].y);
       if(n==1)  printf("0.00\n");
       else
       if(n==2)  printf("%.2lf\n",juli(dian[1],dian[2]));
       else
       {
       sort(dian+1,dian+1+n,comp);
       sort(dian+2,dian+1+n,cmp);
       solve();
       double ans=0;
       for(i=1;i<top;i++)  ans+=juli(dian[tb[i]],dian[tb[i+1]]);
       ans+=juli(dian[tb[1]],dian[tb[top]]);
       printf("%.2lf\n",ans);
       }
    }
    system("pause");
    return 0;
}
