#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
using namespace std; 
int k,n,ans=-1; 
int cost[100010],sum[100010],v[20]; 
int f[70010]; 
int getval(int w) 
{ 
    int now=0; 
    for(int i=1;i<=k;i++)  if(!(w & (1<<(i-1))))  now+=v[i]; 
    return now;  
} 
int getnext(int start,int last) 
{ 
    int l=start,r=n,mid; 
    while(l+1<r) 
    { 
        mid=(l+r)>>1; 
        if(sum[mid]-sum[start]<=last)  l=mid; 
        else r=mid;    
    } 
    if(sum[r]-sum[start]<=last) return r; 
    else return l; 
} 
int main() 
{ 
    int i,j,p; 
    scanf("%d%d",&k,&n); 
    for(i=1;i<=k;i++) scanf("%d",&v[i]); 
    for(i=1;i<=n;i++) {scanf("%d",&cost[i]);sum[i]=sum[i-1]+cost[i];} 
    p=(1<<k); 
    for(i=0;i<p;i++) 
    for(j=1;j<=k;j++) 
    if(!(i & (1<<(j-1))))  
    { 
        f[i | (1<<(j-1))]=max(f[i | (1<<(j-1))],getnext(f[i],v[j])); 
    } 
    for(i=0;i<p;i++)  
    if(f[i]==n) 
    { 
        ans=max(ans,getval(i)); 
    } 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
} 

