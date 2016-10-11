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
    int l,r; 
}dd[100010],heap[100010]; 
int num[200010],shu[200010]; 
int L[100010],R[100010]; 
int T,n,m,ans,sz,tot,top; 
int t[1000010],mark[1000010]; 
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
    int l=1,r=top,mid; 
    while(l+1<r) 
    { 
        mid=(l+r)>>1; 
        if(num[mid]==x)  return mid; 
        if(num[mid]>x)  r=mid; 
        else l=mid; 
    } 
    if(num[r]==x)  return r; return l; 
} 
int downgo(int k) 
{ 
    mark[k+k]+=mark[k];mark[k+k+1]+=mark[k]; 
    t[k+k]+=mark[k];t[k+k+1]+=mark[k]; 
    mark[k]=0; 
} 
void updata(int k,int l,int r,int zuo,int you,int shuzi) 
{ 
    if(l>=zuo && r<=you) {t[k]+=shuzi;mark[k]+=shuzi;return;} 
    int mid=(l+r)>>1; 
    if(mark[k]) downgo(k); 
    if(zuo<=mid)  updata(k+k,l,mid,zuo,you,shuzi); 
    if(you>mid)  updata(k+k+1,mid+1,r,zuo,you,shuzi); 
    t[k]=min(t[k+k],t[k+k+1]); 
} 
int getmin(int k,int l,int r,int zuo,int you) 
{ 
    if(l>r || l>you || r<zuo)  return INF; 
    if(l>=zuo && r<=you)  return t[k]; 
    if(mark[k])  downgo(k); 
    int mid=(l+r)>>1; 
    return min(getmin(k+k,l,mid,zuo,you),getmin(k+k+1,mid+1,r,zuo,you)); 
} 
void swap(sth &a,sth &b) 
{ 
    sth t=a;a=b;b=t; 
} 
void Ins_heap(sth x) 
{ 
    sz++;heap[sz]=x; 
    int now=sz; 
    while(heap[now/2].r<heap[now].r) 
    { 
        if(now==1)  break; 
        swap(heap[now/2],heap[now]); 
        now=now>>1; 
    } 
} 
void get_heap(int x) 
{ 
    while(1) 
    { 
        if(x*2>sz)  break; 
        if(heap[x].r<heap[x+x].r && (x*2==sz || heap[x+x].r>heap[x+x+1].r))   
        {swap(heap[x],heap[x+x]);x=x<<1;}  else
        if(x*2+1<=sz && heap[x].r<heap[x+x+1].r)   
        {swap(heap[x],heap[x+x+1]);x=x+x+1;}  else break; 
    } 
} 
inline bool comp(sth a,sth b) 
{ 
    return a.l<b.l; 
} 
int main() 
{ 
    int i,k; 
    //scanf("%d",&T); 
    T=read(); 
    while(T--) 
    { 
        tot=0;sz=0;top=0; 
        //scanf("%d%d",&n,&m); 
        n=read();m=read(); 
        for(i=1;i<=n;i++) 
        { 
            //scanf("%d%d",&L[i],&R[i]); 
            L[i]=read();R[i]=read(); 
            shu[++tot]=L[i];shu[++tot]=R[i];     
        } 
        sort(shu+1,shu+1+tot); 
        shu[0]=-1; 
        for(i=1;i<=tot;i++) if(shu[i-1]!=shu[i]) num[++top]=shu[i];   
        for(i=1;i<=n;i++)  dd[i].l=find(L[i]),dd[i].r=find(R[i]); 
        sort(dd+1,dd+1+n,comp); 
        memset(mark,0,sizeof(mark)); 
        memset(t,0,sizeof(t)); 
        for(i=1;i<=top;i++)  updata(1,1,top,i,i,m); 
        ans=0; 
        heap[1].r=-1;        
        for(i=1;i<=n;i++) 
        { 
            k=getmin(1,1,top,dd[i].l,dd[i].r); 
            if(k>0)  {ans++;updata(1,1,top,dd[i].l,dd[i].r,-1);Ins_heap(dd[i]);} 
            else
            { 
                if(heap[1].r>dd[i].r)   
                { 
                    updata(1,1,top,heap[1].l,heap[1].r,1); 
                    heap[1].r=-1; get_heap(1); 
                    Ins_heap(dd[i]); 
                    updata(1,1,top,dd[i].l,dd[i].r,-1); 
                } 
            } 
        } 
          
        printf("%d\n",ans);      
    } 
        return 0; 
}