#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
const long long inf=1LL<<60;
int n,m;
int s[1010][1010],p[1010];
long long f[1010][1010],w[1010][1010],sum[1010];
int main()
{
    int i,j,k;
    long long tmp;
    while(scanf("%d%d",&n,&m) && n && m)
    {
        m++;
        memset(sum,0,sizeof(sum));
        memset(w,0,sizeof(w));
        for(i=1;i<=n;i++)  {scanf("%d",&p[i]);sum[i]=sum[i-1]+p[i];}
        for(i=1;i<=n;i++)  for(j=i+1;j<=n;j++)
        {
            w[i][j]=w[i][j-1]+(sum[j-1]-sum[i-1])*p[j];
        }
        for(i=1;i<=n;i++)  {s[1][i]=0;f[1][i]=w[1][i];}
        for(i=2;i<=m;i++)  for(j=0;j<=n;j++)  f[i][j]=inf;
        for(i=2;i<=m;i++)
        {
            s[i][n+1]=n;
            for(j=n;j>=1;j--)
            {
                for(k=s[i-1][j];k<=s[i][j+1];k++)
                {
                    if(k<j)  tmp=f[i-1][k]+w[k+1][j];  else tmp=inf;
                    if(tmp<f[i][j])
                    {
                        f[i][j]=tmp;
                        s[i][j]=k;
                    }
                }
            }
        }
        cout<<f[m][n]<<endl;
    }
    //system("pause");
    return 0;
}
