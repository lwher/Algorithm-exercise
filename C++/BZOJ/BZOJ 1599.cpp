#include <iostream> 
#include <cstring> 
#include <cstdio> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <vector> 
#include <map> 
#include <set> 
#define MAXN 51111 
#define MAXM 555 
#define INF 1000000007 
using namespace std; 
int f[4][86]; 
int main() 
{ 
    int a, b, c; 
    scanf("%d%d%d", &a, &b, &c); 
    for(int i = 1; i <= a; i++) f[1][i] = 1; 
    for(int i = 1; i <= a + b; i++) 
        for(int j = 1; j <= b; j++) 
            if(i > j) f[2][i] += f[1][i - j]; 
    for(int i = 1; i <= a + b + c; i++) 
        for(int j = 1; j <= c; j++) 
            if(i > j) f[3][i] += f[2][i - j]; 
    int ans = 0; 
    for(int i = 1; i <= a + b + c; i++) 
        if(f[3][ans] < f[3][i]) 
            ans = i; 
    printf("%d\n", ans); 
    return 0; 
}