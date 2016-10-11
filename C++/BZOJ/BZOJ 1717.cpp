#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,K,A[20010],shu[20010],top,num[20010],tot;
int a[20010],v[50010],sa[2][50010],rk[2][50010],h[20010];
int k,p,q;
int find(int x)
{
    int l=1,r=tot,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(num[mid]==x)  return mid;
        if(num[mid]>x) r=mid;
        else l=mid; 
    }
    if(num[r]==x)  return r; return l;
}
void Calc_SA(int sa[50010],int rk[50010],int SA[50010],int RK[50010])
{
     int i;
     for(i=1;i<=n;i++) v[rk[sa[i]]]=i;
     for(i=n;i>=1;i--)  if(sa[i]>k)  SA[v[rk[sa[i]-k]]--]=sa[i]-k;
     for(i=n-k+1;i<=n;i++)  SA[v[rk[i]]--]=i;
     for(i=1;i<=n;i++)  RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]] || rk[SA[i]+k]!=rk[SA[i-1]+k]);
}
void PX_SA()
{
     int i;p=0;q=1;k=1;a[0]=-1;
     for(i=1;i<=n;i++)  v[a[i]]++;
     for(i=1;i<=n;i++)  v[i]+=v[i-1];
     for(i=1;i<=n;i++)  sa[p][v[a[i]]--]=i;
     for(i=1;i<=n;i++)  rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(a[sa[p][i-1]]!=a[sa[p][i]]);
     while(k<n)
     {
         Calc_SA(sa[p],rk[p],sa[q],rk[q]);
         p^=1;q^=1;k=k<<1;
     }
}
void getheight()
{
     int i,j;k=0;
     for(i=1;i<=n;i++)
     {
         if(rk[p][i]==1)  h[rk[p][i]]=0;
         else
         {
             j=sa[p][rk[p][i]-1];
             while(a[i+k]==a[j+k]) k++;
             h[rk[p][i]]=k; if(k>0) k--; 
         }
     }
}
bool check(int mid)
{
     int i,now;
     for(i=1;i<=n;i++)
     {
         if(h[i]>=mid)  {now++;if(now==K-1) return 1;}
         else now=0;
     }
     return 0;
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++)  
    {
       scanf("%d",&A[i]);
       shu[++top]=A[i];
    }
    sort(shu+1,shu+1+n);
    num[++tot]=shu[1];
    for(i=2;i<=top;i++)  if(shu[i]!=shu[i-1])  num[++tot]=shu[i];
    for(i=1;i<=n;i++)  a[i]=find(A[i]);
    PX_SA();
    getheight();
    int l=0,r=n,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(check(mid))  l=mid;
        else r=mid;
    }
    if(check(r))  printf("%d\n",r); else printf("%d\n",l);
    system("pause");
    return 0;
}
