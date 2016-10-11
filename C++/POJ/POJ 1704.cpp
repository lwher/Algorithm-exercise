#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int t,n;
int qizi[1010],dp[510];
int main()
{
    int i,ans;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       for(i=1;i<=n;i++)
       scanf("%d",&qizi[i]);
       sort(qizi+1,qizi+1+n);
       if((n & 1)==0)
       {
             for(i=1;i<=n;i+=2)
             {
                dp[(i+1)/2]=qizi[i+1]-qizi[i]-1;
             }
       }
       else
       {
           dp[1]=qizi[1]-1;
           for(i=2;i<=n;i+=2)
           {
               dp[(i/2)+1]=qizi[i+1]-qizi[i]-1;
           }
       }
       ans=dp[1];
       for(i=2;i<=(n+1)/2;i++)
       ans=(ans ^ dp[i]);
       if(!ans)
       printf("Bob will win\n");
       else
       printf("Georgia will win\n");
       
    }
    system("pause");
    return 0;
}
