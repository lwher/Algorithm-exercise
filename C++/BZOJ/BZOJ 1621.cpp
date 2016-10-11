include<iostream> 
#include<cstdio> 
#include<cstdlib> 
using namespace std; 
int f[10000010]; 
bool mark[10000010]; 
int n; 
int k; 
int dfs(int x) 
{ 
    if(x<=10000000 && mark[x])  return f[x]; 
    if(x-k<=0 || ((x-k) & 1))  return 1; 
    else
    { 
        if(x<=10000010)   
        { 
            f[x]=dfs((x-k)/2)+dfs((x-k)/2+k); 
            mark[x]=1; 
            return f[x]; 
        } 
        else
        { 
            return dfs((x-k)/2)+dfs((x-k)/2+k); 
        } 
    }   
} 
int main() 
{ 
    cin>>n>>k; 
    cout<<dfs(n)<<endl; 
    //system("pause"); 
    return 0; 
} 

