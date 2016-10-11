#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
using namespace std; 
const int maxn=50010; 
int stack[maxn],tot,n,w,h[maxn]; 
int main() 
{ 
     int ans=0;tot=0;stack[0]=0; 
     scanf("%d%d",&n,&w); 
     for (int i=1;i<=n;i++) 
     { 
         int x,y; 
         scanf("%d%d",&x,&y); 
         h[i]=y; 
     } 
     h[n+1]=0; 
     for (int i=1;i<=n+1;i++) 
     { 
         while (h[i]<stack[tot] && tot>0) 
         { 
             tot--; 
             ans++;          
         } 
         if (h[i]!=stack[tot]) 
         { 
             tot++; 
             stack[tot]=h[i]; 
         } 
     } 
     printf("%d\n",ans); 
    // system("pause"); 
     return 0; 
}