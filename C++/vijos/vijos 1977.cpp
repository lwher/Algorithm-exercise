#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
struct node{
	int x, v;
	node(int X = 0, int V = 0){
		x = X; v = V;
	}
	bool operator <(const node &b) const{
		return v < b.v;
	}
};
int n, ans, dist[N], cost[N];
std::priority_queue<node> Ql, Qr;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &dist[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &cost[i]);
	for(int i = 1; i <= n; i++)	Qr.push(node(i, cost[i] + 2 * dist[i]));
	int R = 0;
	node pr, pl;		
	for(int i = 1; i <= n; i++){
		while(!Qr.empty() && Qr.top().x <= R) Qr.pop();
		if(!Qr.empty()) pr = Qr.top();
		else pr.v = -500000000;
		if(!Ql.empty()) pl = Ql.top();
		else pl.v = -500000000;
		if(pr.v - 2 * dist[R] > pl.v){
			Qr.pop();
			ans += pr.v - 2 * dist[R];
			while(R < pr.x - 1){
				++R;
				Ql.push(node(R, cost[R]));
			}
			++R;
		}
		else{
			Ql.pop();
			ans += pl.v;
		}
		printf("%d\n", ans);
	}
	return 0;
}

