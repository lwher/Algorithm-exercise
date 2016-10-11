//对一个数列单点修改，区间求和 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,Bit[100001];
int lowbit(int x){
	return x & (-x);
}
void update(int x,int p){
	for(int i=x;i<=n;i+=lowbit(i))
		Bit[i]+=p;
}
int ask(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res+=Bit[i];
	return res;
}
void init(){
	int i,num;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		update(i,num);
	}
}
void solve(){
	int i,k,l,r;
	scanf("%d",&m); 
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&k,&l,&r);
		if(k==1) update(l,r);
		else printf("%d\n",ask(r)-ask(l-1));
	}
}
int main(){
	init();
	solve();
	return 0;
}
