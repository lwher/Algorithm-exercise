//矩阵乘法 logn求fib数列第n项  POJ 3070
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define mod 10000
using namespace std;
struct Matrix{
	int num[2][2];
};
int n;
Matrix operator *(const Matrix &a,const Matrix &b){
	Matrix res={0,0,0,0};
	for(int i=0;i<2;i++) 
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				res.num[i][j]=(res.num[i][j]+a.num[i][k]*b.num[k][j])%mod;
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
	while(scanf("%d",&n) && n!=-1){
		Matrix A={0,1,0,0};
		Matrix B={0,1,1,1};
		if(n==0) printf("0\n");
		else{
			Matrix Ans=A*quickpow(B,n-1);
			printf("%d\n",Ans.num[0][1]);
		}
	}
}
int main(){
	solve();
	return 0;
}

