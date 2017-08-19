#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int P;

int main() {
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i) {
		cin >> P;
		int ans = 0, limt = sqrt(P - 1);
		for (int j = 1; j <= limt; ++j) {
			if ((P - 1) % j == 0) {
				if ((P - 1) / j == j) 
					ans += 1;
				else 
					ans += 2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}