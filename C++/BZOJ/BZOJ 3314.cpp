#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 50010
#define lowbit(x)(((~(x))+1)&x)
#define inf 0x7fffffff
struct Bit{
    int I[MAXN],N;
    Bit (){
        memset(I,0,sizeof(I));
    }
    void Init(int _N){
        N=_N;
    }
    int Sum_(int x){
        int rec=0;
        for(;x;x-=lowbit(x)) rec+=I[x];
        return rec;
    }
    int Sum(int l,int r){
        return Sum_(r)-Sum_(l-1);
    }
    void Add(int x,int y){
        for(int i=x;i<=N;i+=lowbit(i)) I[i]+=y;
    }
} L,R;
int H[MAXN],X[MAXN],n,d,rh[MAXN],rx[MAXN],nh=0,nx=0,ans=0;
struct saver{
    int v,t;
} b[MAXN],c[MAXN];
bool Cmp(saver x,saver y){
    return x.v<y.v;
}
int Search(int k){
    if(k>c[n].v)return nh+1;
    if(c[1].v>=k)return 1;
    int l=1,r=n;
    while(r-l>1){
        int mid=(l+r)>>1;
        if(c[mid].v==k)return rh[c[mid].t];
        if(c[mid].v<k) l=mid;else r=mid;
    }
    return rh[c[r].t];
}
int main(){
    scanf("%d%d",&n,&d);
    for(int i=0;i++<n;){
        scanf("%d%d",&X[i],&H[i]);
        b[i].v=X[i],b[i].t=c[i].t=i,c[i].v=H[i];
    }
    sort(b+1,b+n+1,Cmp),sort(c+1,c+n+1,Cmp);
    b[0].v=c[0].v=-1;
    b[n+1].v=inf;
    for(int i=0;i++<n;){
        if(b[i].v!=b[i-1].v) nx++;
        if(c[i].v!=c[i-1].v) nh++;
        rx[b[i].t]=nx,rh[c[i].t]=nh;
    }
    L.Init(nh),R.Init(nh);
    int l=1,r=1;
    for(;b[r].v-b[1].v<=d;r++) R.Add(rh[b[r].t],1);
    for(int i=0;i++<n;){
        L.Add(rh[b[i].t],1);
        for(;b[i].v-b[l].v>d;l++) L.Add(rh[b[l].t],-1);
        for(;b[r].v-b[i].v<=d;r++) R.Add(rh[b[r].t],1);
        ans+=(L.Sum(Search(H[b[i].t]*2),nh)&&R.Sum(Search(H[b[i].t]*2),nh))?1:0;
        R.Add(rh[b[i].t],-1);
    }
    printf("%d\n",ans);
   // system("pause");
    return 0;
}