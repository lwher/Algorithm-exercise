#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int res[5][5]={0,2,1,1,2,1,0,2,1,2,2,1,0,2,1,2,2,1,0,1,1,1,2,2,0};
			
int n,na,nb,ansa,ansb,NA[210],NB[210],A[210],B[210];
void init(){
	scanf("%d%d%d",&n,&na,&nb);
	for(int i=0;i<na;i++) scanf("%d",&NA[i]);
	for(int i=0;i<nb;i++) scanf("%d",&NB[i]);
	for(int i=0;i<n;i++){
		A[i]=NA[i%na];
		B[i]=NB[i%nb];
    }
}
void solve(){
	ansa=0;ansb=0;
	for(int i=0;i<n;i++){
		int k=res[A[i]][B[i]];
		if(k==1) ansa++; else 
		if(k==2) ansb++;
    }
    printf("%d %d\n",ansa,ansb);
}
int main(){
	freopen("rps.in","r",stdin);
	freopen("rps.out","w",stdout);
	init();
	solve();
	return 0;
}
