#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int n, num[30];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        scanf("%d", &num[i]);
    sort(num + 1, num + 1 + n);
    for(int i = n - 1; i >= 1; i--){
        while(num[i] >= num[i + 1] && num[i]) num[i]--;
    }
    long long res = 0;
    for(int i = 1; i <= n; i++) res += num[i];
    cout << res << endl;
    return 0;
}
