#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
struct point {
    int x,y;
    double ap;
}p[100010];
int n;
ll ans;
inline bool comp(point a,point b){
     return a.ap<b.ap;
}
ll operator *(point a,point b){
     return (ll)a.x*b.y-(ll)b.x*a.y;
}
void init(){
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
             scanf("%d%d",&p[i].x,&p[i].y);
             p[i].ap=atan2(p[i].y,p[i].x);
     }
     sort(p+1,p+1+n,comp);
}
void solve(){
     int i,now=1,cnt=0;
     for(int i=1;i<=n;i++){
             while(p[i]*p[now%n+1]>0) now=now%n+1,cnt++;
             ans-=(ll)cnt*(cnt-1)/2;
             cnt--;
     }
     ans+=(ll)n*(n-1)*(n-2)/6;
     cout<<ans<<endl;
}
int main(){
    init();
    solve();
    system("pause");
    return 0;
}
