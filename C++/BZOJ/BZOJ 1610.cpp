#include<iostream> 
#include<cmath> 
#include<stdio.h> 
#include<algorithm> 
#include<stdlib.h> 
#include<string.h> 
using namespace std; 
int x[300],y[300]; 
int n; 
int fenzi[60008],fenmu[60008]; 
bool hash[60008]; 
int gcd(int a,int b) 
{ 
return b?gcd(b,a%b):a; 
}  
bool haash(int fz,int fm) 
{ 
    int h; 
    h=abs(abs(fz+fm)*23*25*36*3)%60007; 
    while((abs(fenzi[h])!=abs(fz))||(abs(fenmu[h])!=abs(fm))||(fenzi[h]*fenmu[h]!=fz*fm)) 
    { 
    if(hash[h]==0)  
    {hash[h]=1;fenzi[h]=fz;fenmu[h]=fm;return 1;} 
    h++; 
    if(h>=60007)  
    h%=60007; 
    }  
    return 0; 
}  
long long int ans; 
int main() 
{ 
    int fz,fm; 
    int gcc; 
    scanf("%d",&n); 
    int i,j; 
    for(i=1;i<=n;i++) 
    { 
      scanf("%d%d",&x[i],&y[i]); 
    } 
      
    for(i=1;i<=n;i++) 
    { 
    for(j=1;j<=n;j++) 
    { 
        if(i!=j) 
       { 
        if(x[i]==x[j]) {fz=0;fm=1;} 
        else 
        if(y[i]==y[j]) {fz=1;fm=0;} 
        else
        { 
        gcc=gcd(x[i]-x[j],y[i]-y[j]); 
        fz=(x[i]-x[j])/gcc; 
        fm=(y[i]-y[j])/gcc; 
        } 
          
        if(haash(fz,fm)) 
        ans++; 
    } 
     } 
} 
    cout<<ans; 
    //system("pause"); 
    return 0; 
}