#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,h[2000010],q[1000010],maxh[2000010];
int max1,sum1,max2,sum2,tou=1,wei=0;
long long ans;
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void updata(int x)
{
    if(x>max1)  {max2=max1;sum2=sum1;max1=x;sum1=1;} else  if(x==max1)  sum1++;  else
    if(x>max2)  {max2=x;sum2=1;}  else  if(x==max2)  sum2++;
}
int find(int x)
{
    int l=tou,r=wei,mid;
    if(l==r)  return l;
    while(l+1<r)
    {
       mid=(l+r)>>1;
       if(h[q[mid]]>x)  l=mid;
       else r=mid;
    }
    if(h[q[r]]>x)  return r; else return l;
}
int main()
{
    int i,N,w;
    n=read();N=n+n;
    for(i=1;i<=n;i++)  
    {
       h[i]=read();h[i+n]=h[i];updata(h[i]);
    }        
    for(i=1;i<=N;i++)
    {
        while(tou<=wei && i-q[tou]>=n)  tou++;
        while(tou<=wei && h[i]>h[q[wei]])  {ans++;wei--;}
        if(tou<=wei)  
        {
            if(h[q[wei]]>h[i])  {if(h[i]>=maxh[q[wei]]) ans++;}  else
            if(h[q[tou]]==h[i])  ans+=wei-tou+1;  
            else  
            {
                w=find(h[i]);ans+=wei-w;if(h[i]>=maxh[q[w]])  ans++;
            } 
            if(i>n)  maxh[q[wei]]=max(maxh[q[wei]],h[i]);
        }
        if(i<=n) q[++wei]=i;
    }
    if(sum1>1)  ans-=(long long)(sum1)*(sum1-1)/2;  else ans-=sum2;
    cout<<ans<<endl;
    return 0;
}