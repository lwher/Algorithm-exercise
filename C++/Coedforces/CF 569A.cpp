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
int S,T,q,ans=1;
int main(){
    scanf("%d%d%d",&T,&S,&q);
    int now=0,have=S,nq=0;
    while(now<T){
        now++;nq++;
        if(nq!=q) have++;
        if(nq==q) nq=0;
        if(now==have && now!=T) ans++,now=0;
    }
    cout<<ans<<endl;
    return 0;
}
