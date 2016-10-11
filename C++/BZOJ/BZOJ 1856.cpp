#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m;
long long ans=1,tmp=1;
const int p=20100403;
long long qpow(long long a,int b)
{
     long long res=1;a%=p;
     while(b>0)
     {
         if(b & 1)  res=(res*a)%p;
         a=(a*a)%p;
         b=b>>1;
     }
     return res;
}
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    ans=n-m+1;
    for(i=2;i<=n+m;i++) ans=(ans*i)%p;
    for(i=2;i<=m;i++) tmp=(tmp*i)%p;
    for(i=2;i<=n+1;i++) tmp=(tmp*i)%p;
    ans=(ans*qpow(tmp,p-2))%p;
    cout<<ans<<endl;
    system("pause");
    return 0;
}
