#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long calc(long long x) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	long long W = 0;
	for (int i = 0; i < 64; i++){
		if (x > (1LL << i) - 1) W = i;
	}
	long long res = (1LL << W - 1) + 1LL;
	long long red = x - (1LL << W);
	res = res + red - ((1LL << W - 1) - calc((1LL << W) - 1 - red));
	return res;
}

int main() {
	int T;
	long long L, R;
	cin >> T;
	while(T--) {
		cin >> L >> R;
		printf("%I64d\n", calc(R) - calc(L - 1));
	}
	return 0;
}


