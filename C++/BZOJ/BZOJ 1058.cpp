#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<algorithm> 
#define N 1000010 
#define INF 1000000010 
using namespace std; 
int c[N][2],zuo[N],you[N],minc[N],fa[N],zhi[N],size[N]; 
int rot,num[N],num1[N],sum[N],sz,rot1,sz1; 
int c1[N][2],zuo1[N],you1[N],minc1[N],zhi1[N],fa1[N]; 
int n,m; 
void chashu(int x){ 
    while(x<=n){ 
        sum[x]++; 
        x+=((x) & (-x)); 
    } 
} 
int getsum(int x){ 
    int gs=0; 
    while(x>0){ 
        gs+=sum[x]; 
        x-=((x) & (-x)); 
    } 
    return gs; 
} 
//=================================first V 
void updata(int x) 
{ 
    int y=c[x][0],z=c[x][1]; 
    size[x]=size[y]+size[z]+1; 
    zuo[x]=zuo[y];you[x]=you[z]; 
    if(!y)  zuo[x]=zhi[x]; 
    if(!z)  you[x]=zhi[x]; 
    minc[x]=min(minc[z],minc[y]); 
    if(y) 
    minc[x]=min(minc[x],abs(you[y]-zhi[x])); 
    if(z) 
    minc[x]=min(minc[x],abs(zuo[z]-zhi[x])); 
} 
void build(int last,int l,int r) 
{ 
    if(l>r) return; 
    if(l==r) 
    { 
        size[l]=1;zuo[l]=num[l];you[l]=num[l];minc[l]=INF;fa[l]=last;zhi[l]=num[l]; 
        if(l<last)  c[last][0]=l; 
        else c[last][1]=l; 
        return; 
    } 
    int mid=(l+r)>>1; 
    build(mid,l,mid-1); 
    build(mid,mid+1,r); 
    fa[mid]=last; 
    zhi[mid]=num[mid]; 
    updata(mid); 
    if(mid<last)  c[last][0]=mid; 
    else c[last][1]=mid; 
} 
void rotate(int &root,int x) 
{ 
    int y=fa[x],z=fa[y]; 
    int p,q; 
    if(c[y][0]==x)  p=0;else p=1; 
    q=p^1; 
    if(y==root)  root=x; 
    else
    { 
        if(c[z][0]==y)  c[z][0]=x; 
        else  c[z][1]=x; 
    } 
    fa[x]=z;fa[y]=x;fa[c[x][q]]=y; 
    c[y][p]=c[x][q];c[x][q]=y; 
    updata(y);updata(x); 
} 
void splay(int &root,int x) 
{ 
    int y,z; 
    while(x!=root) 
    { 
        y=fa[x];z=fa[y]; 
        if(y!=root) 
        { 
            if((c[y][0]==x)^(c[z][0]==y))  rotate(root,x); 
            else rotate(root,y); 
        } 
        rotate(root,x); 
    } 
} 
int find(int wei,int x) 
{ 
    if(size[c[wei][0]]+1==x)  return wei; 
    else
    if(size[c[wei][0]]>=x)  return find(c[wei][0],x); 
    else
    if(size[c[wei][0]]+1<x)  return find(c[wei][1],x-size[c[wei][0]]-1); 
} 
void Ins1(int k,int tot) 
{    
    int x; 
    k=getsum(k); 
    k++; 
    x=find(rot,k);splay(rot,x); 
    x=find(rot,k+1);splay(c[rot][1],x); 
    sz++; 
    c[x][0]=sz; 
    zhi[sz]=tot;zuo[sz]=tot;you[sz]=tot;fa[sz]=x;minc[sz]=INF;size[sz]=1; 
    updata(x);updata(rot); 
} 
//==========================================  second V 
void updata1(int x) 
{ 
    int y=c1[x][0],z=c1[x][1]; 
    zuo1[x]=zuo1[y];you1[x]=you1[z]; 
    if(!y)  zuo1[x]=zhi1[x]; 
    if(!z)  you1[x]=zhi1[x]; 
    minc1[x]=min(minc1[z],minc1[y]); 
    if(y) 
    minc1[x]=min(minc1[x],abs(you1[y]-zhi1[x])); 
    if(z) 
    minc1[x]=min(minc1[x],abs(zuo1[z]-zhi1[x])); 
} 
void build1(int last,int l,int r) 
{ 
    if(l>r) return; 
    if(l==r) 
    { 
        zuo1[l]=num1[l];you1[l]=num1[l];minc1[l]=INF;fa1[l]=last;zhi1[l]=num1[l]; 
        if(l<last)  c1[last][0]=l; 
        else c1[last][1]=l; 
        return; 
    } 
    int mid=(l+r)>>1; 
    build1(mid,l,mid-1); 
    build1(mid,mid+1,r); 
    fa1[mid]=last; 
    zhi1[mid]=num1[mid]; 
    updata1(mid); 
    if(mid<last)  c1[last][0]=mid; 
    else c1[last][1]=mid; 
} 
void rotate1(int &root,int x) 
{ 
    int y=fa1[x],z=fa1[y]; 
    int p,q; 
    if(c1[y][0]==x)  p=0;else p=1; 
    q=p^1; 
    if(y==root)  root=x; 
    else
    { 
        if(c1[z][0]==y)  c1[z][0]=x; 
        else  c1[z][1]=x; 
    } 
    fa1[x]=z;fa1[y]=x;fa1[c1[x][q]]=y; 
    c1[y][p]=c1[x][q];c1[x][q]=y; 
    updata1(y);updata1(x); 
} 
void splay1(int &root,int x) 
{ 
    int y,z; 
    while(x!=root) 
    { 
        y=fa1[x];z=fa1[y]; 
        if(y!=root) 
        { 
            if((c1[y][0]==x)^(c1[z][0]==y))  rotate1(root,x); 
            else rotate1(root,y); 
        } 
        rotate1(root,x); 
    } 
} 
void Ins2(int last,int &wei,int x) 
{ 
    if(wei==0) 
    { 
        sz1++;wei=sz1; 
        zhi1[wei]=x;zuo1[wei]=x;you1[wei]=x; 
        fa1[wei]=last;minc1[wei]=INF; 
        splay1(rot1,sz1);return; 
    }else
    if(zhi1[wei]>=x)  Ins2(wei,c1[wei][0],x); 
    else Ins2(wei,c1[wei][1],x); 
} 
//================================================== 
void init() 
{ 
    minc[0]=INF; 
    minc1[0]=INF; 
    scanf("%d%d",&n,&m); 
    int i; 
    for(i=1;i<=n;i++) 
    {scanf("%d",&num[i+1]);num1[i]=num[i+1];chashu(i);} 
    num[1]=-500000000;num[n+2]=-500000000; 
    build(0,1,n+2); 
    sort(num1+1,num1+1+n); 
    build1(0,1,n); 
    rot=(3+n)>>1; 
    rot1=(1+n)>>1; 
    sz=n+2;sz1=n; 
} 
void solve() 
{ 
      
    int i; 
    int a,b; 
    char s[15];  
    for(i=1;i<=m;i++) 
    { 
        scanf("%s",s); 
        if(s[0]=='I') 
        { 
            scanf("%d%d",&a,&b); 
            Ins1(a,b);chashu(a); 
            if(minc1[rot1]!=0) 
            Ins2(0,rot1,b); 
        } 
        else
        if(s[4]=='G') 
        printf("%d\n",minc[rot]); 
        else
        printf("%d\n",minc1[rot1]); 
    } 
} 
int main() 
{ 
        init(); 
    solve(); 
    //system("pause"); 
    return 0; 
}