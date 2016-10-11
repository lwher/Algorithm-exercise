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

int n, sum, ans, A[101];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &A[i]);
		sum += A[i];
	}
	sum /= n;
	for(int i = 1; i < n; i++){
		A[i] -= sum;
		if(A[i]) ans++;
		A[i+1] += A[i];
	}
	cout << ans << endl;
	return 0;
}

