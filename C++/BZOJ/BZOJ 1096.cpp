#include<iostream> 
#include<cstdio> 
#include<cmath> 
#include<cstdlib> 
#define N 1000010 
using namespace std; 
int p[N],c[N],x[N]; 
long long sf[N],sp[N]; 
long long f[N]; 
int dui[N]; 
int n; 
long double pd(int k,int j) 
{ 
    return (long double)((f[j]-sf[j]+sp[j]*x[j])-(f[k]-sf[k]+sp[k]*x[k]))/(long double)(sp[j]-sp[k]); 
} 
int main() 
{ 
    int i,j,k,now; 
    int tou,wei; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) 
    { 
        scanf("%d%d%d",&x[i],&p[i],&c[i]); 
        sp[i]=sp[i-1]+p[i]; 
        sf[i]=sf[i-1]+(sp[i-1]*(x[i]-x[i-1])); 
    } 
    f[0]=0; 
    tou=1;wei=1;dui[1]=0; 
    for(i=1;i<=n;i++) 
    { 
        while(tou<wei && pd(dui[tou],dui[tou+1])<x[i])   tou++; 
        now=dui[tou]; 
        f[i]=f[now]+sf[i]-sf[now]-sp[now]*(x[i]-x[now])+c[i]; 
        while(tou<wei && pd(dui[wei-1],dui[wei])>pd(dui[wei],i))  wei--; 
        wei++;dui[wei]=i; 
    } 
    cout<<f[n]<<endl; 
    //system("pause"); 
    return 0; 
}