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

struct point{
	long long x, y;
};
point P[2010], A, B;
int n;
long long ans,maxD[2010];

void read(point &o){
	scanf("%I64d %I64d", &o.x, &o.y);
}

long long dist(const point &a, const point &b){
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
} 

struct sth{
	long long distA, distB;
}Q[2010];

inline bool comp(const sth &a, const sth &b){
	if(a.distA == b.distB) return a.distB > b.distB;
	return a.distA < b.distA;
}

int main(){
	scanf("%d", &n);
	read(A); read(B);
	for(int i = 1; i <= n; i++){
		read(P[i]);
		Q[i].distA = dist(A, P[i]);
		Q[i].distB = dist(B, P[i]);
	}
	sort(Q + 1, Q + 1 + n, comp);
	maxD[n] = Q[n].distB;
	ans = Q[n].distA;
	for(int i = n - 1; i >= 1; i--){
		maxD[i] = max(maxD[i + 1], Q[i].distB);
		ans = min(ans, maxD[i + 1] + Q[i].distA);
	}
	ans = min(ans, maxD[1]);
	cout << ans << endl;
	return 0;
}

