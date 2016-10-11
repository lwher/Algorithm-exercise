#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 1111
#define INF 1011111111
using namespace std;
struct EDGE
{
    int v, w;
    EDGE(){}
    EDGE(int _v, int _w) {v = _v; w = _w;}
};
vector<EDGE>g[MAXN];
int vis[MAXN];
int dis[MAXN];
int q[MAXN * 4];
int n, k, m;
int spfa(int lim)
{
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    for(int i = 1; i <= n; i++) dis[i] = INF;
    dis[1] = 0;
    int h = 0, t = 0;
    q[t++] = 1;
    while(h < t)
    {
        int u = q[h++];
        vis[u] = 0;
        int size = g[u].size();
        for(int i = 0; i < size; i++)
        {
            int v = g[u][i].v;
            int w = g[u][i].w;
            int ad = 0;
            if(w > lim) ad = 1;
            if(dis[u] + ad < dis[v])
            {
                dis[v] = dis[u] + ad;
                if(!vis[v])
                {
                    q[t++] = v;
                    vis[v] = 1;
                }
            }
        }
    }
    if(dis[n] <= k) return 1;
    else return 0;
}
void solve()
{
    scanf("%d%d%d", &n, &m, &k);
    int x, y, z;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back(EDGE(y, z));
        g[y].push_back(EDGE(x, z));
    }
    int low = 0, high = INF, ans = INF;
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        if(spfa(mid)) ans = min(ans, mid), high = mid - 1;
        else low = mid + 1;
    }
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
}
int main()
{
    solve();
    //while(1);
    return 0;
}


