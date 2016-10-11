#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100010],b[100010];
long long f[100010];
long long kabs(long long x)
{
    if(x<0) return -x; return x;
}
long long c(long long x)
{
    if(x==0) return 1e12;
    else return kabs(x);
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d%d",&a[i],&b[i]);
    sort(a+1,a+1+n);sort(b+1,b+1+n);
    f[1]=c(a[1]-b[1]);
    f[2]=min(f[1]+c(a[2]-b[2]),c(a[1]-b[2])+c(a[2]-b[1]));
    for(i=3;i<=n;i++)
    {
        f[i]=f[i-1]+c(a[i]-b[i]);
        f[i]=min(f[i],f[i-2]+c(a[i]-b[i-1])+c(a[i-1]-b[i]));
        long long t=min(c(a[i]-b[i-2])+c(a[i-1]-b[i])+c(a[i-2]-b[i-1]),c(a[i]-b[i-1])+c(a[i-1]-b[i-2])+c(a[i-2]-b[i]));
        f[i]=min(f[i],f[i-3]+t);
    }
    if(f[n]>=1e12)  printf("-1\n");
    else cout<<f[n]<<endl;
    //system("pause");
    return 0;
}