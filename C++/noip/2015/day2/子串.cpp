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

int n, m, K, dp[2][1003][203], sum[2][1003][203], len[1010][210];
char A[1010], B[210];

void init(){
    scanf("%d %d %d", &n, &m, &K);
    scanf("%s", A + 1);
    scanf("%s", B + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int k = 0;
            while(j - k > 0 && i - k > 0 && A[i - k] == B[j - k]) k++;
            len[i][j] = k;
        }
    }
}

void DP(){
    for(int i = 0; i <= n; i++) dp[0][i][0] = 1, sum[0][i][0] = 1;
    for(int j = 1; j <= m; j++)
        for(int i = 1; i <= n; i++)
            sum[0][i][j] = (dp[0][i][j]+ sum[0][i - 1][j - 1]) % mod;
    int p = 1, q = 0;
    for(int k = 1; k <= K; k++){
        memset(sum[p], 0, sizeof(sum[p]));
        for(int j = 1; j <= m; j++){
            for(int i = 1; i <= n; i++){
                dp[p][i][j] = dp[p][i - 1][j];
                if(len[i][j] > 0){
                    if(len[i][j] == i || len[i][j] == j){
                        dp[p][i][j] = dp[p][i][j] + sum[q][i - 1][j - 1];
                        if(dp[p][i][j] > mod) dp[p][i][j] -= mod;
                    }
                    else{
                        dp[p][i][j] = dp[p][i][j] + sum[q][i - 1][j - 1] - sum[q][i - len[i][j] - 1][j - len[i][j] - 1];
                        if(dp[p][i][j] > mod) dp[p][i][j] -= mod;
                    }
                    if(dp[p][i][j] < 0) dp[p][i][j] += mod;
                }
                sum[p][i][j] = dp[p][i][j] + sum[p][i - 1][j - 1];
                if(sum[p][i][j] > mod) sum[p][i][j] -= mod;
            }
        }
        p ^= 1; q ^= 1;
    }
    cout <<dp[q][n][m] << endl;
}

int main(){
    init();
    DP();
    return 0;
}
