#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int num[1010];
bool mark[1010];
int n;
int sum;
bool o;
inline bool comp(int a,int b)
{
    return a>b;
}
bool sc1()
{
   int i;
   for(i=n;i>=1;i--)
   if(num[i]%3==1)
   {mark[i]=1;return 1;}
   return 0;
}
void sc2()
{
   int i,k=2;
   for(i=n;i>=1;i--)
   if(num[i]%3==2)
   {mark[i]=1;k--;
   if(!k) break;
   }
}
bool sc3()
{
   int i;
   for(i=n;i>=1;i--)
   if(num[i]%3==2)
   {mark[i]=1;return 1;}
   return 0;
}
void sc4()
{
   int i,k=2;
   for(i=n;i>=1;i--)
   if(num[i]%3==1)
   {mark[i]=1;k--;
   if(!k) break;
   }
}
int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++)
    {scanf("%d",&num[i]);sum+=num[i];
    if(num[i]==0)
    o=1;
    }
    if(!o)
    printf("-1\n");
    else
    if(n==1)
    cout<<"0"; 
    else
    {
    sort(num+1,num+1+n,comp);
    sum%=3;
    if(sum==1)
    {
       if(!sc1())
       sc2();
    }
    else
    if(sum==2)
    {
       if(!sc3())
       sc4();
    }
    for(i=1;i<=n;i++)
    if(!mark[i] && num[i]!=0)
    {o=0;break;}
    if(o)
    cout<<0;
    else
    {
    for(i=1;i<=n;i++)
    if(!mark[i])
    cout<<num[i];
    }
    }
    system("pause");
    return 0;
}
