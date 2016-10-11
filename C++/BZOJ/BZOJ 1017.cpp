#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
using namespace std; 
int n,m,ans; 
int b[60],c[60],need[60],a[60]; 
int to[60][60],g[60][60]; 
int f[60][2010][110],d[60][2010]; 
bool v[60]; 
void dp(int x) 
{ 
    int i,j,k,l; 
    if(!need[x]) 
    { 
        b[x]=min(b[x],m/c[x]); 
        for(i=b[x];i>=0;i--) 
        for(j=0;j<=i;j++) 
        f[x][i*c[x]][j]=a[x]*(i-j); 
        return; 
    } 
    b[x]=1<<30; 
    for(i=1;i<=need[x];i++) 
    { 
        dp(to[x][i]); 
        b[x]=min(b[x],b[to[x][i]]/g[x][i]); 
        c[x]+=c[to[x][i]]*g[x][i]; 
    } 
    b[x]=min(b[x],m/c[x]); 
    memset(d, -0x3f3f3f3f, sizeof(d));   
    d[0][0]=0; 
    for(l=b[x];l>=0;l--) 
    { 
       for(i=1;i<=need[x];i++) 
       for(j=0;j<=m;j++) 
       for(k=0;k<=j;k++) 
       d[i][j]=max(d[i][j],d[i-1][j-k]+f[to[x][i]][k][l*g[x][i]]); 
       for(j=0;j<=m;j++) 
       for(k=0;k<=l;k++) 
       f[x][j][k]=max(f[x][j][k],d[need[x]][j]+a[x]*(l-k)); 
    } 
} 
int main() 
{ 
    int i,j,k; 
    char s,ch; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++) 
    { 
        scanf("%d%c%c",&a[i],&s,&ch); 
        if(ch=='A') 
        { 
            scanf("%d",&need[i]); 
            for(j=1;j<=need[i];j++) 
            { 
                scanf("%d%d",&to[i][j],&g[i][j]); 
                v[to[i][j]]=1; 
            } 
        } 
        else  scanf("%d%d",&c[i],&b[i]); 
    } 
    memset(f, -0x3f3f3f3f, sizeof(f));   
    for(i=1;i<=n;i++) 
    if(!v[i]) 
    { 
        dp(i); 
        for(j=0;j<=m;j++) 
        for(k=b[i];k>=0;k--) 
        ans=max(ans,f[i][j][k]); 
    } 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}