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

int n, sz, t[1100010][26], size[1100010];
char op[10], S[36];

void Add(char s[]){
	int i, len = strlen(s), now = 0;
	for(i = 0; i < len; i++){
		int k = s[i] - 'a';
		if(!t[now][k]){
			t[now][k] = ++sz;
		}
		now = t[now][k];
		size[now]++;
	}
}

void Delete(char s[], int now, int p){
	if(p == strlen(s) - 1){
		int k = s[p] - 'a';
		if(now != 0) size[now] -= size[t[now][k]];
		t[now][k] = 0;
		return;
	}
	int k = s[p] - 'a';
	if(!t[now][k]) return;
	Delete(s, t[now][k], p + 1);
	if(now != 0){
		size[now] = 0;
		for(int i = 0; i < 26; i++) size[now] += size[t[now][i]]; 
	}
}

bool find(char s[]){
	int len = strlen(s), now = 0;
	for(int i = 0; i < len; i++){
		int k = s[i] - 'a';
		if(!t[now][k]) return 0;
		now = t[now][k];
	}
	return size[now] > 0;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%s", op);
		scanf("%s", S);
		if(op[0] == 'i') Add(S);
		if(op[0] == 'd') Delete(S, 0, 0);
		if(op[0] == 's'){
			if(find(S)) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}

