#include<iostream>
#include<cstdio>
using namespace std;
int n,V,v,w,ans,f[10001];
int main(){
    scanf("%d%d",&V,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&v,&w);
        for(int j=v;j<=V;j++) if(f[j]<f[j-v]+w) f[j]=f[j-v]+w;
    }
    for(int i=1;i<=V;i++) if(f[i]>ans) ans=f[i];
    cout<<ans<<endl;
    system("pause");
    return 0;
}
