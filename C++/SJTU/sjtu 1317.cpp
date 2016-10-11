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

int m, S, n, x[210];

priority_queue<int> Q;

int main(){
	scanf("%d%d%d", &m, &S, &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	sort(x + 1, x + 1 + n);
	
	for(int i = 1; i < n; i++){
		Q.push(x[i + 1] - x[i] - 1);
	}
	int ans = S - x[1] - (S - x[n]) + 1;
	
	for(int i = 1; i < m; i++){
		if(Q.empty()) break;
		int t = Q.top(); Q.pop();
		ans -= t;
	}
	cout << ans << endl;
	return 0;
}

