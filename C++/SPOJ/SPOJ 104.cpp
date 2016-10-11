#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;
int n,m;
double A[15][15];
void swap(double &a,double &b)
{
    double t=a;a=b;b=t;
}
double calc(int N)
{
    int i,j,k;
    double res=1,p;
    for(i=1;i<=N;i++)
    {
        if(fabs(A[i][i])<eps)
        {
           for(j=i+1;j<=N;j++) if(fabs(A[j][i])>eps)
           {
               res*=-1;
               for(k=1;k<=N;k++) swap(A[i][k],A[j][k]);
               break;
           }
        }
        res*=A[i][i];
        for(j=i+1;j<=N;j++)
        if(fabs(A[j][i])>eps)
        {
            p=A[j][i]/A[i][i];
            for(k=1;k<=N;k++) A[j][k]-=A[i][k]*p;
        }
    }
    return res;
}
int main()
{
    int T,i,j,a,b;
    scanf("%d",&T);    
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++) for(j=1;j<=n;j++) A[i][j]=0.00;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            A[a][b]-=1;A[b][a]-=1;
            A[a][a]+=1;A[b][b]+=1;
        }    
        printf("%.0lf\n",calc(n-1));
    }
    return 0;
}
