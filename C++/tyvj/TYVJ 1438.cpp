#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
using namespace std;
int ans,n,k;
int fa[150100];
int getfa(int x)
{
    if(fa[x]==x)  return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}
// yizu 1-n chi  n+1-2*n   beichi  2*n+1 - 3*n 
int main()
{
    int d,a,b,x,y;
    int ax1,ax2,ax3,ay1,ay2,ay3;
    
    cin>>n>>k;
    int i,j;
    for(i=1;i<=n*3;i++)
    {fa[i]=i;}
    for(i=1;i<=k;i++)
    {
      scanf("%d%d%d",&d,&a,&b);
      if(a>n || b>n)  {ans++;continue;}
      
      if(a==b && d==2) {ans++;continue;}
      
      if(a==b && d==1)  continue;
       ax1=getfa(a);ax2=getfa(a+n);ax3=getfa(a+n+n);
       ay1=getfa(b);ay2=getfa(b+n);ay3=getfa(b+n+n);
       if(d==1)
       {
        if(ax2!=ay1 && ax3!=ay1 && ax1!=ay3 && ax1!=ay2)  
        {
        fa[ax1]=ay1;
        fa[ax2]=ay2;
        fa[ax3]=ay3;
        }
        else 
        ans++;
       }
      if(d==2)
      {
        if(ax1!=ay1 && ax3!=ay1 && ax1!=ay2)  
        {
        fa[ax1]=ay3;
        fa[ay1]=ax2;
        fa[ax3]=ay2;
        }
        else 
        ans++;
      }
      }
    
    cout<<ans<<endl;
    system("pause");
    return 0;
}
