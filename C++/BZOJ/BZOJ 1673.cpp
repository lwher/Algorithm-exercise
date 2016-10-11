#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=1010;
int n;
long long w[N],sum[N],maxn,m;
void dfs(int x,long long cur){
    if(cur > m) return ;
    if(x <= 0){
        if(cur > maxn) maxn = cur;
        return ;
    }
    if(cur + sum[x] <= maxn)return ;
    if(cur > maxn) maxn = cur;
    dfs(x-1,cur+w[x]);
    dfs(x-1,cur);
}
int main(){
    int i,j,k;
    long long x;
    while(scanf("%d%lld",&n,&m)!=EOF){
        k=0;
        for(i = 1; i <= n; i++){
            scanf("%lld",&x);
            if(x <= m) w[++k]=x;
        }
        n = k;
        w[0] = 0; maxn = 0;
        for(i = 1; i <= n; i++) sum[i] = sum[i-1] + w[i];
        dfs(n,0);
        printf("%lld\n",maxn);
        //cout<<maxn<<endl;
    }
    return 0;
}

