//区间K大 无修改  POJ 2104
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100001
#define M 3000001
using namespace std;
int n,m,sz,top,tot,A[N],shu[N],num[N];
int root[N],sum[M],ls[M],rs[M];
int find(int x){
	int l=1,r=tot,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		if(num[mid]==x) return mid;
		if(num[mid]>x) r=mid;
		else l=mid;
	}
	if(num[l]==x) return l;
	if(num[r]==x) return r;
} 
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		shu[++top]=A[i];
	}
	sort(shu+1,shu+1+top);
	num[++tot]=*(shu+1);
	for(int i=2;i<=top;i++){
		if(shu[i]!=shu[i-1]) num[++tot]=shu[i];
	}
	for(int i=1;i<=n;i++) A[i]=find(A[i]);
}
void Insert(int x,int &y,int l,int r,int p){
	y=++sz;
	sum[y]=sum[x]+1;
	if(l==r) return;
	ls[y]=ls[x];rs[y]=rs[x];
	int mid=(l+r)>>1;
	if(p<=mid) Insert(ls[x],ls[y],l,mid,p);
	else Insert(rs[x],rs[y],mid+1,r,p);
}
int query(int L,int R,int k){
	int l=1,r=tot,mid;
	L=root[L-1],R=root[R];
	while(l!=r){
		mid=(l+r)>>1;
		if(sum[ls[R]]-sum[ls[L]]>=k){
			L=ls[L];R=ls[R];
			r=mid;
		}
		else{
			k-=sum[ls[R]]-sum[ls[L]];
			L=rs[L];R=rs[R];
			l=mid+1;
		}
	}
	return num[l];
}
void solve(){
	int i,l,r,k;
	for(i=1;i<=n;i++) Insert(root[i-1],root[i],1,tot,A[i]);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(l,r,k));
	}
}
int main(){
	init();
	solve();
	return 0;
}

