#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

bool IsRunNian(int x) {
	if (x % 4 == 0 && x % 100 != 0) return true;
	else if (x % 400 == 0) return true;
	else return false;
}

int main() {
	int T, year, month, day;
	char s[20];
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		scanf("%s", s);
		
		year = 0, month = 0, day = 0;
		for(int i = 0; i < 4; ++i) {
			year = year * 10 + s[i] - '0';
		}
		for(int i = 5; i < 7; ++i) {
			month = month * 10 + s[i] - '0';
		}
		for(int i = 8; i < 10; ++i) {
			day = day * 10 + s[i] - '0';
		}
		int detDay = 0;
		if (month == 2 && day == 29) {
			detDay += 2;
			for (year += 1; ; ++year) {
				if (!IsRunNian(year + 1)) {
					detDay++;
				}
				else {
					if ((detDay + 1) % 7 == 0) {
						cout << year + 1 << endl;
						break;
					}
					detDay += 2;
				}
			}
		}
		else {
			if (month <= 2 && IsRunNian(year)) ++detDay;
			if (month > 2 && IsRunNian(year + 1)) ++detDay; 
			++detDay; 
			for (year += 1; ; ++year) {
				if (detDay % 7 == 0) {
					cout << year << endl;
					break;
				}
				detDay++;
				if (IsRunNian(year + 1) && month > 2) detDay++;
				if (IsRunNian(year) && month <= 2) detDay++; 
			}
		}
	}

	return 0;
}
