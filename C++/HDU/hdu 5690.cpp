#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct Matrix{
	int num[2][2];
};
int X, M, K, C;
Matrix operator *(const Matrix &a,const Matrix &b){
	Matrix res={0,0,0,0};
	for(int i=0;i<2;i++) 
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				res.num[i][j]=(res.num[i][j]+a.num[i][k]*b.num[k][j])%K;
	return res;
}
Matrix quickpow(Matrix A,int b){
	Matrix res={1,0,0,1};
	while(b>0){
		if(b & 1) res=res*A;
		b>>=1;
		A=A*A;
	}
	return res;
}
void solve(){
	Matrix A={X,X,0,0};
	Matrix B={10,0,1,1};
	M--;
	Matrix Ans=A*quickpow(B,M);
	if(Ans.num[0][0] == C) printf("Yes\n");
	else printf("No\n");
}
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		scanf("%d %d %d %d", &X, &M, &K, &C);
		printf("Case #%d:\n", t);
		solve();
	}
	return 0;
}
