#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, Q;

std::map<string, int> Dic;

char s[30];

string p;

void print(string t){
	int L = t.size();
	for(int i = 0; i < L; i++) putchar(t[i]);
}

void solve(){
	string q, ans;
	bool flag = 0;
	int W = 1e6;
	if(Dic.count(p)){
		print(p);
		printf(" is correct\n");
		return;
	}
	int L = p.size();
	for(int i = 0; i < L; i++){
		q = "";
		for(int j = 0; j < i; j++) q += p[j];
		for(int j = i + 1; j < L; j++) q += p[j];
		if(Dic.count(q)){
			flag = 1;
			int x = Dic[q];
			if(W > x){
				W = x;
				ans = q;
			}
		}
	}

	for(int i = 0; i <= L; i++){
		q = "";
		for(int j = 0; j < i; j++) q += p[j];
		q += 'a';
		for(int j = i; j < L; j++) q += p[j];
		for(int j = 0; j < 26; j++){
			q[i] = 'a' + j;
			if(Dic.count(q)){
				flag = 1;
				int x = Dic[q];
				if(W > x){
					W = x;
					ans = q;
				}
			}
		}
	}

	for(int i = 0; i < L; i++){
		q = p;
		for(int j = 0; j < 26; j++){
			q[i] = 'a' + j;
			if(Dic.count(q)){
				flag = 1;
				int x = Dic[q];
				if(W > x){
					W = x;
					ans = q;
				}
			}
		}
	}

	for(int i = 0; i < L - 1; i++){
		q = p;
		char t = q[i];
		q[i] = q[i + 1];
		q[i + 1] = t;
		if(Dic.count(q)){
			flag = 1;
			int x = Dic[q];
			if(W > x){
				W = x;
				ans = q;
			}
		}
	}

	if(flag){
		print(p);
		printf(" is a misspelling of ");
		print(ans);
		printf("\n");
		return;
	}

	print(p);
	printf(" is unknown\n");
}

int main(){
	int L;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		p = ""; L = strlen(s);
		for(int j = 0; j < L; j++) p += s[j];
		Dic[p] = i;
	}
	scanf("%d", &Q);
	for(int i = 1; i <= Q; i++){
		scanf("%s", s);
		p = ""; L = strlen(s);
		for(int j = 0; j < L; j++) p += s[j];
		solve();
	}
	return 0;
}
