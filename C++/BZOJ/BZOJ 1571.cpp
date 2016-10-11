#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
const int MAXC = 111, MAXT = 11111; 
int h[MAXT][MAXC], u[MAXC], f[MAXT][MAXC], g[MAXT]; 
inline void checkmax(int &x, int y) 
{ 
    if (y > x) 
        x = y; 
} 
int main() 
{ 
    int t, s, n; 
    scanf("%d%d%d", &t, &s, &n); 
    ++ t;  
    for (int i = 0; i < s; ++ i) 
    { 
        int m, l, a; 
        scanf("%d%d%d", &m, &l, &a); 
        ++ m; 
        checkmax(h[m + l][a], m); 
    } 
    for (int i = 1; i < MAXC; ++ i) 
        u[i] = MAXT; 
    for (int i = 0; i < n; ++ i) 
    { 
        int c, d; 
        scanf("%d%d", &c, &d); 
        for (int j = c; j < MAXC; ++ j) 
            if (d < u[j]) 
                u[j] = d; 
    } 
    f[0][1] = 0; 
    for (int i = 2; i < MAXC; ++ i) 
        f[0][i] = -MAXT; 
    for (int i = 1; i <= t; ++ i) 
        for (int j = 1; j < MAXC; ++ j) 
        { 
            f[i][j] = f[i - 1][j]; 
            if (h[i][j]) 
                checkmax(f[i][j], g[h[i][j]]); 
            if (u[j] < MAXT && i >= u[j]) 
                checkmax(f[i][j], f[i - u[j]][j] + 1); 
            checkmax(g[i], f[i][j]); 
        } 
    printf("%d\n", g[t]); 
   // system("pause"); 
    return 0; 
}