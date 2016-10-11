#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,num[200001],tmax[200001];
inline int lowbit(int x){
	return x & -x;
}
void update(int x,int p){
	for(int i=x;i<=n;i+=lowbit(i)) tmax[i]=max(tmax[i],p);
}
int askmax(int l,int r){
	int res=-1e9;
	while(l<=r){
		res=max(res,num[r]);
		for(r--;r-lowbit(r)>=l;r-=lowbit(r)) res=max(res,tmax[r]);
	}
	return res;
}
int main(){
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		tmax[i]=-1e9;
	}
	for(int i=1;i<=n;i++) update(i,num[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",askmax(l,r));
	}
	return 0;
}

