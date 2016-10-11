#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n;
long long l,f[50010],num[50010],sum[50010];
int dui[50010];
long long A(int x)
{
     return sum[x]+x;
}
long double G(int j,int k)  //k,i
{
     return (long double) (f[j]-f[k]+A(j)*A(j)-A(k)*A(k))/(long double) (A(j)-A(k));
}
int main()
{
    int i,j;
    cin>>n>>l;
    for(i=1;i<=n;i++)
    {scanf("%lld",&num[i]);sum[i]=sum[i-1]+num[i];}
    int tou=1,wei=1,now;
    for(i=1;i<=n;i++)
    {
       while(tou<wei && G(dui[tou],dui[tou+1])<2*(A(i)-1-l))
       tou++;
       now=dui[tou];
       f[i]=f[now]+(sum[i]-sum[now]+i-now-1-l)*(sum[i]-sum[now]+i-now-1-l);
       while(tou<wei && G(dui[wei-1],dui[wei])>G(dui[wei],i))
       wei--;
       wei++;
       dui[wei]=i;
    }
    cout<<f[n]<<endl;
    system("pause");
    return 0;
}
