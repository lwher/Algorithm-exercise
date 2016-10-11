#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
int n, ans, num[2][300010];
void solve(){
	int i, j, top, p = 0, q = 1, sum;
	for(i = 30;i >= 0;i --){
		top = 0;sum = 0;
		for(j = 1;j <= n; j++){
			if(num[p][j] & (1 << i)){
				num[q][++ top] = num[p][j];
				sum ++;
			}
        }
 		if(sum < 2) continue;
		ans += (1 << i);
		p ^= 1;q ^= 1;
		n = top;	
	}
}
int main(){
	int i;
	scanf("%d", &n);
	for(i = 1;i <= n;i ++) 
		scanf("%d", &num[0][i]);
	solve();
	printf("%d\n", ans);
	system("pause");
	return 0;
}
