#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;
int n;
int a,s;
int ans;
bool up=0;
int main()
{
    int i,j;
    cin>>n;
    cin>>a;
    
    ans=1;
    for(i=2;i<=n;i++)
    {
    scanf("%d",&s);
    if(i==2)
    {
       if(s>a)
       up=1;
    }
    if(up && s<a)
    {ans++;up=0;}
    else
    if(!up && s>a)
    {ans++;up=1;}
    a=s;
    }
    if(ans>1)  ans++;
    cout<<ans;
    system("pause");
    return 0;
}
