/*
	BZOJ 1036
	树链剖分，此模板支持三个功能:
	1、修改某个树上节点的权值
	2、查询两点间路径上的点权和
	3、查询两点间路径上的点权最大值
	修改:log(n) 查询 log(n)^2 
*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 30001
using namespace std;
int n,m,top,fa[N][16],w[N],pl[N],belong[N],size[N],deep[N];
//pl:每个点在线段树中的位置 belong:每个点属于以哪个点为开头的链 
int tmax[N<<2],tsum[N<<2];//线段树
int sz,to[N<<1],pre[N<<1],last[N];
void Ins(int a,int b){
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void init(){
    int i,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
}
void Dfs_work(int x){
    size[x]=1;
    for(int i=1;i<=15;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=last[x];i;i=pre[i]){
        if(fa[x][0]==to[i]) continue;
        fa[to[i]][0]=x;deep[to[i]]=deep[x]+1;
        Dfs_work(to[i]);
        size[x]+=size[to[i]];
    }
}
void Dfs_getchain(int x,int chain){
    int i,k=0;
    pl[x]=++top;belong[x]=chain;
    for(i=last[x];i;i=pre[i]){
        if(fa[x][0]==to[i]) continue;
        if(size[to[i]]>size[k]) k=to[i];
    }
    if(!k) return;
    Dfs_getchain(k,chain);
    for(i=last[x];i;i=pre[i]){
        if(fa[x][0]==to[i] || k==to[i]) continue;
        Dfs_getchain(to[i],to[i]);
    }
}
void modify(int k,int l,int r,int p,int x){
    if(l==r){
        tsum[k]=tmax[k]=x;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) modify(k<<1,l,mid,p,x);
    else modify(k<<1|1,mid+1,r,p,x);
    tsum[k]=tsum[k<<1]+tsum[k<<1|1];
    tmax[k]=max(tmax[k<<1],tmax[k<<1|1]);
}
int asksum(int k,int l,int r,int a,int b){
    if(l>b || r<a) return 0;
    if(l>=a && r<=b) return tsum[k];
    int mid=(l+r)>>1;
    return asksum(k<<1,l,mid,a,b)+asksum(k<<1|1,mid+1,r,a,b);
}
int askmax(int k,int l,int r,int a,int b){
    if(l>b || r<a) return -1e8;
    if(l>=a && r<=b) return tmax[k];
    int mid=(l+r)>>1;
    return max(askmax(k<<1,l,mid,a,b),askmax(k<<1|1,mid+1,r,a,b));
}
int LCA(int A,int B){//求出A,B的最近公共祖先 
    int i,k;
    if(deep[A]<deep[B]) swap(A,B);
    k=deep[A]-deep[B];
    for(i=15;i>=0;i--){
        if(k & (1<<i)) A=fa[A][i];
    }
    for(i=15;i>=0;i--){
        if(fa[A][i]!=fa[B][i]){
            A=fa[A][i];B=fa[B][i];
        }
    }
    if(A==B) return A;
    else return fa[A][0];
}
int solve_sum(int A,int C){//返回从A向上走到祖先C的路径节点权值总和
    int res=0;
    while(belong[A]!=belong[C]){
        res+=asksum(1,1,n,pl[belong[A]],pl[A]);
        A=fa[belong[A]][0];
    } 
    res+=asksum(1,1,n,pl[C],pl[A]);
    return res;
}
int solve_max(int A,int C){//返回从A向上走到祖先C的路径节点权值最大值 
    int res=-1e8;
    while(belong[A]!=belong[C]){
        res=max(res,askmax(1,1,n,pl[belong[A]],pl[A]));
        A=fa[belong[A]][0];
    } 
    res=max(res,askmax(1,1,n,pl[C],pl[A]));
    return res;
}
void solve(){
    int i,A,B,C;
    char s[8];
    deep[1]=1;
    Dfs_work(1);
    Dfs_getchain(1,1);  
    for(i=1;i<=n;i++) modify(1,1,n,pl[i],w[i]);
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%s%d%d",s,&A,&B);
        if(s[1]=='H'){
            modify(1,1,n,pl[A],B);
            w[A]=B;
        } else
        if(s[1]=='S'){
            C=LCA(A,B);
            printf("%d\n",solve_sum(A,C)+solve_sum(B,C)-w[C]);
        }
        else{
            C=LCA(A,B);
            printf("%d\n",max(solve_max(A,C),solve_max(B,C)));
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}
