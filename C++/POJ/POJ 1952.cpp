#include<iostream>
#include<stdio.h>
using namespace std;
int n;
long int num[5001],f[5001],ans[5001],cs[5001];
long int INF,answer=1,a2;
int main()
{
    int i,j;
    
    cin>>n;
    for(i=1;i<=n;i++)
    {scanf("%d",&num[i]);}
    
    f[1]=1;
    cs[1]=1;
    
    for(i=2;i<=n;i++)
{
	  INF=0;
      for(j=1;j<i;j++)
      {
       if( num[j]>num[i] && f[j]>=INF)
       {INF=f[j];a2=j;}
      }
      if(INF==0)  cs[i]++;
      else
      {
	  cs[i]+=cs[a2];
      for(j=i-1;j>=1;j--)
      {
       if( f[j]==INF && num[a2]>num[j] && num[j]>num[i])
       {cs[i]+=cs[j];a2=j;}
      }
	  }
      f[i]=INF+1;
      if(f[i]>answer) answer=f[i];
} 
    a2=0;
    INF=999999999;
    for(i=n;i>=1;i--)
    if(f[i]==answer && INF>num[i])
    {a2+=cs[i];INF=num[i];}
   cout<<answer<<" "<<a2<<endl;
    
    system("pause");
    return 0;
}
