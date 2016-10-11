#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
using namespace std; 
const int mo=10000; 
int ji=0,ou=1; 
int sum=1; 
int k; 
int zs[1010],tot; 
int qpow(int a,int b) 
{ 
    int now=1; 
    a%=mo; 
    while(b>0) 
    { 
        if(b & 1)  now=(now*a)%mo; 
        b=b>>1; 
        a=(a*a)%mo; 
    } 
    return now; 
} 
int main() 
{ 
    int a,b,i; 
    scanf("%d",&k); 
    for(i=1;i<=k;i++) 
    { 
        scanf("%d%d",&a,&b); 
        sum=(sum*qpow(a,b))%mo; 
        if(a!=2)  {tot++;zs[tot]=a;} 
    } 
    sum--; 
    for(i=1;i<=tot;i++) 
    { 
        int tmp=ji; 
        ji+=(ou*(zs[i]-1))%mo; 
        ji%=mo; 
        ou+=(tmp*(zs[i]-1))%mo; 
        ou%=mo; 
    } 
    ou--;ou%=mo;if(ou<0) ou+=mo; 
    sum-=ou+ji; 
    sum%=mo;if(sum<0)  sum+=mo; 
    cout<<ou<<endl<<ji<<endl<<sum<<endl; 
    //system("pause"); 
    return 0; 
}