#include<iostream> 
#include<cstdlib> 
#include<cstdio> 
#include<algorithm> 
using namespace std; 
struct sth 
{ 
    long long x,y,id; 
}d[100010]; 
long long X1[100010],Y1[100010]; 
long long  X2[100010],Y2[100010]; 
long long  ans=1e20; 
int n; 
inline bool comp(sth a,sth b) 
{ 
    return a.x<b.x; 
} 
inline bool cmp(sth a,sth b) 
{ 
    return a.y<b.y; 
} 
int main() 
{ 
    int i,j; 
    long long tmp; 
    long long xx,yy; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) 
    { 
        scanf("%lld%lld",&xx,&yy); 
        d[i].x=xx+yy; 
        d[i].y=xx*2-d[i].x; 
    } 
      
    sort(d+1,d+1+n,cmp); 
    for(i=1;i<=n;i++) 
    { 
        Y1[i]=Y1[i-1]+d[i].y-d[1].y; 
        Y2[n-i+1]=Y2[n-i+2]-d[n-i+1].y+d[n].y; 
        d[i].id=i; 
    } 
      
    sort(d+1,d+1+n,comp); 
    for(i=1;i<=n;i++) 
    { 
        X1[i]=X1[i-1]+d[i].x-d[1].x; 
        X2[n-i+1]=X2[n-i+2]-d[n-i+1].x+d[n].x; 
    } 
      
    for(i=1;i<=n;i++) 
    { 
        tmp=0; 
        tmp+=X1[n]-X1[i]-(n-i)*(X1[i]-X1[i-1]); 
        tmp+=X2[1]-X2[i]-(i-1)*(X2[i]-X2[i+1]); 
        j=d[i].id; 
        tmp+=Y1[n]-Y1[j]-(n-j)*(Y1[j]-Y1[j-1]); 
        tmp+=Y2[1]-Y2[j]-(j-1)*(Y2[j]-Y2[j+1]); 
        if(tmp<ans)  ans=tmp; 
    } 
      
    ans/=2; 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}