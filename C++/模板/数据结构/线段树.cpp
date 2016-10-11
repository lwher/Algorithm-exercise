//对一个数列区间加上一个数V，查询区间和 
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 200001
using namespace std;
int n,m;
long long t[N<<2],tag[N<<2];
void downpush(int k,int l,int r){
	int mid=(l+r)>>1;
	tag[k<<1]+=tag[k];tag[k<<1|1]+=tag[k];
	t[k<<1]+=tag[k]*(mid-l+1);
	t[k<<1|1]+=tag[k]*(r-mid);
	tag[k]=0;
}
void update(int k,int l,int r,int a,int b,int x){
	if(l>=a && r<=b){
		tag[k]+=x;
		t[k]+=(long long)(r-l+1)*x;
		return;
	}
	if(tag[k]) downpush(k,l,r);
	int mid=(l+r)>>1;
	if(a<=mid) update(k<<1,l,mid,a,b,x);
	if(b>mid) update(k<<1|1,mid+1,r,a,b,x);
	t[k]=t[k<<1]+t[k<<1|1];
}
long long ask(int k,int l,int r,int a,int b){
	if(r<a || l>b) return 0;
	if(l>=a && r<=b) return t[k];
	if(tag[k]) downpush(k,l,r);
	int mid=(l+r)>>1;
	return ask(k<<1,l,mid,a,b)+ask(k<<1|1,mid+1,r,a,b);
}
void init(){
	int i,num;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		update(1,1,n,i,i,num);
	}
}
void solve(){
	int i,k,l,r,x;
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&k);
		if(k==1){
			scanf("%d%d%d",&l,&r,&x);
			update(1,1,n,l,r,x);
		}
		else{
			scanf("%d%d",&l,&r);
			printf("%lld\n",ask(1,1,n,l,r));
		}
	}
}
int main(){
	init();
	solve();
	return 0;
}
