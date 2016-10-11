#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n, A[1010][1010];

bool solve(){
	for(int i = 1; i < n; i++) for(int j = 1; j < n; j++){
		if(A[i][j] + A[i + 1][j + 1] != A[i + 1][j] + A[i][j + 1])
			return 0;
	}
	return 1;
}

int main(){
	while(scanf("%d", &n)){
		if(!n) break;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) scanf("%d", &A[i][j]);
		if(solve()) printf("homogeneous\n");
		else printf("not homogeneous\n");
	}
	return 0;
}
