#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int getys(int x)
{
    int sum=0,i,limt=sqrt(x);
    for(i=1;i<=limt;i++)
    {
        if(x%i==0)
        {
             sum++;  if(x/i!=i)  sum++;
        }
    }
    return sum;
}
void solve(int k)
{
     for(int i=1;i<=20000;i++)  if(getys(i)==k)  {printf("%d\n",i);return;}
     printf("NO SOLUTION\n");
}
int main()
{
    int k;
    scanf("%d",&k);
    solve(k);
    system("pause");
    return 0;
}
