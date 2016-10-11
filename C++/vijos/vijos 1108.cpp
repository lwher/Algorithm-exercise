#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define clear(a,b) memset(a,b,sizeof(a))
using namespace std;
int T,n,R[26],num[26],dist[26];
int sz,to[301],pre[301],v[301],last[26];
void Ins(int a,int b,int c){
	sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void init(){
	int x;
	clear(num,0);
	for(int i=0;i<24;i++) scanf("%d",&R[i+1]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		num[x+1]++;
	}
}
void build(int x){
	sz=0;clear(last,0);
	for(int i=1;i<25;i++){
		Ins(i-1,i,num[i]);
		Ins(i,i-1,0);
	}
	for(int i=8;i<25;i++) Ins(i,i-8,-R[i]);
	for(int i=1;i<8;i++) Ins(i,i+16,x-R[i]);
	Ins(24,0,-x);Ins(0,24,x);
}
bool in[26];
bool dfs_spfa(int x){
	in[x]=1;
	for(int i=last[x];i;i=pre[i]){
		if(dist[to[i]]>dist[x]+v[i]){
			if(in[to[i]]) return 0;
			dist[to[i]]=dist[x]+v[i];
			if(!dfs_spfa(to[i])) return 0;
		}
	}
	in[x]=0;
	return 1;
}
bool check(int x){
	build(x);
	clear(dist,127);
	clear(in,0);
	dist[0]=0;
	if(dfs_spfa(0)) return 1;
	else return 0;
}
void solve(){
	if(!check(n)){
		printf("No Solution\n");
		return;
	}
	int l=0,r=n,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	if(check(l)) printf("%d\n",l);
	else printf("%d\n",r);
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		solve();
	}
	return 0;
}

