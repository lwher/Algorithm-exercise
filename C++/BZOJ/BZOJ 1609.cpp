#include<iostream>    
#include<cstring>    
using namespace std;   
int a[100000],best[100000];   
int main() 
{   
    long long  int n;   
    long long int i; 
    cin>>n;   
      
    for (i=1;i<=n;++i) 
         cin>>a[i];   
      
    long long  l=1,ans=0,r=0;   
      
    for (i=1;i<=n;++i) 
    {   
        l=1; 
        r=ans;   
        while (l<=r) 
        {   
              long long  mid=(l+r)/2;   
              if (best[mid]<=a[i]) l=mid+1;   
              else r=mid-1;   
        }   
          
        if (l>ans) 
        {   
                   ans++;   
                   best[ans]=a[i];   
        }   
        else best[l]=a[i];   
    }   
      
    long long Ans=n-ans;  
       
    ans=0;   
      
    memset(best,0,sizeof(best)); 
       
    for (long long i=1;i<=n;++i) 
    {   
        l=1; 
        r=ans;   
        while (l<=r) 
        {   
             long long mid=(l+r)/2;   
             if (best[mid]<a[i]) r=mid-1;   
             else l=mid+1;   
        }   
        if (l>ans) 
        {   
                   ans++;   
                   best[ans]=a[i];   
        }   
        else best[l]=a[i];   
    }   
      
    if (n-ans<Ans) Ans=n-ans; 
        
    cout<<Ans<<endl;   
      
   // system("pause"); 
    return 0;   
} 