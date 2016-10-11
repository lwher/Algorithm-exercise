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

unsigned long long n,m,R;

bool check(unsigned long long mid){
	unsigned long long len = sqrt(mid), res = 0, last, Min = min(n, m);
	if(len < Min){
		res = len * (len * 2 - 2);
		last = mid - len * len;
		if(last > 0){
			if(last <= len){
				res += last * 2 - 1;
			}
			else{
				res += len * 2 - 1;
				last -= len;
				res += last * 2 - 1;
			}
		}
	}
	else{
		len = mid / Min;
		res = len * (Min - 1) + (len - 1) * Min;
		last = mid - len * Min;
		if(last > 0) res += 2 * last - 1;
	}
	if(R + res >= mid * (mid - 1) / 2) return 1;
	else return 0;
}

int main(){
	
	cin >> n >> m >> R;
	unsigned long long K = 2e9;
	unsigned long long l = 1, r = min(n * m, K), mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	if(check(r)) cout << r << endl;
	else cout << l << endl;
	return 0;
}

