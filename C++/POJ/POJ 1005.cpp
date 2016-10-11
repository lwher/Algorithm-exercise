#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    double s,x,y;
    int n;
    int i,year;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%lf %lf",&x,&y);
        s=(x*x+y*y)*3.14/2.0;
        year=(int)(s/50)+1  ;
        printf("Property %d: This property will begin eroding in year %d.\n",i,year);
    }
    printf("END OF OUTPUT.\n");
    system("pause");
    return 0;
}
