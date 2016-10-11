#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int n,k,i;
    scanf("%d",&n);
    if(n%6!=2 && n%6!=3)
    {
        for(i=2;i<=n;i+=2)  printf("%d\n",i);
        for(i=1;i<=n;i+=2)  printf("%d\n",i);
    }
    else
    {
        k=n/2;
        if(k & 1)
        {
            for(i=k;i<n;i+=2)  printf("%d\n",i);
            for(i=1;i<=k-2;i+=2)  printf("%d\n",i);
            for(i=k+3;i<=n;i+=2)  printf("%d\n",i);
            for(i=2;i<=k+1;i+=2)  printf("%d\n",i);
        }
        else
        {
            for(i=k;i<=n;i+=2) printf("%d\n",i);
            for(i=2;i<=k-2;i+=2)  printf("%d\n",i);
            for(i=k+3;i<n;i+=2)  printf("%d\n",i);
            for(i=1;i<=k+1;i+=2) printf("%d\n",i);
        }
        if(n & 1)  printf("%d\n",n);
    }
    return 0;
}