#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int n, X, Y, used = 0;
bool b[1060];
double s = 10000.0, d[1060];
struct node
{int x, y, r;}a[1060];
typedef double LF;
inline LF dis(int i, int j)
{       
        int x = a[i].x - a[j].x, y = a[i].y - a[j].y;       
        return (LF)sqrt(x * x + y * y);
}
vector <int> G[1060];
void dfs(int k)
{       
        if(a[k].x == X && a[k].y == Y)       
        {              
        double ans = s;              
        for(int i = 1; i <= used; i++) ans += d[i];              
        printf("%d", (int)ans);              
        return;       
        }       
        for(int i = 0; i < G[k].size(); i++)       
        {              
                       int u = G[k][i];              
                       if(b[u]) continue;              
                       b[u] = 1;              
                       double p = s;              
                       d[++used] = s;              
                       s = s * a[k].r / a[u].r;              
                       dfs(u);              
                       --used;              
                       s = p;       
        }
} 
int main()
{       
        int i, j, st;       
        cin>>n>>X>>Y;       
        memset(b, false, sizeof(b));       
        for(i = 1; i <= n; i++) 
        {
        cin>>a[i].x>>a[i].y>>a[i].r; 
        if(!a[i].x && !a[i].y) st = i;
        }       
        for(i = 1; i <= n; i++) 
        for(j = i + 1; j <= n; j++)              
        if(dis(i, j) == (LF)(a[i].r + a[j].r)) 
        {G[i].push_back(j); G[j].push_back(i);}       
        b[st] = 1;       
        dfs(st);
        system("pause");
        return 0;
}
