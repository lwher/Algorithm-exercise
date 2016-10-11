#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,v,rp[1010],x[1010],sum[1010],l[1010][1010],r[1010][1010];
int main()
{
    int i,j,L;
    scanf("%d%d",&n,&v);
    for(i=1;i<=n;i++) scanf("%d%d",&x[i],&rp[i]);
    for(i=1;i<=n;i++) sum[i]=sum[i-1]+rp[i];
    for(i=1;i<=n;i++) r[i][i]=l[i][i]=abs(x[i]-x[v])*sum[n];
    for(L=2;L<=n;L++)
    {
        for(i=1;i<=n;i++)
        {
            j=i+L-1;
            if(j>n) break;
            l[i][j]=l[i+1][j]+(x[i+1]-x[i])*(sum[i]+sum[n]-sum[j]);
            l[i][j]=min(l[i][j],r[i][j-1]+(x[j]-x[j-1])*(sum[i-1]+sum[n]-sum[j-1])+(x[j]-x[i])*(sum[n]-sum[j]+sum[i-1]));
            r[i][j]=r[i][j-1]+(x[j]-x[j-1])*(sum[i-1]+sum[n]-sum[j-1]);
            r[i][j]=min(r[i][j],l[i+1][j]+(x[i+1]-x[i])*(sum[i]+sum[n]-sum[j])+(x[j]-x[i])*(sum[i-1]+sum[n]-sum[j]));
        }
    }
    printf("%d\n",min(l[1][n],r[1][n]));
    system("pause");
    return 0;
}
