#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 500010
#define INF 0x7fffffff
using namespace std;
int n,m,K,p,q;
int a[N];char s[N];
int sa[2][N<<1],rk[2][N<<1],v[N<<1],h[N]; 
int dc[N<<2],fg[N<<2];
void Calc_SA(int sa[N<<1],int rk[N<<1],int SA[N<<1],int RK[N<<1])
{
     int i;
     for(i=1;i<=n;i++)  v[rk[sa[i]]]=i;
     for(i=n;i>=1;i--)  if(sa[i]>K)   SA[v[rk[sa[i]-K]]--]=sa[i]-K; 
     for(i=n-K+1;i<=n;i++)  SA[v[rk[i]]--]=i;
     for(i=1;i<=n;i++)  RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]] || rk[SA[i]+K]!=rk[SA[i-1]+K]);
}
void PX_SA()
{
     int i;p=0;q=1;K=1;a[0]=-1;
     for(i=1;i<=n;i++) v[a[i]]++;
     for(i=1;i<=30;i++)  v[i]+=v[i-1];
     for(i=1;i<=n;i++)  sa[p][v[a[i]]--]=i;
     for(i=1;i<=n;i++)  rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(a[sa[p][i]]!=a[sa[p][i-1]]);
     while(K<n)
     {
         Calc_SA(sa[p],rk[p],sa[q],rk[q]);
         p^=1;q^=1;K=K<<1;
     }
}
void getheight()
{
     int i,j;K=0;
     for(i=1;i<=n;i++)
     {
         if(rk[p][i]==1)  h[rk[p][i]]=0;
         else 
         {
              j=sa[p][rk[p][i]-1];
              while(a[i+K]==a[j+K])  K++;
              h[rk[p][i]]=K;if(K>0) K--;  
         }
     }
}
void init()
{
     int i;
     scanf("%s",s+1);
     n=strlen(s+1);
     for(i=1;i<=n;i++)  a[i]=(s[i]-'a')+1;
}
void downgo(int k,int l,int r)
{
     if(fg[k]>0)
     {
         int x=k+k,y=k+k+1;
         if(fg[x]==0) fg[x]=fg[k]; else fg[x]=min(fg[x],fg[k]);
         if(fg[y]==0) fg[y]=fg[k]; else fg[y]=min(fg[y],fg[k]);
         fg[k]=0;
     }
     if(dc[k]>0)
     {
         int x=k+k,y=k+k+1,mid=(l+r)>>1;
         if(dc[x]==0)  dc[x]=dc[k]; else dc[x]=min(dc[k],dc[x]);
         if(dc[y]==0)  dc[y]=dc[k]+(mid-l+1);  else dc[y]=min(dc[y],dc[k]+(mid-l+1));
         dc[k]=0;
     }
}
void updatafg(int k,int l,int r,int zuo,int you,int x)
{
     if(l>=zuo && r<=you)  {if(fg[k]==0) fg[k]=x; else fg[k]=min(fg[k],x);return;}
     if(fg[k] || dc[k]) downgo(k,l,r);
     int mid=(l+r)>>1;
     if(zuo<=mid)  updatafg(k+k,l,mid,zuo,min(mid,you),x);
     if(you>mid)  updatafg(k+k+1,mid+1,r,max(mid+1,zuo),you,x);
}
void updatadc(int k,int l,int r,int zuo,int you,int x)
{
     if(l>=zuo && r<=you)  {if(dc[k]==0) dc[k]=x; else dc[k]=min(dc[k],x);return;}
     if(fg[k] || dc[k]) downgo(k,l,r);
     int mid=(l+r)>>1;
     if(zuo<=mid)   updatadc(k+k,l,mid,zuo,min(mid,you),x);
     if(you>mid)
     {
        if(zuo<=mid)  updatadc(k+k+1,mid+1,r,mid+1,you,x+mid-zuo+1);
        else  updatadc(k+k+1,mid+1,r,zuo,you,x);
     }  
}
int get(int k,int l,int r,int w)
{
     if(l==r)  
     {
         int tmp=INF;
         if(fg[k]!=0)  tmp=min(fg[k],tmp);
         if(dc[k]!=0)  tmp=min(dc[k],tmp);
         return tmp;
     }
     if(fg[k] || dc[k])  downgo(k,l,r);
     int mid=(l+r)>>1;
     if(w<=mid)  return get(k+k,l,mid,w);
     else return get(k+k+1,mid+1,r,w);
}
void solve()
{
     int i,high,len;     
     PX_SA();
     getheight();      
     for(i=1;i<=n;i++)
     {
         high=0;
         if(i>1)  high=max(high,h[i]);
         if(i<n)  high=max(high,h[i+1]);
         len=n-sa[p][i]+1;
         if(len>high)  
         {
              updatafg(1,1,n,sa[p][i],sa[p][i]+high,high+1);
              updatadc(1,1,n,sa[p][i]+high,n,high+1);
         }
     }     
     for(i=1;i<=n;i++)  printf("%d\n",get(1,1,n,i));
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
