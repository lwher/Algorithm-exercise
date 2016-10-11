#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
using namespace std; 
int n,a[51],num[10]; 
int tot,zs[51],f[51]; 
bool check(int x) 
{ 
    for(int i=2;i*i<=x;i++)  if(x%i==0) return 0;  
    return 1; 
} 
void getprime() 
{ 
    for(int i=2;i<=50;i++)  if(check(i))  zs[++tot]=i; 
} 
long long cul(int u) 
{ 
    int i,j,t,k;long long ans=1; 
    memset(f,0,sizeof(f)); 
    for(i=2;i<=u;i++) 
    { 
        t=i; for(j=1;j<=tot && t!=1;j++)  while(t%zs[j]==0)  f[j]++,t/=zs[j]; 
    } 
    for(k=0;k<=9;k++)  for(i=2;i<=num[k];i++) 
    { 
        t=i; for(j=1;j<=tot && t!=1;j++)  while(t%zs[j]==0)  f[j]--,t/=zs[j]; 
    } 
    for(k=1;k<=tot;k++)  for(j=1;j<=f[k];j++)  ans*=zs[k]; 
    return ans; 
} 
long long calc(int u) 
{ 
    if(u==0)  return 1; 
    long long ans=0; 
    for(int i=0;i<a[n-u+1];i++) 
    if(num[i]>0) 
    { 
        num[i]--; 
        ans+=cul(u-1); 
        num[i]++; 
    } 
    num[a[n-u+1]]--; 
    ans+=calc(u-1); 
    return ans; 
} 
int main() 
{ 
    char ch=getchar(); 
    while(ch>='0' && ch<='9') 
    { 
        a[++n]=ch-'0';num[a[n]]++;ch=getchar(); 
    }    
    getprime();  
    cout<<calc(n)-1<<endl; 
    //system("pause"); 
    return 0; 
}