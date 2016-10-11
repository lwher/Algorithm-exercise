#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int f[10][1050][201],blank[201],ans[201];
int k,w;
int Max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
void add(int c[],int a[],int b[])
{
    c[0]=max(a[0],b[0]);
    for(int i=1;i<=c[0];i++)
    {
        c[i]=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    while(c[c[0]+1])
    {
        c[0]++;
        c[c[0]+1]+=c[c[0]]/10;
        c[c[0]]%=10;
    }
}
void print(int a[])
{
    for(int i=a[0];i>=1;i--) printf("%d",a[i]);
    printf(" ");
}
int main()
{
    blank[0]=1;
    scanf("%d%d",&k,&w);
    int limit;
    limit=w%k;
    if(limit==0) limit=k;
    w=(w-limit)/k;
    limit=(1<<limit)-1;
    memset(f,0,sizeof(f));
    memset(blank,0,sizeof(blank));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<=limit;i++)
    {
        f[1][i][0]=1; f[1][i][1]=1;
    }
     if(w<=1)
     {
         f[1][0][0]=1; f[1][0][1]=0;
     }
     for(int i=2;i<=w+1;i++)
    {
        if(i<w)
        {
            f[i%2][0][0]=1; f[i%2][0][1]=1;
        }
        else
        {
            f[i%2][0][0]=1; f[i%2][0][1]=0;
        }
        for(int j=1;j<=(1<<k)-1;j++)
        {
            memcpy(f[i%2][j],blank,sizeof(blank));
            add(f[i%2][j],f[(i-1)%2][j-1],f[i%2][j]);
            if(j>1) add(f[i%2][j],f[i%2][j-1],f[i%2][j]);
        }
    }
    for(int i=0;i<=(1<<k)-1;i++)
        add(ans,ans,f[(w+1)%2][i]);
    for(int i=ans[0];i>=1;i--)
        printf("%d",ans[i]);
    printf("\n");
   // system("pause");
    return 0;
} 
