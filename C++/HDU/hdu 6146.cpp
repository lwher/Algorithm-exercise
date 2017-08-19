#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

long long dp[10010];

void DP() {
    dp[1] = 2;
    dp[2] = 24;
    dp[3] = 96;
    dp[4] = 416;
    dp[5] = 1536;
    for(int i = 6; i <= 10001; i++) {
        dp[i] = (dp[i - 4] * 16 - dp[i - 3] * 8 - dp[i - 2] * 8 + dp[i - 1] * 6) % mod;
        if (dp[i] < 0) {
            dp[i] += mod;
        }
    }    
}

int main(){
    DP();
    int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        cout << dp[n] << endl;
    }
}
