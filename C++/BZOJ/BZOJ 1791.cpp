#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#define N 1000010 
using namespace std; 
int n,fa[N],v[N]; 
long long Fmax[N],fcy[N],fzy[N]; 
int sz,to[N<<1],pre[N<<1],last[N],top,tot; 
int dui[N<<1],w[N<<1]; 
long long dis[N<<1],q[N<<1]; 
bool mark[N],dped[N]; 
long long ans,tmp; 
void Ins(int a,int b) 
{ 
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz; 
} 
void updata(int x,long long num) 
{ 
     if(num>fzy[x])  {fcy[x]=fzy[x];fzy[x]=num;}  else 
     if(num>fcy[x])  fcy[x]=num; 
}  
void treedp(int x) 
{ 
     int tou=1,wei=1,now,i; 
     long long k; 
     dui[1]=x; 
     while(tou<=wei) 
     { 
         now=dui[tou];tou++; 
         i=last[now]; 
         while(i>0) 
         { 
             if(!dped[to[i]]) 
             { 
                 dped[to[i]]=1;mark[to[i]]=1; 
                 dui[++wei]=to[i]; 
             } 
             i=pre[i]; 
         } 
     } 
     for(i=wei;i>=1;i--) 
     { 
         now=dui[i]; 
         Fmax[now]=max(Fmax[now],fzy[now]+fcy[now]); 
         if(i!=1) 
         { 
            Fmax[fa[now]]=max(Fmax[fa[now]],Fmax[now]); 
            k=fzy[now]+v[now];  updata(fa[now],k); 
         } 
     } 
} 
int main() 
{ 
    int p,i,j,l,r; 
    long long k; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++)   
    { 
        scanf("%d%d",&fa[i],&v[i]); 
        Ins(fa[i],i);Ins(i,fa[i]); 
    }                        
    for(p=1;p<=n;p++) 
    if(!mark[p]) 
    { 
         j=p; 
         while(!mark[j])  {mark[j]=1;j=fa[j];} 
         k=j; 
         dped[k]=1; 
         j=fa[j];  while(j!=k) {dped[j]=1;j=fa[j];} 
         treedp(k); 
         j=fa[j];  while(j!=k) {treedp(j);j=fa[j];} 
         top=1;tmp=Fmax[k];dui[1]=k;dis[1]=v[k]; 
         j=fa[j];  while(j!=k) {dui[++top]=j;if(Fmax[j]>tmp) tmp=Fmax[j];dis[top]=v[j];j=fa[j];} 
         tot=top;          
         k=dis[top]; 
         for(i=top;i>=2;i--) dis[i]=dis[i-1];   
         dis[1]=k;          
         for(i=1;i<=top;i++)  {dui[++tot]=dui[i];dis[tot]=dis[i];} 
         for(i=2;i<=tot;i++)  dis[i]+=dis[i-1]; 
         l=1;r=1;q[1]=fzy[dui[1]]-dis[1];w[1]=1; 
         for(i=2;i<=tot;i++) 
         { 
             while(l<r && i-w[l]>=top)  l++; 
             if(fzy[dui[i]]+dis[i]+q[l]>tmp) tmp=fzy[dui[i]]+dis[i]+q[l]; 
             k=fzy[dui[i]]-dis[i]; 
             while(l<=r && q[r]<k)  r--; 
             q[++r]=k;w[r]=i; 
         } 
         ans+=tmp; 
    } 
    cout<<ans<<endl; 
 //   system("pause"); 
    return 0; 
}