#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100010
using namespace std;
int b,point,n,num[N],sum[N],lfre[N<<1],rfre[N<<1],ans;
int main()
{
    scanf("%d%d",&n,&b);
    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]<b) num[i]=-1;
        else if(num[i]>b) num[i]=1;
        else if(num[i]==b) point=i,num[i]=0;
    }
    lfre[n]=1;rfre[n]=1;
    for(int i=point-1;i>=1;i--) sum[i]=sum[i+1]+num[i],lfre[sum[i]+n]++;
    for(int i=point+1;i<=n;i++) sum[i]=sum[i-1]+num[i],rfre[sum[i]+n]++;
    for(int i=0;i<=2*n-1;i++) ans+=lfre[i]*rfre[2*n-i];
    printf("%d\n",ans);
    system("pause");
    return 0; 
}
