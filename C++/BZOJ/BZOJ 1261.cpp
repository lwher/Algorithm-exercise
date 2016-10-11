#include<iostream> 
#include<cstdio> 
#include<cstring> 
using namespace std; 
int f[41][41][41],a[41],n,i,sum; 
double x,y; 
int dp(int l,int r,int dep) 
{ 
    if(l>r) return 0; 
    if(f[l][r][dep]!=0x3f3f3f3f) return f[l][r][dep]; 
    for(int i=l;i<=r;i++) 
    f[l][r][dep]=min(f[l][r][dep],dp(l,i-1,dep+1)+dp(i+1,r,dep+1)+a[i]*dep); 
    return f[l][r][dep]; 
} 
int main() 
{ 
    cin>>n>>x>>y; 
    for(i=1;i<=n;i++) 
    cin>>a[i],sum+=a[i]; 
    memset(f,0x3f,sizeof(f)); 
    printf("%.3f\n",dp(1,n,1)*x/sum+y); 
    system("pause");
    return 0; 
} 
