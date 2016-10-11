#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
__int64 a,b,c,k;
int main()
{
    a=1;b=1;
    cin>>k;
    while(1)
    {
        if(a+b>k)  break;
        c=a+b;
        a=b;
        b=c;
    }
    c=a*a+b*b;
    cout<<c<<endl;
    system("pause");
    return 0;
}
