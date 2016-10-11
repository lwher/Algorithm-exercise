#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,d,k;
long long a[510],b[510];// b:=1  a: -->d
long long num[510];
void jzchen(long long A[510],long long B[510],long long C[510])
{
     long long ans[510]={0};
     int i,j;
     for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  
     {
         if(i-j+1>0)  ans[i]=(ans[i]+(A[j]*B[i-j+1])%m)%m;
         else ans[i]=(ans[i]+(A[j]*B[i-j+1+n])%m)%m;
     }
     for(i=1;i<=n;i++)  C[i]=ans[i];
}
int main()
{
    int i;
    scanf("%d%d%d%d",&n,&m,&d,&k);
    a[1]=1;
    for(i=1;i<=n;i++)  scanf("%I64d",&num[i]);
    for(i=1;i<=d;i++)  {a[i+1]=1;a[n-i+1]=1;}    
    b[1]=1;
    while(k>0)
    {
        if(k & 1)  jzchen(b,a,b);
        k=k>>1;
        jzchen(a,a,a);
    }
    jzchen(num,b,num);
    for(i=1;i<n;i++)  printf("%I64d ",num[i]);  printf("%I64d\n",num[i]);
    system("pause");
    return 0;
}
