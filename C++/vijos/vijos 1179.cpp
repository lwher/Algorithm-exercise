#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m;
int stamp[41],ans[41];
int f[510];
int getmax(int sz)
{
    int i,t,j,tmp;
    f[0]=0;
    tmp=n*stamp[sz];
    for(i=1;i<=tmp;i++)
    {
        f[i]=n+1;
        for(j=1;j<=sz;j++)
        for(t=1;t<=n;t++)
        {
            if(i>=t*stamp[j] && f[i]>f[i-t*stamp[j]]+t)
            f[i]=f[i-t*stamp[j]]+t;
            if(i<t*stamp[j]) break;
        }
        if(f[i]>n)  return i-1;
    }
    return tmp;
} 
inline void ansdata(int now)
{
     if(now>=ans[0])
     {
         ans[0]=now;
         for(int i=1;i<=m;i++)  ans[i]=stamp[i];
     }
}
void dfs(int top,int lastmax)
{
     int i,nmax;
     for(i=stamp[top-1]+1;i<=lastmax+1;i++)
     {
         stamp[top]=i;
         nmax=getmax(top);
         if(top==m)  
         {ansdata(nmax);}
         else
         dfs(top+1,nmax);
     }
}
void print()
{
     int i;
     for(i=1;i<m;i++) printf("%d ",ans[i]);
     printf("%d\n",ans[m]);
     printf("MAX=%d\n",ans[0]);
}
int main()
{
    scanf("%d%d",&n,&m);
    stamp[1]=1;
    if(m==1) 
    {
         printf("1\n");
         printf("MAX=%d\n",n);     
    }
    else
    {
      dfs(2,n);
      print();
    }
    system("pause");
    return 0;
}
