//最小费用最大流模板  Spfa单路增广  POJ 2135
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
int n,m,s,t,dist[N],fromP[N],fromV[N];
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
				fromP[to[i]]=now;
				fromV[to[i]]=i^1;
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
int mincostflow(){
	int x,u,flow,res=0;
	while(spfa()){
		x=s;flow=INF;
		while(x!=t){
			flow=min(flow,v[fromV[x]]);
			x=fromP[x];
		}
		x=s;
		while(x!=t){
			u=fromV[x];
			v[u]-=flow;
			v[u^1]+=flow;
			res+=cost[u]*flow;
			x=fromP[x];	
		}
	}
	return res;
}
int main(){
	init();
	printf("%d\n",mincostflow());
	return 0;
}
