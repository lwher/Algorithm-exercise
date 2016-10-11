#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n, m, tt = 1, map[501][501], color[501];
bool check(int x){
    for(int i = 1; i <= n; i++){
        if(i != x && !map[x][i]) return 0;
    }
    return 1;
}

void dfs(int x){
    for(int i = 1; i <= n; i++) if(map[x][i]){
        if(i == x || color[i]) continue;
        color[i] = color[x];
        dfs(i);
    }
}

void solve(){
    if(tt > 3){
        printf("No\n");
        return;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(color[i] == color[j] && !map[i][j]){
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
    for(int i = 1; i <= n; i++){
        if(color[i] == 1) printf("b"); else
        if(color[i] == 2) printf("a"); else
        if(color[i] == 3) printf("c"); else
        printf(" ");
    }
    printf("\n");
}

int main(){
    int a, b;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &a, &b);
        map[a][b] = map[b][a] = 1;
    }
    for(int i = 1; i <= n; i++) if(check(i)) color[i] = 1;
    
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            color[i] = ++tt;
            dfs(i);
        }
    }
    solve();
    return 0;
}
