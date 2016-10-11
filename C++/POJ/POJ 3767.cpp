#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define N 1210
#define M 20010

using namespace std;

int n, m, Kind[N];
int sz, to[M], pre[M], v[M], last[N];

void Ins(int a, int b, int c){
	sz++; to[sz] = b; v[sz] = c; pre[sz] = last[a]; last[a] = sz;
}

int Q[300010], dist[N];
bool mark[N];
int spfa(){
	memset(mark,0,sizeof(mark));
	memset(dist, 127, sizeof(dist));
	int t = 1, w = 1, now;
	Q[1] = 1; mark[1] = 1; dist[1] = 0;	
	while(t <= w){
		now = Q[t]; t++; mark[now] = 0;
		if(now > n){
			now -= n;		
			for(int i = last[now]; i; i = pre[i]){
				if(Kind[to[i]] != Kind[now]) continue;
				if(dist[now + n] + v[i] < dist[to[i] + n]){
					dist[to[i] + n] = dist[now + n] + v[i];
					mark[to[i] + n] = 1;
					Q[++w] = to[i] + n;
				}		
			}
		}
		else{
    		for(int i = last[now]; i; i = pre[i]){
				if(Kind[to[i]] == Kind[now]){
					if(dist[now] + v[i] < dist[to[i]]){
						dist[to[i]] = dist[now] + v[i];
						mark[to[i]] = 1;
						Q[++w] = to[i];
					}
				}					
				else{
					if(dist[now] + v[i] < dist[to[i] + n]){
						dist[to[i] + n] = dist[now] + v[i];
						mark[to[i] + n] = 1;
						Q[++w] = to[i] + n;
					}	
				}
			}
		}
	}
	int ans = min(dist[2], dist[2 + n]);
	if(ans == dist[0]) return -1;
	else return ans;
}

int main(){
	int a, b, c;
	while(scanf("%d", &n)){
		if(!n) break;
		sz = 0; memset(last, 0, sizeof(last));		
		scanf("%d", &m);
		for(int i = 1; i <= m; i++)	{
			scanf("%d%d%d", &a, &b, &c);
			Ins(a, b, c); Ins(b, a, c);
		}
		for(int i = 1; i <= n; i++) scanf("%d", &Kind[i]);
		cout << spfa() << endl;
	}
	return 0;
}
