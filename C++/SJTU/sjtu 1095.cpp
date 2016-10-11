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
#define M 1000010

using namespace std;

struct node{
	int D, id;
	node(int a = 0, int b = 0){
		D = a; id = b;
	}
	bool operator <(const node &b) const{
		return D < b.D;
	}
};
int T, n, m, Q, hsz, w[N], dist[N];
int sz, to[M], v[M], pre[M], last[N];
bool have[N];
node Heap[N];

int read(){
	char ch = getchar();
	while(!(ch >= '0' && ch <= '9')) ch = getchar();
	int res = 0;
	while(ch >= '0' && ch <= '9'){
		res = res * 10 + (ch - '0');
		ch = getchar();
	}
	return res;	
}

inline void swap(node &a, node &b){
	node t = a; a = b; b = t;
}

void Heap_push(int x){
	while(x != 1 && Heap[x] < Heap[x>>1]){
		swap(Heap[x>>1], Heap[x]);
		swap(w[Heap[x].id], w[Heap[x>>1].id]);
		x >>= 1;
	}	
}

void Heap_Ins(node p){
	Heap[++hsz] = p;
	w[p.id] = hsz;
	Heap_push(hsz);
}

void Heap_downpush(int x){
	while((x<<1) <= hsz){
		int to = (x<<1);
		if(hsz > (x<<1) && Heap[x<<1|1]<Heap[to])
			to = (x<<1|1);
		if(Heap[x] < Heap[to] || Heap[x].D == Heap[to].D) break;
		swap(Heap[x], Heap[to]);
		swap(w[Heap[x].id], w[Heap[to].id]);
		x = to;
	}
}

void Heap_delete(int x){
	swap(Heap[x],Heap[hsz]);
	swap(w[Heap[x].id],w[Heap[hsz].id]);
	hsz--;
	Heap_downpush(x);
}

void Dij(){
	memset(dist, 127, sizeof(dist));	
	dist[1] = 0;hsz = 0;
	for(int i = 1; i <= n; i++)
		Heap_Ins(node(dist[i], i));	
	while(hsz > 0){
		node x = Heap[1];
		Heap_delete(1);
		int now = x.id;
		for(int i = last[now]; i > 0; i = pre[i]){
			if(dist[to[i]] > dist[now] + v[i]){
				dist[to[i]] = dist[now] + v[i];
				Heap[w[to[i]]].D = dist[to[i]];
				Heap_push(w[to[i]]);
			}
		}
	}
}
 
inline void Ins(int a, int b, int c){
	sz++; to[sz] = b; v[sz] = c; pre[sz] = last[a]; last[a] = sz;
}

int main(){
	int a, b, c;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		sz=0;memset(last,0,sizeof(last));
		n = read(); m = read();
		for(int i = 1; i <= n; i++){
			have[i] = read();
		}
		for(int i = 1; i <= m; i++){
			a = read(); b = read(); c = read();
			Ins(a, b, c);
			Ins(b, a, c);
		}
		++n;
		for(int i = 1; i < n; i++)
			if(have[i]){
				Ins(i, n, 0);
				Ins(n, i, 0);
			}	
		Dij();		
		Q = read();
		printf("Case #%d:\n",t);
		for(int i = 1; i <= Q; i++){
			c = read();
			if(dist[c] != dist[0]) printf("%d\n", dist[c]);
			else printf("-1\n");
		}
	}
	return 0;
}


