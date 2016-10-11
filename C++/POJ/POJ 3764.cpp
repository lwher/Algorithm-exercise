#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define N 200010

using namespace std;

int n, Xor[N];
int sz, to[N], v[N], pre[N], last[N];

void Ins(int a, int b, int c){
	sz++; to[sz] = b; v[sz] = c; pre[sz] = last[a]; last[a] = sz;
}

int tsz, trie[3500010][2];

void dfs(int x, int fa){
	for(int i = last[x]; i; i = pre[i]){
		if(to[i] == fa) continue;
		Xor[to[i]] = Xor[x] ^ v[i];
		dfs(to[i], x);
	}
}

void trie_Ins(int X){
	int p = 0, Q = (1 << 30);
	for(int i = Q; i > 0; i >>= 1){
		if(X & i){
			if(!trie[p][1]) trie[p][1] = ++tsz;
			p = trie[p][1];
		}
		else{
			if(!trie[p][0]) trie[p][0] = ++tsz;
			p = trie[p][0];
		}
	}
}

int Query(int X){
	int res = 0, p = 0, Q = (1 << 30);
	for(int i = Q; i > 0; i >>= 1){
		int t = X & i;
		if(t) t = 0; else t = 1;
		if(trie[p][t]){
			res += i;
			p = trie[p][t];
		}	
		else{
			p = trie[p][t ^ 1];
		}
	}
	return res;
}

int main(){
	int a, b, c;
	while(scanf("%d", &n) != EOF){	
		sz = 0;
		memset(last, 0, sizeof(last));		
		for(int i = 1; i < n; i++){
			scanf("%d%d%d", &a, &b, &c);
			a++; b++;
			Ins(a, b, c); Ins(b, a, c);
		}	
		Xor[1] = 0;
		dfs(1, 0);
		tsz = 0;
		memset(trie, 0, sizeof(trie));
		for(int i = 1; i <= n; i++) trie_Ins(Xor[i]);
		int ans = 0;		
		for(int i = 1; i <= n; i++) ans = max(ans, Query(Xor[i]));
		cout << ans << endl;
	}
	return 0;
}
