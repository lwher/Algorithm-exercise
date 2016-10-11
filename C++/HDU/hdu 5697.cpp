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

int n, m;
int A[410], B[410], C[410];

struct point{
	int x, y;
	point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

inline long long Calc_point(const point &a){
	return (long long)(a.x) * a.y;
}

point operator -(const point &a, const point &b){
	return point(a.x - b.x, a.y - b.y);
}

long long operator *(const point &a, const point &b){
	return (long long)(a.x) * b.y - (long long)(b.x) * a.y;
}

long long dp[810], sB[810], sC[810];

point Calc(long long kx, long long ky){
	for(int i = 0; i <= 800; i++) dp[i] = (1LL << 50);
	dp[0] = 0; sB[0] = 0; sC[0] = 0;
	for(int i = 1; i <= n; i++){
		long long k = ky * C[i] - kx * B[i];
		for(int j = 800; j >= A[i]; j--){
			if(dp[j - A[i]] + k < dp[j]){
				dp[j] = dp[j - A[i]] + k;
				sB[j] = sB[j - A[i]] + B[i];
				sC[j] = sC[j - A[i]] + C[i];
			}
		}
	}
	long long now = (1LL << 50);
	point res;
	for(int i = m; i <= 800; i++){
		if(dp[i] < now){
			res = point(sB[i], sC[i]);
			now = dp[i];
		}
	} 
	return res;
}

long long Get_Ans(point l, point r){	
	long long kx = r.y - l.y, ky = r.x - l.x;
	point mid = Calc(kx, ky);
	long long now = min(Calc_point(l), Calc_point(r));
	if((r - l) * (mid - l) >= 0) return now;
	now = min(now, Get_Ans(l, mid));
	now = min(now, Get_Ans(mid, r));
	return now;
}

int main(){
	while(scanf("%d %d", &n, &m) != EOF){
		for(int i = 1; i <= n; i++)
			scanf("%d %d %d", &A[i], &B[i], &C[i]);
		cout << Get_Ans(Calc(-1, 0), Calc(0, 1)) << endl;
	}
	return 0;
}

