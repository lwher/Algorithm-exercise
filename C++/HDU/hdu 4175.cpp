#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int C, T, L, E[26][1001], P[26][1001];
long long f[26][1001];

int main(){
    int t;
    cin >> t;
    while(t--){
        scanf("%d%d%d", &C, &T, &L);
        for(int i = 1; i <= C; i++){
            for(int j = 1; j <= T; j++){
                scanf("%d%d", &P[i][j], &E[i][j]);
            }
        }
        memset(f, 127, sizeof(f));
        f[0][0] = 0;
        for(int i = 0; i < C; i++){
            for(int j = 0; j <= T; j++) if(f[i][j] < f[0][1]){
                for(int k = 1; k <= T; k++){
                    f[i + 1][k] = min(f[i + 1][k], f[i][j] + E[i + 1][k] + abs(P[i][j] - P[i + 1][k]));
                }
            }
        }
        long long ans = 1e20;
        for(int i = 1; i <= T; i++)
            ans = min(ans, f[C][i] + abs(L - P[C][i]));
        cout << ans << endl;
    }
    return 0;
}
