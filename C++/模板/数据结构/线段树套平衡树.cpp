//线段树套平衡树 支持可修改的区间K大 在线操作  ZOJ 2112
#include<iostream>
#include<ctime>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 10001
#define M 1000001
using namespace std;
int n,m,root[N<<2],A[N];
int sz,ls[M],rs[M],size[M],num[M],w[M],rnd[M];
inline void update(int x){
	size[x]=size[ls[x]]+size[rs[x]]+w[x];
}
inline void lturn(int &t){
	int k=rs[t];
	rs[t]=ls[k];ls[k]=t;
	update(t);update(k);
	t=k;
}
inline void rturn(int &t){
	int k=ls[t];
	ls[t]=rs[k];rs[k]=t;
	update(t);update(k);
	t=k;
}
void Treap_Ins(int &p,int x){
	if(!p){
		p=++sz;num[p]=x;size[p]=1;w[p]=1;rnd[p]=rand();
		return;
	}
	if(num[p]==x) w[p]++; else
	if(num[p]>x){
		Treap_Ins(ls[p],x);
		if(rnd[ls[p]]<rnd[p]) rturn(p);
	}
	else{
		Treap_Ins(rs[p],x);
		if(rnd[rs[p]]<rnd[p]) lturn(p);
	}
	update(p);
}
void Treap_Del(int &p,int x){
	if(num[p]==x){
		if(w[p]>1) w[p]--,size[p]--; else
		if(!ls[p] || !rs[p]) p=ls[p]+rs[p]; else
		if(rnd[ls[p]]<rnd[rs[p]]){
			rturn(p);Treap_Del(rs[p],x);update(p);
		}
		else{
			lturn(p);Treap_Del(ls[p],x);update(p);
		}
		return;
	}
	if(num[p]>x) Treap_Del(ls[p],x);
	else Treap_Del(rs[p],x);
	update(p);
}
int Treap_find(int p,int x){
	if(!p) return 0;
	if(num[p]==x) return size[ls[p]];
	if(num[p]<x) return size[ls[p]]+w[p]+Treap_find(rs[p],x);
	else return Treap_find(ls[p],x);
}
void modify(int k,int l,int r,int p,int x,int yx,int ty){
	if(ty) Treap_Del(root[k],yx);
	Treap_Ins(root[k],x);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(p<=mid) modify(k<<1,l,mid,p,x,yx,ty);
	else modify(k<<1|1,mid+1,r,p,x,yx,ty);
}
int query(int k,int l,int r,int a,int b,int x){//查询a-b区间内<x的数的个数 
	if(l>b || r<a) return 0;
	if(l>=a && r<=b) return Treap_find(root[k],x);
	int mid=(l+r)>>1;
	return query(k<<1,l,mid,a,b,x)+query(k<<1|1,mid+1,r,a,b,x);
}
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		modify(1,1,n,i,A[i],0,0);
	}
}
void solve(){
	int i,l,r,k,sum;
	char s[1];	
	for(i=1;i<=m;i++){
		scanf("%s%d%d",s,&l,&r);
		if(s[0]=='C'){
			modify(1,1,n,l,r,A[l],1);
			A[l]=r;
		}
		else{
			scanf("%d",&k);
			int L=0,R=2*1e9,mid;
			while(L+1<R){
				mid=(L+R)>>1;
				sum=query(1,1,n,l,r,mid);
				if(sum<k) L=mid;
				else R=mid;
			}
			sum=query(1,1,n,l,r,R);
			if(sum<k) printf("%d\n",R);
			else printf("%d\n",L);
		}
	}
}
int main(){
	//srand(time(NULL));
	init();	
	solve();
	return 0;
}

