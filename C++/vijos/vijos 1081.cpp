#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 100010
#define M 2000010
using namespace std;
int n,m,tot,num[N],shu[N],A[N];
int sz,root[N],ls[M],rs[M],sum[M];
int find(int x){
     int l=1,r=tot,mid;
     while(l+1<r){
                  mid=(l+r)>>1;
                  if(num[mid]==x) return mid;
                  if(num[mid]>x) r=mid;
                  else l=mid;
     }
     if(num[l]==x) return l;
     else return r;
}
void init(){
     scanf("%d%d",&n,&m);
     for(int i=1;i<=n;i++){
             scanf("%d",&shu[i]);
             A[i]=shu[i];
     }
     sort(shu+1,shu+1+n);
     num[++tot]=shu[1];
     for(int i=2;i<=n;i++) if(shu[i]!=shu[i-1]) num[++tot]=shu[i];
     for(int i=1;i<=n;i++) A[i]=find(A[i]);
}
void Insert(int k,int &x,int y,int l,int r){
     x=++sz;
     sum[x]=sum[y]+1;
     ls[x]=ls[y];rs[x]=rs[y];
     if(l==r) return;
     int mid=(l+r)>>1;
     if(k<=mid) Insert(k,ls[x],ls[y],l,mid);
     else Insert(k,rs[x],rs[y],mid+1,r);
}
void solveask(int zuo,int you,int k){
     int mid,L=root[zuo-1],R=root[you],l=1,r=tot;
     while(l!=r){
             mid=(l+r)>>1;
             if(sum[ls[R]]-sum[ls[L]]>=k){
                                          r=mid;
                                          L=ls[L];
                                          R=ls[R];
             }
             else{
                  k-=(sum[ls[R]]-sum[ls[L]]);
                  l=mid+1;
                  L=rs[L];
                  R=rs[R];
             }
     }
     printf("%d\n",num[l]);
}
void solve(){
     int i,l,r,k;
     for(i=1;i<=n;i++) Insert(A[i],root[i],root[i-1],1,tot);     
     for(i=1;i<=m;i++){
             scanf("%d%d%d",&l,&r,&k);
             solveask(l,r,k);
     }
}
int main(){
    init();    
    solve();
    system("pause");
    return 0;
}
