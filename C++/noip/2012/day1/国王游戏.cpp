#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct HPC{
	int num[2001];
}now,ans;
struct sth{
	int l,r;
}p[1001];
int n,gl,gr;
inline bool comp(sth a,sth b){
	return a.l*a.r<b.l*b.r;
}
HPC operator *(const HPC &a,int b){
	HPC ans;int &len=ans.num[0];
	memset(ans.num,0,sizeof(ans.num));
	for(int i=1;i<a.num[0];i++){
		ans.num[i]+=a.num[i]*b;ans.num[i+1]+=ans.num[i]/10000;ans.num[i]%=10000;
	}
	len=a.num[0];ans.num[len]+=a.num[len]*b;
	for(;ans.num[len]>=10000;len++){
		ans.num[len+1]+=ans.num[len]/10000;ans.num[len]%=10000;
	}
	return ans;
}
HPC operator /(const HPC &a,int b){
	HPC ans;int &len=ans.num[0];
	memset(ans.num,0,sizeof(ans.num));
	for(int i=a.num[0];i>1;i--){
		ans.num[i-1]+=(ans.num[i]+a.num[i])%b*10000;ans.num[i]=(ans.num[i]+a.num[i])/b;
	}
	ans.num[1]=(ans.num[1]+a.num[1])/b;
	for(len=a.num[0];!ans.num[len];len--);
	return ans;
}
bool operator >(const HPC &a,const HPC &b){
	if(a.num[0]>b.num[0]) return 1;
	if(a.num[0]<b.num[0]) return 0;
	for(int i=a.num[0];i;i--){
		if(a.num[i]>b.num[i]) return 1;
	}
	return 0;
}
void print(const HPC &A){
	printf("%d",A.num[A.num[0]]);
	for(int i=A.num[0]-1;i;i--) printf("%.4d",A.num[i]);
	printf("\n");
}
void init(){
	scanf("%d",&n);
	scanf("%d%d",&gl,&gr);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].l,&p[i].r);
	}
	sort(p+1,p+1+n,comp);
}
void solve(){	
	now.num[0]=1;now.num[1]=gl;
	ans.num[0]=1;ans.num[1]=0;
	for(int i=1;i<=n;i++){
		HPC k=now/p[i].r;
		if(k>ans) ans=k;
		now=now*p[i].l;
	}
	print(ans);
}
int main(){
	init();
	solve();
	return 0;
}