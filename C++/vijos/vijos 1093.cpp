#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int a=1,b=1,c;
    int i,n;
    scanf("%d",&n);
    if(n<3) printf("1\n");
    else{
    for(i=3;i<=n;i++)
    {
        c=(a+b)%7654321;
        a=b;b=c;
    }
    cout<<b<<endl;
    }
    system("pause");
    return 0;
}
