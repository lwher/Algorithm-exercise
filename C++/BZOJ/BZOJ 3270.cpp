#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define eps 1e-6
using namespace std;
int n,m,s,e,d[30];// s:start e:end
double p[30],t[30][30],a[501][501],tt;
void swap(double &a,double &b) {double t=a;a=b;b=t;}
int main()
{
    int i,j,k,l,x,y,q;
    scanf("%d%d%d%d",&n,&m,&s,&e);
    q=n*n;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        d[x]++;d[y]++;
        t[x][y]=1;t[y][x]=1;
    }
    for(i=1;i<=n;i++)  scanf("%lf",&p[i]);
    for(i=1;i<=n;i++)  for(j=1;j<=n;j++)
    {
        if(i==j)  t[i][j]=p[i];
        else t[i][j]*=(1-p[i])/d[i];
    }
    for(i=1;i<=n;i++)  for(j=1;j<=n;j++)
    {
        a[(i-1)*n+j][(i-1)*n+j]=-1;
        if(i!=j)
        {
            for(k=1;k<=n;k++) for(l=1;l<=n;l++)
            {
                a[(k-1)*n+l][(i-1)*n+j]+=t[i][k]*t[j][l];
            }
        }
    }
    a[(s-1)*n+e][q+1]=-1;
    int now=1;
    for(i=1;i<=q;i++)
    {
        for(j=now;j<=q;j++)  if(fabs(a[j][i])>eps)  break;
        if(j>q)  continue;
        if(j!=now)  for(k=1;k<=q+1;k++)  swap(a[now][k],a[j][k]);
        tt=a[now][i];
        for(k=1;k<=q+1;k++)  a[now][k]/=tt;
        for(j=1;j<=q;j++) 
        if(j!=now)
        {
            tt=a[j][i];
            for(k=1;k<=q+1;k++)  a[j][k]-=a[now][k]*tt;
        }
        now++;
    }
    for(i=1;i<=n;i++)  printf("%.6lf ",a[(i-1)*n+i][q+1]);
    return 0;
}