//区间K大 可修改 离线做法 BZOJ 1901
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 10001
#define M 3500001
using namespace std;
int n,m,NUM[N],K[N],A[N],B[N],C[N];
int top,tot,shu[N<<1],num[N<<1];
int sz,ls[M],rs[M],sum[M],root[N];
inline int lowbit(int x){
	return x & (-x);
}
int find(int x){
	int l=1,r=tot,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		if(num[mid]==x) return mid;
		if(num[mid]>x) r=mid;
		else l=mid;
	}
	if(num[l]==x) return l;
	else return r;
}
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&NUM[i]);
		shu[++top]=NUM[i];
	}
	char s[1];
	for(int i=1;i<=m;i++){
		scanf("%s%d%d",s,&A[i],&B[i]);
		if(s[0]=='C'){
			shu[++top]=B[i];
		}
		else{
			K[i]=1;
			scanf("%d",&C[i]);
		}
	}
	sort(shu+1,shu+1+top);
	num[++tot]=shu[1];
	for(int i=2;i<=top;i++){
		if(shu[i]!=shu[i-1]) 
			num[++tot]=shu[i];
	}
}
void Insert(int &x,int l,int r,int p,int q){
	if(!x) x=++sz;
	sum[x]+=q;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(p<=mid) Insert(ls[x],l,mid,p,q);
	else Insert(rs[x],mid+1,r,p,q);
}
void modify(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i)) Insert(root[i],1,tot,NUM[x],-1);
	NUM[x]=y;
	for(int i=x;i<=n;i+=lowbit(i)) Insert(root[i],1,tot,y,1); 
}
int query(int left,int right,int k){
	int L[15],R[15],l=1,r=tot,mid,lssum;
	left--;L[0]=0;R[0]=0;
	for(int i=left;i;i-=lowbit(i)) L[++L[0]]=root[i];
	for(int i=right;i;i-=lowbit(i)) R[++R[0]]=root[i];
	while(l!=r){
		mid=(l+r)>>1;
		lssum=0;
		for(int i=1;i<=L[0];i++) lssum-=sum[ls[L[i]]];
		for(int i=1;i<=R[0];i++) lssum+=sum[ls[R[i]]];
		if(lssum>=k){
			for(int i=1;i<=L[0];i++) L[i]=ls[L[i]];
			for(int i=1;i<=R[0];i++) R[i]=ls[R[i]];
			r=mid;
		}
		else{
			for(int i=1;i<=L[0];i++) L[i]=rs[L[i]];
			for(int i=1;i<=R[0];i++) R[i]=rs[R[i]];
			k-=lssum;l=mid+1;
		}
	}
	return num[l];
}
void solve(){
	for(int i=1;i<=n;i++){
		NUM[i]=find(NUM[i]);
		for(int j=i;j<=n;j+=lowbit(j)) Insert(root[j],1,tot,NUM[i],1); 
	}	
	for(int i=1;i<=m;i++){
		if(K[i]){
			printf("%d\n",query(A[i],B[i],C[i]));
		}
		else{
			modify(A[i],find(B[i]));
		}
	}
}
int main(){	
	init();	
	solve();
	return 0;
}

