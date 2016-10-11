#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,c,w[51],gl[51],sum[51];
int l[51][51],r[51][51];
int main()
{
    int i,j,k;
    scanf("%d%d",&n,&c);
    for(i=1;i<=n;i++)  scanf("%d%d",&w[i],&gl[i]);
    for(i=1;i<=n;i++)  sum[i]=sum[i-1]+gl[i];
    for(i=c-1;i>=1;i--)
    {
        l[i][c]=l[i+1][c]+(w[i+1]-w[i])*(sum[i]+sum[n]-sum[c]);
        r[i][c]=l[i][c]+(w[c]-w[i])*(sum[i-1]+sum[n]-sum[c]);
    }
    for(i=c+1;i<=n;i++)
    {
        r[c][i]=r[c][i-1]+(w[i]-w[i-1])*(sum[n]-sum[i-1]+sum[c-1]);
        l[c][i]=r[c][i]+(w[i]-w[c])*(sum[c-1]+sum[n]-sum[i]);
    }
    for(i=c-1;i>=1;i--)   for(j=c+1;j<=n;j++)
    {
        l[i][j]=min(l[i+1][j]+(w[i+1]-w[i])*(sum[n]-sum[j]+sum[i]),r[i][j-1]+(w[j]-w[j-1])*(sum[n]-sum[j-1]+sum[i-1])+(w[j]-w[i])*(sum[n]-sum[j]+sum[i-1]));
        r[i][j]=min(r[i][j-1]+(w[j]-w[j-1])*(sum[n]-sum[j-1]+sum[i-1]),l[i+1][j]+(w[i+1]-w[i])*(sum[i]+sum[n]-sum[j])+(w[j]-w[i])*(sum[n]-sum[j]+sum[i-1]));
    }
    printf("%d\n",min(l[1][n],r[1][n]));
    system("pause");
    return 0;
}
