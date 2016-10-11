#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,K,nf,st,ed,map[13][51][51],p[5],ans[51][51];
bool mark[13][51];
void mul(int a[51][51],int b[51][51],int now[51][51])
{
     int i,j,k,c[51][51]={0};
     for(i=1;i<=n;i++)  
       for(j=1;j<=n;j++)
         for(k=1;k<=n;k++)
            c[i][j]=(c[i][j]+a[i][k]*b[k][j])%10000;
     for(i=1;i<=n;i++) for(j=1;j<=n;j++) now[i][j]=c[i][j];
}
void qpow(int A[51][51],int b)
{
     int i,j,a[51][51];
     for(i=1;i<=n;i++)  ans[i][i]=1;
     for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  a[i][j]=A[i][j];
     while(b)
     {
        if(b & 1) mul(ans,a,ans);
        b=b>>1;
        mul(a,a,a);
     }
}
int main()
{
    int i,j,k,a,b,t;
    scanf("%d%d%d%d%d",&n,&m,&st,&ed,&K);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);a++;b++;
        for(j=1;j<=12;j++)  map[j][a][b]=map[j][b][a]=1;
    }
    scanf("%d",&nf);
    for(i=1;i<=nf;i++)
    {
        scanf("%d",&t);
        for(j=1;j<=t;j++)  {scanf("%d",&p[j]);p[j]++;}
        for(j=1;j<=12;j++)  
        {
           k=j%t; if(!k) k=t;
           mark[j][p[k]]=1;
        }
    }
    for(j=1;j<=12;j++) for(i=1;i<=n;i++)
    if(mark[j][i])
    {
       t=j-1;if(!t) t=12;
       for(k=1;k<=n;k++)  
       {
          map[j][i][k]=0;map[t][k][i]=0;
       }
    }
    for(i=2;i<=12;i++)  mul(map[i-1],map[i],map[i]);    
    qpow(map[12],K/12);
    if(K%12)  mul(ans,map[K%12],ans);
    printf("%d\n",ans[st+1][ed+1]);
    system("pause");
    return 0;
}
