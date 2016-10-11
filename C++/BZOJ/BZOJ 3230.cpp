#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#define N 500010 
using namespace std; 
int n,m,p,q,k,sa[2][N],rk[2][N],v[N],a[N],h[N],aa[N]; 
int L[N],R[N],LENA[N],LENB[N]; 
long long ans[N],sum[N];// L:询问l的右指针反过来  R:询问r的右指针反过来    
int f[N][18]; 
char s[N]; 
long long min(long long a,long long b) 
{ 
    if(a<b) return a; else return b; 
} 
void init() 
{ 
    int i; 
    scanf("%d%d",&n,&m); 
    scanf("%s",s+1); 
    for(i=1;i<=n;i++)  a[i]=(s[i]-'a')+1; 
} 
void Calc_SA(int sa[N],int rk[N],int SA[N],int RK[N]) 
{ 
    int i; 
    for(i=1;i<=n;i++)  v[rk[sa[i]]]=i; 
    for(i=n;i>=1;i--)  if(sa[i]>k)  SA[v[rk[sa[i]-k]]--]=sa[i]-k; 
    for(i=n-k+1;i<=n;i++)  SA[v[rk[i]]--]=i; 
    for(i=1;i<=n;i++)  RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]] || rk[SA[i]+k]!=rk[SA[i-1]+k]);  
} 
void PX_SA() 
{ 
    int i;p=0;q=1;k=1;a[0]=-1; 
    for(i=1;i<=n;i++)  v[a[i]]++; 
    for(i=1;i<=30;i++)  v[i]+=v[i-1]; 
    for(i=1;i<=n;i++)  sa[p][v[a[i]]--]=i; 
    for(i=1;i<=n;i++)  rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(a[sa[p][i]]!=a[sa[p][i-1]]); 
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
            while(a[i+k]==a[j+k])  k++; 
            h[rk[p][i]]=k;  if(k>0) k--; 
        } 
    } 
} 
void swap(int &a,int &b) 
{ 
    int t=a;a=b;b=t; 
} 
long long sqr(long long x) 
{ 
    return x*x; 
} 
int find(long long x) 
{ 
    int l=1,r=n,mid; 
    while(l+1<r) 
    { 
        mid=(l+r)>>1; 
        if(sum[mid]<x)  l=mid; 
        else r=mid; 
    } 
    if(sum[l]>=x) return l; else return r; 
} 
void solve() 
{ 
    int i,j,l,r,C;long long u,b,A,B; 
    for(i=1;i<=n;i++)  sum[i]=sum[i-1]+(n-sa[p][i]+1)-h[i]; 
    for(i=1;i<=n;i++)  f[i][0]=h[i]; 
    for(j=1;j<=17;j++) 
    { 
        k=1<<j; 
        for(i=1;i<=n;i++)  
        { 
            if(i+k-1>n) break; 
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]); 
        } 
    }        
    for(i=1;i<=m;i++) 
    { 
        scanf("%I64d%I64d",&u,&b);  
        if(sum[n]<u || sum[n]<b)  {ans[i]=-1;continue;} 
        l=find(u);r=find(b); 
        A=sum[l]-u+1; 
        A=n-sa[p][l]+1-A+1; 
        B=sum[r]-b+1; 
        B=n-sa[p][r]+1-B+1; 
        L[i]=sa[p][l]+A-1;L[i]=n-L[i]+1;LENA[i]=A; 
        R[i]=sa[p][r]+B-1;R[i]=n-R[i]+1;LENB[i]=B; 
        if(l==r)  ans[i]+=sqr(min(A,B)); 
        else
        { 
            if(l>r) swap(l,r); 
            l++; 
            k=log(r-l+1)/log(2.00); 
            C=min(f[l][k],f[r-(1<<k)+1][k]); 
            ans[i]+=sqr(min(A,min(B,C))); 
        } 
    } 
    for(i=1;i<=n;i++)  aa[i]=a[n-i+1]; 
    for(i=1;i<=n;i++)  a[i]=aa[i]; 
    memset(v,0,sizeof(v)); 
    PX_SA();  
    getheight(); 
    for(i=1;i<=n;i++)  f[i][0]=h[i]; 
    for(j=1;j<=17;j++) 
    { 
        k=1<<j; 
        for(i=1;i<=n;i++)  
        { 
            if(i+k-1>n) break; 
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]); 
        } 
    } 
    for(i=1;i<=m;i++) 
    if(ans[i]!=-1) 
    { 
            l=rk[p][L[i]];r=rk[p][R[i]]; 
            if(l==r)  {ans[i]+=sqr(min(LENA[i],min(LENB[i],n-sa[p][l]+1)));continue;} 
            if(l>r) swap(l,r); 
            l++; 
            k=log(r-l+1)/log(2.00); 
            C=min(f[l][k],f[r-(1<<k)+1][k]); 
            ans[i]+=sqr(min(LENA[i],min(LENB[i],C))); 
    } 
    for(i=1;i<=m;i++)  printf("%I64d\n",ans[i]); 
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

