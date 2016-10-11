//不断将某个点为根的子树所形成的堆向父亲合并  BZOJ 2809
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100001
using namespace std;
int n,M,B[N],C[N],L[N];
int root[N],ls[N],rs[N],num[N],dis[N];
long long sum[N],ans;
std::vector<int> to[N];
int merge(int a,int b){
	if(!a || !b) return a+b;
	if(C[a]<C[b]) swap(a,b);
	rs[a]=merge(rs[a],b);
	if(dis[ls[a]]<dis[rs[a]]) swap(ls[a],rs[a]);
	dis[a]=dis[rs[a]]+1;
	num[a]=num[ls[a]]+num[rs[a]]+1;
	sum[a]=sum[ls[a]]+sum[rs[a]]+C[a];
	return a;
}
void init(){
	scanf("%d%d",&n,&M);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&B[i],&C[i],&L[i]);
		to[B[i]].push_back(i);
	}
}
void dfs(int x){
	root[x]=x;
	num[x]=1;
	sum[x]=C[x];
	for(int i=0;i<to[x].size();i++){
		dfs(to[x][i]);
		root[x]=merge(root[x],root[to[x][i]]);
	}
	while(sum[root[x]]>M) root[x]=merge(ls[root[x]],rs[root[x]]);
	ans=max(ans,(long long)L[x]*num[root[x]]);
}
void solve(){
	dis[0]=-1;			
	dfs(1);
	cout<<ans<<endl;
}
int main(){
	init();
	solve();
	return 0;
}

