#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,num[110],daan[110];
long long f[2][110][110],ans;// 0: max //1: min
char s[3],c[110];
void dp(int w)
{
     int i,j,k,l;
     for(i=1;i<=w;i++)  for(j=1;j<=w;j++) {f[0][i][j]=-1e9;f[1][i][j]=1e9;}
     for(i=1;i<=w;i++)  {f[0][i][i]=num[i];f[1][i][i]=num[i];}
     for(l=2;l<=w;l++)
     for(i=1;i+l-1<=w;i++)
     {
         j=i+l-1;
         for(k=i;k<j;k++)  
         {
            if(c[k]=='t')
            {
                 f[0][i][j]=max(f[0][i][j],f[0][i][k]+f[0][k+1][j]);
                 f[1][i][j]=min(f[1][i][j],f[1][i][k]+f[1][k+1][j]);        
            }
            else
            {
                 f[0][i][j]=max(f[0][i][j],f[0][i][k]*f[0][k+1][j]);
                 f[0][i][j]=max(f[0][i][j],f[1][i][k]*f[1][k+1][j]);
                 f[0][i][j]=max(f[0][i][j],f[1][i][k]*f[0][k+1][j]);
                 f[0][i][j]=max(f[0][i][j],f[0][i][k]*f[1][k+1][j]);
                 
                 f[1][i][j]=min(f[1][i][j],f[1][i][k]*f[1][k+1][j]);  
                 f[1][i][j]=min(f[1][i][j],f[0][i][k]*f[0][k+1][j]);  
                 f[1][i][j]=min(f[1][i][j],f[0][i][k]*f[1][k+1][j]);  
                 f[1][i][j]=min(f[1][i][j],f[1][i][k]*f[0][k+1][j]);  
            }
         }
     }
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s%d",s,&num[i]);
        c[i-1]=s[0];
    }
    c[n]=c[0];    
    for(i=n+1;i<=n+n;i++)   {num[i]=num[i-n];c[i]=c[i-n];}
    dp(n+n);  
    ans=-1e9;
    for(i=1;i<=n;i++)  if(f[0][i][i+n-1]>ans)  ans=f[0][i][i+n-1];
    for(i=1;i<=n;i++)  if(f[0][i][i+n-1]==ans)  daan[++daan[0]]=i;
    cout<<ans<<endl;
    for(i=1;i<daan[0];i++) printf("%d ",daan[i]); printf("%d\n",daan[daan[0]]);
    system("pause");
    return 0;
}
