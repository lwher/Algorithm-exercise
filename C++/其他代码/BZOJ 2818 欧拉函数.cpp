#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,tot,prime[5000010];
long long phi[10000010],ans;
bool mark[10000010];
void getphi()
{
    int i,j;
    phi[1]=1;
    for(i=2;i<=n;i++)
    {
        if(!mark[i])  {prime[++tot]=i;phi[i]=i-1;}
        for(j=1;j<=tot;j++)
        {
            if(i*prime[j]>n)  break;
            mark[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];break;
            }
            else  phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
    for(i=1;i<=n;i++)  phi[i]+=phi[i-1];
    for(i=1;i<=n;i++)  phi[i]=(phi[i]<<1)-1;
}
int main()
{
    scanf("%d",&n);
    getphi();
    for(int i=1;i<=tot;i++)  ans+=phi[n/prime[i]];
    cout<<ans<<endl;
    return 0;
}