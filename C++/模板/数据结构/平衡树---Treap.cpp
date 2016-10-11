//Treap模板 支持插入一个数，删除一个数，查询当前数中某个给定数字的前驱和后继 POJ 2892
#include<iostream>
#include<ctime>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 50010
using namespace std;
int n,m,sz,top,root,lower,upper,Des[N];
int ls[N],rs[N],num[N],rnd[N],w[N];
char s[1];
void rturn(int &t){
	int k=ls[t];
	ls[t]=rs[k];rs[k]=t;
	t=k;
}
void lturn(int &t){
	int k=rs[t];
	rs[t]=ls[k];ls[k]=t;
	t=k;
}
void Treap_Ins(int &W,int x){
	if(W==0){
		W=++sz;ls[W]=rs[W]=0;num[W]=x;w[W]=1;rnd[W]=rand();
		return;
	}
	if(num[W]==x){
		w[W]++;
		return;
	}else
	if(num[W]>x){
		Treap_Ins(ls[W],x);
		if(rnd[ls[W]]<rnd[W]) rturn(W);
	}
	else{
		Treap_Ins(rs[W],x);
		if(rnd[rs[W]]<rnd[W]) lturn(W);
	}
}
void Treap_Del(int &W,int x){
	if(num[W]==x){
		if(w[W]>1) w[W]--; else
		if(!ls[W] || !rs[W]) W=ls[W]+rs[W]; else
		if(rnd[ls[W]]<rnd[rs[W]]){
			rturn(W);
			Treap_Del(rs[W],x);
		}
		else{
			lturn(W);
			Treap_Del(ls[W],x);
		}
		return;
	}
	if(num[W]>x) Treap_Del(ls[W],x);
	else Treap_Del(rs[W],x);
}
void Treap_find(int W,int x){
	if(W==0) return;
	if(num[W]==x){
		lower=upper=x;
		return;
	}
	if(num[W]>x){
		if(num[W]-x<upper-x) upper=num[W];
		Treap_find(ls[W],x);
	}
	else{
		if(x-num[W]<x-lower) lower=num[W];
		Treap_find(rs[W],x);
	}
}
void init_solve(){
	int i,p;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%s",s);
		if(s[0]=='D'){
			scanf("%d",&p);
			Treap_Ins(root,p);
			Des[++top]=p;
		}else
		if(s[0]=='R'){
			Treap_Del(root,Des[top--]);
		}
		else{
			scanf("%d",&p);
			lower=0;upper=n+1;
			Treap_find(root,p);
			if(lower==p && upper==p) printf("0\n");
			else printf("%d\n",upper-lower-1);
		}
	}
}
int main(){
	srand(time(NULL));
	init_solve();
	return 0;
}

