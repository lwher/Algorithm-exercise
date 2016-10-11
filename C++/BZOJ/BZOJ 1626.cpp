#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#define INF 1e50
using namespace std;
long long x[1010],y[1010];
bool mark[1010];
double map[1010][1010];
double d[1010];
int n,m;
int main()
{
    int i,j;
    int a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {scanf("%lld%lld",&x[i],&y[i]);d[i]=INF;}
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    map[i][j]=sqrt(double((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
    for(i=1;i<=m;i++)
    {
       scanf("%d%d",&a,&b);
       map[a][b]=0;map[b][a]=0;
    }
    d[1]=0;
    double ans=0;
    int now;
    double minn;
    for(i=1;i<=n;i++)
    {
        minn=INF;
        for(j=1;j<=n;j++)
        {
           if(!mark[j] && minn>d[j])
           {minn=d[j];now=j;}
        }
        mark[now]=1;
        ans+=d[now];
        for(j=1;j<=n;j++)
        if(now!=j)
        d[j]=min(d[j],map[now][j]);
    }
    printf("%.2lf\n",ans);
    system("pause");
    return 0;
}
