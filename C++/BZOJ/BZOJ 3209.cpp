#include<cstdio>    
#include<cmath>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long LL;    
const int MAXN = 55, MOD = 10000007;    
int a[MAXN], f[2][MAXN][MAXN];    
int calc(bool less, int dep, int sum) 
{     
      if (!dep)         
      return sum ? sum : 1;     
      if (f[less][dep][sum])         
      return f[less][dep][sum];     
      f[less][dep][sum] = 1;     
      int ed = less ? 1 : a[dep];     
      for (int i = 0; i <= ed; ++i)         
      f[less][dep][sum] = LL(f[less][dep][sum]) * calc(less || i < a[dep], dep - 1, sum + i) % MOD;     
      return f[less][dep][sum]; 
}    
int main() 
{     
      LL n;     
      cin>>n;     
      for (; n; n >>= 1)         
      a[++a[0]] = n & 1;     
      printf("%d\n", calc(0, a[0], 0));     
      system("pause");
      return 0; 
} 
