#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int f[101],d[101];
int num[101];
int n;
int ans;
int main()
{
    int i,j,k;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>num[i];
    for(i=1;i<=n;i++)
    {
    k=0;
    for(j=1;j<i;j++)
    if(f[j]>k && num[j]<num[i])   
    k=f[j];
    f[i]=k+1;
    } 
    for(i=n;i>=1;i--)
    {
    k=0;
    for(j=i+1;j<=n;j++)
    if(d[j]>k && num[j]<num[i])   
    k=d[j];
    d[i]=k+1;
    } 
    ans=max(f[n],d[1]);
    for(i=2;i<=n-1;i++)
    if(f[i]+d[i]-1>ans)
    ans=f[i]+d[i]-1;
    cout<<n-ans;
    
    system("pause");
    return 0;
}
