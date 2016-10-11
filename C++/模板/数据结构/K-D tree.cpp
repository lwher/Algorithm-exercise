/*
	K-D tree算法  时间复杂度：一般logn,最差sqrt(n)?  BZOJ 2626
	该代码支持给出n个平面上的点，m个询问，每次回答离某个坐标距离第K大的点，如果距离一样，则编号小的优先 
*/
#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100001
#define eps 1e-9
using namespace std;
struct kdtree{
	double x[2],key;
	int id;
}p[N];
int n,m,K,root,ls[N],rs[N],ansid[21];
double pmax[N][2],pmin[N][2],ansd[21];
inline bool comp(const kdtree &a,const kdtree &b){
	return a.key<b.key;
}
inline void update(int x){
	for(int i=0;i<2;i++) pmax[x][i]=p[x].x[i],pmin[x][i]=p[x].x[i];
	for(int i=0;i<2;i++){
		pmax[x][i]=max(pmax[x][i],pmax[ls[x]][i]);
		pmax[x][i]=max(pmax[x][i],pmax[rs[x]][i]);
		pmin[x][i]=min(pmin[x][i],pmin[ls[x]][i]);
		pmin[x][i]=min(pmin[x][i],pmin[rs[x]][i]);
	}
}
double sqr(double x){
	return x*x;
}
double dist(kdtree a,kdtree b){
	double res=0;
	for(int i=0;i<2;i++) res+=sqr(a.x[i]-b.x[i]);
	return res; 
}
int build(int l,int r,int w){
	if(l>r) return 0;
	for(int i=l;i<=r;i++) p[i].key=p[i].x[w];
	sort(p+l,p+r+1,comp);
	int mid=(l+r)>>1;
	ls[mid]=build(l,mid-1,w^1);
	rs[mid]=build(mid+1,r,w^1);
	update(mid);
	return mid;
}
void init(){
	scanf("%d",&n);	
	for(int i=0;i<2;i++) pmax[0][i]=-1e20,pmin[0][i]=1e20;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&p[i].x[0],&p[i].x[1]);
		p[i].id=i;
	}
	root=build(1,n,0);
}
void query(int x,int w){
	if(!x) return;
	int i,j;double D=0;
	for(i=0;i<2;i++) D+=max(sqr(p[0].x[i]-pmax[x][i]),sqr(p[0].x[i]-pmin[x][i]));
	if(D<ansd[K]-eps) return;
	D=dist(p[x],p[0]);
	for(i=1;i<=K;i++) if(ansd[i]+eps<D || (fabs(ansd[i]-D)<eps && ansid[i]>p[x].id)) break;
	for(j=K;j>i;j--) ansd[j]=ansd[j-1],ansid[j]=ansid[j-1];
	ansd[i]=D;ansid[i]=p[x].id;
	if(p[0].x[w]<=p[x].x[w]){
		query(rs[x],w^1);
		query(ls[x],w^1);
	}
	else{
		query(ls[x],w^1);
		query(rs[x],w^1);
	}
}
void solve(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%lf%lf%d",&p[0].x[0],&p[0].x[1],&K);
		for(int j=1;j<=K;j++) ansd[j]=-1;
		query(root,0);
		printf("%d\n",ansid[K]);
	}
}
int main(){
	init();
	solve();
	return 0;
}

