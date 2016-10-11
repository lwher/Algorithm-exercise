/*
	点分治算法 POJ 1741
	该模板支持询问树上所有权值和小于等于给定K的路径总数
	时间复杂度:O(nlogn) 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 40001
using namespace std;
int n,K,root,top,ans,sum,size[N],fmax[N],dis[N],D[N];
int sz,to[N<<1],pre[N<<1],v[N<<1],last[N];
bool mark[N];
void Ins(int a,int b,int c){
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void init(){
    int i,a,b,c;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        Ins(a,b,c);Ins(b,a,c);
    }
    scanf("%d",&K);
}
void findroot(int x,int fa){
    size[x]=1;fmax[x]=0;
    for(int i=last[x];i;i=pre[i]){
        if(to[i]==fa || mark[to[i]]) continue;
        findroot(to[i],x);
        fmax[x]=max(fmax[x],size[to[i]]);
        size[x]+=size[to[i]];
    }
    fmax[x]=max(fmax[x],sum-size[x]);
    if(fmax[x]<fmax[root]) root=x;
}
void Dfs(int x,int fa){
    D[++top]=dis[x];size[x]=1;
    for(int i=last[x];i;i=pre[i]){
        if(to[i]==fa || mark[to[i]]) continue;
        dis[to[i]]=dis[x]+v[i];
        Dfs(to[i],x);
        size[x]+=size[to[i]];
    }
}
int calc(int x,int V){
    int res=0;dis[x]=V;top=0;
    Dfs(x,0);
    sort(D+1,D+1+top);
    for(int l=0,r=top;r;r--){
        while(D[l+1]+D[r]<=K && l<r) l++;
        if(l>=r) res+=r-1; else res+=l;
    }
    return res;
}
void work(int x){
    ans+=calc(x,0);
    mark[x]=1;
    for(int i=last[x];i;i=pre[i]){
        if(mark[to[i]]) continue;
        ans-=calc(to[i],v[i]);
        sum=size[to[i]];
        fmax[0]=sum;root=0;
        findroot(to[i],0);
        work(root);
    }
}
void solve(){
    sum=n;fmax[0]=n;root=0;
    findroot(1,0);
    work(root);
    printf("%d\n",ans);
}
int main(){
    init();
    solve();
    system("pause");
    return 0;
}
