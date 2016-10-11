#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int f[61][32010];
int v[61][3],p[61][3],sum[61];
int n,m,ans;
bool mark[61];
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    int a,b,c;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(c==0)  {mark[i]=1;v[i][0]=a;p[i][0]=b;}
        else
        {
            sum[c]++;v[c][sum[c]]=a;p[c][sum[c]]=b;
        }
    }    
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    for(i=0;i<m;i++)
    {
         for(j=0;j<=n;j++)
         if(f[i][j]!=-1)
         {
              if(mark[i+1])
              {
                  if(j+v[i+1][0]<=n)   f[i+1][j+v[i+1][0]]=max(f[i+1][j+v[i+1][0]],f[i][j]+v[i+1][0]*p[i+1][0]);
                  if(sum[i+1]>0)
                  {
                      if(sum[i+1]==1)
                      {
                      if(j+v[i+1][0]+v[i+1][1]<=n)  
                      f[i+1][j+v[i+1][0]+v[i+1][1]]=max(f[i+1][j+v[i+1][0]+v[i+1][1]],f[i][j]+v[i+1][0]*p[i+1][0]+v[i+1][1]*p[i+1][1]);
                      } else
                      if(sum[i+1]==2)
                      {
                      if(j+v[i+1][0]+v[i+1][1]<=n)  
                      f[i+1][j+v[i+1][0]+v[i+1][1]]=max(f[i+1][j+v[i+1][0]+v[i+1][1]],f[i][j]+v[i+1][0]*p[i+1][0]+v[i+1][1]*p[i+1][1]);   
                      if(j+v[i+1][0]+v[i+1][2]<=n)  
                      f[i+1][j+v[i+1][0]+v[i+1][2]]=max(f[i+1][j+v[i+1][0]+v[i+1][2]],f[i][j]+v[i+1][0]*p[i+1][0]+v[i+1][2]*p[i+1][2]);
                      if(j+v[i+1][0]+v[i+1][1]+v[i+1][2]<=n)  
                      f[i+1][j+v[i+1][0]+v[i+1][1]+v[i+1][2]]=max(f[i+1][j+v[i+1][0]+v[i+1][1]+v[i+1][2]],f[i][j]+v[i+1][0]*p[i+1][0]+v[i+1][1]*p[i+1][1]+v[i+1][2]*p[i+1][2]);
                      }
                  }
              }
              f[i+1][j]=max(f[i+1][j],f[i][j]);
         }
    }
    ans=0;
    for(i=0;i<=n;i++)  ans=max(ans,f[m][i]);
    cout<<ans<<endl;
    system("pause");
    return 0;
}
