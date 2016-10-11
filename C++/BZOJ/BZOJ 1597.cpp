#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include<cmath> 
using namespace std; 
struct sth 
{ 
    long long x,y; 
}t[50010]; 
struct now 
{ 
    long long x,y; 
}d[50010]; 
long long f[50010];int dui[50010]; 
int n; 
inline bool comp(sth a,sth b) 
{ 
    if(a.x==b.x) return a.y<b.y; 
    return a.x<b.x; 
} 
long double  mul(int j,int k) 
{ 
    return (long double) (f[k]-f[j]) / (long double) (d[j+1].y-d[k+1].y); 
} 
int main() 
{ 
    int i,j; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) 
    scanf("%lld%lld",&t[i].x,&t[i].y); 
    sort(t+1,t+1+n,comp); 
      
    int tou=1,wei=1; 
    dui[1]=1; 
    for(i=2;i<=n;i++) 
    { 
        while(tou<=wei && t[dui[tou]].y<=t[i].y) 
        tou++; 
        while(tou<=wei && t[dui[wei]].y<=t[i].y) 
        wei--; 
        wei++;dui[wei]=i; 
    } 
    int sz=0; 
    for(i=tou;i<=wei;i++) 
    { 
        sz++; 
        d[sz].x=t[dui[i]].x; 
        d[sz].y=t[dui[i]].y; 
    } 
    f[0]=0; 
    tou=1;wei=1; 
    dui[1]=0; 
    for(i=1;i<=sz;i++) 
    { 
        while(tou<wei && mul(dui[tou],dui[tou+1])<d[i].x) 
        tou++; 
        f[i]=f[dui[tou]]+d[i].x*d[dui[tou]+1].y; 
        while(tou<wei && mul(dui[wei-1],dui[wei])>mul(dui[wei],i)) 
        wei--; 
        wei++; 
        dui[wei]=i; 
    } 
    cout<<f[sz]<<endl; 
      
//  system("pause"); 
    return 0; 
}