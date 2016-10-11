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

int n, K;
double X[100010];

bool check(double x){
	int sum = 1;
	double w = X[1];
	for(int i = 2; i <= n; i++){
		if(X[i] - w > x){
			w = X[i], sum++;
		}
	}
	return sum <= K;
}

int main(){
	scanf("%d %d", &n, &K);
	for(int i = 1; i <= n ;i++){
		scanf("%lf", &X[i]);
	}
	double l = 0, r = 1e7, mid;
	for(int i = 1; i <= 70; i++){
		mid = (l + r) * 0.5;
		if(check(mid * 2)) r = mid;
		else l = mid;
	}
	printf("%.6lf\n", l);
	return 0;
}

