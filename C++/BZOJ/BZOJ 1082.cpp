#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
int a[55],b[1010],c[55],s[1010]; 
int n,m,ans,tot,waste,mid; 
bool Dfs(int now,int p) 
{ 
    if (!now) return true; 
    if (waste>tot-s[mid]) return false; 
    for (int i=p;i<=n;i++) 
    {         
        if (c[i]>=b[now])  
        { 
            c[i]-=b[now]; 
            if (b[now-1]==b[now])//第一个优化  
            { 
                if (Dfs(now-1,i)) return true; 
            } 
            else if (Dfs(now-1,1)) return true; 
            c[i]+=b[now];             
        } 
    } 
    return false; 
} 
int main() 
{ 
    scanf("%d",&n); 
    for (int i=1;i<=n;i++) scanf("%d",&a[i]); 
    scanf("%d",&m); 
    for (int i=1;i<=m;i++) scanf("%d",&b[i]); 
    sort(a+1,a+n+1); 
    sort(b+1,b+m+1); 
    for (int i=1;i<=m;i++) s[i]=s[i-1]+b[i]; 
    for (int i=1;i<=n;i++) tot+=a[i]; 
    int l=0,r=m; 
    ans=0; 
    while (l<=r) 
    { 
        waste=0; 
        memcpy(c,a,sizeof a);  
        mid=(l+r)/ 2; 
        if (Dfs(mid,1)) l=mid+1,ans=mid; 
        else r=mid-1; 
    } 
    printf("%d\n",ans); 
    //system("pause"); 
    return 0; 
}