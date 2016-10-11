#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
// wt 表示是否是询问  qian  表示是否为矩形左边  
struct sth 
{ 
    int x,y,x2,y2,w,bh,wt,qian; 
}xw[200010],d[400010]; 
int sz; 
int n,ans[200010],s[500010]; 
void swap(int &a,int &b) 
{ 
    int t=a;a=b;b=t; 
} 
inline bool comp(sth a,sth b) 
{ 
    if(a.x==b.x)  return a.wt<b.wt;    
    return a.x<b.x; 
} 
int lowbit(int x) 
{ 
    return x & (-x); 
} 
void updata(int x,int w) 
{ 
    while(x<=n) 
    { 
        s[x]+=w; 
        x+=lowbit(x); 
    } 
} 
int getsum(int x) 
{ 
    int now=0; 
    while(x>0) 
    { 
        now+=s[x]; 
        x-=lowbit(x); 
    } 
    return now; 
} 
void solve(int l,int r) 
{ 
    if(l==r) return; 
    int mid=(l+r)>>1; 
    solve(l,mid);solve(mid+1,r); 
    int i,tot=0,tmp,bo=0; 
    for(i=l;i<=mid;i++) 
    if(xw[i].wt==0) 
    { 
        tot++;d[tot]=xw[i];bo=1; 
    } 
    if(bo==0) return; 
    for(i=mid+1;i<=r;i++) 
    if(xw[i].wt==1) 
    { 
        tot++;d[tot]=xw[i];d[tot].x--;d[tot].x2=xw[i].x-1;d[tot].bh=i;d[tot].qian=1; 
        tot++;d[tot]=xw[i];d[tot].x=xw[i].x2;d[tot].bh=i;d[tot].qian=0; 
        bo=2; 
    } 
    if(bo==1) return; 
    sort(d+1,d+1+tot,comp); 
    for(i=1;i<=tot;i++) 
    { 
        if(d[i].wt==0)   updata(d[i].y,d[i].w); 
        else
        { 
            tmp=getsum(d[i].y2)-getsum(d[i].y-1); 
            if(d[i].qian==1)  ans[d[i].bh]-=tmp; 
            else  ans[d[i].bh]+=tmp; 
        } 
    } 
} 
int main() 
{ 
    int t,a,b,c,d; 
    scanf("%d",&n); 
    while(scanf("%d",&t)) 
    { 
        if(t==3)  break; 
        if(t==1) 
        { 
            sz++;scanf("%d%d%d",&a,&b,&c); 
            xw[sz].x=a;xw[sz].y=b;xw[sz].w=c;xw[sz].wt=0; 
        }   
        else
        { 
            sz++;scanf("%d%d%d%d",&a,&b,&c,&d); 
            if(a>c || (a==c && b>d))  swap(a,c),swap(b,d); 
            xw[sz].x=a;xw[sz].y=b;xw[sz].x2=c;xw[sz].y2=d;xw[sz].wt=1; 
        } 
    } 
    solve(1,sz); 
    for(int i=1;i<=sz;i++)  if(xw[i].wt==1)  printf("%d\n",ans[i]); 
    //system("pause"); 
    return 0; 
}