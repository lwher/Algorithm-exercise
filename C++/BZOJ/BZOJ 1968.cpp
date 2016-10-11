#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
using namespace std; 
int n,ans; 
int main() 
{ 
    int i; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++)  ans+=n/i; 
    printf("%d\n",ans); 
  //  system("pause"); 
    return 0; 
}