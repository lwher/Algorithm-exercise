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

int n, num[8010], ans[8010], Q[16010];


int main(){
	int up, down;
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
		memset(ans, 0, sizeof(ans));
		for(int i = 1; i <= n; i++){
			memset(Q, 0, sizeof(Q));
			Q[0 + n + 1] = 1;
			up = 0; down = 0;
			for(int j = i - 1; j > 0; j--){
				if(num[j] < num[i]) down++;
				else up++;
				Q[up - down + n + 1]++;
			}
			ans[i] += Q[0 + n + 1];
			up = 0; down = 0;
			for(int j = i + 1; j <= n; j++){
				if(num[j] < num[i]) down++;
				else up++;
				ans[i] += Q[down - up + 1 + n];
			}
		}
		for(int i = 1; i < n; i++) printf("%d ", ans[i]);
		printf("%d\n", ans[n]);
	}
	return 0;
}

