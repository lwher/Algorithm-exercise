#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[20],n,num[20];
long long f[20];
long long qpow(long long a,long long b)
{
     long long res=1;
     while(b>0)
     {
         if(b & 1)  res*=a;
         a*=a;
         b=b>>1;
     }
     return res;
}
long long calc(long long x)
{
     int i;n=0;
     long long j;
     if(x==-1) return 0;
     long long res=0;
     while(x>0)
     {
         a[++n]=x%10;x/=10;
     }
     for(i=1;i<n;i++) res+=f[i];
     for(i=1;i<=n;i++) num[i]=a[n-i+1];
     for(i=1;i<=n;i++)
     {
          if(i==1)
          {
               j=num[i]-1;
               if(j!=0)
               { 
                   if(n==1)  res+=j;   else
                   res+=j*9*qpow(8,n-2);
                   }
          }
          else
          {
              j=num[i];
              if(j!=0) 
              {
                  if(num[i-1]<num[i])  j--;
                  if(i>2 && num[i-2]<num[i]) j--;
                  res+=j*qpow(8,n-i);
              }
          }
          if((i>=2 && num[i]==num[i-1]) || (i>=3 && num[i]==num[i-2]))  break;
          if(i==n)  res++;
     }
     return res+1;
}
int main()
{
    int i;
    long long l,r;
    f[1]=9;f[2]=81;
    for(i=3;i<=18;i++)  f[i]=f[i-1]*8;    
    cin>>l>>r;        
    cout<<calc(r)-calc(l-1)<<endl;
    //system("pause");
    return 0;
}
