#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
using namespace std; 
int d[16],n,k,sz; 
double p[16]; 
double f[110][35000]; 
int main() 
{ 
    int i,j,z; 
    scanf("%d%d",&k,&n); 
    for(i=1;i<=n;i++) 
    { 
        scanf("%lf",&p[i]); 
        while(scanf("%d",&z) && z) 
        { 
            d[i]|=(1<<(z-1)); 
        } 
    } 
    sz=1<<n; 
    for(i=k;i>=1;i--) 
    for(j=0;j<sz;j++) 
    { 
        for(z=1;z<=n;z++) 
        { 
            if((j & d[z])==d[z])  f[i][j]+=max(f[i+1][j],f[i+1][j | (1<<(z-1))]+p[z]); 
            else f[i][j]+=f[i+1][j]; 
        } 
        f[i][j]/=1.0*n;   
    } 
    printf("%.6lf\n",f[1][0]); 
    //system("pause"); 
    return  0; 
}