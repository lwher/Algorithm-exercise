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
#define INF 1e9

using namespace std;

int n, ans, Ans[N], pre[N][6], dp[N][6];
int before[4] ={3, 1, 2, 0};
char s[N];

bool check(){
	for(int i = 1; i <= n; i++) if(!(s[i] >= '0' && s[i] <= '9')) return false;
	return true;
}

void init(){
	scanf("%d", &n);

	scanf("%s", s + 1);
	s[0] = '*';
	for(int i = 0; i <= n; i++) for(int j = 0; j < 4; j++) dp[i][j] = -INF;
	dp[0][0]= 0; 
}

void DP(){
	int lastsum, nowsum;
	for(int i = 1; i <= n; i++){
		for(int k = 0; k < 4; k++){
			if(dp[i - 1][before[k]] >= 0){
				for(int j = 1 ; j >= 0; j--){
					lastsum = 0; nowsum = 0;
					if(before[k] & 1) nowsum++, lastsum++;
					if(before[k] & (1 << 1)) lastsum++;
					if(j == 1) nowsum++, lastsum++;
					if((s[i - 1] == '*' || s[i - 1] - '0' == lastsum) && (s[i] == '*' || s[i] - '0' >= nowsum)){
						int to = ((before[k] & 1) << 1) + j;
						if(dp[i][to] < dp[i - 1][before[k]] + j){
							dp[i][to] = dp[i - 1][before[k]] + j; pre[i][to] = before[k];
						}
					}
				}
			}
		}
	}
}

int p[5][N];
int anssum, answ = 4;
void solve(){
	int now;
	bool flag;
	for(int i = 0; i < 4; i++){
		p[i][n] = before[i] & 1;
		if(before[i] & 2) p[i][n - 1] = 1;
		if(p[i][n] + p[i][n - 1] == s[n] -'0'){
			flag = 0;
			for(int j = n - 1; j > 1; j--){
				if(p[i][j] + p[i][j + 1] > s[j] - '0'){
					flag = 1; break;
				}
				p[i][j - 1] = s[j] - '0' - p[i][j] - p[i][j + 1];
			}
			if(s[1] - '0' != p[i][1] + p[i][2]) flag = 1;
			if(!flag){
				now = 0;
				for(int j = 1; j <= n; j++) if(p[i][j]) now++;
				if(now > ans){
					anssum = now; answ = i;
				}
			}
		}
	}
	cout << anssum << endl;
	for(int i = 1; i <= n; i++) printf("%d", p[answ][i]);
	printf("\n");
}

void PrintAns(){
	int now = -1, sum;	
	for(int i = 0 ; i < 4; i++){
		sum = 0;
		sum += (before[i] & (1 << 1));
		sum += (before[i] & 1);
		if((s[n] == '*' || sum == s[n] - '0') && ans < dp[n][before[i]]){
			now = before[i]; ans = dp[n][before[i]];
		}
	}
	cout << ans << endl;
	for(int i = n; i > 0; i--){
		Ans[i] = now & 1; now = pre[i][now];
	}
	for(int i = 1; i <= n; i++) printf("%d", Ans[i]);
	printf("\n");
}

int main(){
	init();
	if(check()){
		solve();
		return 0;
	}
	DP();
	PrintAns();
	return 0;
}
