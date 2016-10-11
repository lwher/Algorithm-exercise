#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 10010
#define M 200010
using namespace std;
int n,m,s,t;
int sz,to[M],pre[M],last[N];
int SZ,TO[M],PRE[M],LAST[N];//·´ÏòÍ¼
int dui[N],d[N];
bool mark[N],OK[N];
void Insz(int a,int b){
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void Insf(int a,int b){
	SZ++;TO[SZ]=b;PRE[SZ]=LAST[a];LAST[a]=SZ;
}
void init(){
	int i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		Insz(a,b);
		Insf(b,a);
	}
	scanf("%d%d",&s,&t);
}
void bfsT(){
	int tou=1,wei=1,now,i,j;
	dui[1]=t;mark[t]=1;
	while(tou<=wei){
		now=dui[tou];tou++;
		for(i=LAST[now];i;i=PRE[i]){
			if(!mark[TO[i]]){
				mark[TO[i]]=1;
				dui[++wei]=TO[i];
			}
		}
	}
	for(i=1;i<=n;i++) {
		for(j=last[i];j;j=pre[j]){
			if(!mark[to[j]]){
				OK[i]=1;
				break;
			}
		}
	}
}
void bfsS(){
	int tou=1,wei=1,now,i;
	for(i=1;i<=n;i++) d[i]=(1<<20);
	if(OK[s]) return;
	dui[1]=s;d[s]=0;
	while(tou<=wei){
		now=dui[tou];tou++;
		for(i=last[now];i;i=pre[i]){
			if(!OK[to[i]] && d[now]+1<d[to[i]]){
				d[to[i]]=d[now]+1;
				dui[++wei]=to[i];
			}
		}
	}
}
void solve(){
	bfsT();
	bfsS();
	if(d[t]<(1<<20)) printf("%d\n",d[t]);
	else printf("-1\n");
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	solve();
	return 0;
}
