/*
	边双连通分量 POJ 3352
	边双连通分量求法:
	dfn[x]表示搜索到x的时间戳，low[x]表示以x为根的搜索子树能联系到的时间戳最小的
	点，在搜索过程中把点压入栈中。
	如果low[x]>dfn[fa]，那么说明x连向父亲的边是桥，那么栈中到x为止的点构成一个边
	双连通分量，把它们全部弹出来。
	最后还剩下包含根节点的分量，这又是一个新的分量。 
*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 5001
#define M 20001
using namespace std;
int n,m,ans,tt,top,fl=1;
int sz,to[M],pre[M],last[N];
int dfn[N],low[N],stack[N],belong[N],du[N];
bool mark[N];
void Ins(int a,int b){
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void Tarjan(int x,int from){
	dfn[x]=++tt;low[x]=tt;stack[++top]=x;
	for(int i=last[x];i;i=pre[i]){
		if(to[i]==from) continue;
		if(!dfn[to[i]]){
			Tarjan(to[i],x);low[x]=min(low[x],low[to[i]]);
			if(low[to[i]]>dfn[x]){
				fl++;
				while(stack[top]!=to[i]) belong[stack[top--]]=fl;
				belong[stack[top--]]=fl;
			}
		}
		else low[x]=min(low[x],dfn[to[i]]);
	}
}
int main(){
	int i,j,k,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		Ins(a,b);Ins(b,a);
	}
	Tarjan(1,0);
	for(i=1;i<=n;i++) if(belong[i]==0) belong[i]=1;
	for(i=1;i<=fl;i++){
		memset(mark,0,sizeof(mark));
		for(j=1;j<=n;j++) if(belong[j]==i){
			for(k=last[j];k;k=pre[k]){
				if(!mark[belong[to[k]]] && belong[to[k]]!=i){
					mark[belong[to[k]]]=1;du[i]++;
				}
			}
		}
	}
	for(i=1;i<=fl;i++) if(du[i]==1) ans++;
	ans=(ans+1)/2;
	printf("%d\n",ans);
	return 0;
}

