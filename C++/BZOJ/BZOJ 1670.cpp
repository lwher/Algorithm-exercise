#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<math.h>
using namespace std;
struct sth
{
       int x,y;
}d[5010];
int n;
int bao[5010],top=2;
double ans=0;
double juli(sth a,sth b)
{
       return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int chaji(sth a,sth b,sth c)
{
    return ((c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x));
}
inline bool comp(sth a,sth b)
{
       if(a.x==b.x)  return a.y<b.y;
       else  return a.x<b.x;
}
inline bool cmp(sth a,sth b)
{
       if(chaji(d[1],a,b)>0)
       return 0;
       else
       if(chaji(d[1],a,b)==0 && juli(d[1],a)>juli(d[1],b))
       return 0;
       return 1;
}
void tubao()
{
     int i;
     bao[1]=1;bao[2]=2;
     for(i=1;i<=n;i++)
     {
         while(top>=2 && chaji(d[bao[top-1]],d[bao[top]],d[i])>=0)
         top--;
         top++;bao[top]=i;
     }
}
int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    scanf("%d%d",&d[i].x,&d[i].y);
    sort(d+1,d+1+n,comp);
    sort(d+2,d+1+n,cmp);
    tubao();
    ans=0;
    for(i=2;i<=top;i++)
    ans+=juli(d[bao[i-1]],d[bao[i]]);
    ans+=juli(d[bao[1]],d[bao[top]]);
    printf("%.2lf\n",ans);
    system("pause");
    return 0;
}

