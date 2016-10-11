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
int n,K,len,num[1000001];
bool check(int x){
    int now=1,tot=0;
    for(int i=1;i<=len;i++){
        if(i>now) return 0;
        if(num[i+1]-num[i]<=x){
            tot++;now+=(K<<1);i++;
            if(tot==n) break;
        }
    } 
    return 1;
}
int main(){
    scanf("%d%d",&n,&K);
    len=n*K*2;
    for(int i=1;i<=len;i++) scanf("%d",&num[i]);
    sort(num+1,num+1+len);
    int l=num[2]-num[1],r=1e9,mid;
    while(l+1<r){
        mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid;
    }
    if(check(l)) printf("%d\n",l);
    else printf("%d\n",r);
    return 0;
}
