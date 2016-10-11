#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n;
int main()
{
    while(scanf("%d",&n))
    {
         if(n==0)  break;
         if(n & 1)  printf("Bob\n"); else printf("Alice\n");
    }
    system("pause");
    return 0;
}
