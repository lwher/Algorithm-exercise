#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define mod 1000000007
using namespace std;

int n, f[1010];
int main(){
	f[0] = 1; f[1] = 1;
	cin >> n;
	for(int i = 2; i <= n; i++){
		if(!(i & 1)) f[i] = (f[i] + f[i/2]) % mod;
		for(int j = 1; j <= i; j++){
			if((i - j) % 2 == 0){
				f[i] = (f[i] + f[(i - j)/2]) % mod;
			}
		}
	}
	cout << f[n] << endl;
	return 0;
}

