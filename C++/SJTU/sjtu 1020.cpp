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
int N, n, top, ans[50], mi[50];
int main(){
	cin >> N;
	n = N;
	for(int i = 2;i <= sqrt(n);i++){
		if(n % i != 0) continue;
		ans[++top] = i;
		while(n % i == 0){
			mi[top]++;
			n /= i;
		}
	}
	if(n != 1){
		ans[++top] = n;
		mi[top] = 1;
	}
	cout << N << "=";
	for(int i = 1;i <= top;i++){
		cout << ans[i] << "(" << mi[i] << ")";
	}
	cout << endl;
	return 0;
}

