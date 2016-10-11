//SPFA算法 单源最短路 复杂度O(KM) 其中K一般为常数 tyvj 1031
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,s,t,dist[2501];
bool mark[2501];
vector<int> to[2501],v[2501];
queue<int> Q;
void init(){
	int i,a,b,c;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		to[a].push_back(b);v[a].push_back(c);
		to[b].push_back(a);v[b].push_back(c);
	}
}
void SPFA(){
	int i,now;
	memset(dist,127,sizeof(dist));
	dist[s]=0;mark[s]=1;
	Q.push(s);
	while(!Q.empty()){
		now=Q.front();
		Q.pop();
		mark[now]=0;
		for(i=0;i<to[now].size();i++){
			if(dist[to[now][i]]>dist[now]+v[now][i]){
				dist[to[now][i]]=dist[now]+v[now][i];
				if(!mark[to[now][i]]) 
					Q.push(to[now][i]),mark[to[now][i]]=1;
			}
		}
	}
}
void solve(){
	init();
	SPFA();
	printf("%d",dist[t]);
}
int main(){
	solve();
	return 0;
}
