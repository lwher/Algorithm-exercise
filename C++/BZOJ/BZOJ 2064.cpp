#include<iostream>
#include<cstdio>
using namespace std;
int n,m,ed;
int f[2097152],sum[2097152];
void ini()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&sum[1<<i>>1]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
         scanf("%d",&sum[1<<(n+i)>>1]);
         sum[1<<(n+i)>>1]=-sum[1<<(n+i)>>1];
     }
    n=n+m;
    ed=(1<<n)-1;
}
int main()
{
    ini();
    for(int i=1;i<=ed;i++)
    {
         int t=i&(-i);
         sum[i]=sum[t]+sum[i-t];
         for(int j=1;j<=n;j++)
            if((i&(1<<j>>1))>0)
            {
                int k=i-(1<<j>>1);
                if(f[k]>f[i])f[i]=f[k];
            }
         if(sum[i]==0)f[i]++;
    }
    printf("%d",n-2*f[ed]);
    system("pause");
    return 0;
}
