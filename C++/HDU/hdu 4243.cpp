#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

unsigned long long jc[21], ans;

int main(){
    jc[0] = 1;
    for(int i = 1; i <= 20; i++) jc[i] = jc[i - 1] * i;
    int T, n, K, x;
    cin >> T;
    for(int i = 1; i <= T; i++){
        scanf("%d%d%d", &x, &n, &K);
        ans = 0;
        if(K == 1) ans = jc[n - 1];
        else{
            for(int j = 1; j < K; j++){
                ans += jc[K - 2] / jc[K - j - 1] * jc[n - j - 1] * j;
            }
        } 
        cout << x << " " << ans << endl;
    }
    return 0;
}

