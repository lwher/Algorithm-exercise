#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int year,month,day;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&year,&month,&day);
        if(day==30 && (month==9 || month==11)) printf("YES\n");
        else if((day+month)%2==0)  printf("YES\n");
        else printf("NO\n");
    }
    system("pause");
    return 0;
}
