#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
int prime[210],tot;
int fz[210],fm[210],ans[1010];
bool mark[210];
void getprime()
{
    int i,j;
    for(i=2;i<=200;i++)
    {
        if(!mark[i])  prime[++tot]=i;
        for(j=1;j<=tot;j++)
        {
            if(i*prime[j]>200) break;
            mark[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
void fenjie(int t,int f[])
{
    for(int i=1;i<=tot;i++)  
    if(t%prime[i]==0)
    {
        while(t%prime[i]==0)
        {
            f[i]++;t/=prime[i];
        }
    }
}
void GJDchen(int a[],int b,int d[])
{
    int i;
    int c[1010]={0};
    for(i=1;i<=a[0];i++)
    {
        c[i]+=a[i]*b;
        c[i+1]+=c[i]/10000;
        c[i]%=10000;
    }
    i=a[0];
    while(c[i+1]>0)
    {
        i++;
        while(c[i]>=10000)  {c[i+1]+=c[i]/10000;c[i]%=10000;}
    }
    memset(d,0,sizeof(d));
    d[0]=i;
    for(i=1;i<=d[0];i++)  d[i]=c[i];
}
void print()
{
    int i;
    printf("%d",ans[ans[0]]);
    for(i=ans[0]-1;i>=1;i--)  printf("%.4d",ans[i]);  
}
int main()
{
    int i,j,T,t;
    getprime();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if(n>k)  {printf("0 1\n");continue;}
        memset(fz,0,sizeof(fz));
        memset(fm,0,sizeof(fm));        
        fenjie(k+1,fz);
        for(i=1;i<=tot;i++)  fz[i]*=(n-1);
        fenjie(k+1-n,fz);
        fenjie(k,fm);
        for(i=1;i<=tot;i++)  fm[i]*=n;
        for(i=1;i<=tot;i++)
        if(fz[i]>0 && fm[i]>0)
        {
            t=min(fz[i],fm[i]);
            fz[i]-=t;fm[i]-=t;
        }
        memset(ans,0,sizeof(ans));
        ans[0]=1;ans[1]=1;
        for(i=1;i<=tot;i++)
        if(fz[i])
        {
            for(j=1;j<=fz[i];j++)   GJDchen(ans,prime[i],ans);
        }
        print();printf(" ");
        memset(ans,0,sizeof(ans));
        ans[0]=1;ans[1]=1;
        for(i=1;i<=tot;i++)
        if(fm[i])
        {
            for(j=1;j<=fm[i];j++)   GJDchen(ans,prime[i],ans);
        }
        print();printf("\n");
    }
    //system("pause");
    return 0;
}