#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 300001
using namespace std;
char s[N],p[N];
int n,len,ans,R[N];
void Pre_work(){
    n=0;len=strlen(p+1);
    s[0]='@';s[++n]='#';
    for(int i=1;i<=len;i++){
        s[++n]=p[i];s[++n]='#';
    }
    s[++n]='&';s[n+1]='%';
}
void solve(){ 
    int i,k,p=0,r=0;ans=0;//r:不包括本身的回文半径长度 
    for(i=1;i<=n;i++){
        if(i<=p+r) k=min(R[p+p-i],p+r-i); else k=0;
        while(s[i-k]==s[i+k]) k++;
        R[i]=k-1;
        if(i+R[i]>p+r) p=i,r=R[i];
    }
    for(i=1;i<n;i++) ans=max(ans,R[i]);
    printf("%d\n",ans);
}
int main(){
    while(scanf("%s",p+1)!=EOF){
        Pre_work();
        solve();
    }
    return 0;
}
