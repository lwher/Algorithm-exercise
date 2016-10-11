#include<stdio.h> 
long long a[1000009]; 
int main() 
{ 
    a[1]=1; 
    int n,i,id=1; 
  
    while(scanf("%d",&n)!=EOF) 
    {    id=1; 
        for(i=2;i<=n;i+=2) 
    { 
        a[i]=a[i+1]=(a[i-1]+a[id])%1000000000; 
        id++; 
    } 
        printf("%lld\n",a[n]); 
    } 
    return 0; 
}