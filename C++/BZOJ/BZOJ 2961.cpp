#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
#define eps 1e-8 
#define INF 1e8 
using namespace std; 
struct sth 
{ 
    int tp; 
    double x,y; 
}p[500010],q[500010],dw[500010],up[500010]; 
bool ans[500010]; 
int n,t1,t2; 
sth operator -(const sth &a,const sth &b) 
{ 
    sth tmp; 
    tmp.x=a.x-b.x; tmp.y=a.y-b.y; 
    return tmp; 
} 
double operator *(const sth &a,const sth &b) 
{ 
    return a.x*b.y-a.y*b.x; 
} 
double operator ^(const sth &a,const sth &b) 
{ 
    return a.x*b.x+a.y*b.y; 
} 
inline bool comp(sth a,sth b) 
{ 
    if(fabs(a.x-b.x)<eps)  return a.y<b.y; 
    return a.x<b.x;  
} 
void ask(int i) 
{ 
    sth tmp; 
    if(q[i].y<0) 
    { 
        int l=1,r=t1,mid; 
        while(l<=r) 
        { 
            mid=(l+r)>>1; 
            if ((q[i]^(up[mid+1]-up[mid]))>-eps) r=mid-1,tmp=up[mid]; 
            else l=mid+1; 
        } 
    } 
    else
    { 
        int l=1,r=t2; 
        while (l<=r) 
        { 
            int mid=(l+r)>>1; 
            if ((q[i]^(dw[mid]-dw[mid+1]))<eps) r=mid-1,tmp=dw[mid]; 
            else l=mid+1; 
        } 
    } 
    if (2*q[i].x*tmp.x+2*q[i].y*tmp.y-(q[i].x*q[i].x+q[i].y*q[i].y)<eps) ans[i]=0; 
} 
void solve(int l,int r) 
{ 
    if(l==r) return; 
    int mid=(l+r)>>1; 
    solve(l,mid);solve(mid+1,r); 
    int i,tot=0; 
    for(i=l;i<=mid;i++)   if(q[i].tp==0)  p[++tot]=q[i]; 
    sort(p+1,p+1+tot,comp); 
    t1=0;t2=0; 
    for(i=1;i<=tot;i++) 
    { 
        while(t1>1 && (up[t1]-up[t1-1])*(p[i]-up[t1])>-eps) t1--; 
        up[++t1]=p[i]; 
    } 
    for (int i=tot;i>=1;i--) 
    { 
         while (t2>=2&&(dw[t2]-dw[t2-1])*(p[i]-dw[t2])>-eps) t2--; 
         dw[++t2]=p[i]; 
    } 
    up[t1+1].x=up[t1].x+eps;up[t1+1].y=-INF; 
    dw[t2+1].x=dw[t2].x-eps;dw[t2+1].y=INF; 
    for(i=mid+1;i<=r;i++)  if(q[i].tp==1 && ans[i])  ask(i); 
} 
int main() 
{ 
    int i;bool o=0; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) 
    { 
        scanf("%d%lf%lf",&q[i].tp,&q[i].x,&q[i].y); 
        if(q[i].tp==0)  o=1; 
        else ans[i]=o; 
    } 
    solve(1,n); 
    for(i=1;i<=n;i++) 
    if(q[i].tp==1) 
    { 
        if(ans[i])  printf("Yes\n");  else printf("No\n"); 
    } 
    //system("pause"); 
    return 0; 
}