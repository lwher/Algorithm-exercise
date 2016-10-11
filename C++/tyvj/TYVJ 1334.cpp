#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int n;
long long int f[1000000];
int main()
{
    cin>>n;
    f[1]=1;f[2]=1;
    int i=2;
    while(f[i-1]+f[i]<=n)
    {
     i++;
     f[i]=f[i-1]+f[i-2];
    }
    cout<<f[i-1]<<" "<<f[i];
    system("pause");
    return 0;
}
