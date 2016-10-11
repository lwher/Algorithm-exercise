#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#define eps 1e-9
#define INF 0x7fffffff
using namespace std;
struct sth
{
      double x,y;
}d[1010];
struct oo
{
       long double k;
       int id;
}xl[1000000];
int now[1010],wei[1010];
int n,sz;
double ans=1e20;
inline bool comp(sth a,sth b)
{
       if(fabs(a.x-b.x)<eps)  return a.y<b.y;
       return a.x<b.x;
}
inline bool cmp(oo a,oo b)
{
       return a.k<b.k;
}
void check(int u)
{
     if(u<1 || u>n-2)  return;
     int b=now[u+1],c=now[u+2],a=now[u];
     double tmp=fabs(double(d[b].x-d[a].x)*(d[c].y-d[a].y)-(d[b].y-d[a].y)*(d[c].x-d[a].x));
     if(tmp<ans)
     {
     ans=tmp;
     }
}
int main()
{
    int i,j,t1,t2,s;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%lf%lf",&d[i].x,&d[i].y);
    sort(d+1,d+1+n,comp);
    for(i=1;i<=n;i++)
    now[i]=i,wei[i]=i;
    for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
    {
       if(fabs(d[i].x-d[j].x)>eps)
       {sz++;
       xl[sz].id=i;
       xl[sz].k=(long double)(d[j].y-d[i].y)/(long double)(d[j].x-d[i].x);}
        
    }
    for(i=1;i<=n-2;i++)
    check(i);
    sort(xl+1,xl+1+sz,cmp);
    for(i=1;i<=sz;i++)
    {
       check(wei[xl[i].id]);
       check(wei[xl[i].id]-1);
       t1=now[wei[xl[i].id]];
       t2=now[wei[xl[i].id]+1];
       now[wei[xl[i].id]]=t2;now[wei[xl[i].id]+1]=t1;
       wei[t1]++;wei[t2]--;
    }
    printf("%.2lf",ans*0.50);
    //system("pause");
    return 0;
}