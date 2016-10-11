#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 101
using namespace std;
struct sth{
    int x,sum;
}p[N];
int n,ans,S[N];
bool comp(sth a,sth b){
    return a.x<b.x;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].sum);
    p[++n].x=0;p[n].sum=0;
    sort(p+1,p+1+n,comp);
    for(int i=1;i<=n;i++) S[i]=S[i-1]+p[i].sum;
    for(int i=1;i<=n;i++){
        if(p[i].x==0){
            if(i-1>n-i) ans=S[n]-S[2*i-n-2]; else
            if(i-1<n-i) ans=S[i*2]; 
			else ans=S[n];
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
