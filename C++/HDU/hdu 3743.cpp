#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define N 1000001
using namespace std;
int n,tot,num[N],A[N],t[N];
inline int lowbit(int x){
    return x & -x;
}
void add(int x,int p){
    for(int i=x;i<=tot;i+=lowbit(i)) t[i]+=p; 
}
int ask(int x){
    int res=0;
    for(int i=x;i>0;i-=lowbit(i)) res+=t[i];
    return res;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&A[i]);num[i]=A[i];
        }
        sort(num+1,num+1+n);
        tot=unique(num+1,num+1+n)-num-1;
        for(int i=1;i<=n;i++) A[i]=lower_bound(num+1,num+1+n,A[i])-num;        
        memset(t,0,sizeof(t));
        long long ans=0;
        for(int i=n;i>0;i--){
            ans+=ask(A[i]-1);
            add(A[i],1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
