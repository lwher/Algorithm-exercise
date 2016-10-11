#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
       int xx,yy;
}dian[10010];
int n;
long ans,sum;
int x[10010],y[10010];
bool find(int a,int b)
{
     int i;
     for(i=1;i<=n;i++)
     if(a==dian[i].xx && b==dian[i].yy)
     return 1;
     return 0;
}
long juli(int a,int b)
{
    long s=0;
    int i;
    for(i=1;i<=n;i++)
    {s+=abs(x[i]-a);s+=abs(y[i]-b);}
    return s;
}
int main()
{
    int i,j,k;
    long s1,s2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {scanf("%d%d",&x[i],&y[i]);dian[i].xx=x[i];dian[i].yy=y[i];}
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);   
    if(n%2==1)
    {
      k=n/2+1;
      if(!find(x[k],y[k]))
      {
         ans=juli(x[k],y[k]);
         sum=1;
      }
      else
      {
         ans=juli(x[k]-1,y[k]);
         sum=1;
         
         if(juli(x[k],y[k]-1)<ans)
         {ans=juli(x[k],y[k]-1);sum=1;}
         else
         if(juli(x[k],y[k]-1)==ans)
         sum++;
         
         if(juli(x[k]+1,y[k])<ans)
         {ans=juli(x[k]+1,y[k]);sum=1;}
         else
         if(juli(x[k]+1,y[k])==ans)
         sum++;
         
         if(juli(x[k],y[k]+1)<ans)
         {ans=juli(x[k],y[k]+1);sum=1;}
         else
         if(juli(x[k],y[k]+1)==ans)
         sum++;
      }
    }
    else
    {
        k=n/2;
        s1=x[k+1]-x[k]+1;
        s2=y[k+1]-y[k]+1;
        sum=s1*s2;
        ans=juli(x[k],y[k]);
        for(i=1;i<=n;i++)
        {
           if(dian[i].xx>=x[k] && dian[i].xx<=x[k+1])
           if(dian[i].yy>=y[k] && dian[i].yy<=y[k+1])
           sum--;
        }
    }
    cout<<ans<<" "<<sum<<endl;
    system("pause");
    return 0;
}
