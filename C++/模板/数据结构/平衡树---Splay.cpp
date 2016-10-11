//Splay模板  支持区间加上一个数V，区间翻转，查询区间最大值 BZOJ 1251
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 50010
using namespace std;
int n,m,root,fa[N],c[N][2],tag[N],tmax[N],size[N],num[N];
bool rev[N];
void update(int x){
	int ls=c[x][0],rs=c[x][1];
	tmax[x]=max(tmax[ls],max(tmax[rs],num[x]));
	size[x]=size[ls]+size[rs]+1;
}
void downpush(int x){
	int ls=c[x][0],rs=c[x][1];
	if(rev[x]){
		if(ls) rev[ls]^=1;
		if(rs) rev[rs]^=1;
		swap(c[x][0],c[x][1]);
		rev[x]^=1;
	}
	if(tag[x]){
		if(ls){
			tag[ls]+=tag[x];num[ls]+=tag[x];tmax[ls]+=tag[x];
		}
		if(rs){
			tag[rs]+=tag[x];num[rs]+=tag[x];tmax[rs]+=tag[x];
		}
		tag[x]=0;
	}
}
void rotate(int &root,int x){
	int y=fa[x],z=fa[y],p,q;
	if(c[y][0]==x) p=0; else p=1;
	q=p^1;
	if(y==root) root=x;
	else{
		if(c[z][0]==y) c[z][0]=x;
		else c[z][1]=x;
	}
	fa[x]=z;fa[y]=x;fa[c[x][q]]=y;
	c[y][p]=c[x][q];c[x][q]=y;
	update(y);update(x);
}
void splay(int &root,int x){
	int y,z;
	while(x!=root){
		y=fa[x];z=fa[y];
		if(y!=root){
			if((c[z][0]==y) ^ (c[y][0]==x)) rotate(root,x);
			else rotate(root,y);
		}
		rotate(root,x);
	}
}
int find(int x,int k){
	downpush(x);
	int y=c[x][0];
	if(size[y]+1==k) return x;
	if(size[y]>=k) return find(c[x][0],k);
	else return find(c[x][1],k-size[y]-1);
}
void build(int last,int l,int r){
	if(l>r) return;
	int mid=(l+r)>>1;
	fa[mid]=last;size[mid]=1;
	if(mid<last) c[last][0]=mid;
	else c[last][1]=mid;
	build(mid,l,mid-1);
	build(mid,mid+1,r);
	update(mid);
}
void add(int l,int r,int v){
	int x=find(root,l);
	splay(root,x);
	x=find(root,r+2);
	splay(c[root][1],x);
	x=c[c[root][1]][0];
	if(x){
		tag[x]+=v;num[x]+=v;tmax[x]+=v;
	}
}
void reverse(int l,int r){
	int x=find(root,l);
	splay(root,x);
	x=find(root,r+2);
	splay(c[root][1],x);
	x=c[c[root][1]][0];
	if(x) rev[x]^=1;
}
int getmax(int l,int r){
	int x=find(root,l);
	splay(root,x);
	x=find(root,r+2);
	splay(c[root][1],x);
	x=c[c[root][1]][0];
	return tmax[x];
}
void solve(){
	int i,k,l,r,v;
	num[0]=tmax[0]=-1e9;
	scanf("%d%d",&n,&m);
	n+=2;
	root=(n>>1);
	build(0,1,n);		
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&k,&l,&r);
		if(k==1){
			scanf("%d",&v);
			add(l,r,v);
		}else		
		if(k==2){
			reverse(l,r);
		}
		else{
			printf("%d\n",getmax(l,r));
		}
	}
}
int main(){
	solve();
	return 0;
}

