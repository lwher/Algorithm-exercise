#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>


using namespace std;

int n, V[100010];
long long dist[100010], ans, res;
std::vector<int> to[100010], v[100010];

void Ins(int a, int b, int c){
    to[a].push_back(b); v[a].push_back(c);
}

void dfs(int x, int fa){
    for(int i = 0; i < to[x].size(); i++){
        if(to[x][i] == fa) continue;
        dist[to[x][i]] = dist[x] + v[x][i];
        dfs(to[x][i], x);
    }
}

int main(){
    int a, b, c;
    while(scanf("%d", &n) != EOF){
        n++; ans = 0; res = 0;
        for(int i = 1; i <= n; i++){ 
            to[i].clear(); v[i].clear();
        }
        for(int i = 1; i <= n; i++)
            scanf("%d", &V[i]);
        for(int i = 1; i < n; i++){
            scanf("%d %d %d", &a, &b, &c);
            ++a; ++b;
            Ins(a, b, c); Ins(b, a, c);
            res += 2 * c;
        }
        dist[1] = 0;
        dfs(1, 0);
        //cout << dist[1] << " " << dist[2] << " " <<dist[3] << endl;
        res += V[1];
        ans = res;
        for(int i = 1; i <= n; i++){
            ans = min(ans, res - V[1] - dist[i] + V[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
