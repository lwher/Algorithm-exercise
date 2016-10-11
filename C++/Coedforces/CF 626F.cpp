#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

#define mod 1000000007

using namespace std;

int n, K, A[210], f[210][210][1010];

void Plus(int &x, int num){
    x = (x + num) % mod;
}

int main(){
    scanf("%d%d", &n, &K);
    for(int i = 1; i <= n; i++){
        scanf("%d", &A[i]);
    }
    sort(A + 1, A + 1 +n);
    f[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= K; k++){
                if(!f[i][j][k]) continue;
                int to = k + j * (A[i + 1] - A[i]), p = ((long long)f[i][j][k] * j) % mod;
                if(to > K) continue;
                Plus(f[i + 1][j + 1][to], f[i][j][k]);
                Plus(f[i + 1][j][to], p);
                Plus(f[i + 1][j][to], f[i][j][k]);
                if(j) Plus(f[i + 1][j - 1][to], p);
            }
        }
    }
    int ans = 0;
    for(int k = 0; k <= K; k++) 
        Plus(ans, f[n][0][k]);
    cout << ans << endl;
    return 0;
}
