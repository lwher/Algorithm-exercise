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
 
long long n, L[50], R[50];
int num[50], top, ans[50];
 
int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		top = 0;
		while(n > 0){
			num[++top] = n % 10;
			n /= 10;
		}
		memset(ans, 0, sizeof(ans));
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		for(int i = top; i > 0; i--){
			L[i] = L[i + 1] * 10 + num[i];
		}
		long long p = 1;
		for(int i = 1; i <= top; i++){
			R[i] = R[i - 1] + p * num[i];
			p *= 10;
		}
		for(int i = 1; i <= 9; i++){
			ans[1] = (ans[1] + (L[2] * i % 10)) % 10;
		}		
		for(int i = 1; i <= num[1]; i++) ans[1] = (ans[1] + i) % 10;
		
		for(int i = 2; i <= top; i++){
			ans[i] = (ans[i] + (R[i - 1] + 1) * num[i] % 10) % 10;
		}
		while(top && !ans[top]) top--;
		if(!top) printf("0\n");
		else{
			for(int i = top; i > 0; i--) printf("%d", ans[i]);
			printf("\n");
		}
	}
	
	return 0;
}
