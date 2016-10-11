#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#define INF 0x7fffffff 
using namespace std; 
double dfs(double x,double y,int k) 
{ 
    if(x<y) 
    {double t;t=x;x=y;y=t;} 
    if(k==1)  return x/y; 
    int i; 
    double ans=INF,a,b; 
    for(i=1;i<=k-1;i++) 
    { 
        a=max(dfs(x/double(k)*i,y,i),dfs(x-x/double(k)*i,y,k-i)); 
        b=max(dfs(x,y/double(k)*i,i),dfs(x,y-y/double(k)*i,k-i)); 
        ans=min(ans,min(a,b)); 
    } 
    return ans; 
} 
int main() 
{ 
    int x,y,n; 
    cin>>x>>y>>n; 
    printf("%.6lf\n",dfs(x,y,n)); 
    //system("pause"); 
    return 0; 
}