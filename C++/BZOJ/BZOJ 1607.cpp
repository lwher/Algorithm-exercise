#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
bool have[1000010];
int sum[1000010],ans[1000010];
int n,a[100010];
int main()
{
    int i,num,j,maxx=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);have[a[i]]=1;sum[a[i]]++;
        if(maxx<a[i])  maxx=a[i];
    }
    for(i=1;i<=maxx;i++)
    if(have[i])
    {
        if(sum[i]>1)   ans[i]+=sum[i]-1;
        for(j=2*i;j<=maxx;j+=i)
        {
           ans[j]+=sum[i];
        }
    }
    for(i=1;i<=n;i++)
    printf("%d\n",ans[a[i]]);
    system("pause");
    return 0;
} 
