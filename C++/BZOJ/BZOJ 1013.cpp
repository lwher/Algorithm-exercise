#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
using namespace std; 
double f[15][15]; 
double shizi[15]; 
int n; 
double Sqr(double a) 
{ 
    return a*a; 
} 
void init() 
{ 
    int i,j; 
    double k; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) 
    {scanf("%lf",&shizi[i]);} 
    for(i=1;i<=n;i++) 
    for(j=1;j<=n;j++) 
    { 
    scanf("%lf",&k); 
    f[i][j]=2*(shizi[j]-k);   
    f[i][n+1]+=Sqr(shizi[j])-Sqr(k);   
    } 
} 
void solve() 
{ 
    int i,j,k; 
    for(i=1;i<=n;i++) 
    for(j=1;j<=n;j++) 
    { 
        if(j==i || f[j][i]==0) continue; 
        for(k=1;k<=n+1;k++) 
        { 
            if(k!=i) 
            { 
                f[j][k]*=f[i][i]/f[j][i]; 
                f[j][k]-=f[i][k]; 
            } 
        } 
        f[j][i]=0; 
    } 
    for(i=1;i<=n;i++) 
    f[i][n+1]/=f[i][i]; 
} 
int main() 
{ 
    int i,j; 
    init(); 
    solve(); 
    for(i=1;i<=n-1;i++) 
    printf("%.3lf ",f[i][n+1]); 
    printf("%.3lf\n",f[n][n+1]); 
    //system("pause"); 
    return 0; 
}