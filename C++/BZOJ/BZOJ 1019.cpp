#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
using namespace std; 
int A,B,n,sz; 
int Q[3][31],a[7],b[7]; 
unsigned long long f[31]; 
int solve(int N) 
{ 
    int ans=0,i,j,x,y,lm=-1; 
    Q[0][0]=N; 
    for(i=1;i<=N;i++)   Q[0][i]=N-i+1; 
    Q[1][0]=Q[2][0]=0; 
    while(1) 
    { 
        ans++; 
        for(i=1;i<=6;i++) 
        { 
            x=a[i];y=b[i]; 
            if(x!=lm && Q[x][0]>0 && (Q[y][0]==0 || Q[y][Q[y][0]]>Q[x][Q[x][0]])) 
            { 
                lm=y; 
                Q[y][++Q[y][0]]=Q[x][Q[x][0]--]; 
                break; 
            } 
        } 
        if(Q[1][0]==N || Q[2][0]==N)  break; 
    } 
    return ans; 
} 
int main() 
{ 
    scanf("%d",&n); 
    int i;char ch; 
    getchar();   
    for(i=1;i<=6;i++) 
    { 
        ch=getchar(); 
        while(!(ch>=65 && ch<=90))  ch=getchar(); 
        sz++;a[sz]=ch-'A'; 
        ch=getchar(); 
        b[sz]=ch-'A'; 
    } 
    for(i=1;i<=5;i++)  f[i]=solve(i); 
    A=(f[5]-f[4])/(f[4]-f[3]); 
    B=f[4]-f[3]*A; 
    for(i=6;i<=n;i++)  f[i]=f[i-1]*A+B; 
    cout<<f[n]<<endl; 
    //system("pause"); 
    return 0; 
}