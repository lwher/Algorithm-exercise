#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#define N 100010 
using namespace std; 
int c[N][2],C[N],l[N],fa[N],size[N],dui[N],father[N]; 
long long ans,sum[N]; 
int n,m; 
void updata(int x) 
{ 
    int y=c[x][0],z=c[x][1]; 
    size[x]=size[y]+size[z]+1; 
    sum[x]=sum[y]+sum[z]+C[x]; 
} 
void rotate(int x) 
{ 
    int y=fa[x],z=fa[y],p,q; 
    if(c[y][0]==x)  p=0; else p=1; 
    q=p^1; 
    if(z) 
    { 
        if(c[z][0]==y)  c[z][0]=x; else c[z][1]=x; 
    } 
    fa[x]=z;fa[y]=x;fa[c[x][q]]=y; 
    c[y][p]=c[x][q];c[x][q]=y; 
    updata(y);updata(x); 
} 
void splay(int x) 
{ 
    int y,z; 
    while(fa[x]) 
    { 
        y=fa[x];z=fa[y]; 
        if(z) 
        { 
            if((c[z][0]==y)^(c[y][0]==x))  rotate(x); 
            else rotate(y); 
        } 
        rotate(x); 
    } 
} 
void Ins(int &x,int last,int p) 
{ 
    if(x==0) 
    { 
        x=p;fa[x]=last;size[p]=1;sum[p]=C[p];c[p][0]=0;c[p][1]=0;splay(p);return; 
    } 
    if(C[p]<C[x])  Ins(c[x][0],x,p); 
    else Ins(c[x][1],x,p); 
} 
int find(int x,int k) 
{ 
    if(sum[x]<=k) return size[x]; 
    int y=c[x][0],z=c[x][1]; 
    if(sum[y]>=k)   return find(y,k); else 
    if(sum[y]+C[x]>=k)  return size[y]+bool(sum[y]+C[x]==k); else 
    if(sum[y]+C[x]<k) return size[y]+1+find(z,k-sum[y]-C[x]); 
} 
void swap(int &a,int &b) 
{ 
    int t=a;a=b;b=t; 
} 
void merge(int x,int y)//  y->x  
{ 
    splay(x);splay(y); 
    if(size[y]>size[x])  swap(x,y); 
    int now,tou=1,wei=1; 
    dui[1]=y; 
    while(tou<=wei) 
    { 
        now=dui[tou];tou++; 
        if(c[now][0])  dui[++wei]=c[now][0]; 
        if(c[now][1])  dui[++wei]=c[now][1]; 
        Ins(x,0,now);x=now; 
    } 
} 
int main() 
{ 
    int i; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++) 
    { 
        scanf("%d%d%d",&father[i],&C[i],&l[i]); 
        size[i]=1;sum[i]=C[i]; 
    }    
    for(i=n;i>=1;i--) 
    { 
        splay(i); 
        ans=max(ans,(long long)(l[i])*find(i,m)); 
        if(father[i])  merge(i,father[i]); 
    } 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}