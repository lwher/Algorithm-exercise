#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
using namespace std; 
int tot,s; 
int c[5],d[5]; 
long long f[100010]; 
long long ans; 
void dfs(int now,int re,bool mark) 
{ 
    if(re<0)  return; 
    if(now==4) 
    { 
        if(mark) 
        ans-=f[re]; 
        else
        ans+=f[re]; 
        return; 
    } 
    dfs(now+1,re-c[now+1]*(d[now+1]+1),1-mark); 
    dfs(now+1,re,mark); 
} 
int main() 
{ 
      
    scanf("%d%d%d%d%d",&c[1],&c[2],&c[3],&c[4],&tot); 
    int i,j; 
    memset(f,0,sizeof(f)); 
    f[0]=1; 
    for(i=1;i<=4;i++) 
    for(j=c[i];j<=100010;j++) 
    { 
        f[j]+=f[j-c[i]]; 
    } 
      
    for(i=1;i<=tot;i++) 
    { 
        scanf("%d%d%d%d%d",&d[1],&d[2],&d[3],&d[4],&s); 
        ans=0; 
        dfs(0,s,0); 
        cout<<ans<<endl; 
    } 
    //system("pause"); 
    return 0; 
}