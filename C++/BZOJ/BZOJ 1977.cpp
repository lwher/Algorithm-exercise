#include<iostream>
#include<algorithm>
#include<cctype>
#include<climits>
#include<cstdio>
using namespace std;
#define f1 first
#define f2 second
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100001, MAXM = 300000;
struct edge
{
    int x, y, w;
} e[MAXM];
struct adj_list
{
    int v, w, nxt;
} a[MAXN << 1];
struct set
{
    int fa, s;
} s[MAXN];
bool v[MAXN], in[MAXM];
int n, m, size, h[MAXN], log2[MAXN], fa[MAXN][20], dep[MAXN], q[MAXN];
LL mst;
PII d[MAXN][20];
inline bool operator < (edge x, edge y)
{
    return x.w < y.w;
}
inline void make_set(int x)
{
    s[x].fa = x;
    s[x].s = 1;
}
int find_set(int x)
{
    return s[x].fa == x ? x : s[x].fa = find_set(s[x].fa);
}
inline void union_set(int x, int y)
{
    if (s[x].s < s[y].s)
    {
        s[x].fa = y;
        s[y].s += s[x].s;
    }
    else
    {
        s[y].fa = x;
        s[x].s += s[y].s;
    }
}
inline void add_edge(int x, int y, int w)
{
    a[size].v = y;
    a[size].w = w;
    a[size].nxt = h[x];
    h[x] = size ++;
}
inline void check_max(int &x, int y)
{
    if (y > x)
        x = y;
}
inline void check_min(LL &x, LL y)
{
    if (y < x)
        x = y;
}
inline int getint()
{
    char c;
    while (!isdigit(c = getchar()));
    int ret = c - 48;
    while (isdigit(c = getchar()))
        ret = ret * 10 + c - 48;
    return ret;
}

inline void init()
{
    n = getint();
    m = getint();
    for (int i = 0; i < m; ++ i)
    {
        e[i].x = getint();
        e[i].y = getint();
        e[i].w = getint();
    }
    sort(e, e + m);
    for (int i = 1, j = 0; i <= n; ++ i)
    {
        make_set(i);
        h[i] = -1;
        log2[i] = j;
        if (i == (1 << j + 1) - 1)
            ++ j;
    }
}

inline void kruskal()
{
    for (int i = 0, c = 1; c < n; ++ i)
    {
        int fx = find_set(e[i].x), fy = find_set(e[i].y);
        if (fx != fy)
        {
            mst += e[i].w;
            ++ c;
            in[i] = true;
            add_edge(e[i].x, e[i].y, e[i].w);
            add_edge(e[i].y, e[i].x, e[i].w);
            union_set(fx, fy);
        }
    }
}

inline void bfs()
{
    q[0] = 1;
    v[1] = true;
    dep[1] = 0;
    for (int l = 0, r = 0; l <= r; ++ l)
    {
        int u = q[l];
        for (int k = 1; k <= log2[dep[u]]; ++ k)
        {
            fa[u][k] = fa[fa[u][k - 1]][k - 1];
            d[u][k].f1 = max(d[u][k - 1].f1, d[fa[u][k - 1]][k - 1].f1);
            d[u][k].f2 = max(d[u][k - 1].f1 != d[u][k].f1 ? d[u][k - 1].f1 : d[u][k - 1].f2,
                             d[fa[u][k - 1]][k - 1].f1 != d[u][k].f1 ? d[fa[u][k - 1]][k - 1].f1 : d[fa[u][k - 1]][k - 1].f2);
        }
        for (int k = h[u]; k != -1; k = a[k].nxt)
            if (!v[a[k].v])
            {
                v[a[k].v] = true;
                dep[a[k].v] = dep[u] + 1;
                fa[a[k].v][0] = u;
                d[a[k].v][0].f1 = a[k].w;
                q[++ r] = a[k].v;
            }
    }
}
inline PII max_edge(int x, int y)
{
    PII ret = make_pair(0, 0);
    if (dep[x] > dep[y])
        swap(x, y);
    while (dep[y] > dep[x])
    {
        int k = log2[dep[y] - dep[x]];
        check_max(ret.f1, d[y][k].f1);
        check_max(ret.f2, d[y][k].f1 != ret.f1 ? d[y][k].f1 : d[y][k].f2);
        y = fa[y][k];
    }
    if (x == y)
        return ret;
    for (int k = log2[dep[x]]; k >= 0; -- k)
        if (fa[x][k] != fa[y][k])
        {
            check_max(ret.f1, max(d[x][k].f1, d[y][k].f1));
            check_max(ret.f2, max(d[x][k].f1 != ret.f1 ? d[x][k].f1 : d[x][k].f2,d[y][k].f1 != ret.f1 ? d[y][k].f1 : d[y][k].f2));
            x = fa[x][k];
            y = fa[y][k];
        }
    check_max(ret.f1, max(d[x][0].f1, d[y][0].f1));
    check_max(ret.f2, max(d[x][0].f1 != ret.f1 ? d[x][0].f1 : d[x][0].f2,d[y][0].f1 != ret.f1 ? d[y][0].f1 : d[y][0].f2));
    return ret;
}
inline void work()
{
    LL ans = LONG_LONG_MAX;
    for (int i = 0; i < m; ++ i)
        if (!in[i])
        {
            PII t = max_edge(e[i].x, e[i].y);
            check_min(ans, mst - (t.f1 == e[i].w ? t.f2 : t.f1) + e[i].w);
        }
    printf("%lld\n", ans);
}
int main()
{
    init();
    kruskal();
    bfs();
    work();
    system("pause");
    return 0;
}

