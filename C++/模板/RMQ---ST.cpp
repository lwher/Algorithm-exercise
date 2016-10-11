//RMQ 倍增算法 支持在不修改的情况下，nlogn预处理，之后O(1)回答每个询问 vijos 1514
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 200001
using namespace std;
int n,m,num[N],f[N][18],Log2[N];
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		f[i][0]=num[i];
	}
	int now=0,k=2;
	for(int i=1;i<=n;i++){
		if(i==k){
			now++;k<<=1;
		}
		Log2[i]=now;
	}
}
void solve(){
	int l,r,k;
	for(int j=1;j<=Log2[n];j++){
		for(int i=1;i<=n;i++){
			if(i-1+(1<<j)>n) break; 
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	scanf("%d",&m);	
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		k=Log2[r-l+1];
		printf("%d\n",max(f[l][k],f[r-(1<<k)+1][k]));
	}
}
int main(){
	init();
	solve();
	return 0;
}

