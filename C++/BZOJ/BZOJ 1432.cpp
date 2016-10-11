#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    if(n==1 && k==1)  printf("1\n");
    else
    {
        if(n-k+1<k)  k=n-k+1;
        printf("%d\n",2*k);
    }
    return 0;
}