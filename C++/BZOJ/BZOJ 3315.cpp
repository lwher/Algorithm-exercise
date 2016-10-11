#include<iostream> 
#include<cstdio> 
#include<cmath> 
#include<cstdlib> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
struct sth 
{ 
    int x,p; 
}d[1010]; 
int n,f[1010][1010],ans; 
inline bool cmp1(sth a,sth b) 
{ 
    return a.x<b.x; 
} 
inline bool cmp2(sth a,sth b) 
{ 
    return a.x>b.x; 
} 
int main() 
{ 
    int i,j,k,T=2,val; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) scanf("%d%d",&d[i].x,&d[i].p); 
    sort(d+1,d+1+n,cmp1); 
    while(T--) 
    { 
        memset(f,0,sizeof(f)); 
        for(i=1;i<=n;i++)  f[i][i]=d[i].p; 
        for(j=1;j<=n;j++) 
        { 
            k=j;val=f[j][j]; 
            for(i=j+1;i<=n;i++) 
            { 
                while(k>0 && abs(d[i].x-d[j].x)>=abs(d[j].x-d[k].x)) 
                { 
                    val=max(val,f[j][k]); 
                    k--; 
                } 
                f[i][j]=val+d[i].p; 
            } 
        } 
        for(i=1;i<=n;i++)  for(j=1;j<=i;j++)  ans=max(ans,f[i][j]); 
        sort(d+1,d+1+n,cmp2); 
    } 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}