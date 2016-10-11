#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<sstream>
#include<queue>
#include<vector>
#define MAXN 100005
#define MAXM 211111
#define eps 1e-8
#define INF 50000001
#define lch(x) x<<1
#define rch(x) x<<1|1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int mi[MAXN * 4];
int cover[MAXN * 4];
struct node
{
    int l, r;
}q[MAXN];
bool cmp(node x, node y)
{
    if(x.r != y.r) return x.r < y.r;
    return x.l > y.l;
}
int a[MAXN];
int n, m;
void up(int rt)
{
    mi[rt] = min(mi[lch(rt)], mi[rch(rt)]);
}
void down(int rt)
{
    if(cover[rt])
    {
        cover[lch(rt)] += cover[rt];
        cover[rch(rt)] += cover[rt];
        mi[lch(rt)] -= cover[rt];
        mi[rch(rt)] -= cover[rt];
        cover[rt] = 0;
    }
}
void build(int l, int r, int rt)
{
    if(l == r)
    {
        mi[rt] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    up(rt);
}
int check(int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r) return mi[rt];
    down(rt);
    int m = (l + r) >> 1;
    int mi = INF;
    if(L <= m) mi = min(mi, check(L, R, lson));
    if(R > m) mi = min(mi, check(L, R, rson));
    return mi;
}
void update(int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        cover[rt] += 1;
        mi[rt] -= 1;
        return;
    }
    down(rt);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, lson);
    if(R > m) update(L, R, rson);
    up(rt);
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, n, 1);
    for(int i = 0; i < m; i++) scanf("%d%d", &q[i].l, &q[i].r);
    sort(q, q + m, cmp);
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        if(check(q[i].l, q[i].r, 1, n, 1) > 0) ans++, update(q[i].l, q[i].r, 1, n, 1);
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}
