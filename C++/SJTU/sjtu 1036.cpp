#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;

int n , T[N], s[3][N] , p[3];
long long sumT[2], lastT[2];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &T[i]);
	}
	for(int i = 1; i <= n; i++){
		s[i % 3][++s[i % 3][0]] = i;
	}
	for(int i = 0; i < 3; i++){
		int T0 = 0;
		for(int j = 1; j <= s[i][0]; j++){
			sumT[0] += (long long)T[s[i][j]] * (s[i][0] - j);
			T0 += T[s[i][j]];
		}
		lastT[0] = max(lastT[0], (long long)T0);
	}
	p[0] = T[1]; p[1] = T[2]; p[2] = T[3];
	int i = 4;
	while(i <= n){
		int tmin = 1<<30;
		for(int j = 0; j < 3; j++) tmin = min(tmin, p[j]);
		if(tmin == 0){
			for(int j = 0; j < 3; j++){
				if(p[j] == 0  && i <= n) p[j] = T[i++];
			}
			continue;
		}
		sumT[1] += (long long)tmin * (n - i + 1);
		lastT[1] += tmin;
		for(int j = 0; j < 3; j++) p[j] -= tmin;
		for(int j = 0; j < 3; j++){
			if(p[j] == 0 && i <= n) p[j] = T[i++];
		}
	}
	int tmax = 0;
	for(int j = 0; j < 3; j++) tmax = max(tmax, p[j]);
	lastT[1] += tmax;
	for(int j = 0; j < 2; j++){
		cout << sumT[j] << " " << lastT[j] << endl;
	}
	return 0;
}

