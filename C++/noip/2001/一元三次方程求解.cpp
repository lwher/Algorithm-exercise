#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define eps 1e-10
using namespace std;
double a,b,c,d;
double f(double x)
{
       return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    cin>>a>>b>>c>>d;
    int i;    
    for(i=-100;i<=100;i++)
    { 
        if(fabs(f(i))<eps)  printf("%d.00 ",i);
        else  
        if(f(i)*f(i+1)<-eps)  
        {
            double l=i,r=i+1,mid;
            while(r-l>0.00001)
            {
                 mid=(l+r)*0.50000;
                 if(f(l)*f(mid)<=0)  r=mid;
                 else l=mid;
            }
            printf("%.2lf ",mid);
        }
    }
    system("pause");
    return 0;
}
