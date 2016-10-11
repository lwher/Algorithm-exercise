#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const double  perfect=0.6180339887498949;
int num[30010],n;
int na,nb;
double ans,nans;
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d",&num[i]);
    sort(num+1,num+1+n);
    int l,r,mid;
    na=num[1];nb=num[2];ans=double(num[1])/num[2];
    for(i=3;i<=n;i++)
    {
          l=1;r=i-1;
          while(l+1<r)
          {
               mid=(l+r)>>1;
               nans=double(num[mid])/num[i];
               if(nans<perfect)  l=mid;
               else r=mid;
          }
          nans=double(num[l])/num[i];
          if(fabs(nans-perfect)<fabs(ans-perfect))   {ans=nans;na=num[l];nb=num[i];}
          nans=double(num[r])/num[i];
          if(fabs(nans-perfect)<fabs(ans-perfect))   {ans=nans;na=num[r];nb=num[i];}
    }
    cout<<na<<endl<<nb<<endl;
    system("pause");
    return 0;
}
