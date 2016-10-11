#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#define N 200010 
using namespace std; 
long long d[N],heap[N*3],ans; 
int n,k,zhi[N],bh[N*3]; 
int sz,to[N],pre[N],last[N],hsz; 
int shuru()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void swap(long long &a,long long &b) 
{ 
     long long t=a;a=b;b=t; 
} 
void Ins(int a,int b) 
{ 
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz; 
} 
void init() 
{ 
     int i,a,b; 
     n=shuru();k=shuru();//scanf("%d%d",&n,&k); 
     for(i=1;i<=n;i++) zhi[i]=shuru(); //scanf("%d",&zhi[i]); 
     for(i=1;i<n;i++)  {a=shuru();b=shuru();Ins(a,b);}//{scanf("%d%d",&a,&b);Ins(a,b);} 
} 
void getd(int x) 
{ 
     int i=last[x]; 
     d[x]=zhi[x]; 
     while(i>0) 
     { 
         getd(to[i]); 
         if(d[to[i]]+zhi[x]>d[x])  d[x]=zhi[x]+d[to[i]]; 
         i=pre[i]; 
     } 
} 
void charu(int hao) 
{ 
     hsz++;heap[hsz]=d[hao];bh[hsz]=hao; 
     int now=hsz; 
     while(heap[now/2]<heap[now]) 
     { 
        if(now==1)  break; 
        swap(heap[now],heap[now/2]);swap(bh[now],bh[now/2]); 
        now=now>>1; 
     } 
} 
void weihu(int x) 
{ 
     while(heap[x]<heap[x*2] || heap[x]<heap[x*2+1]) 
     { 
          if(heap[x]<heap[x*2] && heap[x*2]>=heap[x*2+1]) 
          { 
               swap(heap[x],heap[x*2]);swap(bh[x],bh[x*2]);x=x<<1; 
          } 
          else
          { 
              swap(heap[x],heap[x*2+1]);swap(bh[x],bh[x*2+1]);x=x+x+1; 
          } 
     } 
} 
void shanchu(int x) 
{ 
     int i=last[x],j=0; 
     while(i>0) 
     { 
         if(d[to[i]]==d[x]-zhi[x]) 
         {j=to[i];break;} 
         i=pre[i]; 
     } 
     i=last[x]; 
     while(i>0) 
     { 
         if(to[i]!=j)  charu(to[i]); 
         i=pre[i]; 
     } 
     if(j) shanchu(j); 
} 
int main() 
{ 
    memset(heap,-1,sizeof(heap)); 
    init(); 
    getd(1); 
    charu(1); 
    for(int i=1;i<=k;i++) 
    { 
        ans+=heap[1];int dian=bh[1]; 
        heap[1]=-1;weihu(1); 
        shanchu(dian); 
    } 
    cout<<ans<<endl; 
    system("pause"); 
    return 0; 
}
