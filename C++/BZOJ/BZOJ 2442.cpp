#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,k,w[100010],num[100010];
long long f[100010],sum;
int main()
{
    int i,l,r;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)  {scanf("%d",&num[i]);sum+=num[i];}
    num[++n]=0;
    l=1;r=1;w[1]=0;    
    for(i=1;i<=n;i++)
    {
        while(i-w[l]>k+1)  l++;
        f[i]=f[w[l]]+num[i];
        while(l<=r && f[i]<f[w[r]])  r--;
        w[++r]=i;
    }
    cout<<sum-f[n]<<endl;
    return 0;
}