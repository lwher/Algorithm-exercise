#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int MAX=3000;
int ans[MAX]={0};
int main()
{
    int n,i,j,carry;
    cin>>n;
    ans[0]=1;
    for( i=2 ; i<=n ; ++i )
    {
         carry=0;
         for( j=0 ; j<=MAX ; ++j )
         {
              int val;
              val=ans[j]*i+carry;
              ans[j]=val%10;
              carry=val/10;
         }
    }
    int sum=0;
    for( i=0 ; i<=MAX ;++i )
    {
         sum+=ans[i];
    }
    cout<<sum;
    bool flag=1;
    for( i=2 ; i<=sqrt(sum) ; ++i )
    {
         if( sum%i==0 )
         {
             flag=0;
             break;
         }
    }
    if(flag)cout<<'T';
    else cout<<'F';
    system("PAUSE");
    return 0;
}
