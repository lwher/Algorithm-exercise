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

int n, T, len, ans;
char s[10];
bool mark[10][100001];

void dfs(int now, int top, int k, int L){
	if(top == L + 1){
		mark[L][now] = 1;
		return;
	}
	int x = s[top] - '0';
	if(x - k >= 0) dfs(now * 10 + (x - k), top + 1, k, L);
	if(x + k <= 9) dfs(now * 10 + (x + k), top + 1, k, L);
}

int main(){
	scanf("%d", &T);		
	for(int t = 1; t <= T; t++){
		scanf("%d", &n);
		ans = 0;
		memset(mark, 0, sizeof(mark));		
		for(int i = 1; i <= n; i++){
			scanf("%s", s + 1);
			len = strlen(s + 1);
			int x = 0;
			for(int j = 1; j <= len; j++){
				x = x * 10 + (s[j] - '0');
			}
			if(mark[len][x]) continue;
			ans++;
			for(int k = 0; k <= 9; k++){
				dfs(0, 1, k, len);
			}
		}
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}

