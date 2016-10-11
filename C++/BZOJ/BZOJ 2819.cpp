#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,num[500010];
int stack[500010],top,shang[500010],fa[500010][20];
int tt,ft[500010],sd[500010],t[1000010],deep[500010];
int sz,to[1000010],pre[1000010],last[500010];
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dfs(int x)
{
    int i,now;
    ft[x]=++tt;stack[++top]=x;shang[1]=last[x];deep[x]=1;
    while(top>0)
    {
        now=stack[top];
        i=shang[top];
        if(to[i]==fa[now][0])  i=pre[i];
        if(i>0)
        {
            ft[to[i]]=++tt;
            shang[top]=pre[i];
            stack[++top]=to[i];
            fa[to[i]][0]=now;
            deep[to[i]]=deep[now]+1;
            shang[top]=last[to[i]];
        }
        else
        {
            sd[now]=++tt;top--;
        }
    }
}
void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
int lca(int a,int b)
{
    int i,c;
    if(deep[a]<deep[b])  swap(a,b);
    c=deep[a]-deep[b];
    for(i=19;i>=0;i--)  if(c>=(1<<i))  {c-=(1<<i);a=fa[a][i];}
    for(i=19;i>=0;i--)
    {
        if(fa[a][i]!=fa[b][i])  
        {
            a=fa[a][i];b=fa[b][i];
        }
    }
    if(a==b) return a; return fa[a][0];
}
int lowbit(int x)
{
    return x & (-x);
}
void add(int x,int k)
{
    for(int i=x;i<=n;i+=lowbit(i))  t[i]^=k;
}
int ask(int x)
{
    int i,now=0;
    for(i=x;i>0;i-=lowbit(i))  now^=t[i];
    return now;
}
int main()
{
    int i,j,a,b,tmp;
    char s[3];
    n=read();
    for(i=1;i<=n;i++) num[i]=read();
    for(i=1;i<n;i++)
    {
        a=read();b=read();
        Ins(a,b);Ins(b,a);
    }   
    dfs(1); 
    for(j=1;j<=19;j++)  for(i=1;i<=n;i++)  fa[i][j]=fa[fa[i][j-1]][j-1];
     
    n=n<<1; 
    for(i=1;i<=n/2;i++)  {add(ft[i],num[i]);add(sd[i],num[i]);}
    m=read();
    for(i=1;i<=m;i++)
    {
        scanf("%s",s);a=read();b=read();
        if(s[0]=='C')
        {
            add(ft[a],num[a]^b);add(sd[a],num[a]^b);
            num[a]=b;
        }
        else
        {
            tmp=ask(ft[a])^ask(ft[b])^num[lca(a,b)];
            if(tmp)  printf("Yes\n"); else printf("No\n");
        }
    }
    return 0;
}