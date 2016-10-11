#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<cmath>  
using namespace std;  
int phi(int x)  
{  
    if(x==1) return 1;  
    int m=x,ans=x;  
    int i=2,root=int(sqrt(double(x)));  
    while(i<=root)  
    {  
        if(m%i==0)  
        {  
            ans-=ans/i;  
        while(m%i==0)  
        m/=i;  
        root=int(sqrt(double(m)));  
        }  
        i++;  
    }  
    if(m>1)  ans-=ans/m;  
    return ans;  
}  
int main()  
{  
    int i,n,root;  
    long long ans=0;  
    cin>>n;  
    root=int(sqrt(n));  
    for(i=1;i<=root;i++)  
    {  
        if(n%i==0)  
        {  
        ans+=phi(n/i)*i;  
        if(i*i!=n)   
        ans+=phi(i)*(n/i);  
        }  
    }  
    cout<<ans<<endl;  
    //system("pause");  
    return 0;  
}