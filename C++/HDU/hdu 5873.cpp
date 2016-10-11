#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, num[20010];

void solve(){
	int sum = 0;
	for(int i = 1; i <= n; ++i){
		sum += num[i];
		if(sum < i * (i - 1)){
			puts("F");
			return;
		}
	}
	if(sum != n * (n - 1)) puts("F");
	else puts("T");
}

int main(){
	int T;
	while(cin >> T){
		while(T--){
			scanf("%d", &n);
			for(int i = 1; i <= n; ++i)
				scanf("%d", &num[i]);
			sort(num + 1, num + 1 + n);
			solve();
		}
	}
	return 0;
}

