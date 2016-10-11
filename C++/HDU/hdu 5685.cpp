#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define mod 9973

using namespace std;

int Q, len, L[510], R[510], belong[100010], Hash[510];
char s[100010];

int main(){
	int l, r;
	while(scanf("%d", &Q) != EOF){
		scanf("%s", s + 1);
		len = strlen(s + 1);
		int limt = sqrt(len), now = limt, ksz = 0;
		for(int i = 1; i <= len; i++){
			now++;
			if(now > limt){
				R[ksz] = i - 1;
				ksz++; now = 1;
				L[ksz] = i;
			}
			belong[i] = ksz;
		}
		R[ksz] = len;
		for(int i = 1; i <= ksz; i++){
			Hash[i] = 1;
			for(int j = L[i]; j <= R[i]; j++) Hash[i] = Hash[i] * (s[j] - 28 + mod) % mod;
			Hash[i] %= mod;
			if(Hash[i] < 0) Hash[i] += mod;
		}
		for(int t = 1; t <= Q; t++){
			scanf("%d %d", &l, &r);
			int res = 1;
			if(belong[l] == belong[r]){
				for(int i = l; i <= r; i++) res = res * (s[i] - 28 + mod) % mod;
			}
			else{
				for(int i = l; i <= R[belong[l]]; i++) res = res * (s[i] - 28 + mod) % mod;
				for(int i = belong[l] + 1; i < belong[r]; i++) res = res * Hash[i] % mod;
				for(int i = L[belong[r]]; i <= r; i++) res = res * (s[i] - 28 + mod) % mod;
			}
			res %= mod;
			if(res < 0) res += mod;
			printf("%d\n", res);
		}
	}
	return 0;
}

