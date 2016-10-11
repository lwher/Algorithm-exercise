//网络流最大流模板 SAP算法 用上了断层优化和当前弧优化 POJ 1273
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 201
#define M 501
#define INF 0x7fffffff
using namespace std;
int n,m,s,t;
int H[N],gap[N],cur[N];
int sz=1,to[M],v[M],pre[M],last[N];
std::queue<int> Q;
void Ins(int a,int b,int c){
	sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
	sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void init(){
	int i,a,b,c;
	scanf("%d%d",&m,&n);
	s=1;t=n;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		Ins(a,b,c);
	}
}
void bfs(){
	memset(H,-1,sizeof(H));
	memset(gap,0,sizeof(gap));
	H[t]=0;gap[0]=1;
	Q.push(t);
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		for(int i=last[now];i;i=pre[i]){
			if(H[to[i]]==-1){
				H[to[i]]=H[now]+1;
				gap[H[to[i]]]++;
				Q.push(to[i]);
			}
		}
	}
}
int dfs(int x,int F){
	if(x==t) return F;
	int i,used=0,w;
	for(i=cur[x];i;i=pre[i]){
		if(v[i]>0 && H[to[i]]==H[x]-1){
			w=min(v[i],F-used);
			w=dfs(to[i],w);
			v[i]-=w;v[i^1]+=w;used+=w;
			if(v[i]>0) cur[x]=i;
			if(F==used) return F;
		}
	}
	gap[H[x]]--;
	if(!gap[H[x]]) H[s]=n+2;
	cur[x]=last[x];
	gap[++H[x]]++;
	return used;
}
int SAP(){
	int res=0;	
	bfs();
	for(int i=1;i<=n;i++) cur[i]=last[i];
	while(H[s]<n+2) res+=dfs(s,INF);
	return res;
}
int main(){
	init();
	printf("%d\n",SAP());
	return 0;
}
