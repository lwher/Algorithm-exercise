#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
#define INF 1e9 
using namespace std; 
struct sth 
{ 
    int l,r,you,w; 
}heap[3000010]; 
int sz,n,k,L,R,v[500100],f[500010][20],wz[500010][20],sum[500010]; 
int Log2[500100]; 
long long ans; 
int read() 
{ 
    bool o=0;char ch=getchar(); 
    if(ch=='-')  o=1; 
    while(!(ch>='0' && ch<='9'))  {ch=getchar();if(ch=='-') o=1;} 
    int x=0; 
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();} 
    if(o) x=-x; 
    return x; 
} 
void swap(sth &a,sth &b) 
{ 
    sth t=a;a=b;b=t; 
} 
void heap_Ins(int l,int r,int w,int you) 
{ 
    if(l>r || l<0 || r<0 || l>n || r>n)  return; 
    sz++;int x=sz; 
    heap[sz].l=l;heap[sz].r=r;heap[sz].w=w;heap[sz].you=you; 
    while(heap[x].w>heap[x/2].w) 
    { 
        if(x/2==0)  break; 
        swap(heap[x],heap[x/2]); 
        x/=2; 
    } 
} 
void heap_weihu(int x) 
{ 
    while(1) 
    { 
        if(x*2>sz)  break; 
        if(heap[x].w<heap[x*2].w && (x*2+1>sz || heap[x*2].w>heap[x*2+1].w)) 
        { 
            swap(heap[x],heap[x*2]);x*=2; 
        }else
        if(x*2+1<=sz && heap[x].w<heap[x*2+1].w) 
        { 
            swap(heap[x],heap[x*2+1]);x=x*2+1; 
        } 
        else break; 
    } 
} 
int main() 
{ 
    int i,j,l,r,w,p,you,d; 
    //scanf("%d%d%d%d",&n,&k,&L,&R); 
    n=read();k=read();L=read();R=read(); 
    for(i=1;i<=n;i++)   
    { 
        v[i]=read();sum[i]=sum[i-1]+v[i]; 
        f[i][0]=sum[i];wz[i][0]=i;Log2[i]=log(i)/log(2.00); 
    } 
    for(j=1;j<=19;j++) 
    { 
        for(i=0;i<=n;i++) 
        if(i+(1<<j)-1<=n) 
        { 
            if(f[i][j-1]<f[i+(1<<(j-1))][j-1])  wz[i][j]=wz[i][j-1]; 
            else  wz[i][j]=wz[i+(1<<(j-1))][j-1]; 
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]); 
        }  
        else break; 
    } 
    for(i=1;i<=n;i++) 
    { 
        l=max(i-R,0);r=i-L; 
        if(r<0) continue; 
        p=Log2[r-l+1]; 
        w=sum[i]-min(f[l][p],f[r-(1<<p)+1][p]); 
        heap_Ins(l,r,w,i); 
    } 
    while(k--) 
    { 
        ans+=heap[1].w; 
        l=heap[1].l;r=heap[1].r;you=heap[1].you; 
        heap[1].w=-INF;heap_weihu(1); 
        p=log(r-l+1)/log(2.00); 
        if(f[l][p]<f[r-(1<<p)+1][p]) d=wz[l][p];  else d=wz[r-(1<<p)+1][p]; 
        if(d-1>=l) 
        { 
            p=Log2[d-l]; 
            w=sum[you]-min(f[l][p],f[d-(1<<p)][p]); 
            heap_Ins(l,d-1,w,you); 
        } 
        if(d+1<=r) 
        { 
            p=Log2[r-d]; 
            w=sum[you]-min(f[d+1][p],f[r-(1<<p)+1][p]); 
            heap_Ins(d+1,r,w,you); 
        } 
    } 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}