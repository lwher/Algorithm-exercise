#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,d;
double dist,D;
int main()
{
    int fz,fm,a,b;
    scanf("%d%d",&n,&d);
    dist=1e20;
    for(b=1;b<=32767;b++)
    {
        a=(int)floor(double(n)/d*b);
        if(a*d!=n*b)
        {
            D=fabs(double(n)/d-double(a)/b);
            if(D<dist)
            {
                dist=D;fz=a;fm=b;
            }
        }
        a=(int)floor(double(n)/d*b)+1;
        if(a*d!=n*b)
        {
            D=fabs(double(n)/d-double(a)/b);
            if(D<dist)
            {
                dist=D;fz=a;fm=b;
            }
        }
    }
    printf("%d %d\n",fz,fm);
    return 0;
}