#include<iostream>
#include<cstdio>
#define N 40000
using namespace std;
int n;
int phi[N],prime[N],tot,ans;
bool mark[N];
void getphi()
{  
   int i,j;
   phi[1]=1;
   for(i=2;i<=N;i++)
   {
       if(!mark[i])  {prime[++tot]=i;phi[i]=i-1;}
       for(j=1;j<=tot;j++)
       {
          if(i*prime[j]>N)  break;
          mark[i*prime[j]]=1;
          if(i%prime[j]==0)
          {
             phi[i*prime[j]]=phi[i]*prime[j];break;
          }
          else  phi[i*prime[j]]=phi[i]*(prime[j]-1);
       }
   }
}
int main()
{
    scanf("%d",&n);
    getphi();
    for(int i=1;i<n;i++)
       ans+=phi[i];
    printf("%d",2*ans+1);
    return 0;
 }