#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, T;
char map[51][51], s[100];
long long sum[3];// 0 : R, 1 : G, 2 : B

inline int findid(char x){
	if(x == 'R') return 0;
	if(x == 'G') return 1;
	return 2;
}

void solve(int x, int y){
	int w, top = 0;
	char p;
	s[++top] = map[x][y];
	while(x < n && y < m){
		s[++top] = map[++x][++y];
	}
	for(w = 1; w <= top; w++){
		if(s[w] != '.') break;
	}
	if(w <= top){
		sum[findid(s[w])] += T;
		for(int i = w + 1; i <= top; i++){
			p = s[i];
			for(int j = min(top, i + T - 1); j >= i; j--)
				if(s[j] != '.') p = s[j];
			if(p != '.') sum[findid(p)]++;
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%s", map[i]+1);
	}
	scanf("%d", &T);
	for(int i = 1; i <= m; i++){
		solve(1, i);
	}
	for(int i = 2; i <= n; i++){
		solve(i, 1);
	}
	cout << sum[0] << " " << sum[1] << " " << sum[2] <<endl;
	return 0;
}

