#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m,num[1000010],fa[1000010],root[1000010];
int ls[1000010],rs[1000010],dis[1000010];
bool killed[1000010];
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
void swap(int &a,int &b)
{
     int t=a;a=b;b=t;
}
int merge(int a,int b)
{
    if(!a || !b)  return a+b;
    if(num[a]>num[b])  swap(a,b);
    rs[a]=merge(rs[a],b);
    if(dis[ls[a]]<dis[rs[a]]) swap(ls[a],rs[a]);
    dis[a]=dis[rs[a]]+1;
    return a;
}
int main()
{
    int i,x,y,a,b;char ch[3];
    dis[0]=-1;
    n=read();//scanf("%d",&n);
    for(i=1;i<=n;i++) 
    {
       num[i]=read();//scanf("%d",&num[i]);
       root[i]=i;
    }
    m=read();//scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='M')
        {
           a=read();b=read();//scanf("%d%d",&a,&b);
           if(killed[a] || killed[b])  continue;
           x=getfa(a);y=getfa(b);
           if(x!=y)
           {
               fa[x]=y;
               root[y]=merge(root[x],root[y]);
           }
        }
        else
        {
            x=read();//scanf("%d",&x);
            if(killed[x])  printf("0\n");
            else
            {
                y=getfa(x);
                printf("%d\n",num[root[y]]);
                killed[root[y]]=1;
                root[y]=merge(ls[root[y]],rs[root[y]]);
            }
        }
    }
    system("pause");
    return 0;
}
