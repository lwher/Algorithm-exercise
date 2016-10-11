#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define N 3001000
using namespace std;
int n,tot,p,q,k;
char ch[N],s[N];
int v[N],sa[2][N],rk[2][N],pos[N],h[N],f[1001000][21],LEN[N];
void init()
{
     int i,j,len;
     scanf("%d",&n);
     for(i=1;i<=n;i++)
     {
         scanf("%s",ch+1);
         len=strlen(ch+1);LEN[i]=len;
         pos[i]=tot+1;
         for(j=1;j<=len;j++)   s[++tot]=ch[j];
         s[++tot]='#';
     }
}
void Calc_SA(int sa[N],int rk[N],int SA[N],int RK[N])
{
     int i;
     for(i=1;i<=tot;i++)  v[rk[sa[i]]]=i;
     for(i=tot;i>=1;i--)  if(sa[i]>k)  SA[v[rk[sa[i]-k]]--]=sa[i]-k;
     for(i=tot-k+1;i<=tot;i++)  SA[v[rk[i]]--]=i;
     for(i=1;i<=tot;i++)  RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]] || rk[SA[i]+k]!=rk[SA[i-1]+k]);
}
void PX_SA()
{
     int i;s[0]='*';p=0;q=1;k=1;
     for(i=1;i<=tot;i++)  v[int(s[i])]++;
     for(i=1;i<=333;i++)  v[i]+=v[i-1];
     for(i=1;i<=tot;i++)  sa[p][v[int(s[i])]--]=i;
     for(i=1;i<=tot;i++)  rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(s[sa[p][i-1]]!=s[sa[p][i]]);
     while(k<tot)
     {
         Calc_SA(sa[p],rk[p],sa[q],rk[q]);
         p^=1;q^=1;k=k<<1;
     }
}
void getheight()
{
     int i=1,j;k=0;
     for(i=1;i<=tot;i++)
     {
         if(rk[p][i]==1)  h[rk[p][i]]=0;
         else
         {
             j=sa[p][rk[p][i]-1];
             while(s[i+k]==s[j+k]) k++;
             h[rk[p][i]]=k; if(k>0) k--;
         }
     }
}
int findpre(int x,int len)
{
    int l,r,mid,tmp;
    if(x==1) return 1;
    if(h[x]<len)  return x;
    l=1;r=x-1;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        k=log(x-mid)/log(2.00);
        tmp=min(f[mid+1][k],f[x-(1<<k)+1][k]);
        if(tmp>=len)  r=mid;
        else l=mid;
    }
    k=log(x-l)/log(2.00);
    tmp=min(f[l+1][k],f[x-(1<<k)+1][k]);
    if(tmp>=len) return l; else return r;
}
int findnext(int x,int len)
{
    int l,r,mid,tmp;
    if(x==tot) return x;
    if(h[x+1]<len)  return x;
    l=x+1;r=tot;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        k=log(mid-x)/log(2.00);
        tmp=min(f[x+1][k],f[mid-(1<<k)+1][k]);
        if(tmp>=len)  l=mid;
        else r=mid;
    }
    k=log(r-x)/log(2.00);
    tmp=min(f[x+1][k],f[r-(1<<k)+1][k]);
    if(tmp>=len) return r; else return l;
}
void solve()
{
     int i,j,a,b;
     for(i=1;i<=tot;i++)  f[i][0]=h[i];
     for(i=1;i<=20;i++)
     {
         for(j=1;j<=tot;j++)
         {
             if(j+(1<<i)-1>tot)  break;
             f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
         }
     }
     for(i=1;i<=n;i++)
     {
         j=pos[i];j=rk[p][j];
         a=findpre(j,LEN[i]);b=findnext(j,LEN[i]);
         printf("%d\n",b-a+1);
     }
}
int main()
{
    init();
    PX_SA();
    getheight();
    solve();
    system("pause");
    return 0;
}
