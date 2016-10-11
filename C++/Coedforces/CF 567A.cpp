#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
int n,x[100001],mind[100001],maxd[100001];
using namespace std;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=n;i++){
		if(i==1) mind[i]=x[i+1]-x[i];else 
		if(i==n) mind[i]=x[i]-x[i-1];
		else mind[i]=min(x[i]-x[i-1],x[i+1]-x[i]);
		maxd[i]=max(x[n]-x[i],x[i]-x[1]);
	}
	for(int i=1;i<=n;i++) printf("%d %d\n",mind[i],maxd[i]);
	return 0;
}

