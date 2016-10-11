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
 
char A[1001];
 
int main(){
	gets(A + 1);
	int ans = 0, L = strlen(A + 1);
	for(int i = 1; i <= L; i++){
		if(A[i] >= 'A' && A[i] <= 'Z') ans += (A[i] - 'A' + 1) * i;
		if(A[i] >= 'a' && A[i] <= 'z') ans += (A[i] - 'a' + 27) * i;
	}
	cout << ans << endl;
	return 0;
}