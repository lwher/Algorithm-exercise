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

struct num{
	int A, B;
};

int n, top;
num p[300010];

inline bool comp(const num &a, const num &b){
	if(a.A * b.B == a.B * b.A) return a.B < b.B;
	return a.A * b.B < a.B * b.A;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){ 
			p[++top].A = j;
			p[top].B = i;
		}
	}
	sort(p + 1, p + 1 + top, comp);
	
	printf("%d/%d\n", p[1].A, p[1].B);
	for(int i = 2; i <= top; i++){
		if(p[i].A * p[i - 1].B == p[i].B * p[i - 1].A) continue;
		printf("%d/%d\n", p[i].A, p[i].B);
	}
	return 0;
}

