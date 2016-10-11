#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[47];
int main()
{
    int i;
    while(scanf("%d",&n))
    {
       if(n==0) break;
       for(i=1;i<=n;i++)
       scanf("%d",&a[i]);
       if((n & 1)==0)
       {
       sort(a+1,a+1+n);
       for(i=1;i<=n;i+=2)
       {
          if(a[i]!=a[i+1])
          break;
       }
       if(i<n)
       printf("1\n");
       else
       printf("0\n");
       }
       else
       printf("1\n");
    }
    system("pause");
    return 0;
}
