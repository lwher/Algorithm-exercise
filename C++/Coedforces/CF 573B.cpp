#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,ans,h[100001],minl[100001],minr[100001];
int main(){
    int i,p;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&h[i]);
    p=1;minl[1]=1;
    for(i=2;i<=n;i++){
        minl[i]=min(minl[p]+i-p,h[i]);
        if(i-p+minl[p]>minl[i]) p=i;
    }
    p=n;minr[n]=1;
    for(i=n-1;i>0;i--){
        minr[i]=min(minr[p]+p-i,h[i]);
        if(p-i+minr[p]>minr[i]) p=i;
    }
    for(int i=1;i<=n;i++) ans=max(ans,min(minl[i],minr[i]));
    cout<<ans<<endl;
    return 0;
}
