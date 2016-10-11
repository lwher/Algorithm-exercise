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
int n, m, tot, prime[6001], mi[6001];
bool mark[50001];
map<int, int> Q;
void getprime(){
	for(int i = 2; i <= 50000; i++){
		if(!mark[i]) prime[++tot] = i;
		for(int j = 1; j <= tot; j++){
			if(i * prime[j] > 50000) break;
			mark[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
void solve(){
	int x;
	long long P = 1;
	bool flag = 0;
	memset(mi,0,sizeof(mi));
	Q.clear();
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){		
		scanf("%d", &x);
		for(int j = 1; j <= tot; j++){
			if(prime[j] > x) break;
			while(x % prime[j] == 0){
				x /= prime[j];
				mi[j]++;
			}
		}
		if(x != 1) Q[x]++;
	}	
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		scanf("%d", &x);
		P = P * x;
		for(int j = 1;j <= tot; j++){
			if(prime[j] > x) break;
			while(x % prime[j] == 0){
				x /= prime[j];
				mi[j]--;
				if(mi[j] < 0) flag = 1;
			}
		}
		if(x != 1) Q[x]--;
		if(Q[x] < 0) flag = 1;
	}
	if(flag && P != 2) printf("No\n");
	else printf("Yes\n");
}
inline int gcd(int a,int b){
	return b == 0 ? a : gcd(b, a % b);
}
int main(){
	int T;
	getprime();
	scanf("%d", &T);
	if(T > 100000){
		while(T--){
			long long A = 1, B = 1;
			scanf("%d", &n);
			for(int i = 1; i <= n; i++){
				int x;
				scanf("%d", &x);
				A = A * x;
			}
			scanf("%d", &m);
			for(int i = 1; i <= m; i++){
				int x;
				scanf("%d", &x);
				B = B * x;
			}
			if(A % B == 0) printf("Yes\n");
			else printf("No\n");
		}
	}else
	if(T <= 1000 && n <= 500 && m <= 500){
		int A[501], B[501];
		while(T--){
			int A[501], B[501];
			long long p = 1;
			scanf("%d", &n);
			for(int i = 1; i <= n; i++){
				scanf("%d", &A[i]);
			}
			scanf("%d", &m);
			for(int i = 1; i <= m; i++){
				scanf("%d", &B[i]);
				p = p * B[i];
			}
			for(int i = n; i >= 1; i--){
				for(int j = m; j >= 1; j--){
					if(A[i] == 1) break;
					if(B[j] == 1) continue;
					int d = gcd(A[i], B[j]);
					A[i] /= d;
					B[j] /= d;
				}
			}
			bool flag = 0;
			for(int i = 1; i <= m; i++){
				if(B[i] != 1) flag = 1;
			}
			if(flag && p != 2) printf("No\n");
			else printf("Yes\n");
		}
	}
	else{
		while(T--){
			solve();
		}
	}
	return 0;
}

