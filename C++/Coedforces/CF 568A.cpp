#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ans,rub[3000001],phi[3000001];
int tot,prime[3000001];
bool mark[3000001];
bool check(int x){
    int y=x,top=0,num[20];
    while(y>0){
        num[++top]=y%10;y/=10;
    }
    y=0;
    for(int i=1;i<=top;i++) y=y*10+num[i];
    if(x==y) return 1;
    else return 0;
}
void getprime(){
    int i,j;
    for(i=2;i<=n;i++){
        if(!mark[i]){
            phi[i]++;prime[++tot]=i;
        }
        for(j=1;j<=tot;j++){
            if(prime[j]*i>n) break;
            mark[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
    for(i=1;i<=n;i++) phi[i]+=phi[i-1];
}
int main(){
    n=3000000;
    for(int i=1;i<=n;i++) if(check(i)) rub[i]++;
    for(int i=1;i<=n;i++) rub[i]+=rub[i-1];
    getprime();
    long long p,q;
    cin>>p>>q;
    for(int i=1;i<=n;i++){
        if(q*phi[i]<=p*rub[i]) ans=i;
    }
    if(ans) printf("%d\n",ans);
    else cout<<"Palindromic tree is better than splay tree"<<endl;
    return 0;
}
