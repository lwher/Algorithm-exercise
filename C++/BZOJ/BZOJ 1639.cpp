#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m;
int num[100010];
bool check(int x)
{
     int i,sum,now;
     now=0;sum=0;
     for(i=1;i<=n;i++)
     {
        if(now+num[i]>x)
        {sum++;now=0;}
        now+=num[i];
     }
     if(now>0)  sum++;
     if(sum<=m)  return 1;
     else return 0;
}
int main()
{
    int i,maxx=0,r=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
       scanf("%d",&num[i]);
       if(num[i]>maxx) maxx=num[i];
       r+=num[i];
    }
    int l=maxx;
    int mid;
    while(l<r)
    {
              if(l+1==r)  break;
              mid=(l+r)>>1;
              if(check(mid))  r=mid;
              else l=mid;
    }
    if(check(l))  cout<<l<<endl;
    else cout<<r<<endl;
    system("pause");
    return 0;
}
