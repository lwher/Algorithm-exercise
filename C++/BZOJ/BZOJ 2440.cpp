#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
using namespace std; 
int tot,prime[55001],u[55001]; 
bool mark[55001]; 
void getprime() 
{ 
     int i,j; 
     u[1]=1; 
     for(i=2;i<=55000;i++) 
     { 
          if(!mark[i])  {prime[++tot]=i;u[i]=1;} 
          for(j=1;j<=tot;j++) 
          { 
              if(i*prime[j]>55000)  break; 
              mark[i*prime[j]]=1; 
              if(i%prime[j]==0) {u[i*prime[j]]=0;break;} 
              else  u[i*prime[j]]=u[i]*(-1); 
          } 
     } 
} 
long long check(long long x) 
{ 
     int i,k=sqrt(x);long long res=x; 
     for(i=2;i<=k;i++)  res-=u[i]*(x/(i*i)); 
     return res; 
} 
long long getans(long long x) 
{ 
     long long l=0,r=x*2,mid; 
     while(l+1<r) 
     { 
         mid=(l+r)>>1; 
         if(check(mid)>=x)  r=mid; 
         else l=mid; 
     } 
     if(check(l)>=x) return l; return r; 
} 
int main() 
{ 
    getprime(); 
    int t,a; 
    scanf("%d",&t); 
    while(t--) 
    {        
        scanf("%d",&a);         
        printf("%lld\n",getans((long long)(a))); 
    } 
   // system("pause"); 
    return 0; 
}
