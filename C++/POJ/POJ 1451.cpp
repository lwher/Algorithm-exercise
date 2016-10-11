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

int n, m, sz, sum[10010], to[10010][8];
string ans[10010];
char word[310];

std::map<string, int>Q;

inline int char_to_num(char s){
	if(s == 'a' || s == 'b' || s == 'c') return 2;
	if(s == 'd' || s == 'e' || s == 'f') return 3;
	if(s == 'g' || s == 'h' || s == 'i') return 4;
	if(s == 'j' || s == 'k' || s == 'l') return 5;
	if(s == 'm' || s == 'n' || s == 'o') return 6;
	if(s == 'p' || s == 'q' || s == 'r' || s == 's') return 7;
	if(s == 't' || s == 'u' || s == 'v') return 8;
	if(s == 'w' || s == 'x' || s == 'y' || s == 'z') return 9;
}

void add(char* s, int p){
	int len = strlen(s), now = 0, k, gs;
	string res = "";
	for(int i = 0; i < len; i++){
		k = char_to_num(s[i]) - 2;
		if(!to[now][k]) to[now][k] = ++sz, ans[sz] = "";
		now = to[now][k];
		res += s[i];
		gs = (Q[res] += p);
		if(gs > sum[now]){
			sum[now] = gs;
			ans[now] = res;
		}
		else if(gs == sum[now]){
			if(res < ans[now]) ans[now] = res;
		}
	}
}

void query(char *s){
	int len = strlen(s), now = 0, k, i, L;
	for(i = 0; i < len; i++){
		if(s[i] == '1') return;
		k = (s[i] - '0') - 2;
		if(!to[now][k]) break;
		now = to[now][k];
		L = ans[now].size();
		for(int j = 0; j < L; j++) 
			putchar(ans[now][j]);
		putchar('\n');
	}
	while(i < len){
		if(s[i] == '1') return;
		else printf("MANUALLY\n");
		i++;
	}
}

int main(){
	int T, p;
	cin >> T;
	for(int tt = 1; tt <= T; tt++){
		memset(sum, 0, sizeof(sum));
		memset(to, 0, sizeof(to));
		sz = 0; Q.clear();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%s", word);
			scanf("%d", &p);
			add(word, p);
		}
		printf("Scenario #%d:\n", tt);
		scanf("%d", &m);
		for(int i = 1; i <= m; i++){
			scanf("%s", word);
			query(word);
			printf("\n");
		}
		printf("\n");
		
	}
	return 0;
}

