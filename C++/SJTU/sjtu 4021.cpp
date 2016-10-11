#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 200000
#define INF 1LL<<50
using namespace std;
int n,m,hp[101],da[101],cost[101],kind[101];//1:all 0:single
long long ans=INF,f[200001],g[200001];
char s[50];
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&hp[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		scanf("%d",&cost[i]);
		scanf("%s",s);
		if(s[0]=='A') kind[i]=1;
		scanf("%d",&da[i]);
		if(da[i]>(N>>1)) da[i]=(N>>1);
	}
}
void DP(){//f:Aoe
	for(int i=1;i<=N;i++) f[i]=INF,g[i]=INF;
	for(int i=1;i<=m;i++) if(kind[i]==1){
		for(int j=0;j<=N-da[i];j++){
			if(f[j+da[i]]>f[j]+cost[i])
				f[j+da[i]]=f[j]+cost[i];
		}
	}
	for(int i=N-1;i>0;i--) f[i]=min(f[i],f[i+1]);
	for(int i=1;i<=m;i++) if(kind[i]==0){
		for(int j=0;j<=N-da[i];j++){
			if(g[j+da[i]]>g[j]+cost[i])
				g[j+da[i]]=g[j]+cost[i];
		}
	}
	for(int i=N-1;i>0;i--) g[i]=min(g[i],g[i+1]);
	int p=(N>>1);
	for(int i=0;i<=p;i++){
		long long res=f[i];
		for(int j=1;j<=n;j++){
			if(hp[j]<=i) continue;
			res+=g[hp[j]-i];
		}
		if(res<ans) ans=res;
	}
	cout<<ans<<endl;
}
int main(){
	init();
	DP();
	return 0;
}

