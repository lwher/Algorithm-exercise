#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int sum[100001],f[100001],g[100001],q[100001];
int n,h,t;
int main()
{
    scanf("%d",&n);
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        int j;
        scanf("%d",&j);
        sum[i]=sum[i-1]+j;
    }
    h=t=1;q[1]=n+1;
    for(int i=n;i>0;i--)
    {
        while(t>h && sum[q[h+1]-1]-sum[i-1]>=f[q[h+1]]) h++;
        f[i]=sum[q[h]-1]-sum[i-1];
        g[i]=g[q[h]]+1;
        while(t>h && f[i]-sum[i-1]<f[q[t]]-sum[q[t]-1])  --t;
        q[++t]=i;
    }
    printf("%d\n",g[1]);
    system("pause");
    return 0;
}
