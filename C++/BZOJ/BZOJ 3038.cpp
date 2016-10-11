#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
using namespace std; 
int n,m,fa[100010]; 
long long t[100010],num[100010]; 
int lowbit(int x) 
{ 
    return x & (-x); 
} 
void updata(int x,long long k) 
{ 
    while(x<=n) 
    { 
        t[x]+=k; 
        x+=lowbit(x); 
    } 
} 
long long ask(int x) 
{ 
    long long sum=0; 
    while(x>0) 
    { 
        sum+=t[x]; 
        x-=lowbit(x); 
    } 
    return sum; 
} 
int getfa(int x) 
{ 
    if(fa[x]==0)  return x; 
    else return fa[x]=getfa(fa[x]); 
} 
void swap(int &a,int &b) 
{ 
    int t=a;a=b;b=t; 
} 
int main() 
{ 
    int i,j,l,r,k; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++)  {scanf("%lld",&num[i]);updata(i,num[i]);} 
    scanf("%d",&m); 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d%d",&k,&l,&r); 
        if(l>r)  swap(l,r); 
        if(k==0) 
        { 
            for(j=getfa(l);j<=r;j=getfa(j+1)) 
            { 
                updata(j,-num[j]); 
                num[j]=sqrt(double(num[j])); 
                updata(j,num[j]); 
                if(num[j]==0 || num[j]==1)  fa[j]=j+1; 
            } 
        } 
        else
        { 
            printf("%lld\n",ask(r)-ask(l-1)); 
        } 
    } 
    //system("pause"); 
    return 0; 
} 

?
