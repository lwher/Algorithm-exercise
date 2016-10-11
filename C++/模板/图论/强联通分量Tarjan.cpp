//求出有向图的强联通分量  强联通分量：一个分量中的任意点都可以走到其他同分量的任何一个点上，即互相可达 
//vijos 1023
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,T,fl,top,dfn[201],low[201],stack[201];
bool in[201];
vector<int> to[201];
void init(){
	int i,p;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		while(scanf("%d",&p) && p)
			to[i].push_back(p);
	}
}
void Tarjan(int x){
	dfn[x]=++T;low[x]=T;
	stack[++top]=x;
	in[x]=1;
	for(int i=0;i<to[x].size();i++){
		if(!dfn[to[x][i]]){
			Tarjan(to[x][i]);
			low[x]=min(low[x],low[to[x][i]]);
		}
		else if(in[to[x][i]]) low[x]=min(low[x],dfn[to[x][i]]);
	}
	if(dfn[x]==low[x]){
		fl++;
		while(stack[top+1]!=x){
			in[stack[top]]=0;
			top--;
		}
	}
}
void solve(){
	for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);
	printf("%d",fl);
}
int main(){
	init();
	solve();
	return 0;
}
