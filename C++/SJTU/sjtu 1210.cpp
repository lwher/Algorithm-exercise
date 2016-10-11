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

int phi(int x){
	int res = 1;
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0){
			x /= i;
			res *= i - 1;
			while(x % i == 0){
				x /= i;
				res *= i;
			}
		}
	}
	if(x > 1) res *= x - 1;
	return res;
}

int qpow(int a, int b, int c){
	int res = 1;
	a %= c;
	while(b > 0){
		if(b & 1) res = (res * a) % c;
		b >>= 1;
		a = (a * a) % c;
	}
	return res;
}

int gcd(int a, int b){
	if(!b) return a;
	else return gcd(b, a % b);
}

int tot, prime[50];
void Divide(int x){
	for(int i = 2; i <= sqrt(x); i++){
		if(x % i == 0){
			prime[++tot] = i;
			while(x % i == 0)
				x /= i;
		}
	}
	if(x > 1) prime[++tot] = x;	
}

bool check(int x, int p, int m){
	for(int i = 1; i <= tot; i++){
		if(qpow(x, p / prime[i], m) == 1)
			return 0;
	}
	return 1;
}

int m, sum;
int main(){
	cin >> m;
	if(m == 1 || m == 2){
		cout << 1 << endl;
		return 0;
	}
	int p = phi(m);
	Divide(p);
	for(int i = 2; i <= m; i++)
		if(gcd(i, m) == 1 && check(i, p, m)) 
			cout << i << endl, sum++;
	if(!sum) cout << -1 <<endl;
	return 0;
}

