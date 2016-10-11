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

int T, n, m, K[61][61];
char s[310];

int Atoi(int l, int r){
	int res = 0, p = 1, w = l;
	if(s[w] == '-') p = -1, w++;
	while(w <= r){
		res = res * 10 + (s[w] - '0');
		w++;
	}
	return res * p;
}

void init(){
	int L, k;
	memset(K, 0, sizeof(K));
	scanf("%d %d", &n, &m);
	getchar();
	for(int i = 1; i <= m; i++){
		gets(s + 1);
		L = strlen(s + 1);
		if(L == 0) continue;
		s[++L] = ' ';
		k = 1;
		for(int j = 1; j <= L; j++){
			if(s[j] == ' ' || s[j] == '\n'){
				K[i][++K[i][0]] = Atoi(k, j-1);
				k = j + 1;
			}
		}
	}
}

bool used[25], flag;

bool check(){
	bool OK;
	for(int i = m; i >= 1; i--){
		OK = 0;
		if(!K[i][0]) OK = 1;
		for(int j = 1; j <= K[i][0]; j++){
			if(K[i][j] < 0){
				if(!used[-K[i][j]]){
					OK = 1; break;
				}
			}
			else{
				if(used[K[i][j]]){
					OK = 1; break;
				}
			}
		}
		if(!OK) return 0;
	}	
	return 1;
}

void dfs(int top){
	if(top > n){
		if(check()) flag = 1;
		return;
	}
	used[top] = 0;
	dfs(top + 1);
	if(flag) return;
	used[top] = 1;
	dfs(top + 1);
	if(flag) return;
}

int main(){
	scanf("%d", &T);
	while(T--){
		init();
		flag = 0;
		dfs(1);
		if(!flag) printf("Sigh...\n");
		else printf("Bingo!\n");
	}
	return 0;
}

