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
int n,top,num[100001],sum[100001],ans[100001],stack[100001];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        if(sum[num[i]] || num[i]>n) stack[++top]=i;
        else ans[i]=num[i];
        sum[num[i]]++;
    }
    for(int i=1;i<=n;i++) if(!sum[i]){
        ans[stack[top]]=i;top--;
    }
    for(int i=1;i<n;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    return 0;
}
