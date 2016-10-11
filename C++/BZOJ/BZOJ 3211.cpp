#include<iostream>
#include<cstdlib>
#include<cmath> 
#include<cstdio>
#include<algorithm>
using namespace std;    
typedef long long LL;    
const int MAXN = 111111;    
int n, a[MAXN], f[MAXN]; 
LL s[MAXN];    
inline void add(int x,int v) 
{     
      for(;x<=n;x+=x & -x)         
      s[x]+=v; 
}    
inline LL sum(int x) 
{     
      LL ret=0;     
      for(;x;x-=x & -x)         
      ret+=s[x];     
      return ret; 
}   
int find(int x) 
{     
      return f[x]== x ? x : f[x] = find(f[x]); 
}    
int main() 
{     
      scanf("%d",&n);     
      for(int i=1;i<=n;++i) 
      {         
                scanf("%d",&a[i]);         
                add(i,a[i]);         
                f[i]=a[i] <= 1 ? i + 1 : i;     
      }     
      f[n+1]=n+1;     
      int m;     
      scanf("%d",&m);     
      while(m--) 
      {         
                int x,l,r;         
                scanf("%d%d%d",&x,&l,&r);         
                if(x==1)             
                printf("%lld\n",sum(r) - sum(l - 1));         
                else 
                {             
                              for(l=find(l); l <= r; l = find(l+1)) 
                {                 
                              int t=int(sqrt(a[l]));                 
                              add(l,t-a[l]);                 
                              if((a[l]=t)==1)                     
                              f[l]=l+1;             
                }         
                }     
                }    
      system("pause"); 
      return 0; 
} 
