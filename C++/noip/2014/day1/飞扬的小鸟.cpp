#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=1000000000;
int n,m,K,ans,f[10010][1010];
int X[10010],Y[10010],x[10010];
bool mark[10010][1010];
void init(){
	int i,j,h,l;
	scanf("%d%d%d",&n,&m,&K);
	for(i=0;i<n;i++) scanf("%d%d",&X[i],&Y[i]);
	for(i=1;i<=K;i++){
		scanf("%d%d%d",&x[i],&l,&h);
		for(j=0;j<=l;j++) mark[x[i]][j]=1;
		for(j=m;j>=h;j--) mark[x[i]][j]=1;
	}
}
bool check(int p){
	for(int i=1;i<=m;i++) if(f[p][i]<INF) return 1;
	return 0;
}
void solve(){
	int i,j,k,p,l;
	int nowp,nowmin;
	for(i=0;i<=n;i++) for(j=0;j<=m;j++) f[i][j]=INF; 
	for(i=1;i<=m;i++) f[0][i]=0;	
	for(i=1;i<=n;i++){
		for(j=1;j<=X[i-1];j++){
			nowp=0;nowmin=INF/2;
			for(k=0;k<=m+5;k++){
				if(j+k*X[i-1]>m) break;	
					p=j+k*X[i-1];
					if(p-X[i-1]>0 && !mark[i-1][p-X[i-1]] && f[i-1][p-X[i-1]]<INF){
						if(nowmin>f[i-1][p-X[i-1]]-k) {
							nowmin=f[i-1][p-X[i-1]]-k;
							nowp=p-X[i-1];
						}
					}
                    if(!mark[i][j+k*X[i-1]])
                    {
    					if(p+Y[i-1]<=m && !mark[i-1][p+Y[i-1]]) f[i][p]=min(f[i][p],f[i-1][p+Y[i-1]]);
    					if(nowp!=0 && nowmin<INF) f[i][p]=min(f[i][p],f[i-1][nowp]+(p-nowp)/X[i-1]);
    				}
			}
		}
        if(!mark[i][m]){
			for(j=1;j<=m;j++) if(!mark[i-1][j]){
				if(m!=j && (m-j)%X[i-1]==0) f[i][m]=min(f[i][m],f[i-1][j]+(m-j)/X[i-1]);
				else f[i][m]=min(f[i][m],f[i-1][j]+(m-j)/X[i-1]+1);
			}
		}
	}
	ans=INF;
	for(i=1;i<=m;i++) ans=min(ans,f[n][i]);
	if(ans<INF) {
		printf("1\n%d\n",ans);
		return;
	}
	ans=0;		
	for(i=n;i>=1;i--){
		if(check(i)) {
			for(j=1;j<=K;j++) if(x[j]<=i) ans++;
			printf("0\n%d\n",ans);
			return;
		}
	} 
}
int main(){
	freopen("bird.in","r",stdin);
	freopen("bird.out","w",stdout);
	init();
	solve();
	return 0;
}
