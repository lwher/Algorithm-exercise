#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,f[53][53];
char s[53];
int main()
{
    int i,j,k,l;
    scanf("%s",s+1);n=strlen(s+1);
    memset(f,127,sizeof(f));
    for(i=1;i<=n;i++)  f[i][i]=1;
    for(l=2;l<=n;l++)
    {
       for(i=1;i<=n;i++)
       {
          j=i+l-1;
          if(j>n) break;
          for(k=i;k<j;k++)  f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
          if(s[i]==s[j])  
          {
             if(l==2) f[i][j]=1; 
             else
             {
                 f[i][j]=min(f[i+1][j],f[i][j-1]);
                 f[i][j]=min(f[i][j],f[i+1][j-1]+1);
             }
          }
       }
    }
    printf("%d\n",f[1][n]);
    return 0;
}