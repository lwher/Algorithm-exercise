#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

bool check_prime(long long x){
	int limt = sqrt(x);
	for(int i = 2; i <= limt; ++i)
		if(x % i == 0)
			return false;
	return true;
}

int solve(long long n){
	if(n == 2) return 1;
	if(n % 2 == 0) return 2;
	if(check_prime(n)) return 1;
	if(check_prime(n - 2)) return 2;
	return 3;
}

int main(){
	long long n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}

