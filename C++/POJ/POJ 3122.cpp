#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int v[100001];
double x,y,mid;
double q=3.141592653589793238462643383279502884197169399;
int ci,n,f;
bool check(double mm)
{
     int ans=0;
     int i;
     for(i=1;i<=n;i++)
     {ans+=(int)(v[i]/mm);}
     if(ans>=f+1) return 1;
     return 0;
}
int main()
{
   
    cin>>ci;
    int r,i,j;
    for(i=1;i<=ci;i++)
    {
       scanf("%d%d",&n,&f);
       y=0;
       for(j=1;j<=n;j++)
       {
       scanf("%d",&r);v[j]=r*r;
       y+=v[j];
       }
       y/=f+1;
       x=0;
       while(y-x>0.000001)
       {
         mid=(x+y)/2;
         if(check(mid)) x=mid;
         else y=mid;
       }
       printf("%.4lf\n",mid*q);
    }
    system("pause");
    return 0;
}
