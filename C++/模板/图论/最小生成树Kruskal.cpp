//最小生成树 Kruskal算法  vijos 1190
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct road{
	int A,B,V;
}R[10001];
int n,m,fa[301];
inline bool comp(const road &a,const road &b){
	return a.V<b.V;
}
int getfather(int x){
	if(fa[x]==0) return x;
	return fa[x]=getfather(fa[x]);
}
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) 
		scanf("%d%d%d",&R[i].A,&R[i].B,&R[i].V);
}
void solve(){
	int i,x,y,now=0;
	sort(R+1,R+1+m,comp);
	for(i=1;i<=m;i++){
		x=getfather(R[i].A);
		y=getfather(R[i].B);
		if(x!=y){
			fa[x]=y;
			now++;
			if(now==n-1){
				printf("%d %d\n",now,R[i].V);
				return;
			}
		}
	}
}
int main(){
	init();
	solve();
	return 0;
}
