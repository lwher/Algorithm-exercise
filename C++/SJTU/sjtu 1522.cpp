#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 1e8
#define N 300001
int x[N],y[N],n; 
bool OK[N],up[10][N];
void cover(int X,int Y,int mid){
	for(int i=1;i<=n;i++){
		if(!OK[i] && x[i]>=X && x[i]-X<=mid && y[i]>=Y && y[i]-Y<=mid) OK[i]=1;
	}
}
bool check(int mid,int last){
	int minx=INF,miny=INF,maxx=-INF,maxy=-INF;
	for(int i=1;i<=n;i++){
		if(OK[i]) continue;
		minx=min(x[i],minx);miny=min(y[i],miny);
		maxx=max(x[i],maxx);maxy=max(y[i],maxy); 
	}
	if(last==1){ 
		if(maxx-minx>mid || maxy-miny>mid) return 0;
		else return 1;
	}
	for(int i=1;i<=n;i++) up[last][i]=OK[i];
	cover(minx,miny,mid);
	if(check(mid,last-1)) return 1;
	for(int i=1;i<=n;i++) OK[i]=up[last][i];
	cover(minx,maxy-mid,mid);
	if(check(mid,last-1)) return 1;
	for(int i=1;i<=n;i++) OK[i]=up[last][i];
	cover(maxx-mid,miny,mid);
	if(check(mid,last-1)) return 1;
	for(int i=1;i<=n;i++) OK[i]=up[last][i];
	cover(maxx-mid,maxy-mid,mid);
	if(check(mid,last-1)) return 1;
	for(int i=1;i<=n;i++) OK[i]=up[last][i];
	return 0;
}
int main(){
	scanf("%d", &n);
	int minx=INF,miny=INF,maxx=-INF,maxy=-INF;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		minx=min(x[i],minx);miny=min(y[i],miny);
		maxx=max(x[i],maxx);maxy=max(y[i],maxy); 
	}
	int l=0,r=1e7,mid;
	
	while(l+1<r){
		int mid=(l+r)/2;
		memset(OK,0,sizeof(OK));
		if(check(mid,3)) r=mid;
		else l=mid;
	}
	memset(OK,0,sizeof(OK));
	if(check(l,3)) printf("%d\n",l);
	else printf("%d\n",r);
	return 0;
}
