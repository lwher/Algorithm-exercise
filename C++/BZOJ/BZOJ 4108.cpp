#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 310
#define M 30010
#define INF 1000000000
using namespace std;
int n,K,S,T,dui[300010];
int sz=1,to[M],pre[M],v[M],last[N];
long long ans,dist[N],cost[M];
bool mark[N];
void Ins(int a,int b,int c,long long d){
    sz++;to[sz]=b;v[sz]=c;cost[sz]= d;pre[sz]=last[a];last[a]=sz;
    sz++;to[sz]=a;v[sz]=0;cost[sz]=-d;pre[sz]=last[b];last[b]=sz;
}
bool spfa(){
	int t=1,w=1,now;
	for(int i=1;i<=T;i++) dist[i]=INF;
	memset(mark,0,sizeof(mark));
	dist[T]=0;dui[1]=T;mark[T]=1;
	while(t<=w){
		now=dui[t];t++;
		mark[now]=0;
		for(int i=last[now];i;i=pre[i]){
			if(v[i^1]>0 && dist[to[i]]>dist[now]-cost[i]){
				dist[to[i]]=dist[now]-cost[i];
				if(!mark[to[i]]){
					mark[to[i]]=1;
					dui[++w]=to[i];
				}
			}
		}
	}
	return dist[S]!=INF;
}
int dfs(int x,int F){
	mark[x]=1;
	if(x==T) return F;
	int used=0,w;
	for(int i=last[x];i;i=pre[i]){
		if(v[i]>0 && !mark[to[i]] && dist[x]-cost[i]==dist[to[i]]){
			w=min(v[i],F-used);
			w=dfs(to[i],w);
			v[i]-=w;v[i^1]+=w;used+=w;
			if(F==used) return F;
		}
	}
	return used;
}
void mincostflow(){
	while(spfa()){
		mark[T]=1;
		while(mark[T]){
			memset(mark,0,sizeof(mark));
			ans+=dist[S]*dfs(S,INF);
		}
	}
}
void init(){
	scanf("%d%d",&n,&K);
	int x;n++;
	S=1;T=n+n+1;
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			scanf("%d",&x);
			Ins(i+n,i+j,INF,x);
		}	
	}
	Ins(S,n+1,K,0);
	for(int i=2;i<=n;i++) Ins(i,i+n,1,-100000000000LL);
	for(int i=1;i<=n;i++) Ins(i+n,T,INF,0);
}
int main(){
	init();
	mincostflow();
	while(ans<0) ans+=100000000000LL;
	cout<<ans<<endl;
	return 0;
}

