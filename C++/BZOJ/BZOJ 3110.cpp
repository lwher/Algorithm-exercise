#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#define N 200010 
#define M 15000002 
#define T 100010 
using namespace std; 
int sz,n,m,A; 
int all[N],rot[N],q[N],w[N]; 
int ls[M],rs[M],sum[M]; 
void updata(int l,int r,int &rt,int wei,int x) 
{ 
    if(!rt)  rt=++sz; 
    sum[rt]+=x; 
    if(l==r)  return; 
    int mid=(l+r)>>1; 
    if(wei<=mid)  updata(l,mid,ls[rt],wei,x); 
    else  updata(mid+1,r,rs[rt],wei,x); 
} 
void modify(int k,int l,int r,int zuo,int you,int x) 
{ 
    if(l>=zuo && r<=you)  {updata(1,T,all[k],x,1);return;} 
    updata(1,T,rot[k],x,you-zuo+1); 
    int mid=(l+r)>>1; 
    if(zuo<=mid)  modify(k<<1,l,mid,zuo,min(mid,you),x); 
    if(you>mid)  modify(k+k+1,mid+1,r,max(zuo,mid+1),you,x); 
} 
void ask(int k,int l,int r,int zuo,int you) 
{ 
    q[++A]=all[k];w[A]=you-zuo+1; 
    if(l>=zuo && r<=you)  {q[++A]=rot[k];w[A]=1;return;} 
    int mid=(l+r)>>1; 
    if(zuo<=mid)  ask(k<<1,l,mid,zuo,min(mid,you)); 
    if(you>mid)  ask(k+k+1,mid+1,r,max(zuo,mid+1),you); 
} 
int que(int l,int r,int k) 
{ 
    int i,cnt=0; 
    if(l==r) return l; 
    int mid=(l+r)>>1; 
    for(i=1;i<=A;i++)  cnt+=sum[rs[q[i]]]*w[i]; 
    if(cnt>=k) 
    { 
        for(i=1;i<=A;i++)  q[i]=rs[q[i]]; 
        return que(mid+1,r,k); 
    } 
    else
    { 
        for(i=1;i<=A;i++)  q[i]=ls[q[i]]; 
        return que(l,mid,k-cnt); 
    } 
} 
int main() 
{ 
    int i,a,b,c,d; 
    scanf("%d%d",&n,&m); 
    while(m--) 
    { 
        scanf("%d%d%d%d",&a,&b,&c,&d); 
        if(a==1) modify(1,1,T,b,c,d+n+1); 
        else
        { 
            A=0; 
            ask(1,1,T,b,c); 
            printf("%d\n",que(1,T,d)-n-1); 
        } 
    } 
    //system("pause"); 
    return 0; 
}