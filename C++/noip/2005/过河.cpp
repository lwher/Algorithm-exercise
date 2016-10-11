#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int l,s,t,n;
int wei[110];
int f[50010];
bool mark[50010];
int ans;
inline bool comp(int a,int b)
{
       return a<b;
}
int main()
{
    memset(f,127,sizeof(f));
    int i,j,k,now;
    scanf("%d%d%d%d",&l,&s,&t,&n);
    for(i=1;i<=n;i++)
    scanf("%d",&wei[i]);
    sort(wei+1,wei+1+n,comp);
    if(s==t)
    {
       for(i=1;i<=n;i++)
       if(wei[i]%s==0)
       ans++;
       cout<<ans<<endl;
    }
    else
    {      
        if(wei[1]>100)  {mark[100]=1;j=100;}
        else   {mark[wei[1]]=1;j=wei[1];}
        
        for(i=2;i<=n;i++)
        {
           k=wei[i]-wei[i-1];
           if(k>100)
           k=100;
           j+=k;
           mark[j]=1;
        }
        k=l-wei[n];
        if(k>100) k=100;
        j+=k;
        f[0]=0;
        for(i=s;i<=j+t-1;i++)
        {
          now=f[i-s];
          for(k=i-s-1;k>=i-t;k--)
          {
          if(k<0)  continue;
          now=min(now,f[k]);
          }
          if(mark[i])
          f[i]=now+1;
          else
          f[i]=now;
        }
        ans=110;
        for(i=j;i<=j+t-1;i++)
        {
          ans=min(ans,f[i]);
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}