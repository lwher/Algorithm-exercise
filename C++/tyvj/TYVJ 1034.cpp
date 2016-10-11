#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int d[10002];
int rw[10001][5001];

int n,k;
int main()
{
    cin>>n>>k;
    int i,j,l;
    int a,b;
    for(i=1;i<=k;i++)
    {
      scanf("%d%d",&a,&b);
      rw[a][0]++;
      rw[a][rw[a][0]]=a+b;
      }
    for(i=n;i>=1;i--)
    {
       if(rw[i][0]==0)   d[i]=d[i+1]+1;
       else
       {
         for(j=1;j<=rw[i][0];j++)
         {
         d[i]=max(d[i],d[rw[i][j]]);
         }      
        }
    }
  
   cout<<d[1];
    system("pause");
    return 0;
}
