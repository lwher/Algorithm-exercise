#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define N 300010
#define INF 1LL<<30
using namespace std;
int n,sz,last,w[N],step[N<<1],next[N<<1],trans[N<<1][26];
long long minw[N<<1],maxw[N<<1],maxans[N<<1],size[N<<1],sumans[N<<1],sum[N],maxx[N];
int topsort[N<<1],v[N];
char s[N];
void init(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
}
void SAM_Add(int id){
    int np=++sz,p=last;step[np]=step[p]+1;
    last=np;
    for(;p!=-1 && !trans[p][id];p=next[p]) trans[p][id]=np;
    if(p==-1) next[np]=0;
    else{
        int q=trans[p][id];
        if(step[q]==step[p]+1) next[np]=q;
        else{
            int nq=++sz;step[nq]=step[p]+1;
            next[nq]=next[q];next[q]=next[np]=nq;
            for(int i=0;i<26;i++) trans[nq][i]=trans[q][i];
            for(;p!=-1 && trans[p][id]==q;p=next[p]) trans[p][id]=nq;
        }
    }
}
void Add_suf(){
    int i,p=0,k;
    for(i=n;i>0;i--){
        k=s[i]-'a';
        for(;p!=-1 && !trans[p][k];p=next[p]);
        if(p==-1) p=0;
        else p=trans[p][k];
        minw[p]=w[i];maxw[p]=w[i];size[p]++;
    }
}
void solve(){
    next[0]=-1;
    for(int i=n;i>0;i--) SAM_Add(s[i]-'a');    
    for(int i=0;i<=sz;i++) v[step[i]]++;
    for(int i=1;i<=n;i++) v[i]+=v[i-1];
    for(int i=0;i<=sz;i++) topsort[v[step[i]]--]=i;
    for(int i=0;i<=sz;i++) minw[i]=INF,maxw[i]=-INF,maxans[i]=-((INF)*(INF)); 
    Add_suf();               
    for(int i=sz+1;i>1;i--){
        int p=topsort[i],pre=next[p];
        sumans[pre]+=size[pre]*size[p];
        size[pre]+=size[p];
        if(maxw[pre]!=-INF && maxw[p]!=-INF) maxans[pre]=max(maxans[pre],maxw[p]*maxw[pre]);
        if(minw[pre]!=INF && minw[p]!=INF) maxans[pre]=max(maxans[pre],minw[p]*minw[pre]);
        maxw[pre]=max(maxw[pre],maxw[p]);
        minw[pre]=min(minw[pre],minw[p]);
    }    
    for(int i=0;i<=n;i++) maxx[i]=-((INF)*(INF));        
    for(int i=0;i<=sz;i++){
        sum[step[i]]+=sumans[i];        
        maxx[step[i]]=max(maxx[step[i]],maxans[i]);
    }
    for(int i=n-1;i>=0;i--){
        sum[i]+=sum[i+1];
        maxx[i]=max(maxx[i],maxx[i+1]);
    }
}
void print(){
    for(int i=0;i<n;i++){
        if(sum[i]) printf("%lld %lld\n",sum[i],maxx[i]);
        else printf("0 0\n");
    }
}
int main(){
    init();
    solve();
    print();
    return 0;
}
