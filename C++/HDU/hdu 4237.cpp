#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, T;

int main(){
    int x;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d%d%d", &x, &n, &m);
        long long ans = 0;
        int y = n - m;
        if(n == 0 || m == 0) printf("%d 1\n", x);
        else{
            ans = 1;
            for(int i = 1; i <= m; i++) ans += y;
            printf("%d %lld\n", x, ans);
        }
    }
    return 0;
}
