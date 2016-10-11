#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define N 2000010
using namespace std;
int n,sz,tot,ft[N],rj[N],ro[N],sum[N],size[N],trans[N][26];
char A[N],s[N];
long long ans;
void init(){
    int len;
    scanf("%d",&n); 
    A[0]='#';   
    for(int i=1;i<=n;i++){
        scanf("%d%s",&len,s+1);
        ft[i]=tot+1;
        for(int j=1;j<=len;j++) A[++tot]=s[j];
    }
    A[tot+1]='@';ft[n+1]=tot+1;
}
void Manacher(){
    int i,p,r,k;
    p=0;r=0;
    for(i=1;i<=tot;i++){
        if(p+r>i) k=min(rj[p*2-i],p+r-i); 
        else k=1;
        while(A[i-k]==A[i+k]) k++;
        rj[i]=k;
        if(i+k>p+r) p=i,r=k;
    }
    p=0;r=0;
    for(i=1;i<tot;i++){
        if(p+r>i) k=min(ro[p*2-i],p+r-i);
        else k=0;
        while(A[i-k]==A[i+k+1]) k++;
        ro[i]=k;
        if(i+k>p+r) p=i,r=k;
    }
}
bool check(int id,int k,int i){//第id个串去掉头i个，剩下长度为k是否是回文串 
     if(!k || k==1) return 1;
     else{
         int x=(k>>1);
         if(k & 1){
             if(rj[ft[id]+i+x]>x) return 1;
         }
         else{
             if(ro[ft[id]+i+x-1]>=x) return 1;  
         }
     }
     return 0;
}
void trie_add(int id){
    int p=0,k,x,L=ft[id+1];
    for(int i=ft[id];i<L;i++){
        k=A[i]-'a';
        if(!trans[p][k]) trans[p][k]=++sz;
        p=trans[p][k];
        k=L-i-1;
        if(check(id,k,i-ft[id]+1)) sum[p]++;
    }
    size[p]++;
}
void solve(){
    Manacher();
    for(int i=1;i<=n;i++) trie_add(i);            
    for(int i=1;i<=n;i++){
        int p=0,k,L=ft[i+1];
        for(int j=L-1;j>=ft[i];j--){
             k=A[j]-'a';p=trans[p][k];
             if(!p) break;
             if(j>ft[i] && check(i,j-ft[i],0)) ans+=size[p];
        }
        if(p) ans+=sum[p];
    }
    cout<<ans<<endl;
}
int main(){
    //cout<<(sizeof(trans)>>20)+(sizeof(ft)>>20)*7<<endl;
    init();
    solve();
    return 0;
}
