//Dijkstra算法 单源最短路 用上了堆（优先队列）优化  tyvj 1031
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 2501
using namespace std;
struct node{
	int D,P;
};
bool operator <(const node &a,const node &b) {
	return a.D > b.D;
}
int n,m,s,t,dist[N];
bool mark[N];
vector<int> to[N],v[N];
priority_queue<node> q;
void init(){
	int i,a,b,c;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		to[a].push_back(b);v[a].push_back(c);
		to[b].push_back(a);v[b].push_back(c);
	}
}
void Dij(){
	memset(dist,127,sizeof(dist));
	node now;
	now.D=0;now.P=s;
	q.push(now);
	dist[s]=0;
	while(!q.empty()){
		now=q.top();
		q.pop();
		if(mark[now.P]) continue;
		mark[now.P]=1;
		for(int i=0;i<to[now.P].size();i++){
			if(dist[now.P]+v[now.P][i]<dist[to[now.P][i]]){
				dist[to[now.P][i]]=dist[now.P]+v[now.P][i];
				node newp;
				newp.D=dist[to[now.P][i]];
				newp.P=to[now.P][i];
				q.push(newp);
			}
		}
	}
}
void solve(){
	init();
	Dij();
	printf("%d\n",dist[t]);
}
int main(){
	solve();
	return 0;
}
