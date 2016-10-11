#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cmath>
using namespace std;
int n,p;
int a[30010];
inline bool comp(int a,int b)
{
     return a<b;
}
__int64 ans;
int main()
{
    cin>>n>>p;
    p%=1000;
    int i,j;
    for(i=1;i<=n;i++)
    {scanf("%d",&a[i]);}
    sort(a+1,a+1+n,comp);
    ans+=a[1];
    for(i=2;i<=n;i++)
    {
      ans+=(long long)(((a[i])%1000)*i)%1000;
      ans%=1000;
      if(a[i]==a[i-1])
      ans+=p;
      ans%=1000;
    }
    cout<<ans;
    system("pause");
    return 0;
}
