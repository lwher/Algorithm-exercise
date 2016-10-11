#include<iostream> 
#include<cstdio> 
#include<cstring> 
#include<cstdlib> 
#define INF 0x7fffffff 
using namespace std; 
int n,m; 
int a[50010]; 
int zc[50010],q[50010]; 
int ans; 
int maxx; 
int dp[2][50010]; 
bool check(int now) 
{ 
    int k=0,sum=0; 
    int i; 
    for(i=1;i<=n;i++) 
    { 
        if(k+a[i]>now) 
        {sum++;k=0;} 
        k+=a[i]; 
    } 
    if(sum<=m)  return 1; 
    return 0; 
} 
void maxsize() 
{ 
    int l=maxx,r=100000000,mid; 
    while(l<r) 
    { 
        if(l+1==r)  break; 
        mid=(l+r)/2; 
        if(check(mid)) 
        r=mid; 
        else
        l=mid; 
    } 
    if(check(l))  ans=l; 
    else
    ans=r; 
} 
void solve() 
 { 
    int ans1=0; 
     dp[0][0]=1; 
     for(int i=1;i<=m;i++) 
     { 
         int h=1,t=0,res; 
         q[++t]=0; res=dp[(i-1)&1][0]; 
         for(int j=1;j<=n;j++) 
         { 
             while(h<=t&&zc[j]-zc[q[h]]>ans) 
             { 
                 res-=dp[(i-1)&1][q[h]]; h++; 
                 res%=10007; 
                 if(res<0) res+=10007; 
             } 
             dp[i&1][j]=res; 
             q[++t]=j; res+=dp[(i-1)&1][j]; 
             res%=10007; 
         } 
         for(int j=n-1;j>=1;j--) 
         { 
             if(zc[n]-zc[j]>ans) break; 
             ans1+=dp[i&1][j]; 
             ans1%=10007; 
         } 
         memset(dp[(i-1)&1],0,sizeof dp[(i-1)&1]); 
     } 
     printf("%d\n",ans1); 
 } 
  
int main() 
{ 
    int i; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++) 
    { 
    scanf("%d",&a[i]); 
    zc[i]=zc[i-1]+a[i]; 
    if(maxx<a[i])  maxx=a[i]; 
    } 
    maxsize(); 
    printf("%d ",ans); 
    solve(); 
      
      
    //system("pause"); 
    return 0; 
}