/*
	KMP算法 线性复杂度 HDU 1711
	此代码功能是查询B串在A串中第一次出现的位置 
*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 10001
using namespace std;
int nA,nB,T,fail[N],A[100*N],B[N];
void Get_fail(int len,int s[]){
    int i,j;
	fail[0]=-1;
    for(i=1;i<=len;i++){
		for(j=fail[i-1];j!=-1 && s[j+1]!=s[i];j=fail[j]);
		fail[i]=j+1;
	}
}
void init(){
	scanf("%d%d",&nA,&nB);
	for(int i=1;i<=nA;i++) scanf("%d",&A[i]);
	for(int i=1;i<=nB;i++) scanf("%d",&B[i]);
}
void solve(){
	int i,j=0;
	for(i=1;i<=nA;i++){
		for(;j!=-1 && B[j+1]!=A[i];j=fail[j]);
		j++;
		if(j==nB){
			printf("%d\n",i-j+1);
			return;
		}
	}
	printf("-1\n");
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		Get_fail(nB,B);				
		solve();
	}
	return 0;
}

