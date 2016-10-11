//最小费用最大流模板 ZKW多路增广  POJ 2135
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1010
#define M 50010
#define INF 0x7fffffff
using namespace std;
int n,m,s,t,dist[N];
int sz=1,to[M],v[M],cost[M],pre[M],last[N];
bool mark[N];
std::queue<int> Q;
void Ins(int a,int b,int c,int d){
	sz++;to[sz]=b;v[sz]=c;cost[sz]= d;pre[sz]=last[a];last[a]=sz;
	sz++;to[sz]=a;v[sz]=0;cost[sz]=-d;pre[sz]=last[b];last[b]=sz;
}
void init(){
	int i,a,b,c;
	scanf("%d%d",&n,&m);
	s=n+1;t=s+1;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		Ins(a,b,1,c);Ins(b,a,1,c);
	}
	Ins(s,1,2,0);
	Ins(n,t,2,0);
}
bool spfa(){
	memset(dist,127,sizeof(dist));
	memset(mark,0,sizeof(mark));
	dist[t]=0;
	mark[t]=1;
	Q.push(t);
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		mark[now]=0;
		for(int i=last[now];i;i=pre[i]){
			if(v[i^1]>0 && dist[to[i]]>dist[now]-cost[i]){
				dist[to[i]]=dist[now]-cost[i];
				if(!mark[to[i]]){
					mark[to[i]]=1;
					Q.push(to[i]);
				}
			}
		}
	}
	if(dist[s]==dist[0]) return 0;
	else return 1;
}
int dfs(int x,int F){
	mark[x]=1;
	if(x==t) return F;
	int i,used=0,w;
	for(i=last[x];i;i=pre[i]){
		if(v[i]>0 && !mark[to[i]] && dist[to[i]]==dist[x]-cost[i]){
			w=min(v[i],F-used);
			w=dfs(to[i],w);
			v[i]-=w;v[i^1]+=w;
			used+=w;
			if(F==used) return F;
		}
	}
	return used;
}
int mincostflow(){
	int res=0;
	while(spfa()){
		mark[t]=1;
		while(mark[t]){
			memset(mark,0,sizeof(mark));
			res+=dfs(s,INF) * dist[s];
		}
	}
	return res;
}
int main(){
	init();
	printf("%d\n",mincostflow());
	return 0;
}
