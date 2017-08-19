#include <iostream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define N 100010

using namespace std;

int L, fa[N], ans[N];

int stack[N << 2], top; 

set<int> NotEqual[N];
set<int>::iterator it;

int getfa(int x) {
	if (fa[x] == 0) return x;
	else return fa[x] = getfa(fa[x]);
}

void AllClear() {
	while (top > 0) {
		fa[stack[top]] = 0;
		NotEqual[stack[top]].clear();
		--top;
	}
}

int main() {
	int x, y, a, b, c;
	cin >> L;
	for (int i = 1; i <= L; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		x = getfa(a);
		y = getfa(b);
		stack[++top] = a;
		stack[++top] = b;
		if (c == 1) {
			if (NotEqual[x].count(y) || NotEqual[y].count(x)) {
				ans[++ans[0]] = i;
				AllClear();
			}
			else {
				if (x != y) {
					if (NotEqual[x].size() < NotEqual[y].size()) {
						swap(x, y);
					}
					fa[y] = x;
					for (it = NotEqual[y].begin(); it != NotEqual[y].end(); ++it) {
						NotEqual[x].insert(*it);
					}
				}
			}
		}
		else {
			if (x == y) {
				ans[++ans[0]] = i;
				AllClear();
			}
			else {
				NotEqual[x].insert(y);
				NotEqual[y].insert(x);
			}
		}
	}
	if (ans[0] == 0) {
		cout << 0 << endl;
	}
	else {
		cout << ans[0] << endl;
		cout << ans[1] << endl;
		for (int i = 2; i <= ans[0]; ++i) {
			cout << ans[i] - ans[i - 1] << endl;
		}
	}
	return 0;
}
