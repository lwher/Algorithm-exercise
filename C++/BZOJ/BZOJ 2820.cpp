#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#define N 10000010 
using namespace std; 
int n,m; 
bool mark[N]; 
int tot,prime[N],u[N],g[N],sum[N]; 
void swap(int &a,int &b) {int t=a;a=b;b=t;} 
void get() 
{ 
    int i,j; 
    u[1]=1;g[1]=0; 
    for(i=2;i<N;i++) 
    { 
        if(!mark[i]) {prime[++tot]=i;u[i]=-1;g[i]=1;} 
        for(j=1;j<=tot;j++) 
        { 
            if(i*prime[j]>=N)  break; 
            mark[i*prime[j]]=1; 
            if(i%prime[j]==0) 
            { 
                u[i*prime[j]]=0;g[i*prime[j]]=u[i];break; 
            } 
            else
            { 
                u[i*prime[j]]=-u[i];g[i*prime[j]]=u[i]-g[i]; 
            } 
        } 
    } 
    for(i=1;i<N;i++)  sum[i]=sum[i-1]+g[i]; 
} 
int main() 
{ 
    int t,i,j; 
    long long ans; 
    get(); 
    scanf("%d",&t); 
    while(t--) 
    { 
        scanf("%d%d",&n,&m); 
        ans=0;if(n>m)  swap(n,m); 
        for(i=1;i<=n;i=j+1) 
        { 
            j=min(n/(n/i),m/(m/i)); 
            ans+=(long long)(sum[j]-sum[i-1])*(n/i)*(m/i); 
        } 
        printf("%lld\n",ans); 
    } 
    //system("pause"); 
    return 0; 
}