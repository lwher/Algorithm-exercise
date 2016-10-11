#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,a[1000010],b[1000010];
long long ans,f[1000010],sum[1000010];
int dui[1000010];
double calc(int k,int j)
{
    return ((double)(f[j])-f[k])/(double(sum[k])-sum[j]);
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d",&a[i]);
    for(i=1;i<=n;i++)  scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
    {
        ans+=((long long)(n)-i)*b[i];
        sum[i]=sum[i-1]+b[i];
    }
    int tou=1,wei=1;
    dui[1]=0;
    for(i=1;i<=n;i++)
    {
        while(tou<wei && calc(dui[tou],dui[tou+1])<double(i-n))  tou++;
        f[i]=f[dui[tou]]+(n-i)*(sum[i]-sum[dui[tou]])-a[i];
        while(tou<wei && calc(dui[wei-1],dui[wei])>calc(dui[wei],i))  wei--;
        dui[++wei]=i; 
    }
    cout<<ans-f[n]<<endl;
    //system("pause");
    return 0;
}