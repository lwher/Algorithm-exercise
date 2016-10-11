#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 200010
using namespace std;
int sz,n,root,l[N],r[N],num[N],W[N],rnd[N];
void rturn(int &t){
     int k=l[t];
     l[t]=r[k];r[k]=t;
     t=k;
}
void lturn(int &t){
     int k=r[t];
     r[t]=l[k];l[k]=t;
     t=k;
}
void Insert(int &w,int x){
     if(!w){
            w=++sz;
            num[w]=x;
            W[w]=1;
            rnd[w]=rand();
            return;
     }
     if(num[w]==x){
                   W[w]++;
                   return;
     }
     if(num[w]>x){
                  Insert(l[w],x);
                  if(rnd[l[w]]<rnd[w]) rturn(w);
     }
     else{
          Insert(r[w],x);
          if(rnd[r[w]]<rnd[w]) lturn(w);
     }
}
void print(int x){
     if(!x) return;
     print(l[x]);
     printf("%d %d\n",num[x],W[x]);
     print(r[x]);
}
void solve(){
     int i,x;
     scanf("%d",&n);
     for(i=1;i<=n;i++){
                       scanf("%d",&x);
                       Insert(root,x);
     }
     print(root);
}
int main(){
    solve();
    system("pause");
    return 0;
}
