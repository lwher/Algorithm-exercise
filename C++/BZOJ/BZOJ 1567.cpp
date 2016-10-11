#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <cstring> 
#define rep(i,n) for (int i=1;i<=n;i++) 
#define repr(i,n) for (int i=n;i>=1;i--) 
  
using namespace std; 
  
const int N=55; 
int m[2][N][N],ans,n; 
long long hash[2][N][N][N]; 
  
void makehash(int o) 
{ 
       rep(len,n)rep(x,n-len+1)rep(y,n-len+1) 
       { 
              for (int i=x;i<=x+len-1;i++) 
                     for (int j=y;j<=y+len-1;j++) hash[o][x][y][len]+=m[o][i][j]*((i-x)*10171019+j-y)*815713; 
       } 
} 
  
void init() 
{ 
       scanf("%d",&n); 
       rep(i,n) rep(j,n) scanf("%d",&m[0][i][j]); 
       rep(i,n) rep(j,n) scanf("%d",&m[1][i][j]); 
       makehash(0);makehash(1); 
} 
  
void dawn() 
{ 
       repr(len,n)rep(x1,n-len+1)rep(y1,n-len+1)rep(x2,n-len+1)rep(y2,n-len+1) 
              if (hash[0][x1][y1][len]==hash[1][x2][y2][len]) {printf("%d\n",len);return;} 
} 
  
int main() 
{ 
       init(); 
       dawn(); 
}