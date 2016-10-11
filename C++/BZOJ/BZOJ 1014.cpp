#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#define N 150010 
#define MOD 9875321 
using namespace std; 
int sz,c[N][2],size[N],zhi[N],hash[N],fa[N],rot; 
int jzs[N]; 
int a[N]; 
char s[N]; 
void updata(int x) 
{ 
    int y=c[x][0],z=c[x][1]; 
    size[x]=size[y]+size[z]+1; 
    hash[x]=hash[y]+((long long)(jzs[size[y]])*zhi[x])%MOD+((long long)(hash[z])*jzs[size[y]+1])%MOD;   
    hash[x]%=MOD; 
} 
void rotate(int x,int &root) 
{ 
    int y=fa[x],z=fa[y],p,q; 
    if(c[y][0]==x)  p=0; else p=1; 
    q=p^1; 
    if(y==root)  root=x; 
    else
    { 
        if(c[z][0]==y)  c[z][0]=x;  else  c[z][1]=x; 
    } 
    fa[x]=z;fa[y]=x;fa[c[x][q]]=y; 
    c[y][p]=c[x][q];c[x][q]=y; 
    updata(y);updata(x); 
} 
void splay(int x,int &root) 
{ 
    int y,z; 
    while(x!=root) 
    { 
        y=fa[x];z=fa[y]; 
        if(y!=root)  
        { 
            if((c[y][0]==x) ^ (c[z][0]==y))  rotate(x,root); 
            else rotate(y,root); 
        } 
        rotate(x,root); 
    } 
} 
int find(int wei,int k) 
{ 
    int now=wei; 
    while(1) 
    { 
       int y=c[now][0],z=c[now][1]; 
       if(size[y]+1==k)  break;   else 
       if(size[y]>=k)    now=y;  else 
       if(size[y]+1<k)   {now=z;k-=size[y]+1;} 
    } 
    return now; 
} 
void build(int l,int r,int last) 
{ 
    if(l>r) return; 
    if(l==r)  
    { 
        fa[l]=last;size[l]=1;zhi[l]=a[l];hash[l]=zhi[l]; 
        if(l<last) c[last][0]=l;else c[last][1]=l;return; 
    } 
    int mid=(l+r)>>1; 
    build(l,mid-1,mid); 
    build(mid+1,r,mid); 
    fa[mid]=last;zhi[mid]=a[mid]; 
    updata(mid); 
    if(mid<last) c[last][0]=mid;else c[last][1]=mid; 
} 
void xiugai(int k,int shu) 
{ 
    int x=find(rot,k+1); 
    splay(x,rot); 
    zhi[rot]=shu; updata(rot); 
} 
void Ins(int k,int shu) 
{ 
    int x=find(rot,k+1); splay(x,rot); 
    x=find(rot,k+2); splay(x,c[rot][1]); 
    x=c[rot][1]; 
    sz++;c[x][0]=sz;zhi[sz]=shu;size[sz]=1;hash[sz]=shu;fa[sz]=x; 
    splay(sz,rot); 
} 
void init() 
{ 
    scanf("%s",s); 
    int i,n=strlen(s); 
    jzs[0]=1; 
    for(i=1;i<N;i++)  jzs[i]=((long long)(jzs[i-1])*27)%MOD; 
    for(i=0;i<n;i++) 
    a[i+2]=int(s[i])-96; 
    rot=(n+3)>>1; 
    build(1,n+2,0); 
    sz=n+2; 
} 
bool check(int mid,int a,int b) 
{ 
    int x,h1,h2; 
    x=find(rot,a); splay(x,rot); 
    x=find(rot,a+mid+1); splay(x,c[rot][1]); 
    h1=hash[c[x][0]]; 
    x=find(rot,b); splay(x,rot); 
    x=find(rot,b+mid+1); splay(x,c[rot][1]); 
    h2=hash[c[x][0]]; 
    if(h1==h2)  return 1; 
    else return 0; 
} 
int maxans(int a,int b) 
{ 
    if(a>b)  {int  t=a;a=b;b=t;}   
    int l=0,r=sz-2-b+1,mid; 
    while(l<r) 
    { 
        if(l+1==r)  break; 
        mid=(l+r)>>1; 
        if(check(mid,a,b))  l=mid; 
        else r=mid; 
    } 
    if(check(r,a,b)) return r; 
    else return l; 
} 
void solve() 
{ 
    int i,m,a,b; 
    char d; 
    scanf("%d",&m); 
    for(i=1;i<=m;i++) 
    { 
        scanf("%s",s); 
        if(s[0]=='R')   
        { 
            scanf("%d %c",&a,&d); 
            xiugai(a,int(d)-96); 
        } else
        if(s[0]=='I') 
        { 
            scanf("%d %c",&a,&d); 
            Ins(a,int(d)-96); 
        } 
        else
        { 
            scanf("%d%d",&a,&b); 
            printf("%d\n",maxans(a,b)); 
        }  
    } 
} 
int main() 
{ 
    init(); 
    solve(); 
    //system("pause"); 
    return 0; 
}