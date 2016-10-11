#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n, A[100010];

long long ans;

int main(){
	while(scanf("%d", &n)){
		if(!n) break;
		for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
		ans = 0;
		int now = 0;
		for(int i = 1; i <= n; i++){
			now -= A[i];
			ans += abs(now);
		}
		cout << ans << endl;
	}
	return 0;
}
