#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-7
using namespace std;
struct point 
{
    double x,y,z;
}p[1010];
double A[1010],B[1010],D[1010];
bool mark[1010];
inline double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int n;
int main()
{
    int i,j,k;
    double ans,L,Min,ta,tb,aa,bb;
    while(scanf("%d",&n) && n)
    {
        for(i=1;i<=n;i++) scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        ans=0;L=1e10;        
        while(fabs(ans-L)>eps)
        {
            ans=L;
            memset(mark,0,sizeof(mark));
            mark[1]=1;aa=0;bb=0;
            for(i=2;i<=n;i++) 
            {
                A[i]=fabs(p[i].z-p[1].z);
                B[i]=dist(p[i],p[1]);
                D[i]=A[i]-B[i]*ans;
            }
            for(i=2;i<=n;i++)
            {
                Min=1e10;k=0;
                for(j=2;j<=n;j++) if(!mark[j] && D[j]<Min)
                {
                    Min=D[j];k=j;
                }
                mark[k]=1;
                aa+=A[k];bb+=B[k];
                for(j=2;j<=n;j++) if(!mark[j])
                {
                    ta=fabs(p[j].z-p[k].z);tb=dist(p[j],p[k]);
                    if(ta-tb*ans<D[j])
                    {
                        A[j]=ta;
                        B[j]=tb;
                        D[j]=ta-tb*ans;
                    } 
                }
            }
            L=aa/bb;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}