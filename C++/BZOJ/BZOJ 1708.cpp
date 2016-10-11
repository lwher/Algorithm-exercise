#include<iostream>
#include<cstdio>
using namespace std;
int v,n;
int a[26];long long f[10001];
int main()
{
    scanf("%d%d",&v,&n);
    for(int i=1;i<=v;i++)scanf("%d",&a[i]);
    f[0]=1;
    for(int i=1;i<=v;i++)  for(int j=a[i];j<=n;j++)  f[j]+=f[j-a[i]];
    printf("%lld",f[n]);
    return 0;
}