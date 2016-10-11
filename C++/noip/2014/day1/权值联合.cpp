#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 200010
using namespace std;
int n,sz=0,w[N],maxw=0;
int to[N<<1],pre[N<<1],last[N];
unsigned long long sum=0;
void Insert(int a,int b){
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void init(){
	int i,a,b;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		Insert(a,b);
		Insert(b,a);
	}
	for(i=1;i<=n;i++) scanf("%d",&w[i]); 
}
void checkmax(int &a,int &b,int c){
	if(c>=a) b=a,a=c; else
	if(c>b)  b=c; 
}
void solve(){
	int i,j,k;
	long long nsum;
	int max1,max2;		
	for(i=1;i<=n;i++){
		nsum=0;max1=0;max2=0;
		j=last[i];k=to[j];
		max1=w[k];
		nsum+=w[k];
		for(j=pre[j];j;j=pre[j]){
			k=to[j];
			checkmax(max1,max2,w[k]);
			sum+=nsum*w[k];
			nsum+=w[k];
		}
		if(max1*max2>maxw) maxw=max1*max2;
    }
    sum=sum<<1;
    cout<<maxw<<" "<<sum%10007<<endl;
}
int main(){
	freopen("link.in","r",stdin);
	freopen("link.out","w",stdout);
	init();
	solve();
	return 0;
}
