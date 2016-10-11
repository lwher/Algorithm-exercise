#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
#define INF 10000000 
using namespace std; 
struct sth 
{ 
    int w,v,sj; 
}pe[500010]; 
int n,m,tot,num[500010],h[500010],shu[500010],vv[500010],t[500010]; 
long long gs[500010],ans; 
int tmin[3000010]; 
int read() 
{ 
    char ch=getchar(); 
    while(!(ch>='0' && ch<='9'))  ch=getchar(); 
    int x=0; 
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();} 
    return x; 
} 
int find(int x) 
{ 
    int mid,l=1,r=tot; 
    while(l+1<r) 
    { 
        mid=(l+r)>>1; 
        if(num[mid]==x)  return mid; 
        if(num[mid]>x)  r=mid; 
        else l=mid; 
    } 
    if(num[r]==x)  return r; 
    else return l; 
} 
void Ins(int x,int tt) 
{ 
    for(int i=x;i<=n;i+=(i & (-i)))  t[i]+=tt; 
} 
long long asksum(int x) 
{ 
    int i;long long sum=0; 
    for(i=x;i>0;i-=(i & (-i)))  sum+=t[i]; 
    return sum;   
} 
void updata(int k,int l,int r,int x,int p) 
{ 
    if(l==r)  {tmin[k]=p;return;} 
    int mid=(l+r)>>1; 
    if(x<=mid)  updata(k+k,l,mid,x,p); 
    else updata(k+k+1,mid+1,r,x,p); 
    tmin[k]=min(tmin[k+k],tmin[k+k+1]); 
} 
int askmin(int k,int l,int r,int zuo,int you) 
{ 
    if(l>you || r<zuo)  return INF; 
    if(l>=zuo && r<=you)   return tmin[k]; 
    int mid=(l+r)>>1; 
    return min(askmin(k+k,l,mid,zuo,you),askmin(k+k+1,mid+1,r,zuo,you)); 
} 
inline bool comp(sth a,sth b) 
{ 
    if(a.v==b.v)  return a.w<b.w; 
    return a.v>b.v; 
} 
int main() 
{ 
    int i,j,k; 
    //scanf("%d%d",&n,&m); 
    n=read();m=read(); 
    for(i=1;i<=n;i++)   
    { 
        h[i]=read();//scanf("%d",&h[i]); 
        shu[i]=h[i]; 
    }    
    sort(shu+1,shu+1+n); 
    num[++tot]=shu[1]; 
    for(i=2;i<=n;i++)  if(shu[i]!=shu[i-1])  num[++tot]=shu[i]; 
    for(i=1;i<=n;i++)  pe[i].w=i,pe[i].v=find(h[i]);  
    for(i=n;i>=1;i--)   
    { 
        vv[i]=asksum(pe[i].v-1); 
        ans+=vv[i];Ins(pe[i].v,1); 
    } 
    for(i=1;i<=m;i++)   
    { 
        j=read();//scanf("%d",&j); 
        if(!pe[j].sj) pe[j].sj=i;  
    } 
    sort(pe+1,pe+1+n,comp);  
    for(i=1;i<=n;i++)  updata(1,1,n,i,INF); 
    for(i=1;i<=n;i++)   
    { 
        if(pe[i].sj)  updata(1,1,n,pe[i].w,pe[i].sj); 
        k=askmin(1,1,n,1,pe[i].w); 
        if(k!=INF)  gs[k]+=vv[pe[i].w]; 
    }    
    printf("%lld\n",ans); 
    for(i=1;i<=m;i++) 
    {                 
        ans-=gs[i]; 
        printf("%lld\n",ans); 
    } 
    //system("pause"); 
    return 0; 
}