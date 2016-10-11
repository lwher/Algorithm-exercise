#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#define N 1000010 
#define max(aa,bb) ((aa)>(bb)?(aa):(bb)) 
using namespace std; 
int c[N][2],lmax[N],rmax[N],tmax[N],zhi[N],sum[N],fa[N],size[N]; 
int sz,hs[N],rot,n,m; 
bool fz[N],gs[N]; 
int shuzhi[N],bh[N]; 
inline void updata(int x) 
{ 
    int y=c[x][0],z=c[x][1]; 
    sum[x]=sum[y]+sum[z]+zhi[x]; 
    size[x]=size[y]+size[z]+1; 
    tmax[x]=max(tmax[y],tmax[z]); 
    tmax[x]=max(tmax[x],rmax[y]+zhi[x]+lmax[z]); 
    lmax[x]=max(lmax[y],sum[y]+zhi[x]+lmax[z]); 
    rmax[x]=max(rmax[z],sum[z]+zhi[x]+rmax[y]); 
} 
inline void downgo(int x) 
{ 
    int y,z; 
    y=c[x][0];z=c[x][1]; 
    if(gs[x]){ 
       gs[x]=0; 
       fz[x]=0; 
       if(y) 
       {gs[y]=1;fz[y]=0;zhi[y]=zhi[x];sum[y]=zhi[x]*size[y];} 
       if(z) 
       {gs[z]=1;fz[z]=0;zhi[z]=zhi[x];sum[z]=zhi[x]*size[z];} 
       if(zhi[x]>=0) { 
            if(y) {lmax[y]=sum[y];rmax[y]=sum[y];tmax[y]=sum[y];} 
            if(z) {lmax[z]=sum[z];rmax[z]=sum[z];tmax[z]=sum[z];} 
       } 
       else{ 
            if(y){lmax[y]=0;rmax[y]=0;tmax[y]=zhi[x];} 
            if(z){lmax[z]=0;rmax[z]=0;tmax[z]=zhi[x];} 
       } 
       return; 
    } 
    if(fz[x]){ 
        int t; 
        fz[x]^=1; 
        fz[y]^=1;fz[z]^=1; 
        t=lmax[y];lmax[y]=rmax[y];rmax[y]=t; 
        t=c[y][0];c[y][0]=c[y][1];c[y][1]=t; 
        t=rmax[z];rmax[z]=lmax[z];lmax[z]=t; 
        t=c[z][0];c[z][0]=c[z][1];c[z][1]=t; 
        updata(x); 
    } 
} 
void rotate(int &root,int x) 
{ 
    int y,z; 
    int p,q; 
    y=fa[x];z=fa[y]; 
    if(c[y][0]==x)  p=0; else  p=1; 
    q=p^1; 
    if(y==root)  root=x; 
    else{ 
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
    while(x!=root){ 
        y=fa[x];z=fa[y]; 
        if(y!=root) 
        if((c[y][0]==x) ^ (c[z][0]==y))  rotate(root,x); 
        else rotate(root,y); 
        rotate(root,x); 
    } 
} 
int find(int wei,int x) 
{ 
    downgo(wei); 
    if(size[c[wei][0]]+1==x)  return wei; 
    else
    if(size[c[wei][0]]>=x)  return find(c[wei][0],x); 
    else
    if(size[c[wei][0]]+1<x)  return find(c[wei][1],x-size[c[wei][0]]-1); 
} 
void build(int last,int l,int r) 
{ 
    if(r<l) return; 
    if(l==r) 
    { 
        zhi[bh[l]]=shuzhi[l];tmax[bh[l]]=shuzhi[l]; 
        if(shuzhi[l]>0) 
        {lmax[bh[l]]=shuzhi[l];rmax[bh[l]]=shuzhi[l];} 
        else
        {lmax[bh[l]]=0;rmax[bh[l]]=0;} 
        fa[bh[l]]=bh[last];size[bh[l]]=1;sum[bh[l]]=shuzhi[l]; 
        if(l<last)  c[bh[last]][0]=bh[l]; 
        else  c[bh[last]][1]=bh[l]; 
        return; 
    } 
    int mid=(l+r)>>1; 
    build(mid,l,mid-1); 
    build(mid,mid+1,r); 
    zhi[bh[mid]]=shuzhi[mid]; 
    updata(bh[mid]); 
    fa[bh[mid]]=bh[last]; 
    if(mid<last)  c[bh[last]][0]=bh[mid]; 
    else  c[bh[last]][1]=bh[mid]; 
} 
void charu(int k,int tot) 
{ 
    int x,y; 
    int i,num; 
    for(i=1;i<=tot;i++) 
    { 
        scanf("%d",&shuzhi[i]); 
        if(hs[0])  {bh[i]=hs[hs[0]];hs[0]--;} 
        else  {sz++;bh[i]=sz;} 
    } 
    build(0,1,tot); 
    y=bh[(1+tot)>>1]; 
    k++; 
    x=find(rot,k);splay(rot,x); 
    x=find(rot,k+1);splay(c[rot][1],x); 
    fa[y]=c[rot][1];c[c[rot][1]][0]=y; 
    updata(c[rot][1]);updata(rot); 
} 
void huishou(int wei) 
{ 
    if(wei==0) return; 
    huishou(c[wei][0]); 
    huishou(c[wei][1]); 
    lmax[wei]=0;rmax[wei]=0;tmax[wei]=0; 
    sum[wei]=0;size[wei]=0;zhi[wei]=0; 
    fa[wei]=0;c[wei][0]=0;c[wei][1]=0; 
    gs[wei]=0;fz[wei]=0; 
    hs[0]++;hs[hs[0]]=wei; 
} 
void shanchu(int k,int tot) 
{ 
    int x; 
    x=find(rot,k);splay(rot,x); 
    x=find(rot,k+tot+1);splay(c[rot][1],x); 
    int wei=c[c[rot][1]][0]; 
    huishou(wei); 
    c[c[rot][1]][0]=0; 
    updata(c[rot][1]);updata(rot); 
} 
void cl(int y,int x) 
{ 
       gs[y]=1;fz[y]=0; 
       sum[y]=x*size[y]; 
       zhi[y]=x; 
       if(zhi[y]>=0) { 
            lmax[y]=sum[y];rmax[y]=sum[y];tmax[y]=sum[y]; 
       } 
       else{ 
            lmax[y]=0;rmax[y]=0;tmax[y]=zhi[y]; 
       } 
} 
void gaishu(int k,int tot,int o) 
{ 
    int x; 
    x=find(rot,k);splay(rot,x); 
    x=find(rot,k+tot+1);splay(c[rot][1],x); 
    cl(c[c[rot][1]][0],o); 
    updata(c[rot][1]);updata(rot); 
} 
void cz(int x) 
{ 
    if(gs[x]) return; 
    fz[x]^=1; 
    int t; 
    t=c[x][0];c[x][0]=c[x][1];c[x][1]=t; 
    t=lmax[x];lmax[x]=rmax[x];rmax[x]=t; 
} 
void fangzhuang(int k,int tot) 
{ 
    int x; 
    x=find(rot,k);splay(rot,x); 
    x=find(rot,k+tot+1);splay(c[rot][1],x); 
    cz(c[c[rot][1]][0]); 
    updata(c[rot][1]);updata(rot); 
} 
int getsum(int k,int tot) 
{ 
        int x; 
        x=find(rot,k);splay(rot,x); 
        x=find(rot,k+tot+1);splay(c[rot][1],x); 
        return sum[c[c[rot][1]][0]]; 
} 
void solve() 
{ 
    char s[10]; 
    int i,num,tot,k; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++) 
    {scanf("%d",&shuzhi[i+1]);bh[i+1]=i+1;} 
    tmax[0]=-10000000; 
    shuzhi[1]=-10000000;bh[1]=1; 
    shuzhi[n+2]=-10000000;bh[n+2]=n+2; 
    build(0,1,n+2); 
    rot=(3+n)>>1; 
      
    sz=n+2; 
    for(i=1;i<=m;i++) 
    { 
        scanf("%s",s); 
        if(s[0]=='I') 
        { 
          scanf("%d%d",&k,&tot); 
          charu(k,tot); 
        } 
        else
        if(s[0]=='D') 
        { 
          scanf("%d%d",&k,&tot); 
          shanchu(k,tot); 
        } 
        else
        if(s[0]=='M') 
        { 
          if(s[2]=='K') 
          {scanf("%d%d%d",&k,&tot,&num); 
          gaishu(k,tot,num);} 
          else
          printf("%d\n",tmax[rot]); 
          
        } 
        else
        if(s[0]=='R') 
        { 
          scanf("%d%d",&k,&tot); 
          fangzhuang(k,tot); 
        } 
        else
        if(s[0]=='G') 
        { 
          scanf("%d%d",&k,&tot); 
          printf("%d\n",getsum(k,tot)); 
        } 
        else
        { 
          printf("%d\n",tmax[rot]); 
        } 
    } 
} 
int main() 
{ 
        solve(); 
    //system("pause"); 
    return 0; 
}