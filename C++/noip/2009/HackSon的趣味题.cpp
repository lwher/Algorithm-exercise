#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int zs[3000001],gs[3000001],sz,T,sum;
int num[5000001];
int a1,a0,b1,b0,ans;
void fenjie()
{
     int i;
     int b=b1;
     for(i=2;(long long)(i)*i<=b;i++)
     {
         if(b % i == 0)  {sz++;zs[sz]=i;gs[sz]=1;b/=i;}
         while(b % i== 0)
         {
             gs[sz]++;
             b/=i;
         }
     }
     if(b>1)  {sz++;zs[sz]=b;gs[sz]=1;}
}
void dfs(int top,int now)
{
     if(top==sz+1)
     {
          sum++;num[sum]=now;return;
     }
     int i;
     int tmp=now;
     dfs(top+1,tmp);
     for(i=1;i<=gs[top];i++)
     {
         tmp*=zs[top];
         dfs(top+1,tmp);
     }
}
int gcd(int a,int b)
{
    if(b==0)  return a;
    else return gcd(b,a%b);
}
long long lcm(int a,int b)
{
     long long now=1;
     now*=a;now*=b;now/=gcd(a,b);
     return now;
}
int main()
{
    int i;
    cin>>T;
    while(T--)
    {
         scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
         sz=0;sum=0;ans=0;
         fenjie();
         
         dfs(1,1);
         for(i=1;i<=sum;i++)
         {
             if(gcd(num[i],a0)==a1 && lcm(num[i],b0)==b1) ans++;
         }
         printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
