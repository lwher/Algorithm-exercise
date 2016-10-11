#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define eps 1e-8 
using namespace std;
int n,m,y,x,D,s;
int g[210],dui[210];
bool mark[210];
double p[110],a[210][210];
bool bfs()
{
     memset(mark,0,sizeof(mark));
     int tou=1,wei=1,i,now,to;bool flag=0;
     dui[1]=s;mark[s]=1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         for(i=1;i<=m;i++)  
         if(fabs(p[i])>eps)
         {
             to=(now+i)%(2*n-2);
             if(to==0)  to=2*n-2;
             if(!mark[to]) 
             {
                mark[to]=1;dui[++wei]=to;
                if(g[to]==y)  flag=1;
             }
         }
     }
     return flag;
}
void build()
{
     int i,j,k;
     memset(a,0,sizeof(a));
     for(k=1;k<=2*n-1;k++)
     if(mark[k])
     {
         if(g[k]==y)
         {
             a[k][2*n]=0;a[k][k]=1;continue;
         }
         for(i=1;i<=m;i++)
         {
             j=(k+i)%(2*n-2);
             if(j==0) j=2*n-2;
             if(!mark[j])  continue;
             a[k][j]+=p[i];
             a[k][2*n]-=p[i]*i;
         }
         a[k][k]-=1;
     }
}
void swap(double &a,double &b)
{
     double t=a;a=b;b=t;
}
bool gauss()
{
     int nm=2*n-1,i,j,k,now=1;double tt;
     for(i=1;i<=nm;i++)
     {
         for(j=now;j<=nm;j++)  if(fabs(a[j][i])>eps)  break;
         if(j>nm) continue;
         if(now!=j) for(k=1;k<=nm+1;k++)  swap(a[now][k],a[j][k]);
         tt=a[now][i];
         for(k=1;k<=nm+1;k++)  a[now][k]/=tt;
         for(j=1;j<=nm;j++)
         if(j!=now)
         {
             tt=a[j][i];
             for(k=1;k<=nm+1;k++)   a[j][k]-=a[now][k]*tt;
         }
         now++;
     }
     for(i=now;i<=nm;i++)  if(fabs(a[i][nm+1])>eps)  return 0;
     return 1;
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d",&n,&m,&y,&x,&D);
        y++;x++;
        for(i=1;i<=m;i++)  {scanf("%lf",&p[i]);p[i]/=100.00;}
        if(x==y) {printf("0.00\n");continue;}
        memset(g,0,sizeof(g));
        s=x;  if(D==1)  {s=n+(n-x);if(s==2*n-1) s=1;}
        for(i=1;i<=n;i++)  g[i]=i;
        for(i=n+1;i<=n+n-1;i++)  g[i]=n-(i-n);
        if(!bfs())  {puts("Impossible !");continue;}         
        build();
        if(!gauss())  {puts("Impossible !");continue;}
        for(i=1;i<=n*2-1;i++)  if(fabs(a[i][s])>eps)   
        {
           if(fabs(a[i][n*2])<eps)  printf("0.00\n"); else printf("%.2lf\n",a[i][n*2]);
        }
    } 
    system("pause");
    return 0;
}
