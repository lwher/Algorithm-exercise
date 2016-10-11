#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
char a[101][101];
int sqr(int x)
{
    return x*x;
}
int main()
{
  int i,j,k,l,x1,y1,x2,y2,z,ans;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++) cin>>a[i][j];
  }
  ans=0;
  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   if (a[i][j]=='J') 
   {
     z=0;
     for(k=n;k>=i;k--)
      for(l=n;l>=1;l--)
      if (a[k][l]=='J')
      {
        if ((k==i)&&(l==j)) break;
        if (((sqr(i-k)+sqr(j-l))>>1)<=ans)  continue;
        if (((i-j+k+l) & 1)==1)  continue;
        if (((i+j+k-l) & 1)==1)  continue;
        x1=(i-j+k+l)>>1;
        y1=i+l-x1;
        x2=(i+j+k-l)>>1;
        y2=j+k-x2;
        if ((x1<1)||(x1>n)||(y1<1)||(y1>n)||(x2<1)||(x2>n)||(y2<1)||(y2>n)) continue;
        if (((a[x1][y1]=='J')&&(a[x2][y2]!='B'))||((a[x1][y1]!='B')&&(a[x2][y2]=='J'))) 
         if (((sqr(i-k)+sqr(j-l))>>1)>ans)
         {
           ans=(sqr(i-k)+sqr(j-l))>>1;
           z=1;
        }
     }
   }
  cout<<ans<<endl;
  system("pause");
  return 0;
}
