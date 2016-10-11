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

int n, H[100010];
int top, Q[100010],W[100010];
long long ans;

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &H[i]);
	H[++n] = 0;
	top = 0;
	for(int i = 1; i <= n; i++){
		int w = 0;
		while(top > 0 && H[Q[top]] >= H[i]){
			w += W[top];
			if(top > 1)
				ans = max(ans, (long long)(w + W[top-1]) * H[Q[top-1]]);
			top--;
		}
		Q[++top] = i, W[top] = w + 1;
		ans = max(ans, (long long)W[top] * H[i]);
	}
	cout << ans << endl;
	return 0;
}

