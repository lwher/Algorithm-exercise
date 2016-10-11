#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,q[1000010];
long long aa[1000010],A[1000010],f[1000010];
double calc(int j,int k)
{
    return (2.00*f[j]+(double)(j)*j-2.00*f[k]-(double)(k)*k)/(double)(k-j);
}
int main()
{
    int i,j,l=1,r=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%lld",&aa[i]);
    for(i=1;i<=n;i++) A[i]=aa[n-i+1];
    f[1]=A[1];
    q[1]=1;
    for(i=2;i<=n+1;i++)
    {
       while(l<r && calc(q[l],q[l+1])>-2.00*i+1) l++;
       f[i]=f[q[l]]+(long long)(i-q[l])*(i-q[l]-1)/2+A[i];
       while(l<r && calc(q[r-1],q[r])<calc(q[r-1],i)) r--;
       q[++r]=i;
    }
    cout<<f[n+1]<<endl;
    return 0;
}