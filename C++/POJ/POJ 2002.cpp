#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
struct sth
{
   int x;int y;
}hash[10007][100];
int sum[10007];
int n;
long long ans;
int x1[1001],y11[1001];
void ha(int xx,int yy)
{
     long long k;
     k=abs(xx*yy)*47+abs(xx+yy)*48+12347;
     k%=10007;
     sum[k]++;
     hash[k][sum[k]].x=xx;
     hash[k][sum[k]].y=yy;
}
bool find(int a,int b)
{
     long long k;
     k=abs(a*b)*47+abs(a+b)*48+12347;
     k%=10007;
     int i;
     for(i=1;i<=sum[k];i++)
     {
      if(hash[k][i].x==a && hash[k][i].y==b)
      return 1;
     }
     return 0;
}
int main()
{
    int i,j;
    int a,b;
    while(scanf("%d",&n))
    {
       if(n==0)  break;
       ans=0;
       memset(hash,0,sizeof(hash));
       for(i=1;i<=n;i++)
       {scanf("%d%d",&x1[i],&y11[i]);ha(x1[i],y11[i]);}
       for(i=1;i<=n-1;i++)
       for(j=i+1;j<=n;j++)
       {
          a=x1[i]-x1[j];
          b=y11[i]-y11[j];
          if(find(x1[i]+b,y11[i]-a) && find(x1[j]+b,y11[j]-a))
          ans++;
          if(find(x1[i]-b,y11[i]+a) && find(x1[j]-b,y11[j]+a))
          ans++;
       }
       ans/=4;
       printf("%d\n",ans);
    }
    system("pause");
    return 0;
} 
