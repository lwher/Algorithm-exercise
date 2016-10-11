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
	num[x]=p;
	for(int i=x;i<=n;i+=lowbit(i)){
		tmax[i]=p;
		for(int j=1;j<lowbit(i);j<<=1)
			tmax[i]=max(tmax[i],tmax[i-j]);
	}
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
	char C[3];
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
			tmax[i]=-1e9;
		}
		for(int i=1;i<=n;i++) update(i,num[i]);
		for(int i=1;i<=m;i++){
			scanf("%s%d%d",C,&l,&r);
			if(C[0]=='Q') printf("%d\n",askmax(l,r));
			else update(l,r);
		}
	}
	return 0;
}

