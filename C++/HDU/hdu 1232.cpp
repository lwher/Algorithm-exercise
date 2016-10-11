#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1001
using namespace std;
int n,m,ans,fa[N],rk[N];
int getfa(int x){
    int t,p,id;
    for(p=x;fa[p]!=0;p=fa[p]);
    id=p;
    for(p=x;fa[p]!=0;p=t){
        t=fa[p];fa[p]=id;
    }
    return id;
}
int main(){
    int i,a,b,x,y;
    while(scanf("%d",&n)){
        if(n==0) break;
        memset(fa,0,sizeof(fa));
        memset(rk,0,sizeof(rk));
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            x=getfa(a);y=getfa(b);
            if(x==y) continue;
            if(rk[x]>=rk[y]){
                fa[y]=x;
                if(rk[x]==rk[y]) rk[y]++;
            }
            else fa[x]=y;
        }
        ans=-1;
        for(i=1;i<=n;i++){
            if(fa[i]==0) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
