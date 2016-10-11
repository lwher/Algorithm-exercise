//最小生成树Prim算法 用上了堆（优先队列）优化  vijos 1190
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct node{
	int p,d;
};
bool operator <(const node &a,const node &b){
	return a.d > b.d;
}
int n,m,ans,dist[301];
bool mark[301];
int sz,to[30001],v[30001],pre[30001],last[301];
priority_queue<node> q;
void Ins(int a,int b,int c){
	sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void init(){
	int i,a,b,c;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		Ins(a,b,c);Ins(b,a,c);
	}
}
void solve(){
	int num=0,i,now;
	memset(dist,127,sizeof(dist));
	dist[1]=0;
	node P;
	P.p=1;P.d=0;
	q.push(P);
	while(!q.empty()){
		P=q.top();
		q.pop();
		now=P.p;
		if(mark[now]) continue;
		mark[now]=1;
		ans=max(ans,dist[now]);
		num++;
		if(num==n) break;
		for(i=last[now];i;i=pre[i]){
			if(v[i]<dist[to[i]]){
				dist[to[i]]=v[i];
				P.p=to[i];P.d=v[i];
				q.push(P);
			}
		}
	}
	printf("%d %d\n",num-1,ans);
}
int main(){
	init();
	solve();
	return 0;
}
