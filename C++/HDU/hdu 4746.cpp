#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define N 500010
using namespace std;
int n,m,p,tot,prime[N],mob[N];
int f[N][20],num[N];
bool check[N];
void get()
{
    int i,j;
    mob[1]=1;num[1]=0;
    for(i=2;i<N;i++)
    {
        if(!check[i])  {prime[++tot]=i;num[i]=1;mob[i]=-1;}
        for(j=1;j<=tot;j++)
        {
            if(i*prime[j]>=N)  break;
            check[i*prime[j]]=1;num[i*prime[j]]=num[i]+1;
            if(i%prime[j]==0)
            {
                mob[i*prime[j]]=0;break;
            }  
            else  mob[i*prime[j]]=mob[i]*(-1);
        }
    }
    for(i=1;i<N;i++)  for(j=i;j<N;j+=i)  f[j][num[i]]+=mob[j/i];
    for(i=1;i<N;i++)  for(j=1;j<=19;j++)  f[i][j]+=f[i][j-1];
    for(i=1;i<N;i++)  for(j=0;j<=19;j++)  f[i][j]+=f[i-1][j];
}
void swap(int &a,int &b)   {int t=a;a=b;b=t;}
int main()
{
    long long ans;
    int t,i,j,;
    get();scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&p);
        if(p>=19)  {printf("%I64d\n",(long long)(n)*m);continue;}
        ans=0;if(n>m)  swap(n,m);
        for(i=1;i<=n;i=j+1)
        {
            j=min(n/(n/i),m/(m/i));
            ans+=(long long)(f[j][p]-f[i-1][p])*(n/i)*(m/i);
        }
        printf("%I64d\n",ans);
    }
    //system("pause");
    return 0;
}
