#include<iostream>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
char p[101][101],map[101][101];
int n,m,f[101][101][101],g[101][101][101],h[101][101];
long long ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%s",p[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) map[i][j]=p[n-i+1][j];	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)if(map[i][j]!='x'){
		while(h[i][j]+i<=n && map[h[i][j]+i][j]!='x') h[i][j]++;
	}		
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=1;k<=h[i][j];k++){
		for(int l=j;l<=m;l++){
			if(h[i][l]<k) break;
			f[i][j][k]++;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=1;k<=h[i][j];k++){
		g[i][j][k]=g[i][j][k-1];
		if(g[i][j][k]<k*f[i][j][k]) g[i][j][k]=f[i][j][k]*k;
	}			
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=2;k<=h[i][j];k++){
		for(int l=j+1;l<=f[i][j][k]+j;l++){
			if(l>m) break;
			if(g[i][l][min(k-1,h[i][l])]>0 && (l-j)*k+g[i][l][min(k-1,h[i][l])]>ans) ans=(l-j)*k+g[i][l][min(k-1,h[i][l])];
		}
	}						
	cout<<ans<<endl;
	return 0;
}

