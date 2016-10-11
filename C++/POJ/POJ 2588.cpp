#include<iostream>
#include <algorithm>
#include <float.h>
#include<stdio.h>
#include<cmath>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int n;
double r[1001],x[1001],y[1001];
bool mark[1001],o;
double a1=1000,a2=1000;
void doing(int i)
{
     if(o) return;
     if(y[i]-r[i]<0)  {o=1;return;}
     int j;
     if(x[i]-r[i]<0) 
     {
      if(a1>y[i]-sqrt(r[i]*r[i]-x[i]*x[i]))
      a1=y[i]-sqrt(r[i]*r[i]-x[i]*x[i]);
     } 
     if(x[i]+r[i]>1000) 
     {
      if(a2>y[i]-sqrt(r[i]*r[i]-(1000-x[i])*(1000-x[i])))
      a2=y[i]-sqrt(r[i]*r[i]-(1000-x[i])*(1000-x[i]));
     } 
     for(j=1;j<=n;j++)
     {
     if(!mark[j] && sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))<r[i]+r[j]) 
     {mark[j]=1;doing(j);} 
     if(o) return;
     }
}
int main()
{
    int i,j;
    
    cin>>n;
    for(i=1;i<=n;i++)
    {cin>>x[i]>>y[i]>>r[i];}
    for(i=1;i<=n;i++)
    {if(!mark[i] && y[i]+r[i]>1000) {mark[i]=1; doing(i); }}
    
    if(o) cout<<"Bill will be bitten."<<endl;
    
    else 
    {
    cout<<"Bill enters at (0.00, ";
    printf("%.2f",a1);
    cout<<") and leaves at (1000.00, ";
    printf("%.2f",a2);
    cout<<").";
    }
 

    system("pause");
    return 0;
}
