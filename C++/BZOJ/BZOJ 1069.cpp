#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<math.h>
#define eps 1e-8
using namespace std;
struct sth
{
       double x,y;
}d[2010];
int n;
int bao[2010],top=2;
double ans=0;
double juli(sth a,sth b)
{
       return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double chaji(sth a,sth b,sth c)
{
    return ((c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x));
}
inline bool comp(sth a,sth b)
{
       if(fabs(a.x-b.x)<eps)  return a.y<b.y;
       else  return a.x<b.x;
}
inline bool cmp(sth a,sth b)
{
       if(chaji(d[1],a,b)>0)
       return 0;
       else
       if(fabs(chaji(d[1],a,b))<eps && juli(d[1],a)>juli(d[1],b))
       return 0;
       return 1;
}
void tubao()
{
     int i;
     bao[1]=1;bao[2]=2;
     for(i=1;i<=n;i++)
     {
         while(top>=2 && chaji(d[bao[top-1]],d[bao[top]],d[i])>-eps)
         top--;
         top++;bao[top]=i;
     }
}
void qiaqiao()
{
     int i,j,p1,p2,k;
     for(i=1;i<top;i++)
     {
        p1=i;p2=i+1;
        for(j=i+1;j<=top;j++)
        {
            while(1)
            {
                 k=p1+1;
                 if(p1==j)
                 k=i;
                 if(fabs(chaji(d[bao[i]],d[bao[j]],d[bao[p1]]))<fabs(chaji(d[bao[i]],d[bao[j]],d[bao[k]])))
                 p1=k;
                 else
                 break;   
            }
            while(1)
            {
                k=p2+1;
                if(p2==top)
                k=1;
                if(fabs(chaji(d[bao[i]],d[bao[j]],d[bao[p2]]))<fabs(chaji(d[bao[i]],d[bao[j]],d[bao[k]])))
                p2=k;
                else
                break;
            }
            ans=max(ans,fabs(chaji(d[bao[i]],d[bao[j]],d[bao[p1]]))*0.500+fabs(chaji(d[bao[i]],d[bao[j]],d[bao[p2]])*0.5000));
        }
     }
}
int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    scanf("%lf%lf",&d[i].x,&d[i].y);
    sort(d+1,d+1+n,comp);
    sort(d+2,d+1+n,cmp);
    tubao();
    qiaqiao();
    printf("%.3lf\n",ans);
    
    system("pause");
    return 0;
}
