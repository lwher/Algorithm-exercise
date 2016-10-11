#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int n,K,h[100010],root;
int sz,size[100010],num[100010],w[100010],ls[100010],rs[100010],rnd[100010];
long long sum[100010],ans,L,R,LS,RS;
void updata(int x)
{
     int y=ls[x],z=rs[x];
     size[x]=size[y]+size[z]+w[x];
     sum[x]=sum[z]+sum[y]+(long long)(w[x])*num[x];
}
inline void rturn(int &t)
{
     int k=ls[t];
     ls[t]=rs[k];rs[k]=t;
     updata(t);updata(k);
     t=k;
}
inline void lturn(int &t)
{
     int k=rs[t];
     rs[t]=ls[k];ls[k]=t;
     updata(t);updata(k);
     t=k;
}
void Ins(int &W,int x)
{
     if(!W)
     {
         W=++sz;rnd[sz]=rand();
         num[sz]=sum[sz]=x;
         w[sz]=size[sz]=1;
         ls[sz]=rs[sz]=0;;
         return;
     }
     if(num[W]==x)  
     {
         w[W]++;size[W]++;sum[W]+=x;
         return;
     } else
     if(num[W]>x) 
     {
         Ins(ls[W],x);
         if(rnd[ls[W]]<rnd[W])  rturn(W);
     }
     else
     {
         Ins(rs[W],x);
         if(rnd[rs[W]]<rnd[W])  lturn(W);
     }
     updata(W);
}
void del(int &W,int x)
{
     if(num[W]==x)
     {
         if(w[W]>1) w[W]--;  else
         if(ls[W]*rs[W]==0) W=ls[W]+rs[W];  else
         if(rnd[ls[W]]<rnd[rs[W]]){rturn(W);del(rs[W],x);}
         else {lturn(W);del(ls[W],x);}
     }  else
     if(num[W]<x) del(rs[W],x);
     else del(ls[W],x);
     updata(W);
}
int find(int x,int k)
{
    if(size[ls[x]]>=k) 
    {
       R+=sum[rs[x]]+(long long)(w[x])*num[x];
       RS+=size[rs[x]]+w[x];
       return find(ls[x],k); 
    }else
    if(size[ls[x]]+w[x]>=k)  
    {
       LS+=size[ls[x]];RS+=size[rs[x]];
       L+=sum[ls[x]];R+=sum[rs[x]]; 
       return x;
    }  
    else
    {
       LS+=size[ls[x]]+w[x];
       L+=sum[ls[x]]+(long long)(w[x])*num[x];
       return find(rs[x],k-size[ls[x]]-w[x]);
    }
}
int main()
{
    int i,k;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++)  scanf("%d",&h[i]);
    for(i=1;i<=K;i++)  Ins(root,h[i]);    
    L=0;R=0;LS=0;RS=0;
    k=find(root,K/2+1);
    ans=LS*num[k]-L+R-RS*num[k];
    for(i=K+1;i<=n;i++)
    {
        Ins(root,h[i]);
        del(root,h[i-K]);
        L=0;R=0;LS=0;RS=0;
        k=find(root,K/2+1);
        ans=min(ans,LS*num[k]-L+R-RS*num[k]);
    }
    cout<<ans<<endl;
    return 0;
}