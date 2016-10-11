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
int n, K;
int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> n >> K;
		if(K >= n) printf("5555\n");
		else{
			if(K > 1) printf("Yeah!\n");
			else{
				if(n & 1) printf("5555\n");
				else printf("Yeah!\n");  
			}
		}
	}
	return 0;
}

