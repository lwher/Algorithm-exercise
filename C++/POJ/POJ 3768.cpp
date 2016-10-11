#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n, top;
char s[30][30], ans[3010][3010];

inline int get(int k){
	int res = 1;
	for(int i = 1; i <= k; i++) res *= n;
	return res;
}

void Put(int x, int y){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			ans[x + i - 1][y + j - 1] = s[i][j];
		}
	}
}

void work(int x, int y, int last){
	if(last == 1){
		Put(x, y); return;
	} 
	int p = get(last - 1), X = 0, Y;
	for(int i = 1; i <= n; i++){
		Y = 0;		
		for(int j = 1; j <= n; j++){
			if(s[i][j] != ' ') work(X + x, Y + y, last - 1);			
			Y += p;
		}
		X += p;
	}
}

int main(){
	while(scanf("%d", &n)){
		if(!n) break;
		getchar();		
		for(int i = 1; i <= n; i++){
			gets(s[i] + 1);
		}
		scanf("%d", &top);
		int p = get(top);
		memset(ans,0,sizeof(ans));
		for(int i = 1; i <= p; i++) for(int j = 1; j <= p; j++) ans[i][j] = ' ';
		work(1, 1, top);	
		for(int i = 1; i <= p; i++){
			for(int j = 1; j <= p; j++) {		
					putchar(ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
