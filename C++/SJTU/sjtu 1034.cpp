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
int n, K, num[500001], q[500001];
long long ans = 1LL<<50;
int main(){
	scanf("%d %d", &n, &K);
	for(int i = 1; i <= n; i++){
		scanf("%d", &num[i]);
		num[i + n] = num[i];	
	}
	int t = 1,w = 0;
	for(int i = 1; i < K; i++){
		while(t <= w && num[q[w]] < num[i]) w--;
		q[++w] = i;
	}
	n <<= 1;
	for(int i = K; i <= n; i++){
		while(t <= w && i - q[t] >= K) t++;
		while(t <= w && num[q[w]] < num[i]) w--;
		q[++w] = i;
		if(num[q[t]] < ans) ans = num[q[t]];
	}
	cout << ans << endl;
	return 0;
}

