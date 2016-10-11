#include<iostream> 
#include<cmath> 
#include<cstring> 
#include<cstdio> 
#include<cstdlib> 
using namespace std; 
const int mo=99997; 
int t,k; 
int y,z,p,sz; 
int pre[100001],num[100001],last[100001]; 
long long  qpow(long long  a,long long  b,long long c) 
{ 
    long long now=1; 
    a%=c; 
    while(b>0) 
    { 
        if(b & 1)   
        now=now*a%p; 
        b=b>>1; 
        a=a*a%p; 
    } 
    return now; 
} 
void Ins(int u,int v) 
{ 
    sz++; 
    num[sz]=v;pre[sz]=last[u];last[u]=sz; 
} 
void solve() 
{ 
    memset(last,0,sizeof(last)); 
    sz=0; 
    z%=p; 
    if(z==p) 
    { 
        printf("0\n"); 
        return; 
    } 
    long long tmp=z; 
    int i,lim; 
    lim=sqrt(p); 
    for(i=1;i<=lim+1;i++) 
    { 
        Ins(tmp % mo,tmp); 
        tmp=(tmp * y)%p; 
    } 
    int mi=qpow(y,lim,p); 
    if(mi==0) 
    {printf("Orz, I cannot find x!\n");return;} 
    int x;tmp=1; 
    for(i=1;i<=lim+1;i++) 
    { 
        tmp=(tmp * mi)%p; 
        x=tmp % mo; 
        x=last[x]; 
        while(x>0) 
        { 
            if(num[x]==tmp) 
            { 
                printf("%d\n",i*lim-x+1); 
                return; 
            } 
            x=pre[x]; 
        } 
    } 
    printf("Orz, I cannot find x!\n"); 
} 
int main() 
{ 
    int i; 
    long long ni; 
    scanf("%d%d",&t,&k); 
    for(i=1;i<=t;i++) 
    { 
        scanf("%d%d%d",&y,&z,&p); 
        if(k==1) 
        printf("%d\n",qpow(y,z,p)); 
        else
        if(k==2) 
        { 
           z%=p; 
           ni=qpow(y,p-2,p);     
           ni=(ni*z)%p; 
           if(ni==0 && z!=0) 
           cout<<"Orz, I cannot find x!"<<endl; 
           else
           cout<<ni<<endl; 
        } 
        else
        solve(); 
    } 
        return 0; 
}