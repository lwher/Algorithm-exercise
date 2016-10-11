#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,u[10000010],prime[5000010],tot,C[10000010];
long long ans;
bool mark[10000010];
void getC()
{
    int i,j;
    u[1]=1;C[1]=0;
    for(i=2;i<=n;i++)
    {
        if(!mark[i])  {prime[++tot]=i;u[i]=-1;C[i]=1;}
        for(j=1;j<=tot;j++)
        {
            if(i*prime[j]>n)  break;
            mark[i*prime[j]]=1;
            if(i%prime[j]==0) 
            {
                u[i*prime[j]]=0;C[i*prime[j]]=u[i];break;
            }
            else {u[i*prime[j]]=-u[i];C[i*prime[j]]=u[i]-C[i];}  
        }
    }
    for(i=1;i<=n;i++)  C[i]=C[i]+C[i-1];
}
int main()
{
    int i,j;    
    scanf("%d",&n);
    getC();
    for(i=1;i<=n;i=j+1)
    {
        j=n/(n/i);
        ans+=(long long)(C[j]-C[i-1])*(n/i)*(n/i);
    }
    cout<<ans<<endl;
    return 0;
}