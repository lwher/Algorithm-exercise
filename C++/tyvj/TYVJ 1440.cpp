#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string>
using namespace std;
string s;
int n;
int sum[1100];
void dfs(int l,int r)
{
   if(l==r)  
   {
   if(sum[l]==sum[l-1])  
   printf("B");
   else
   printf("I");
   return;
   }
   int mid=(l+r-1)>>1;
   dfs(l,mid);
   dfs(mid+1,r);
   if(sum[r]-sum[l-1]==r-l+1)
   printf("I");
   else
   if(sum[r]-sum[l-1]==0)
   printf("B");
   else
   printf("F");
   
}
int main()
{
    cin>>n;
    cin>>s;
    int i,num=1;
    for(i=0;i<=s.size()-1;i++)
    {
      if(s[i]=='1')
      sum[i+1]=sum[i]+1;
      else
      sum[i+1]=sum[i];
    }
    for(i=1;i<=n;i++)
    num*=2;
    dfs(1,num);
    system("pause");
    return 0;
}
