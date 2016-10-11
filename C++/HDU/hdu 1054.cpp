#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1500
using namespace std;
int n,sum,belong[N];
bool vis[N];
std::vector<int> to[N];
bool find(int x){
	for(int i=0;i<to[x].size();i++){
		if(vis[to[x][i]]) continue;
		vis[to[x][i]]=1;
		if(belong[to[x][i]]==-1 || find(belong[to[x][i]])){
			belong[to[x][i]]=x;
			return 1;
		}
	}
	return 0;
}
void solve(){
	int i,x,y,m;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++) to[i].clear();
		for(i=0;i<n;i++){
			scanf("%d:(%d)",&x,&m);
			while(m--){
				scanf("%d",&y);
				to[x].push_back(y);
				to[y].push_back(x);
			}
		}
		sum=0;
		memset(belong,-1,sizeof(belong));
		for(i=0;i<n;i++){
			memset(vis,0,sizeof(vis));
			if(find(i)) sum++;
		}
		printf("%d\n",sum/2);
	}
}
int main(){
	solve();
	return 0;
}
