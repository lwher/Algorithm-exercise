#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100001
using namespace std;
struct node{
	long long W,deep;
};
int n,K;
long long Anssum,Ansdeep,w[N];
bool operator <(const node &a,const node &b){
	if(a.W==b.W) return a.deep>b.deep;
	return a.W>b.W;
}
priority_queue<node> Q;
int main(){
	node p,q;
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++){
		scanf("%lld",&w[i]);
		p.W=w[i];p.deep=0;
		Q.push(p);
	}	
	p.W=0;p.deep=0;
	if((n-1)%(K-1)) for(int i=1;i<=K-1-(n-1)%(K-1);i++) Q.push(p);	
	while(!Q.empty()){
		p=Q.top();Q.pop();
		if(Q.empty()){
			Ansdeep=p.deep;break;
		}
		for(int i=1;i<K;i++){
			q=Q.top();Q.pop();
			p.W+=q.W;
			p.deep=max(p.deep,q.deep);
		}
		Anssum+=p.W;p.deep++;
		Q.push(p);
	}
	cout<<Anssum<<endl<<Ansdeep<<endl;
	return 0;
}

