#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 50001
int N,a[maxn],Max;
inline void read(int&a)
{
   char ch;while(!(((ch=getchar())>='0')&&(ch<='9')));a=ch-'0';
   while(((ch=getchar())>='0')&&(ch<='9'))a*=10,a+=ch-'0';  
}int main()
{
   read(N);for(int i=1;i<=N;++i)read(a[i]);
   for(int i=1;i<=N;++i)
   {
   for(int j=i-1,k=0;j>=1;--j){if(a[j]>a[i]&&k==1)break;if(a[j]>a[i])++k;Max=max(a[i]^a[j],Max);}
   for(int j=i+1,k=0;j<=N;++j){if(a[j]>a[i]&&k==1)break;if(a[j]>a[i])++k;Max=max(a[i]^a[j],Max);}
   }
   
   printf("%d\n",Max);
   system("pause");
   return 0;
}
