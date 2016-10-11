#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 3010
#define M 3000010
#define INF 0x7fffffff

using namespace std;

int n, m, S, T, max_flow;
int H[N], gap[N], cur[N];
int sz = 1, to[M], v[M], pre[M], last[N];
int Q[N];

void Ins(int a, int b, int c){
    sz++; to[sz] = b; v[sz] = c; pre[sz] = last[a]; last[a] = sz;
    sz++; to[sz] = a; v[sz] = 0; pre[sz] = last[b]; last[b] = sz;
}

void bfs(){
    memset(H, -1, sizeof(H));
    memset(gap, 0, sizeof(gap));
    int t = 1, w = 1, now;
    Q[1] = T;
    H[T] = 0; gap[0] = 1;
    while(t <= w){
        now = Q[t]; t++;
        for(int i = last[now]; i; i = pre[i]){
            if(H[to[i]] == -1){
                H[to[i]] = H[now] + 1;
                gap[H[to[i]]]++;
                Q[++w] = to[i];
            }
        }
    }
}

int dfs(int x, int F){
    if(x == T){
        max_flow = max(max_flow, F);
        return F;
    }
    int i, used = 0, w;
    for(i = cur[x]; i; i = pre[i]){
        if(v[i] > 0 && H[to[i]] == H[x] - 1){
            w = min(v[i], F - used);
            w = dfs(to[i], w);
            v[i] -= w; v[i ^ 1] += w; used += w;
            if(v[i] > 0) cur[x] = i;
            if(F == used) return F;
        }
    }
    gap[H[x]]--;
    if(!gap[H[x]]) H[S] = n + 2;
    cur[x] = last[x];
    gap[++H[x]]++;
    return used;
}

int SAP(){
    int res = 0;
    bfs();
    for(int i = 1; i <= n; i++) cur[i] = last[i];
    while(H[S] < n + 2) res += dfs(S, INF);
    return res;
}

int main(){
    int Case, X, a, b, c;
    cin >> Case;
    while(Case--){
        sz = 1;
        memset(last, 0, sizeof(last));
        scanf("%d%d%d%d%d", &X, &n, &m, &S, &T);
        S++; T++;
        for(int i = 1; i <= m; i++){
            scanf("%d%d%d", &a, &b, &c);
            a++; b++;
            Ins(a, b, c);
        }
        max_flow = 0;
        int res = SAP();
        printf("%d %.3f\n", X, (double)(res) * 1.000 / max_flow);
    }
    return 0;
}
