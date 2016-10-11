#include<iostream> 
#include<cstdio> 
#include<cmath> 
using namespace std; 
int n,t; 
int num[60]; 
int main() 
{ 
    int i,ji,ans; 
    bool o=0; 
    scanf("%d",&t); 
    while(t--) 
    { 
        o=0;ji=0;ans=0; 
        scanf("%d",&n); 
        for(i=1;i<=n;i++) 
        { 
           scanf("%d",&num[i]); 
           if(num[i]>1) 
           o=1; 
           if(num[i]==1) 
           ji++; 
           ans^=num[i]; 
        } 
        if(!o) 
        { 
            if(ji%2==1) 
            cout<<"Brother"<<endl; 
            else
            cout<<"John"<<endl; 
        } 
        else
        { 
            if(ans) 
            cout<<"John"<<endl; 
            else
            cout<<"Brother"<<endl; 
        } 
          
    } 
    //system("pause"); 
    return 0; 
} 

