#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1001
using namespace std;
struct node{
	int keyA,keyB;	
}RA[N],CB[N],RB[N],CA[N];
int n,m,T,A[N][N],B[N][N],num[N];
const int mod1=10007,mod2=23333;
bool comp(const node &a,const node &b){
	if(a.keyA==b.keyA) return a.keyB<b.keyB;
	return a.keyA<b.keyA;
}
void Hash(int P[N][N],node R[N],node C[N]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) num[j]=P[i][j];
		sort(num+1,num+1+m);
		int k1=0,k2=0;
		for(int j=1;j<=m;j++){
			k1=(k1*mod2+(num[j]%mod1))%mod1;
			k2=(k2*mod1+(num[j]%mod2))%mod2;
		}
		R[i].keyA=k1;R[i].keyB=k2;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) num[j]=P[j][i];
		sort(num+1,num+1+n);
		int k1=0,k2=0;
		for(int j=1;j<=n;j++){
			k1=(k1*mod2+(num[j]%mod1))%mod1;
			k2=(k2*mod1+(num[j]%mod2))%mod2;
		}
		C[i].keyA=k1;C[i].keyB=k2;
	}
}
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&A[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&B[i][j]);
}
void solve(){	
	Hash(A,RA,CA);Hash(B,RB,CB);				
	sort(RA+1,RA+1+n,comp);
	sort(RB+1,RB+1+n,comp);	
	for(int i=1;i<=n;i++) if(RA[i].keyA!=RB[i].keyA || RA[i].keyB!=RB[i].keyB){
		printf("NIE\n");return;
	}
	sort(CA+1,CA+1+m,comp);
	sort(CB+1,CB+1+m,comp);
	for(int i=1;i<=m;i++) if(CA[i].keyA!=CB[i].keyA || CA[i].keyB!=CB[i].keyB){
		printf("NIE\n");return;
	}	
	printf("TAK\n");
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		solve();
	}
	return 0;
}

