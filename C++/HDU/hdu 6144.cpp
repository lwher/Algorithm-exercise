#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

int n, m;

string stack[100010];
int top;

char s[100010];

int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		top = 0;
		string now = "";
		for (int i = 1; i <= n; ++i) {
			if (s[i] == '(' || s[i] == ')') {
				if (now != "") {
					stack[++top] = now;
					now = "";
				}
			}
			if (s[i] == '#') {
				if (now != "") {
					stack[++top] = now;
					now = "";
				}
				stack[++top] = '#';
			}
			if (s[i] >= '0' && s[i] <= '9') {
				now += s[i];
			}
		}
		if (now != "") {
			stack[++top] = now;
		}
		long long ans = 0;
		for (int i = 1; i <= top; ++i) {
			if (i < top && stack[i + 1] == "#") {
				for (int k = 0; k < stack[i + 2][0] - '0'; ++k) {
					for (int j = 0; j < stack[i].size(); ++j) {
						ans = ((ans * 10) + stack[i][j] - '0') % mod;
					}
				}
				i += 2;
			}
			else {
				for (int j = 0; j < stack[i].size(); ++j) {
					ans = ((ans * 10) + stack[i][j] - '0') % mod;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
