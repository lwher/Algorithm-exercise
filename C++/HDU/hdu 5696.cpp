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
const long long INF = 1LL << 62;

using namespace std;

int n, num[N];
long long ans[N];

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d", &num[i]);
			ans[i] = -INF;
		}
		int L, R, p;
		long long t;						
		for(int i = 1; i <= n; i++){
			ans[1] = max(ans[1], (long long)(num[i]) * num[i]);
			
			L = i - 1;	R = i + 1; 
			while(L > 0 && num[L] <= num[i]) L--;
			while(R < n + 1 && num[R] <= num[i]) R++;
			
			int minl = 2e9, minr = 2e9;
			
			for(int r = i, l = i; l > L; l--){ 
				if(num[l] < minl) minl = num[l];
				while(r < R - 1 && num[r + 1] >= minl) r++;
				t = (long long)(num[i]) * minl;
				if(t > ans[r - l + 1]) ans[r - l + 1] = t;
			}
			
			for(int l = i, r = i; r < R; r++){ 
				if(num[r] < minr) minr = num[r];
				while(l > L + 1 && num[l - 1] >= minr) l--;
				t = (long long)(num[i]) * minr;
				if(t > ans[r - l + 1]) ans[r - l + 1] = t;
			}
			
		}
		for(int i = n - 1; i > 0; i--) ans[i] = max(ans[i], ans[i + 1]);
		for(int i = 1; i <= n; i++) printf("%I64d\n", ans[i]);
	}
	return 0;
}

