//支持插入一个数，询问当前数中最小的元素  tyvj 1315
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth{
	int cost,p;
}heap[1010];
int n,m,sz,ans,cost[1010],up[1010];
void swap(sth &a,sth &b){
	sth t=a;a=b;b=t;
}
void upput(int x){
	while(heap[x>>1].cost>heap[x].cost){
		swap(heap[x],heap[x>>1]);
		x>>=1;
	}
}
void downput(int x){
	while((x<<1)<=sz){
		int y=(x<<1);
		if((x<<1|1)<=sz && heap[x<<1|1].cost<heap[x<<1].cost) y=(x<<1|1);
		if(heap[y].cost<heap[x].cost){
			swap(heap[x],heap[y]);
			x=y;
		}
		else break;
	}
}
void Heap_Ins(int C,int P){
	heap[++sz].cost=C;
	heap[sz].p=P;
	upput(sz);
}
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&cost[i],&up[i]);
}
void solve(){
	for(int i=1;i<=n;i++) Heap_Ins(cost[i],i);
	for(int i=1;i<=m;i++){
		ans+=heap[1].cost;
		heap[1].cost+=up[heap[1].p];
		downput(1);
	}
	printf("%d\n",ans); 
}
int main(){
	init();
	solve();
	return 0;
}

