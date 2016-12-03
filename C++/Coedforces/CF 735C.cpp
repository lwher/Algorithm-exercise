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

int solve(long long n){
	if(n == 1) 
		return 0;
	if(n == 2)
		return 1;
	if(n <= 4)
		return 2;
	long long A = 1, B = 2, C;		
	for(int i = 1; ; i++){
		C = A + B;
		if(C > n)
			return i;
		A = B; B = C;
	}
}

int main(){
	long long n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}

