#include <iostream> 
#include <fstream> 
#include <iomanip> 
#include <algorithm> 
#include <cstring> 
#include <cstdio> 
#include <cstdlib> 
#include <functional> 
#include <cmath> 
using namespace std; 
const int maxn = 2000; 
const int maxm = 100000 + 50; 
const double EPS = 1e-7; 
const int inf = ~0U >> 5; 
struct Edge 
{ 
    int v, cap, Pre; 
    double w; 
    Edge(int _v = 0, int _cap = 0, double _w = 0.0, int _Pre = 0):v(_v), cap(_cap), w(_w), Pre(_Pre){} 
}; 
Edge E[maxm << 1]; 
int EN[maxn] = {0}; 
int lastedge = 1; 
void InsEdge(int u, int v, int cap, double w) 
{ 
    E[++lastedge] = Edge(v, cap, w, EN[u]), EN[u] = lastedge; 
    E[++lastedge] = Edge(u, 0, -w, EN[v]), EN[v] = lastedge; 
} 
double dist[maxn] = {0}; 
int Q[maxn << 3] = {0}; 
bool Inq[maxn] = {0}; 
bool vis[maxn] = {0}; 
int S, T; 
int MaxFlow = 0; 
double MinCost = 0.0; 
int n, m, s; 
bool SPFA() 
{ 
    memset(Inq, 0, sizeof(Inq)); 
    int head = 0, tail = 0; 
    for (int i = 1; i <= n; i++) 
    { 
        dist[i] = 100000; 
    } 
    dist[T] = 0; 
    Q[0] = T; 
    Inq[T] = 1; 
    for (; head <= tail; ) 
    { 
        int u = Q[head]; 
        head++; 
        Inq[u] = false; 
        for (int i = EN[u]; i; i = E[i].Pre) 
        { 
            if (E[i ^ 1].cap > 0 && dist[E[i].v] - (dist[u] + E[i ^ 1].w) > EPS) 
            { 
                dist[E[i].v] = dist[u] + E[i ^ 1].w; 
                if (!Inq[E[i].v]) 
                { 
                    Inq[E[i].v] = true; 
                    if (head > 0 && head <= tail && dist[E[i].v] - dist[Q[head]] < -EPS) 
                    { 
                        Q[--head] = E[i].v; 
                    } 
                    else
                    { 
                        Q[++tail] = E[i].v; 
                    } 
                } 
            } 
        } 
    } 
    return dist[S] < 100000.0; 
} 
int DFS(int X, int flow) 
{ 
    if (X == T) 
    { 
        return flow; 
    } 
    int cnt = 0; 
    vis[X] = true; 
    for (int i = EN[X]; i; i = E[i].Pre) 
    { 
        if (E[i].cap > 0 && fabs(dist[X] - (dist[E[i].v] + E[i].w)) < EPS && !vis[E[i].v]) 
        { 
            int w = min(E[i].cap, flow - cnt); 
            w = DFS(E[i].v, w); 
            E[i].cap -= w; 
            E[i ^ 1].cap += w; 
            cnt += w; 
            if (cnt == flow) 
            { 
                return flow; 
            } 
        } 
    } 
    return cnt; 
} 
void ZKW_MinCost() 
{ 
    while (SPFA()) 
    { 
        int t = 0; 
        do
        { 
            memset(vis, false, sizeof(vis)); 
            t = DFS(S, inf); 
            MaxFlow += t; 
            MinCost += exp(dist[S]) * t; 
        } 
        while (t); 
    } 
} 
double logp[102]; 
int main() 
{ 
    //fin >> n >> m >> s; 
    //freopen("profit.in","r",stdin); 
    //freopen("profit.out","w",stdout); 
    scanf("%d%d%d",&n,&m,&s); 
    S = 1; T = n; 
    for (int i = 0; i <= 100; i++) 
    { 
        logp[i] = log(1 + i / 100.0); 
    } 
    for (int i = 1; i <= m; i++) 
    { 
        int u, v, c, x; 
        //fin >> u >> v >> c >> x; 
        scanf("%d%d%d%d",&u,&v,&c,&x); 
        InsEdge(u, v, c, logp[x]); 
    } 
    ZKW_MinCost(); 
    //fout << MaxFlow << endl; 
    printf("%d\n",MaxFlow); 
    //fout << MinCost * s << endl; 
    printf("%.1lf\n",MinCost*s); 
    return 0; 
}