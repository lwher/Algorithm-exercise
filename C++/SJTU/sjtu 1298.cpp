#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define N 1000010

using namespace std;

int n, m, tt, ft[N], sd[N], num[N];
int sz, to[N], pre[N], last[N];
bool deep[N];
int t[N];

int read(){
	int res = 0, f = 1;
	char ch = getchar();
	while(!(ch >= '0' && ch <= '9')){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		res = res * 10 + (ch -'0'); 
		ch = getchar();
	}
	return res * f;
}

void update(int x, int y){
	for(int i = x; i <= n; i += (i & (-i)))
		t[i] += y;
}

int ask(int x){
	int res = 0;
	for(int i = x; i; i -= (i & (-i)))
		res += t[i];
	return res;
}

void Ins(int a, int b){
	sz++; to[sz] = b; pre[sz] = last[a]; last[a] = sz;
}

void dfs(int x, int fa){
	ft[x] = ++tt;
	for(int i = last[x]; i; i = pre[i]){
		if(to[i] == fa) continue;
		deep[to[i]] = deep[x] ^ 1;
		dfs(to[i], x);
	}
	sd[x] = tt;
}

int main(){
	int ty, a, b;
	n = read(); m = read();//scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) num[i] = read();//scanf("%d", &num[i]);
	for(int i = 1; i < n; i++){
		a = read(); b = read();//scanf("%d %d", &a, &b);
		Ins(a, b); Ins(b, a);
	}
	dfs(1, 0);
	for(int i = 1; i <= m; i++){
		ty = read(); a = read();//scanf("%d %d", &ty, &a);
		if(ty == 1){
			b = read();//scanf("%d", &b);
			if(deep[a]) b *= -1;
			update(ft[a], b);
			update(sd[a] + 1, -b);
		}
		else{
			int ans = ask(ft[a]);
			if(deep[a]) ans *= -1;
			printf("%d\n", ans + num[a]);
		}
	}
	return 0;
}

