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

int T, n ,d, Max, num[10001];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	scanf("%d", &T);
	while(T--){
		Max = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &num[i]);
			Max = max(Max, num[i]);
		}
		d = Max;
		for(int i = 1; i <= n; i++) d = gcd(d, num[i]);
		Max /= d;
		if((Max - n) & 1) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}

