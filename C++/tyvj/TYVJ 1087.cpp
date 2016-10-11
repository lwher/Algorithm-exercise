#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long f[1000010];
int n;
int main()
{
    int i,j,k;
    scanf("%d",&n);
    f[0]=1;
    int mo=1000000000;
    for(i=0;(1<<i)<=n;i++)
    {
       k=1<<i;
       for(j=0;j<=n-k;j++)
       { 
       f[j+k]+=f[j];
       f[j+k]=f[j+k]%mo;
       }
    }
   cout<<f[n]<<endl;
    system("pause");
    return 0;
}
