#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int pre[20],tim[21][21],emerge[21],order[401];
bool vis[21][4001]={false};int us[21][21];int n,m,ans=-1,lo;
int max(int x,int y)
{
   if (x>y)   return (x);
   else return (y);
}
void  find1(int num1,int num2 )
{ 
   int i,j,k,tot;bool get=false;
   for(i=pre[num1]+1;i<=4000;i++) 
   {
       tot=0;
       for (k=i;k<=i+tim[num1][num2]-1;k++)
       if (!vis[us[num1][num2]][k]) tot++;
       if (tot==tim[num1][num2])   get=true;
       if (get) lo=i;
       if (get) break;
   }
}
void take()
{
    int i,j,k;
    for (i=1;i<=n*m;i++) 
    {
         emerge[order[i]]++;
      find1(order[i],emerge[order[i]]);
         ans=max(ans,lo+tim[order[i]][emerge[order[i]]]-1);
      for (j=lo;j<=lo+tim[order[i]][emerge[order[i]]]-1;j++)   
      vis[us[order[i]][emerge[order[i]]]][j]=true;
      pre[order[i]]=lo+tim[order[i]][emerge[order[i]]]-1;
    }
    printf("%d",ans);
}
int main()
{ 
    int i,j,k;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n*m;i++)   scanf("%d",&order[i]);
    for(i=1;i<=n;i++) 
    for(j=1;j<=m;j++)   scanf("%d",&us[i][j]);
    for(i=1;i<=n;i++) 
    for(j=1;j<=m;j++)   scanf("%d",&tim[i][j]);
    take();
    system("pause");
    return 0;
}


