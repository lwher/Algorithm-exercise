#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,limt;
int pre[10010],last[1000010],PRE[10010];
int now[10010],ys[10010];
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void build()
{
     int i,k;
     for(i=1;i<=n;i++)  {pre[i]=last[ys[i]];now[i]=pre[i];last[ys[i]]=i;}
     for(i=1;i<=n;i+=limt)  
     {
         k=min(i+limt,n+1);
         sort(now+i,now+k);
     }
}
void rebuild()
{
     int i,j,t,l,r;
     for(i=1;i<=n;i++)  last[ys[i]]=0;
     for(i=1;i<=n;i++)  {PRE[i]=last[ys[i]];last[ys[i]]=i;}
     for(i=1;i<=n;i++)
     if(PRE[i]!=pre[i])
     {
         pre[i]=PRE[i];
         t=(i-1)/limt+1;
         l=(t-1)*limt+1; r=min(limt*t,n);
         for(j=l;j<=r;j++)  now[j]=pre[j];
         sort(now+l,now+r+1);
     }
}
int ask(int t,int w)
{
    int zuo=(t-1)*limt+1,l=(t-1)*limt+1,r=min(t*limt,n),mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(now[mid]>=w)  r=mid;
        else l=mid;
    }
    if(now[r]<w) return r-zuo+1;
    if(now[l]<w) return l-zuo+1;
    return 0;
}
int solve(int zuo,int you)
{
    int l=(zuo-1)/limt+1,r=(you-1)/limt+1,t,ans=0;
    for(t=l+1;t<r;t++)  ans+=ask(t,zuo);
    int i,k=min(l*limt,you);
    for(i=zuo;i<=k;i++)  if(pre[i]<zuo)  ans++;
    if(l!=r)
    {
        k=(r-1)*limt+1; for(i=k;i<=you;i++)  if(pre[i]<zuo)  ans++;
    }
    return ans;
}
int main()
{
    //freopen("maintain.in","r",stdin);
    //freopen("maintain.out","w",stdout);
    char ch[3];int i,a,b;
    n=read();m=read();
    limt=sqrt(n);
    for(i=1;i<=n;i++)  ys[i]=read();
    build();
    while(m--)
    {
        scanf("%s",ch);
        if(ch[0]=='R')
        {
            a=read();b=read();
            ys[a]=b;rebuild();
        }
        else
        {
            a=read();b=read();
            printf("%d\n",solve(a,b));
        }
    }
    system("pause");
    return 0;
}
