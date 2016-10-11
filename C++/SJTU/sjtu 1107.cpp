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

int n;
int main(){
	int x;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		if(!x) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}

