#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n, X[100010];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &X[i]);
	sort(X + 1, X + 1 + n);
	int P = n / 2 + 1, ans = 0;
	for(int i = 1; i <= n; i++){
		ans += abs(X[i] - X[P]);
	}
	cout << ans << endl;
	return 0;
}

