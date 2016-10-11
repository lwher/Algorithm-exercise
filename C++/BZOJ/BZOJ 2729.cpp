#include<iostream> 
#include<cstring> 
#include<cstdio> 
using namespace std; 
int ans[4000];
int A[4000],B[4000]; 
int n,m,tot; 
void mul(int now[],int k) 
{ 
     int i; 
     int answer[4000]={0}; 
     for(i=1;i<=now[0];i++) 
     {answer[i]+=now[i]*k;answer[i+1]+=answer[i]/10000;answer[i]%=10000;} 
     while(answer[now[0]+1]) 
     { 
        now[0]++; 
        answer[now[0]+1]+=ans[now[0]]/10000; 
        answer[now[0]]%=10000; 
     } 
     answer[0]=now[0]; 
     for(i=0;i<=answer[0];i++) 
     ans[i]=answer[i]; 
} 
void add(int a[],int b[])
{
     int i,j;
     int answer[4000]={0};
     j=max(a[0],b[0]);
     for(i=1;i<=j;i++)
     {
        answer[i]+=a[i]+b[i];
        if(answer[i]>=10000)
        {
           answer[i+1]+=answer[i]/10000;
           answer[i]%=10000;                 
        }
     } 
     if(answer[j+1]>=10000)
     {
        j++;
        answer[j+1]+=answer[j]/10000;
           answer[j]%=10000;  
     }
     ans[0]=j;
     for(i=1;i<=j;i++)
     ans[i]=answer[i];
}
void print(int now[]) 
{ 
     int i; 
     printf("%d",now[now[0]]); 
     for(i=now[0]-1;i>=1;i--) 
     printf("%.4d",now[i]); 
     cout<<endl; 
} 
int main() 
{ 
    int i,j;
    scanf("%d%d",&n,&m);
    ans[0]=1;ans[1]=1;
    mul(ans,(n+1)*m);
    for(i=n-m+4;i<=n+2;i++)
    mul(ans,i);
    mul(ans,2);
    for(i=1;i<=ans[0];i++)
    A[i]=ans[i];
    A[0]=ans[0];
    
    ans[0]=1;ans[1]=1;
    mul(ans,(n+1)*n);
    for(i=n-m+4;i<=n+3;i++)
    mul(ans,i);
    for(i=1;i<=ans[0];i++)
    B[i]=ans[i];
    B[0]=ans[0];
    
    add(A,B);
    for(i=2;i<=n;i++)
    mul(ans,i);
    print(ans);
    system("pause"); 
    return 0; 
}
