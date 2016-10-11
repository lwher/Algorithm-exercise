#include<iostream> 
#include<cstdio> 
#include<cstring> 
#include<cstdlib> 
#include<cmath> 
#include<stack> 
using namespace std; 
#define rep(i,a,b)  for(int i=a,tt=b;i<=tt;++i) 
#define drep(i,a,b) for(int i=a,tt=b;i>=tt;--i) 
const int oo=~0U>>1; 
stack<int> s; 
int n,num[1000010],l[1000010],r[1000010],ans; 
void Work() 
{ 
    scanf("%d",&n); 
    rep(i,1,n)scanf("%d",&num[i]);   
    num[0]=num[n+1]=oo;s.push(0); 
    rep(i,1,n) 
    { 
        while(num[i]>num[s.top()])s.pop(); 
        l[i]=s.top()+1; 
        s.push(i); 
    } 
    while(!s.empty())s.pop(); 
    s.push(n+1); 
    drep(i,n,1) 
    { 
        while(num[i]>num[s.top()])s.pop(); 
        r[i]=s.top()-1;  
        s.push(i); 
    } 
    rep(i,1,n) 
    { 
        if(r[i]-l[i]+1>=num[i]) 
            ans=max(ans,num[i]); 
    } 
    printf("%d\n",ans); 
} 
int main() 
{ 
    Work(); 
 //   system("pause"); 
    return 0; 
}