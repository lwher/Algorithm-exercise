#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct point {
	long long x, y;
	point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
};

struct line {
	point A, B;
	bool xyCase; // 0: X is the same, 1: Y is the same;
};

const int MAXN = 50;

int read() {
	char ch = getchar();
	while(!(ch >= '0' && ch <= '9')) ch = getchar();
	int x = 0;
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0'; 
		ch = getchar();
	}
	return x;
}

bool IsCross(const line &A, const line &B) {
	if (A.xyCase == B.xyCase && A.xyCase == 0) {
		return !(A.A.x != B.A.x || max(A.A.y, A.B.y) < min(B.A.y, B.B.y) || min(A.A.y, A.B.y) > max(B.A.y, B.B.y));
	}
	if (A.xyCase == B.xyCase && A.xyCase == 1) {
		return !(A.A.y != B.A.y || max(A.A.x, A.B.x) < min(B.A.x, B.B.x) || min(A.A.x, A.B.x) > max(B.A.x, B.B.x));
	}
	if (A.xyCase != B.xyCase && A.xyCase == 0) {
		return !(A.A.x < min(B.A.x, B.B.x) || A.A.x > max(B.A.x, B.B.x) || B.A.y < min(A.A.y, A.B.y) || B.A.y > max(A.A.y, A.B.y));
	}
	if (A.xyCase != B.xyCase && A.xyCase == 1) {
		return !(A.A.y < min(B.A.y, B.B.y) || A.A.y > max(B.A.y, B.B.y) || B.A.x < min(A.A.x, A.B.x) || B.A.x > max(A.A.x, A.B.x));
	}	
}

int n, X;
line path[MAXN];

int main() {
	int T;
	bool flag;
	long long x, y;
	cin >> T;
	while(T--) {
		n = read();
		x = 0; y = 0;
		flag = false;
		for (int i = 1; i <= n; ++i) {
			X = read();
			path[i % 50].A = point(x, y);
			int p = i % 4;
			if (p == 1) y += X, path[i % 50].xyCase = 0;
			else if(p == 2) x += X, path[i % 50].xyCase = 1;
			else if(p == 3) y -= X, path[i % 50].xyCase = 0;
			else x -= X, path[i % 50].xyCase = 1;
			path[i % 50].B = point(x, y);
			if (!flag) {
				for (int j = max(1, i - 8); j < i - 1; ++j) {
					if (IsCross(path[i % 50], path[j % 50])) {
						cout << i << endl;
						flag = true;
						break;
					}	
				}
			}
		}
		if (!flag)
			cout << "Catch you" << endl;
	}
	return 0;
}
