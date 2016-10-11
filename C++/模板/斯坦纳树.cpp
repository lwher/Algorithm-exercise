/*
	斯坦纳树  时间复杂度O(3 ^ K * n) HDU 4085
	问题：给出n个点，m条边，每条边有一个权值，表示修复这条边需要的代价
	从前k个点中任取一个使其和后k个点中的某一个点，通过边连接，并且必须是一一对应，问最小的代价是多少
	
	设dp[i][j]表示2*K个点状态压缩后的状态 i下，包含 j号点的最优值
	dp[i][j] = min{dp[k][j]+dp[l][j]} k,l合并可构成i,并且k,l均包含j
	dp[i][j] = min{dp[i'][j']+w[j'][j]} 从j'点伸到j来的，直接转移
	以上两个取min，就是dp[i][j]了
	
	下面考虑转移，我们发现不同层的状态（第一维）是拓扑关系，因此我们对于第二个转移通过spfa迭代就行了，注意只有同层才进队再次松弛
	每层一开始的初始值则是通过第一个转移从低的层得到
	
	这题的答案可能是一片森林，所以求出dp以后，还得再一次状压DP，并且只有包含前K个点的数量和后K个点相同才是合法的状态 
*/
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 51
#define M 2001
#define INF 1e9
using namespace std;
struct sth{
	int p,s;//p:处于点的位置 s:状态压缩 
}Q[M<<1];
int n,m,K,SZ,st[N],f[1<<10],dp[1<<10][N];
int sz,to[M],v[M],pre[M],last[N];
bool mark[1<<10][N];
void Ins(int a,int b,int c){
	sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
bool check(int x){
	int i,num=0;
	for(i=1;i<=K;i++){
		if(x & st[i]) num++;
		if(x & st[n-K+i]) num--;
	}
	return num==0;
}
void init(){
	int i,j,a,b,c;
	memset(st,0,sizeof(st));
	memset(last,0,sizeof(last));
	scanf("%d%d%d",&n,&m,&K);
	SZ=(1<<(K*2));sz=0;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		Ins(a,b,c);Ins(b,a,c);
	}
	for(i=0;i<SZ;i++) for(j=1;j<=n;j++) dp[i][j]=INF;
	for(i=1;i<=K;i++){
		st[i]=(1<<(i-1));st[n-K+i]=(1<<(K+i-1));
		dp[st[i]][i]=0;dp[st[n-K+i]][n-K+i]=0;
	}
}
void Spfa(int t,int w){
	int i,ns,np,ts;
	while(t<=w){
		ns=Q[t].s;np=Q[t].p;
		t++;mark[ns][np]=0;
		for(i=last[np];i;i=pre[i]){
			ts=(ns|st[to[i]]);
			if(dp[ts][to[i]]>dp[ns][np]+v[i]){
				dp[ts][to[i]]=dp[ns][np]+v[i];
				if(ts==ns){
					Q[++w].s=ts;Q[w].p=to[i];mark[ts][to[i]]=1;
				}
			}
		}
	}
}
void DP(){
	int i,j,k,t,w;
	for(i=0;i<SZ;i++){
		t=1;w=0;
		for(j=1;j<=n;j++){
			if(st[j] && !(i & st[j])) continue;
			for(k=(i-1)&i;k;k=(k-1)&i) dp[i][j]=min(dp[i][j],dp[k|st[j]][j]+dp[(i^k)|st[j]][j]);
			if(dp[i][j]<INF){
				Q[++w].s=i;Q[w].p=j;mark[i][j]=1;
			}
		}
		Spfa(t,w);
	}	
	for(i=0;i<SZ;i++){
		f[i]=INF;
		if(!check(i)) continue;
		for(j=1;j<=n;j++) f[i]=min(f[i],dp[i][j]);
	}	
	for(i=1;i<SZ;i++){
		if(!check(i)) continue;
		for(k=(i-1)&i;k;k=(k-1)&i) f[i]=min(f[i],f[k]+f[i^k]);
	}
	if(f[SZ-1]>=INF) printf("No solution\n");
    else printf("%d\n",f[SZ-1]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		DP();
	}
	return 0;
}

