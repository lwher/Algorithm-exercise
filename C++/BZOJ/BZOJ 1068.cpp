#include<iostream> 
#include<cstdio> 
#include<cstring> 
#include<cstdlib> 
using namespace std; 
char ch[60]; 
int f[55][55][3]; 
bool v[55][55][3]; 
bool match(int l,int len) 
{ 
    int i; 
    for(i=0;i<=len-1;i++) 
    { 
        if(ch[l+i]!=ch[l+i+len]) 
        return 0; 
    } 
    return 1; 
} 
int dp(int l,int r,int t) 
{ 
    int i,len; 
    int &x=f[l][r][t]; 
    if(v[l][r][t])  return f[l][r][t]; 
    v[l][r][t]=1; 
    len=r-l+1; 
    x=len; 
    if(len==1)   
    return 1; 
    if(t==1) 
    { 
    for(i=l;i<r;i++) 
    { 
        x=min(x,dp(l,i,t)+1+dp(i+1,r,t)); 
    } 
    } 
    for(i=l;i<r;i++) 
    { 
        x=min(x,dp(l,i,t)+r-i); 
    } 
    if(len%2==0 && match(l,len/2)) 
    x=min(x,dp(l,l+len/2-1,0)+1); 
    return x; 
} 
int main() 
{ 
    cin>>ch; 
      
    cout<<dp(0,strlen(ch)-1,1)<<endl; 
    //system("pause"); 
    return 0; 
}