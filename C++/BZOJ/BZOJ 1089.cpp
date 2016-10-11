#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,d,ans[5010];
int w[18][5010];
void mul(int a[],int b[],int c[])
{
    int i,j;
    memset(ans,0,sizeof(ans));
    for(i=1;i<=a[0];i++)  for(j=1;j<=b[0];j++)
    {
        ans[i+j-1]+=a[i]*b[j];
        if(ans[i+j-1]>=10000)
        {
            ans[i+j]+=ans[i+j-1]/10000;
            ans[i+j-1]%=10000;
        }
    }
    ans[0]=a[0]+b[0]-1;
    if(ans[ans[0]+1])  ans[0]++;
    for(i=0;i<=ans[0];i++)  c[i]=ans[i];
}
void add(int a[])
{
    int i=1;
    a[i]+=1;
    while(a[i]>=10000)
    {
         if(i==a[0])  {a[0]++;a[a[0]]=0;}
         a[i+1]++;
         a[i]-=10000;
         i++;
    }
}
void jian(int a[],int b[],int c[])
{
    int i;
    memset(ans,0,sizeof(ans));
    for(i=1;i<=a[0];i++)
    {
        if(a[i]<b[i])  {a[i+1]--;a[i]+=10000;}
        ans[i]=a[i]-b[i];
    }
    ans[0]=a[0];
    while(!ans[ans[0]] && ans[0]>1)  ans[0]--;
    for(i=0;i<=ans[0];i++)  c[i]=ans[i];  
}
void qpow(int A[],int b,int c[])
{
    int i,a[5010],now[5010];
    for(i=0;i<=A[0];i++)  a[i]=A[i];
    now[0]=1;now[1]=1;
    while(b>0)
    {
        if(b & 1)  mul(now,a,now);
        mul(a,a,a);
        b=b>>1;
    }
    for(i=0;i<=now[0];i++)  c[i]=now[i];
}
void print(int p[])
{
    int i;
    printf("%d",p[p[0]]);
    for(i=p[0]-1;i>0;i--)  printf("%.4d",p[i]);
    printf("\n");
}
int main()
{
    int i;
    scanf("%d%d",&n,&d);
    if(d==0)  printf("1\n");
    else
    {
        w[0][0]=1;w[0][1]=1;
        for(i=1;i<=d;i++)
        {
            qpow(w[i-1],n,w[i]);
            add(w[i]);
        }
        jian(w[d],w[d-1],w[d+1]);
        print(w[d+1]);
    }
    return 0;
}