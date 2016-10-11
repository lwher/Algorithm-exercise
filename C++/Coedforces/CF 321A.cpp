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

int n, X, Y, x[101], y[101];
char s[101];

void solve(){	
	int nx, ny;		
	if(!X & !Y){
		printf("Yes\n"); return;	
	}
	for(int i = 1; i <= n; i++){
		if(x[i] == X && y[i] == Y){
			printf("Yes\n"); return;
		}
		nx = X - x[i];
		ny = Y - y[i];
		if(x[n] && !nx) continue;
		if(y[n] && !ny) continue;
		if(!x[n] && nx) continue;
		if(!y[n] && ny) continue;
		if((x[n] && (nx % x[n])) || (y[n] && (ny % y[n]))) continue;
		if(!nx){
			if(ny / y[n] > 0){
				printf("Yes\n"); return;
			} 
		} else 
		if(!ny){
			if(nx / x[n] > 0){
				printf("Yes\n"); return;
			} 
		} 
		else{
			int a = nx / x[n], b = ny / y[n];
			if(a == b && a > 0){
				printf("Yes\n"); return;
			}
		}
	}
	printf("No\n");
}

int main(){
	int dx = 0, dy = 0, nx, ny;
	scanf("%d%d", &X ,&Y);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++){
		if(s[i] == 'U') dy++;
		if(s[i] == 'D') dy--;
		if(s[i] == 'L') dx--;
		if(s[i] == 'R') dx++;
		x[i] = dx; y[i] = dy;
	}
	solve();
	return 0;
}

