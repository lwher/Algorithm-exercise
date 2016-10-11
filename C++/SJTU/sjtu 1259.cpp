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

int n, X, Y, A, B;
priority_queue<int> Q;

void solve(){
	int x, minB = B, nowB = B;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		nowB -= X;
		if(nowB <= 0){
			cout << "Win" << endl << i << endl;
			return;
		}
		minB = min(minB, nowB); 
		A -= x; Q.push(x);
		while(A <= 0){
			A += max(Q.top(), Y);
			Q.pop(); nowB += X; 
		}
	}
	cout << "Lose" << endl;
	cout << B - minB << endl;
}

int main(){
	scanf("%d %d %d %d %d", &n, &X, &Y, &A, &B);
	solve();
	return 0;
}

