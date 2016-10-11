#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
int n,ans,v[N],down[N],up[N],size[N],sum[N],num[N];
void solve(){
	int i,t,x,y;
	for(i=1;i<=n;i++){
		t=0;num[v[i]]++;
		for(x=v[i];x;x>>=1) down[x]+=t++,size[x]++;
	}			
	for(i=2;i<=100000;i+=2){
		x=(i>>1);y=(i^1);
		up[i]=up[x]+down[y]+size[y]*2+n-size[i]-size[y];
		sum[i]=sum[x]+size[y]+num[x];
	}
	ans=0x7fffffff;
	for(i=1;i<=100000;i++){
		if(i&1){
			if(size[i]==n) ans=min(ans,down[i]);
		}
		else{
			if(sum[i]+size[i]==n) ans=min(ans,up[i]+down[i]);
		}
	}
	cout<<ans<<endl;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	solve();
	return 0;
}

