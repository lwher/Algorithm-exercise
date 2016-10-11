#include <iostream> 
#include <cstring> 
#include <cstdio> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <vector> 
#include <map> 
#include <set> 
#include <cmath> 
#define lch(x) x<<1 
#define rch(x) x<<1|1 
#define lson l,m,rt<<1 
#define rson m+1,r,rt<<1|1 
#define MAXN 111111 
#define MAXM 555 
#define INF 1000000007 
using namespace std; 
int n, m; 
int cover[4 * MAXN]; 
int sum[4 * MAXN]; 
void up(int rt) 
{ 
    sum[rt] = sum[lch(rt)] + sum[rch(rt)]; 
} 
void down(int rt, int l, int r) 
{ 
    if(cover[rt]) 
    { 
        cover[lch(rt)] ^= 1; 
        cover[rch(rt)] ^= 1; 
        int m = (l + r) >> 1; 
        sum[lch(rt)] = m - l + 1 - sum[lch(rt)]; 
        sum[rch(rt)] = r - m - sum[rch(rt)]; 
        cover[rt] = 0; 
    } 
} 
void update(int L, int R, int l, int r, int rt) 
{ 
    if(L <= l && R >= r) 
    { 
        cover[rt] ^= 1; 
        sum[rt] = r - l + 1 - sum[rt]; 
        return; 
    } 
    down(rt, l, r); 
    int m = (l + r) >> 1; 
    if(L <= m) update(L, R, lson); 
    if(R > m) update(L, R, rson); 
    up(rt); 
} 
int query(int L, int R, int l, int r, int rt) 
{ 
    if(L <= l && R >= r) return sum[rt]; 
    down(rt, l, r); 
    int m = (l + r) >> 1; 
    int ret = 0; 
    if(L <= m) ret += query(L, R, lson); 
    if(R > m) ret += query(L, R, rson); 
    return ret; 
} 
int main() 
{ 
    int op, s, t; 
    scanf("%d%d", &n, &m); 
    for(int i = 0; i < m; i++) 
    { 
        scanf("%d%d%d", &op, &s, &t); 
        if(op) printf("%d\n", query(s, t, 1, n, 1)); 
        else update(s, t, 1, n, 1); 
    } 
    return 0; 
}