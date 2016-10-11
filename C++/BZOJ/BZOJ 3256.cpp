#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
char a[210],b[210],c[210];
int next[210],la,lb,lc,f[210][210][210];
int main()
{
    int i,j,k,t;
    scanf("%d%d%d",&la,&lb,&lc);
    scanf("%s",a+1); 
    scanf("%s",b+1); 
    scanf("%s",c+1); 
    next[0]=-1;
    for(i=0;i<=lc;i++)
    {
        for(j=next[i];j!=-1;j=next[j])  if(c[i+1]==c[j+1])  break;
        next[i+1]=j+1;
    }
    for(i=0;i<=la;i++)
    for(j=0;j<=lb;j++)
    for(k=0;k<lc;k++)
    {
        if(k>0 && f[i][j][k]==0)  continue;
        f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]);
        f[i][j+1][k]=max(f[i][j+1][k],f[i][j][k]);
        if(a[i+1]==b[j+1])
        {
            for(t=k;t!=-1;t=next[t])  if(a[i+1]==c[t+1])  break;
            f[i+1][j+1][t+1]=max(f[i+1][j+1][t+1],f[i][j][k]+1);
        }
    }
    int ans=0;
    for(i=0;i<lc;i++)   ans=max(ans,f[la][lb][i]);
    printf("%d\n",ans);
    //system("pause");
    return 0;
}