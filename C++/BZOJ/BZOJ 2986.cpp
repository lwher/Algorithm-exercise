#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define N 200000
using namespace std;
int prime[400010],tot,u[400010];
bool mark[400010];
long long n;
void getu()
{
    int i,j;
    u[1]=1;
    for(i=2;i<=N;i++)
    {
        if(!mark[i])  {prime[++tot]=i;u[i]=1;}
        for(j=1;j<=tot;j++)
        {
            if(i*prime[j]>N)  break;
            mark[i*prime[j]]=1;
            if(i%prime[j]==0)  {u[i*prime[j]]=0;break;}
            else u[i*prime[j]]=-u[i];  
        }
    } 
}
long long Count(long long x)
{
    int i,limt=sqrt(x);
    long long res=0;
    for(i=2;i<=limt;i++)  res+=u[i]*(x/((long long)(i)*i));
    return res;
}
int main()
{
    getu();
    cin>>n;
    long long l=1,r=10*n,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(Count(mid)>=n)  r=mid;
        else l=mid;
    }
    if(Count(l)==n)  cout<<l<<endl;  else cout<<r<<endl;  
    //system("pause");
    return 0;
}