#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 100010
#define M 10000010
using namespace std;
struct sth{
    int w,p,type;
}event[N<<1];
int n,m,esz,root[N];
int tot,top,num[N],shu[N];
int A[N],B[N],C[N];
int sz,ls[M],rs[M],gsum[M];
long long tsum[M];
inline bool comp(const sth &a,const sth &b){
    return a.w<b.w;
}
void Insert(int x,int &y,int p,int ty,int l,int r){
    y=++sz;
    gsum[y]=gsum[x]+ty;
    tsum[y]=tsum[x]+ty*num[p];
    if(l==r) return;
    ls[y]=ls[x];rs[y]=rs[x];
    int mid=(l+r)>>1;
    if(p<=mid) Insert(ls[x],ls[y],p,ty,l,mid);
    else Insert(rs[x],rs[y],p,ty,mid+1,r);
}
long long query(int x,int k){
    int l=1,r=tot,mid;
    long long res=0;
    x=root[x];
    if(k>=gsum[x]) return tsum[x];
    while(l!=r){
        mid=(l+r)>>1;
        if(k>=gsum[ls[x]]){
            res+=tsum[ls[x]];
            k-=gsum[ls[x]];
            x=rs[x];
            l=mid+1;
        } 
        else x=ls[x],r=mid;
    }
    res+=(long long)(num[l])*k;
    return res;
}
int find(int x){
    int l=1,r=tot,mid;
    while(l+1<r){
        mid=(l+r)>>1;
        if(num[mid]>=x) r=mid;
        else l=mid;
    }
    if(num[r]==x) return r;
    else return l;
}
void init(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&A[i],&B[i],&C[i]);
        shu[++top]=C[i];
    }
    sort(shu+1,shu+1+top);
    num[++tot]=shu[1];
    for(int i=2;i<=top;i++) if(shu[i]!=shu[i-1]) num[++tot]=shu[i];
    for(int i=1;i<=m;i++){
        event[++esz].w=A[i];
        event[esz].p=find(C[i]);
        event[esz].type=1;
        event[++esz].w=B[i]+1;
        event[esz].p=find(C[i]);
        event[esz].type=-1;
    }
}
void solve(){
    sort(event+1,event+1+esz,comp);
    int i,x,k=1,a,b,c;
    for(i=1;i<=n;i++){
        root[i]=root[i-1];
        while(k<=esz && event[k].w==i){
            Insert(root[i],root[i],event[k].p,event[k].type,1,tot);
            k++;
        }
    }        
    long long ans,pre=1;        
    for(i=1;i<=n;i++){
        scanf("%d%d%d%d",&x,&a,&b,&c);
        pre%=c;
        k=(pre*a+b)%c+1;
        ans=query(x,k);
        printf("%lld\n",ans);
        pre=ans;
    }
}
int main(){
    init();
    solve();
    return 0;
}
