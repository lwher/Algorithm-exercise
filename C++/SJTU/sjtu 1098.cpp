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

struct road{
	int u, v;
	road(int a = 0,int b = 0){
		u = a; v = b;
	}
	bool operator <(const road &b) const{
		if(u == b.u) return v < b.v;
		else return u < b.u;
	}
};
road R[1010];
int n, m, T, Du[101];

bool check(){
	for(int i = 1; i <= n; i++) 
		if(!(Du[i] & 1)) 
			return 0;
	return 1;
}

int main(){
	int a, b;
	scanf("%d", &T);
	while(T--){
		memset(Du, 0, sizeof(Du));
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= m; i++){
			scanf("%d %d", &a, &b);
			if(a > b) swap(a, b);
			Du[a]++;
			Du[b]++;
			R[i] = road(a, b);
		}
		if(m == 0) printf("NO ODD SUBGRAPH\n"); else
		if(check()) printf("ODD GRAPH\n"); 
		else{
			int k = 1;
			for(int i = 2; i <= m; i++){
				if(R[i] < R[k])
					k = i;
			}
			printf("2 %d %d\n",R[k].u, R[k].v);
		}
	}
	return 0;
}

