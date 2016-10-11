#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
long long f[11][11];
long long d[11];
int num[11];
long long R,L;
long long a1,a2;
void get(long long x)
{
     while(x>0)
     {
          num[0]++;
          num[num[0]]=x%10;
          x/=10;
     }
}
int getans()
{
    int ans=0;
    int i,j,k;
    for(i=1;i<num[0];i++)
    ans+=d[i];
    for(j=1;j<num[num[0]];j++)
    ans+=f[num[0]][j];
    for(i=num[0]-1;i>=1;i--)
    {
       for(j=0;j<num[i];j++)
       {
           if(abs(j-num[i+1])>1)
           ans+=f[i][j];
       }
       if(abs(num[i]-num[i+1])<=1)
       break;
    }
    
    return ans;
}
int main()
{
    int i,j,k;
    scanf("%lld%lld",&L,&R);
    for(i=0;i<=9;i++)  f[1][i]=1;
    for(i=2;i<=10;i++)
    for(j=0;j<=9;j++)
    for(k=0;k<=9;k++)
    if(abs(j-k)>1)
    f[i][j]+=f[i-1][k];
    for(i=1;i<=10;i++)
    for(j=1;j<=9;j++)
    d[i]+=f[i][j];    
    num[0]=0;
    get(L);    
    a1=getans();
    num[0]=0;
    get(R+1);
    
    a2=getans();
    cout<<a2-a1<<endl;
    
    system("pause");
    return 0;
}
