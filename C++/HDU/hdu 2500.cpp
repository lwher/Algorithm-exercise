#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int T, m;
	cin >> T;
	while (T--){
		cin >> m;
		for (int i = 1; i <= m * 3; i++){
			for (int j = 1; j <= m; j++){
				cout << "HDU";
			}
			cout << endl;
		}
	}
	return 0;
}