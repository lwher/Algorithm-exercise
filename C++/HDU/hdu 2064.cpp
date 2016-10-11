#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long f[40];
int main()
{
    int i,n;
    for(i=1;i<=35;i++)  f[i]=3*f[i-1]+2;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%I64d\n",f[n]);
        //cout<<f[n]<<endl;
    }
    //system("pause");
    return 0;
}
