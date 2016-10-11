#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m;
int a[110][110];
int now[110][110];
int sum;
int main()
{
    int i,j,k;
    bool o;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {scanf("%d",&a[i][j]);sum+=a[i][j];}
    int r,c,x,y;
    
    for(r=n;r>=1;r--)
    for(c=m;c>=1;c--)
    if(sum%(r*c)==0)
    {
     o=0;
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  now[i][j]=a[i][j];
     for(i=1;i<=n-r+1;i++) 
     for(j=1;j<=m-c+1;j++)
     {
      k=now[i][j];
      for(x=i;x<=i+r-1;x++)  
      for(y=j;y<=j+c-1;y++)  
      now[x][y]-=k;
     }
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  if(now[i][j]!=0)  o=1;
     if(!o)
     {printf("%d\n",sum/(r*c));system("pause");return 0;}
    }
    system("pause");
    return 0;
}
