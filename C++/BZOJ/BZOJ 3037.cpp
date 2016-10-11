#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define inf 10000000
using namespace std;
int n,fa[1000010],father[1000010],cd[1000010],dui[1000010];
int sz,to[2000010],pre[2000010],last[1000010];
int top,A[1000010],B[1000010],f[1000010][2],ans;
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
int getfa(int x)
{
    if(father[x]==0)  return x;
    return father[x]=getfa(father[x]);
}
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dp(int x)
{
    if(last[x]==0)
    {
        f[x][1]=-inf;f[x][0]=0;return;
    }
    int i;
    f[x][0]=0;f[x][1]=1;
    for(i=last[x];i;i=pre[i])
    {
        f[x][0]+=max(f[to[i]][0],f[to[i]][1]);
    }
    for(i=last[x];i;i=pre[i])
    {
        f[x][1]=max(f[x][1],1+f[x][0]-max(f[to[i]][0],f[to[i]][1])+f[to[i]][0]);
    }
}
int main()
{
    int i,j,k,x,y,now,add,a,b;
    n=read();
    for(i=1;i<=n;i++)
    {
        k=read();
        x=getfa(k);y=getfa(i);
        if(x!=y)  
        {
            father[x]=y;Ins(k,i);fa[i]=k;cd[k]++;
        }
        else
        {
            fa[i]=-1;A[++top]=i;B[top]=k;
        }
    }
     
    int tou=1,wei=0;
    for(i=1;i<=n;i++)  if(cd[i]==0)  dui[++wei]=i;
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        dp(now);
        if(fa[now]!=-1)
        {
            cd[fa[now]]--;
            if(cd[fa[now]]==0)  dui[++wei]=fa[now];
        }
    }
    for(i=1;i<=top;i++)
    {
        x=A[i];y=B[i];
        add=f[x][1];k=0;
        for(j=last[y];j;j=pre[j])  k+=f[to[j]][1];
        if(f[y][1]<k+1)
        {
            f[y][1]=k+1;now=fa[y];
            while(now!=-1)
            {
                a=f[now][0];b=f[now][1];
                dp(now);
                if(a==f[now][0] && b==f[now][1])  break;
                now=fa[now];
            }
        }
        add=max(add,f[x][0]); ans+=add; 
    }
    printf("%d\n",ans);
    return 0;
}