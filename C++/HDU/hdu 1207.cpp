#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n;
unsigned long long f[65],h[65];
int main()
{
    int i,j;
    for(i=1;i<=65;i++)  f[i]=f[i-1]*2+1;
    
    for(i=1;i<=65;i++) 
    {
        h[i]=f[i]; 
        for(j=1;j<i;j++)  
        h[i]=min(h[i],h[j]*2+f[i-j]);
    }
    while(scanf("%d",&n)!=EOF)   printf("%I64d\n",h[n]); 
    //system("pause");
    return 0;                             
}
