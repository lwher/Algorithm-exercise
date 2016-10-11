#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
#define eps 1e-9 
#define INF 1e9 
using namespace std; 
struct sth 
{ 
    double k,a,b,rate;int pos; 
}q[100010],nq[100010]; 
struct point 
{ 
    double x,y; 
    friend bool operator <(const point &a,const point &b) 
    { 
        return (a.x<b.x ||(fabs(a.x-b.x)<eps && a.y<b.y)); 
    } 
}p[100010],np[100010]; 
int n,top,st[100010]; 
double f[100010]; 
inline bool comp(sth a,sth b){return a.k<b.k;} 
double getk(int a,int b) 
{ 
    if(a==0) return -INF; 
    if(b==0) return INF; 
    if(fabs(p[a].x-p[b].x)<eps)  return -INF; 
    return (p[a].y-p[b].y)/(p[a].x-p[b].x); 
} 
void solve(int l,int r) 
{ 
    if(l==r) 
    { 
        f[l]=max(f[l],f[l-1]); 
        p[l].y=f[l]/(q[l].a*q[l].rate+q[l].b); 
        p[l].x=p[l].y*q[l].rate; 
        return; 
    } 
    int i,mid=(l+r)>>1,l1=l,l2=mid+1,j=1; 
    for(i=l;i<=r;i++) 
    { 
        if(q[i].pos<=mid)  nq[l1++]=q[i]; 
        else nq[l2++]=q[i]; 
    } 
    for(i=l;i<=r;i++)  q[i]=nq[i]; 
    solve(l,mid);top=0; 
    for(i=l;i<=mid;i++) 
    { 
        while(top>=2 && getk(i,st[top])>getk(st[top],st[top-1]))  top--; 
        st[++top]=i; 
    } 
    for(i=r;i>mid;i--) 
    { 
        while (j<top&&q[i].k<getk(st[j],st[j+1])) j++; 
        f[q[i].pos]=max(f[q[i].pos],p[st[j]].x*q[i].a+p[st[j]].y*q[i].b); 
    } 
    solve(mid+1,r); 
    l1=l,l2=mid+1; 
    for(i=l;i<=r;i++) 
    { 
        if((p[l1]<p[l2]||l2>r) && l1<=mid)  np[i]=p[l1++]; 
        else np[i]=p[l2++]; 
    } 
    for(i=l;i<=r;i++)   p[i]=np[i]; 
} 
int main() 
{ 
    int i; 
    scanf("%d%lf",&n,&f[0]); 
    for(i=1;i<=n;i++) 
    { 
        scanf("%lf%lf%lf",&q[i].a,&q[i].b,&q[i].rate); 
        q[i].k=-q[i].a/q[i].b; 
        q[i].pos=i; 
    } 
    sort(q+1,q+1+n,comp); 
    solve(1,n); 
    printf("%.3lf\n",f[n]); 
    //system("pause"); 
    return 0; 
} 

