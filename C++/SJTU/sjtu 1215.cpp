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
	int num;
	node(int x) : num(x) {}
	bool operator <(const node &b) const{
		return num > b.num;
	}
};

priority_queue<node> Q;
char op[10];
int T;

void solve(){
	cin >> T;
	for(int i = 1; i <= T; i++){
		scanf("%s", op);
		if(op[0] == 'i'){
			int x;
			scanf("%d", &x);
			Q.push(node(x));
		} else
		if(op[0] == 'd'){
			Q.pop();
		}
		else{
			node p = Q.top();
			printf("%d\n", p.num);
		}
	}
}

int main(){
	solve();
	return 0;
}

