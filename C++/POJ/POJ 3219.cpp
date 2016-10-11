#include<iostream>
#include<cstdio>
using namespace std;

int count(int n)
{
    int num=0;
    while(n)
    {
        num+=n/2;
        n=n/2;
    }
    return num;
}

int main(void)
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2&&!(n==0&&k==0))
    {
        int a,b,c;
        a=count(n);
        b=count(k);
        c=count(n-k);
        if(a>b+c)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
