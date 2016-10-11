#include <cstdio> 
#include <iostream> 
#include <cmath> 
using namespace std; 
  
const int max_n = 50000 + 10; 
int n, x, y, t; 
int a[max_n] = {0}; 
int min_num[max_n][17] = {0}, max_num[max_n][17] = {0}; 
  
inline int ask_min()//x,y区间的最值 
{ 
    int k = log((double)(y - x + 1))/log(2.0); 
    return min(min_num[x][k], min_num[y - (1<<k) + 1][k]); 
} 
  
inline int ask_max() 
{ 
    int k = log((double)(y - x + 1))/log(2.0); 
    return max(max_num[x][k], max_num[y - (1<<k) + 1][k]); 
} 
  
inline void read(int &x) 
{ 
       char ch; 
       while (ch=getchar(),ch>'9' || ch<'0') ; 
       x=ch-48; 
       while (ch=getchar(),ch<='9' && ch>='0') x=x*10+ch-48;  
} 
  
int main() 
{ 
    read(n); read(t); 
    for (int i = 1; i <= n; ++ i)    scanf("%d", &a[i]); 
    for (int i = 1; i <= n; ++ i)    min_num[i][0] = max_num[i][0] = a[i]; 
        int k = (int)(log((double)n)/log(2.0));   
    for (int j = 1; j <= k; ++ j) 
    { 
        for (int i = 1; i + (1<<j)-1 <=n; ++ i) 
        { 
            int m = i + (1 << (j - 1)); 
            min_num[i][j] = min(min_num[i][j - 1], min_num[m][j - 1]); 
            max_num[i][j] = max(max_num[i][j - 1], max_num[m][j - 1]); 
        } 
    } 
    while (t --) 
    { 
        read(x); read(y); 
        printf("%d\n", ask_max()-ask_min()); 
    } 
    return 0; 
}