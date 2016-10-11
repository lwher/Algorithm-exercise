#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[3000010];

int main(){
    int T, x, R, L;
    cin >> T;
    for(int i = 1; i <= T; i++){
        scanf("%d%d", &x, &R);
        scanf("%s", s);
        L = strlen(s);
        printf("%d ", x);
        for(int i = 0; i < L; i++)
            for(int j = 1; j <= R; j++)
                    printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}
