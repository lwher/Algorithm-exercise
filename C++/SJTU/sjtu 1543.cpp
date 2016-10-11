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

long long n, f[110][2], ans;
int top, num[110];

int main(){
	cin >> n;
	while(n){
		num[++top] = n % 3;
		n /= 3;
	}
	for(int j = top; j >= 1; j--){
		if(num[j] > 0){
			memset(f, 0, sizeof(f));
			f[j][0] = 1;
			for(int i = j - 1; i >= 1; i--){
				f[i][0] += f[i + 1][0];
				if(num[i] == 0){
					f[i][1] += f[i + 1][0];
				} 
				else {
					f[i][0] += f[i + 1][0];
				}
				if(num[i] < 2){
					f[i][1] += f[i + 1][0];
				}
				else{
					f[i][0] += f[i + 1][0];
				}
				f[i][1] += f[i + 1][1] * 3;
			}
			ans += f[1][1] * num[j];
		}
	}
	cout << ans << endl;
	return 0;
}

