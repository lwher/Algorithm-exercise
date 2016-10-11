#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int f[2][200001];
bool mark[2][200001];
int a[101],b[101];
int o=0;
int main()
{
    int i,j,k;
    cin>>n;
    for(i=1;i<=n;i++)
    scanf("%d%d",&a[i],&b[i]);
    f[o][100000]=0;
    mark[o][100000]=1;
    for(i=1;i<=n;i++)
    {
       memset(mark[1-o],0,sizeof(mark[1-o]));
       k=a[i];
       for(j=0;j<=200000;j++)
       {
          if(mark[o][j])
          {
             if(!mark[1-o][j])
             {mark[1-o][j]=1;f[1-o][j]=f[o][j];}
             else
             f[1-o][j]=max(f[1-o][j],f[o][j]);
             if(!mark[1-o][j+k])
             {
             mark[1-o][j+k]=1;
             f[1-o][j+k]=f[o][j]+b[i];
             }
             else
             f[1-o][j+k]=max(f[1-o][j+k],f[o][j]+b[i]);
          }
       }
       o=1-o;
    }
    
    int ans=0;
    for(i=100000;i<=200000;i++)
    {
      if(mark[o][i] && f[o][i]>=0)
      {
        ans=max(ans,i-100000+f[o][i]);
      }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
