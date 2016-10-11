#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 200010

using namespace std;

int n, tt, top, dfn[N], low[N], stack[N];
int fl, size[N];
int sz, pre[N], to[N], last[N];
bool in[N];

void Ins(int a, int b){
	sz++; to[sz] = b; pre[sz] = last[a]; last[a] = sz;
}

void init(){
	int x;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		Ins(i, x);
	}
}

int tot, S[N], Pre[N];
void Tarjan(int y){
	S[++tot] = y; Pre[tot] = last[y];
	dfn[y] = ++tt; low[y] = tt;
	stack[++top] = y; in[y] = 1;
	while(tot > 0){
		int x = S[tot];
		if(!Pre[tot]){
			if(low[x] == dfn[x]){
				size[++fl]++;
				while(stack[top] != x){
					size[fl]++;
					in[stack[top]] = 0;
					top--;
				}
				in[x] = 0; top--;
			}
			tot--;
			if(tot) low[S[tot]] = min(low[S[tot]], low[x]);
		}
		else {
		    int To = to[Pre[tot]];
			Pre[tot] = pre[Pre[tot]];
		    if(!dfn[To]){
				S[++tot] = To;
				Pre[tot] = last[To];
				dfn[To] = ++tt; low[To] = tt; 
				stack[++top] = To; in[To] = 1;
			} else
			if(in[To]) low[x] = min(low[x], dfn[To]); 
			
		}
	}
}

void solve(){
	
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) Tarjan(i);
	}
	int ans = n + 1;
	for(int i = 1; i <= fl; i++){
		if(size[i] != 1) ans = min(ans ,size[i]);
	}
	cout << ans << endl;
}
int main(){
	init();
	solve();
	return 0;
}

