#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1030

using namespace std;

int n, ans, num[N], x[N], map[N][N];
char s[N];
int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%s", s+1);
			for(int j = 1; j <= n; j++) 
				map[i][j] = s[j] - '0';
		}
		ans = 0;		
		memset(num, 0, sizeof(num));
		memset(x, 0, sizeof(x));				
		for(int j = n; j >= 1; j--){
			int cs = 0;
			for(int i = 1; i < j; i++){
				if(!((map[i][j] + x[i] + cs) & 1)){
					ans++; x[i]++; cs++;
				} 
			}
			num[j] += cs + x[j];
		}
		memset(x, 0, sizeof(x));
		for(int j = 1; j <= n; j++){
			int cs = 0;
			for(int i = n; i > j; i--){
				if(!((map[i][j] + x[i] + cs) & 1)){
					ans++; x[i]++; cs++;
				} 
			}
			num[j] += cs + x[j];
		}	
		for(int i = 1; i <= n; i++)
			if(!((map[i][i] + num[i]) & 1)) 
				ans++;
		cout << ans << endl;
	}
	return 0;
}

