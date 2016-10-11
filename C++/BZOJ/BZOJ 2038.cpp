#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
int n,m,sz; 
struct sth 
{ 
    long long a,b; 
    int l,r,id; 
}q[50010],ans[50010]; 
long long sum[50010]; 
int a[50010]; 
inline bool comp(sth a,sth b) 
{ 
    if(a.l/sz!=b.l/sz)   return a.l/sz<b.l/sz; 
    return a.r<b.r; 
} 
long long gcd(long long a,long long b) 
{ 
    if(b==0) return a;  return gcd(b,a%b); 
} 
void solve() 
{ 
    int i,L=1,R=0; 
    long long tmp=0; 
    for(i=1;i<=m;i++) 
    { 
        while(R>q[i].r)  
        { 
            tmp-=sum[a[R]]*sum[a[R]]; 
            sum[a[R]]--; 
            tmp+=sum[a[R]]*sum[a[R]]; 
            R--; 
        } 
        while(R<q[i].r)  
        { 
            R++; 
            tmp-=sum[a[R]]*sum[a[R]]; 
            sum[a[R]]++; 
            tmp+=sum[a[R]]*sum[a[R]]; 
        } 
        while(L<q[i].l)  
        { 
            tmp-=sum[a[L]]*sum[a[L]]; 
            sum[a[L]]--; 
            tmp+=sum[a[L]]*sum[a[L]]; 
            L++; 
        } 
        while(L>q[i].l)  
        { 
            L--; 
            tmp-=sum[a[L]]*sum[a[L]]; 
            sum[a[L]]++; 
            tmp+=sum[a[L]]*sum[a[L]]; 
        } 
        ans[q[i].id].a=tmp-(R-L+1); 
        ans[q[i].id].b=(long long)((R-L))*(R-L+1); 
        long long d=gcd(ans[q[i].id].a,ans[q[i].id].b); 
        ans[q[i].id].a/=d; 
        ans[q[i].id].b/=d; 
    }    
} 
int main() 
{ 
    int i; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++)  scanf("%d",&a[i]); 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d",&q[i].l,&q[i].r); 
        q[i].id=i; 
    } 
    sz=(int)sqrt(n); 
    sort(q+1,q+1+m,comp); 
    solve(); 
    for(i=1;i<=m;i++)  printf("%lld/%lld\n",ans[i].a,ans[i].b); 
    //system("pause"); 
    return 0; 
}