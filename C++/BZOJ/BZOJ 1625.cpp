#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
using namespace std; 
int n,m; 
int v[3500],p[3500]; 
int f[13000]; 
int main() 
{ 
    cin>>n>>m; 
    int i,j; 
    for(i=1;i<=n;i++)  scanf("%d%d",&v[i],&p[i]); 
      
    for(i=1;i<=n;i++) 
    { 
        for(j=m;j>=0;j--) 
        { 
            if(j+v[i]<=m) 
            f[j+v[i]]=max(f[j+v[i]],f[j]+p[i]);   
        } 
    } 
    int ans=0; 
    for(i=0;i<=m;i++) 
    ans=max(ans,f[i]); 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}