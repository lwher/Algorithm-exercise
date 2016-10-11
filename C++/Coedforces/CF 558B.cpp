#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,ans,A[100001],num[1000001],l[1000001],r[1000001];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        if(!num[A[i]]) l[A[i]]=i;
        num[A[i]]++;r[A[i]]=i;
    }
    ans=0;
    for(int i=1;i<=1000000;i++){
        if(num[ans]<num[i] || (num[ans]==num[i] && (r[ans]-l[ans]>r[i]-l[i]))) ans=i;
    }
    cout<<ans[l]<<" "<<ans[r]<<endl;
    return 0;
}
