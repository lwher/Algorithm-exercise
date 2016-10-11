#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define N 200010

using namespace std;

int n, m;
int sz, to[N], pre[N], last[N], du[N];

void Ins(int a, int b){
	sz++; to[sz] = b; pre[sz] = last[a]; last[a] = sz;
	du[b]++;
}

int ans[N];
std::priority_queue<int> Q;
void topsort(){
	int top = 0, now;
	while(!Q.empty()) Q.pop();
	for(int i = 1; i <= n; i++){
		if(!du[i]) Q.push(i);
	}
	while(!Q.empty()){
		now = Q.top();
		ans[++top] = now;
		Q.pop();
		for(int i = last[now]; i; i = pre[i]){
			du[to[i]]--;
			if(!du[to[i]]) Q.push(to[i]);
		}
	}
}

int main(){
	int T, a, b;
	cin >> T;
	while(T--){
		sz = 0;
		memset(last, 0, sizeof(last));
		memset(du, 0, sizeof(du));
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; i++){
			scanf("%d %d", &a, &b);
			Ins(a, b);
		}
		topsort();
		long long res = 0, maxx = n;
		for(int i = 1; i <= n; i++){
			if(maxx > ans[i]) maxx = ans[i];
			res += maxx;
		}
		printf("%I64d\n", res);
	}
	return 0;
}

