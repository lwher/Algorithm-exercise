#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
using namespace std; 
long long x1,A,B,p,t,l,r; 
int sz,last[1000010],pre[1000010],num[1000010]; 
long long qpow(long long a,long long b) 
{ 
     long long now=1; 
     while(b>0) 
     { 
         if(b & 1)  now=(now*a)%p; 
         b=b>>1; 
         a=(a*a)%p; 
     } 
     return now; 
} 
void exgcd(long long a,long long b,long long &d,long long &x,long long &y)  
{      
      if(b==0){d=a;x=1;y=0;return;}      
      exgcd(b,a%b,d,y,x);y-=(a/b)*x;  
}  
void work1()  
{      
      t=((t-x1)%p+p)%p;long long d,x,y;exgcd(B,p,d,x,y);      
      printf("%lld\n",(x*t%p+p)%p+1);  
}  
void Ins(int x) 
{ 
     sz++;num[sz]=x;pre[sz]=last[x%1000007];last[x%1000007]=sz; 
} 
void work2() 
{ 
     if(B==0) 
     { 
         r=(t*qpow(x1,p-2))%p;     
     } 
     else
     { 
         r=(t+B*qpow(A-1,p-2))%p; 
         l=(x1+B*qpow(A-1,p-2))%p; 
         r=(r*qpow(l,p-2))%p;      
     } 
     if(r<0) r+=p; 
     int i,x; 
     long long limt=sqrt(p)+1; 
     long long tmp=r; 
     memset(last,0,sizeof(last)); 
     sz=0; 
     for(i=1;i<=limt;i++) 
     { 
         Ins(tmp%p); 
         tmp=(tmp*A)%p; 
     } 
     long long mi=qpow(A,limt-1);tmp=1; 
     for(i=1;i<=limt;i++) 
     { 
         tmp=(tmp*mi)%p; 
         x=tmp%1000007; 
         x=last[x]; 
         while(x>0) 
         { 
             if(num[x]==tmp) 
             { 
                 printf("%lld\n",i*(limt-1)-x+2);return; 
             } 
             x=pre[x]; 
         } 
     } 
     printf("-1\n"); 
} 
int main() 
{ 
    int m; 
    scanf("%d",&m); 
    while(m--) 
    { 
        scanf("%lld%lld%lld%lld%lld",&p,&A,&B,&x1,&t); 
        if(x1==t)  
        { 
            printf("1\n");continue;   
        } 
        if(t>=p) 
        { 
            printf("-1\n");continue; 
        } 
        if(A==0 && B==0)          
        {              
            printf("-1\n");continue;          
        }          
        if(A==0)          
        {              
            if(B==t)printf("2\n");else printf("-1\n");continue;          
        }          
        if(A==1 && B==0)          
        {              
            if(x1==t)printf("1\n");else printf("-1\n");continue;         
        }  
        if(A==1)  work1(); 
        else work2();  
    } 
 //   system("pause"); 
    return 0; 
}