#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#define N 200010 
using namespace std; 
int c[N][2],size[N],fa[N],sz,rot,n,m,shu[N]; 
long long zhi[N],d[N],gds[N]; 
long long sum[N],jdc[N]; 
bool gais[N]; 
void updata(int x) 
{ 
     int y=c[x][0],z=c[x][1]; 
     size[x]=size[y]+size[z]+1; 
     sum[x]=sum[y]+sum[z]+zhi[x]; 
} 
void rotate(int x,int &root) 
{ 
     int p,q,y,z; 
     y=fa[x];z=fa[y]; 
     if(c[y][0]==x)  p=0;  else p=1; 
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
void splay(int x,int &root) 
{ 
     int y,z; 
     while(x!=root) 
     { 
         y=fa[x];z=fa[y]; 
         if(y!=root) 
         { 
             if((c[y][0]==x)^(c[z][0]==y))  rotate(x,root); 
             else  rotate(y,root); 
         } 
         rotate(x,root); 
     } 
} 
void downgo(int x) 
{ 
     int y=c[x][0],z=c[x][1]; 
     if(gais[x]) 
     { 
         gais[x]=0; 
         if(y)  {jdc[y]=0;d[y]=0;gais[y]=1;gds[y]=gds[x];zhi[y]=gds[x];sum[y]=(long long)(size[y])*gds[x];} 
         if(z)  {jdc[z]=0;d[z]=0;gais[z]=1;gds[z]=gds[x];zhi[z]=gds[x];sum[z]=(long long)(size[z])*gds[x];} 
         gds[x]=0; 
     } 
     if(jdc[x]!=0 || d[x]!=0) 
     { 
         if(y)  { 
         jdc[y]+=jdc[x];d[y]+=d[x];zhi[y]+=jdc[x]+size[c[y][0]]*d[x]; 
         sum[y]+=size[y]*((size[y]-1)*d[x]+2*jdc[x])/2; 
         } 
         if(z)  { 
         jdc[z]+=jdc[x]+(size[y]+1)*d[x];d[z]+=d[x]; 
         zhi[z]+=jdc[x]+(size[y]+1)*d[x]+d[x]*size[c[z][0]];sum[z]+=size[z]*((size[z]-1)*d[x]+2*(jdc[x]+(size[y]+1)*d[x]))/2; 
         } 
         jdc[x]=0;d[x]=0; 
     } 
} 
int find(int x,int k) 
{ 
    downgo(x); 
    int y=c[x][0]; 
    if(size[y]+1==k)  return x; 
    if(size[y]>=k)    return find(y,k); 
    else   return find(c[x][1],k-size[y]-1); 
} 
void build(int l,int r,int last) 
{ 
     if(l>r)  return; 
     if(l==r) 
     { 
             fa[l]=last;zhi[l]=shu[l];size[l]=1;sum[l]=zhi[l]; 
             if(l<last) c[last][0]=l;else c[last][1]=l;return; 
     } 
     int mid=(l+r)>>1; 
     build(l,mid-1,mid);build(mid+1,r,mid); 
     fa[mid]=last;zhi[mid]=shu[mid];updata(mid); 
     if(mid<last)  c[last][0]=mid; else c[last][1]=mid; 
} 
void gaishu(int l,int r,int num) 
{ 
     int x=find(rot,l);splay(x,rot); 
     x=find(rot,r+2); splay(x,c[rot][1]); 
     x=c[x][0]; 
     jdc[x]=0;d[x]=0;gais[x]=1;gds[x]=num;zhi[x]=num;sum[x]=size[x]*num; 
     downgo(x);splay(x,rot); 
} 
void jiadengcha(int l,int r,int C) 
{ 
     int x=find(rot,l);splay(x,rot); 
     x=find(rot,r+2);splay(x,c[rot][1]); 
     x=c[x][0]; 
     if(jdc[x] || d[x]) downgo(x); 
     jdc[x]=C;d[x]=C; 
     zhi[x]+=(size[c[x][0]]+1)*jdc[x]; 
     sum[x]+=size[x]*(size[x]*jdc[x]+jdc[x])/2; 
     downgo(x);splay(x,rot); 
} 
void charu(int wei,int num) 
{ 
     int x=find(rot,wei);splay(x,rot); 
     x=find(rot,wei+1);splay(x,c[rot][1]); 
     sz++;c[x][0]=sz; 
     sum[sz]=num;zhi[sz]=num;size[sz]=1;fa[sz]=x;splay(sz,rot); 
} 
long long getsum(int l,int r) 
{ 
     int x=find(rot,l);splay(x,rot); 
     x=find(rot,r+2); splay(x,c[rot][1]); 
     x=c[x][0]; 
     return sum[x]; 
} 
int main() 
{ 
   // freopen("upit.in","r",stdin); 
    //freopen("upit.out","w",stdout); 
    int i,kind,l,r; 
    int num; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++)  scanf("%d",&shu[i+1]); 
    build(1,n+2,0);rot=(n+3)>>1;sz=n+2;              
    for(i=1;i<=m;i++) 
    { 
         scanf("%d",&kind); 
         if(kind==1) 
         { 
                    scanf("%d%d%d",&l,&r,&num);gaishu(l,r,num); 
         } 
         else 
         if(kind==2) 
         { 
                    scanf("%d%d%d",&l,&r,&num);jiadengcha(l,r,num); 
         } 
         else
         if(kind==3) 
         { 
                    scanf("%d%d",&l,&num);charu(l,num); 
         } 
         else
         { 
                    scanf("%d%d",&l,&r);printf("%lld\n",getsum(l,r)); 
         } 
    } 
   // system("pause"); 
    return 0; 
}