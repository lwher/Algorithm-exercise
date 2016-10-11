#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int num[100010];
long long n,l;
__int64 ans;
double answer;
int main()
{
    cin>>n>>l;
    int i;
    for(i=1;i<=n;i++)
    {
      scanf("%d",&num[i]);
    }
    sort(num+1,num+1+n);
    int k=n;
    for(i=1;i<=n;i++)
    {
      while(num[i]+num[k]>l && k>0)
      {
        k--;
      }
      ans+=k;
      if(k>=i) ans--;
      if(k==0)  break;
    }
    ans/=2;
    answer=double(ans)/double(n*(n-1)/2.000);
   printf("%.2f",answer);
  // cout<<ans;
    system("pause");
    return 0;
}
