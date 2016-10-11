#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100001
using namespace std;
int n,m,tt,belong[N],size[N],pl[N],ft[N],sd[N],fa[N][18];
int sz,to[N],pre[N],last[N];
int tsum[N<<2];//统计有多少个1 
bool tag[N<<2];
void Ins(int a,int b){
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void init(){
    int i,p;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        scanf("%d",&p);p++;
        Ins(p,i);
    }
}
void Dfs_work(int x){
    for(int i=1;i<=17;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=last[x];i;i=pre[i]){
        fa[to[i]][0]=x;
        Dfs_work(to[i]);
        size[x]+=size[to[i]];
    }
    size[x]++;
}
void Dfs_getchain(int x,int chain){
    int i,k=0;
    pl[x]=++tt;ft[x]=tt;sd[x]=tt;belong[x]=chain;
    for(i=last[x];i;i=pre[i]){
        if(size[to[i]]>size[k]) k=to[i];
    }
    if(k==0) return;
    Dfs_getchain(k,chain);
    for(i=last[x];i;i=pre[i]){
        if(to[i]==k) continue;
        Dfs_getchain(to[i],to[i]);
    }
    sd[x]=tt;
}
void downpush(int k,int l,int r){
    if(tsum[k]==0){
        tsum[k<<1]=0;tsum[k<<1|1]=0;
    }
    else{
        int mid=(l+r)>>1;
        tsum[k<<1]=mid-l+1;tsum[k<<1|1]=r-mid;
    } 
    tag[k<<1]=1;tag[k<<1|1]=1;tag[k]=0;
}
int ask(int k,int l,int r,int a,int b,int x){
    if(l>b || r<a) return 0;
    if(l>=a && r<=b){
        if(x==1) return tsum[k];
        else return r-l+1-tsum[k];
    }
    if(tag[k]) downpush(k,l,r);
    int mid=(l+r)>>1;
    return ask(k<<1,l,mid,a,b,x)+ask(k<<1|1,mid+1,r,a,b,x);
}
void update(int k,int l,int r,int a,int b,int x){
    if(l>=a && r<=b){
        if(x==1) tsum[k]=r-l+1;
        else tsum[k]=0;
        tag[k]=1;return;
    }
    if(tag[k]) downpush(k,l,r);
    int mid=(l+r)>>1;
    if(a<=mid) update(k<<1,l,mid,a,b,x);
    if(b>mid) update(k<<1|1,mid+1,r,a,b,x);
    tsum[k]=tsum[k<<1]+tsum[k<<1|1];
}
int solve_install(int x){
    int f=1,l,r,res=0;
    while(belong[x]!=belong[f]){
        l=pl[belong[x]];r=pl[x];
        res+=ask(1,1,n,l,r,0);
        update(1,1,n,l,r,1);
        x=fa[belong[x]][0];
    }
    l=pl[f];r=pl[x];
    res+=ask(1,1,n,l,r,0);
    update(1,1,n,l,r,1);
    return res;
}
int solve_uninstall(int x){
    int l=ft[x],r=sd[x],res;
    res=ask(1,1,n,l,r,1);
    update(1,1,n,l,r,0);
    return res;
}
void solve(){
    int i,x;char s[10];
    Dfs_work(1);
    Dfs_getchain(1,1);
    scanf("%d",&m);    
    for(i=1;i<=m;i++){
        scanf("%s%d",s,&x);
        if(s[0]=='i'){
            printf("%d\n",solve_install(x+1));
        }
        else{
            printf("%d\n",solve_uninstall(x+1));
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}
