#include<iostream>
#include<stdio.h>
using namespace std;
int f[81];
int n;
int main()
{
    cin>>n;
    f[0]=1;
    int i,j;
    for(i=1;i<=n-1;i++)
    for(j=0;j<=n-i;j++)
    f[j+i]+=f[j];
    cout<<f[n];
    system("pause");
    return 0;
}
