#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define N 30010

using namespace std;

int n, toL[N << 1], toR[N << 1], maxx[N << 1];
int X[N], Y[N], Z[N], D[N];
int shu[N << 1], top, num[N << 1], tot;

int find(int x){
	int l = 1, r = tot, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(num[mid] == x) return mid;
		if(num[mid] < x) l = mid;
		else r = mid;
	}
	if(num[l] == x) return l;
	else return r;
}

int main(){
	int x, y, z, d, T;
	cin >> T;
	for(int tt = 1; tt <= T; tt++){
		printf("Case #%d:\n", tt);
		scanf("%d", &n);
		top = tot = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d %d %d %d", &x, &y, &z, &d);
			X[i] = x; Y[i] = y; Z[i] = z; D[i] = d;
			if(y - x > 2 * z) continue;
			shu[++top] = x + z; shu[++top] = y - z;
		}
		sort(shu + 1, shu + 1 + top);
		num[++tot] = shu[1];
		for(int i = 2; i <= top; i++) if(shu[i] != shu[i - 1]) num[++tot] = shu[i];
		memset(toL, 0, sizeof(toL));
		memset(toR, 0, sizeof(toR));
		for(int i = 1; i <= n; i++){
			if(Y[i] - X[i] > 2 * Z[i]) continue;
			if(D[i] == 1){
				toR[find(Y[i] - Z[i])]++;
				toR[find(X[i] + Z[i]) + 1]--;
			}
			else{
				toL[find(X[i] + Z[i])]++;
				toL[find(Y[i] - Z[i]) - 1]--;
			}
		}
		int ans = 0;
		for(int i = 1; i <= tot; i++){
			toR[i] += toR[i - 1];
			maxx[i] = max(maxx[i - 1], toR[i]);
		}
		int now = 0;
		for(int i = tot; i >= 1; i--){
			toL[i] += toL[i + 1];
			now = max(now, toL[i]);
			ans = max(ans, now + maxx[i]);
		}
		cout << ans << endl;
	}
	return 0;
}

