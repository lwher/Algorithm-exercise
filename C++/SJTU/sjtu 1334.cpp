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

int n, ans;
map<int,int> Q;

int main(){
	int x;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		Q[x]++;
		if(Q[x] > n / 2) 
			ans = x;
	}
	cout << ans << endl;
	return 0;
}

