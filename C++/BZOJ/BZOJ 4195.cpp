#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 200001
using namespace std;
struct sth{
	int opt,A,B;
}p[N];
int n,T,top,tot,shu[N],num[N],fa[N];
bool comp(const sth &a,const sth &b){
	return a.opt>b.opt;
}
int getfa(int x){
	if(fa[x]==0) return x;
	return fa[x]=getfa(fa[x]);
}
int find(int x){
	int l=1,r=tot,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		if(num[mid]==x) return mid;
		if(num[mid]>x) r=mid;
		else l=mid; 
	}
	if(num[r]==x) return r;
	else return l;
}
void init(){
	top=tot=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&p[i].A,&p[i].B,&p[i].opt);
		shu[++top]=p[i].A;shu[++top]=p[i].B;
	}
	sort(shu+1,shu+1+top);
	num[++tot]=shu[1];
	for(int i=2;i<=top;i++) if(shu[i]!=shu[i-1]) num[++tot]=shu[i];
	for(int i=1;i<=n;i++){
		p[i].A=find(p[i].A);
		p[i].B=find(p[i].B);
	}
	sort(p+1,p+1+n,comp);
}
void solve(){
	memset(fa,0,sizeof(fa));
	int i,x,y;
	for(i=1;i<=n;i++){
		if(p[i].opt){
			x=getfa(p[i].A);y=getfa(p[i].B);
			if(x!=y) fa[x]=y;
		}
		else{
			x=getfa(p[i].A);y=getfa(p[i].B);
			if(x==y){
				printf("NO\n");return;
			}
		}
	}
	printf("YES\n");
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		solve();
	}
	return 0;
}

