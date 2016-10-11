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
struct node{
	int v;
	node(int p=0){
		v=p;
	}
	bool operator <(const node &b) const{
		return v>b.v;
	}
};
int n,ans;
priority_queue<node> q;
int main(){
	int num;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		q.push(node(num));
	}
	node A,B;
	for(int i=1;i<n;i++){
		A=q.top();q.pop();
		B=q.top();q.pop();
		ans+=A.v+B.v;
		q.push(node(A.v+B.v));
	}
	cout<<ans<<endl;
	return 0;
}

