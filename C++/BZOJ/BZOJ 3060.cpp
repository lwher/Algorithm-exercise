#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,k,ans,fa[1000010];
int A[2000010],B[2000010];
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
    if(fa[x]==0)  return x;
    return fa[x]=getfa(fa[x]);
}
int main()
{
    int i,x,y;
    n=read();m=read();k=read();
    for(i=1;i<=m;i++)
    {
        A[i]=read();B[i]=read();
        if(A[i]>k && B[i]>k)
        {
            x=getfa(A[i]);y=getfa(B[i]);
            if(x!=y)  fa[x]=y;
        }
    }
    for(i=1;i<=m;i++)
    if(A[i]<=k || B[i]<=k)
    {
        x=getfa(A[i]);y=getfa(B[i]);
        if(x!=y)  fa[x]=y;  else ans++;
    }
    printf("%d\n",ans);
    return 0;
}