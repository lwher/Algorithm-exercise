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

char s[50];
string p[7];

bool the_same(char A[], int l, int x){
	for(int i = 0; i < 5; i++)
		if(A[l + i] != p[x][i])
			return 0;
	return 1;
}

int pipei(char A[], int l){
	int L = strlen(A + 1);
	if(L - l < 4) return -1;
	for(int i = 1; i <= 6; i++){
		if(the_same(A, l, i))
			return i;
	}
	return -1;
}

bool check(char A[]){
	int L = strlen(A + 1);
	if(!L) return 1;
	char now[50];
	memset(now, '\0', sizeof(now));
	for(int i = 1; i < L; i++){
		if(A[i] == A[i + 1]){
			for(int j = 1; j < i; j++) now[j] = A[j];
			for(int j = i + 2; j <= L; j++) now[j - 2] = A[j];
			return check(now);
		}
	}
	for(int i = 1; i < L; i++){
		if(pipei(A, i) != -1){
			int x = pipei(A, i);
			int len = 0;
			for(int j = 1; j < i; j++) now[++len] = A[j];
			for(int j = 1; j < 4; j++) now[++len] = p[x][j];
			for(int j = i + 5; j <= L; j++) now[++len] = A[j];
			return check(now);
		}
	}
	return 0;
}

int main(){
	p[1] = "bcbcb";
	p[2] = "cacac";
	p[3] = "babab";
	p[4] = "ababa";
	p[5] = "cbcbc";
	p[6] = "acaca";
	int T;	
	cin >> T;
	while(T--){
		scanf("%s", s + 1);
		if(check(s)) printf("closed\n");
		else printf("open\n");
	}
	return 0;
}

