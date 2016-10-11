#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define mod 1000000007
#define N 200001
long long f[200010],nf[200010];

using namespace std;
long long qpow(int a, int b){
    long long c, d; c = 1; d = a;
    while (b > 0){
        if (b & 1) c = c * d % mod;
        b = b >> 1;
        d = (d * d) % mod;
    }
    return c;
}

void init(){
    f[0]=nf[0]=1;
    for(int i=1;i<N;++i){
        f[i]=1LL*f[i-1]*i%mod;
        nf[i]=qpow(f[i], mod-2);
    }
}

int C(int x,int y){
    return 1LL*f[x]*nf[y]%mod*nf[x-y]%mod;
}

int main(){
    init();
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        printf("%d\n",C(n+m-4,n-2));
    }
    return 0;
}
