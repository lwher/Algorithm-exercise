#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
struct sth
{
    int to[26];
}p[300010];
int n,sz,len;
char s[300010],ch[300010];
int tot,num[100010],pre[100010],last[300010];
int w[100010],dfsxu[100010],tt,ft[300010],sd[300010];//w[i]: 第i个串的尾标记在数中的位置     first+1 --> second
int SZ,ls[3000010],rs[3000010],sum[3000010],root[100010];
void charu(int a,int b)  //  在树上的a节点插入 b串的尾标记 
{
     tot++;num[tot]=b;pre[tot]=last[a];last[a]=tot;
}
void Ins(int x,int top,int bh)
{
     if(top==len+1)  {charu(x,bh);w[bh]=x;return;}
     int k=s[top]-'a';
     if(!p[x].to[k])  p[x].to[k]=++sz;
     Ins(p[x].to[k],top+1,bh);
}
void init()
{
     int i,j;
     scanf("%d",&n);
     for(i=1;i<=n;i++) 
     {
         scanf("%s",ch+1);len=strlen(ch+1);
         for(j=1;j<=len;j++)  s[j]=ch[len-j+1];
         Ins(0,1,i);
     }
}
void dfs(int x)
{
     int i=last[x];ft[x]=tt;
     while(i>0) {dfsxu[++tt]=num[i];i=pre[i];}
     for(i=0;i<26;i++)  if(p[x].to[i])  dfs(p[x].to[i]);
     sd[x]=tt;
}
void build(int l,int r,int x,int &y,int shu)
{
     y=++SZ;
     sum[y]=sum[x]+1;
     ls[y]=ls[x];rs[y]=rs[x];
     if(l==r)  return;
     int mid=(l+r)>>1;
     if(shu<=mid)  build(l,mid,ls[x],ls[y],shu);
     else  build(mid+1,r,rs[x],rs[y],shu);
}
int ask(int x,int y,int l,int r,int k)
{
    if(l==r)  return l;
    int mid=(l+r)>>1;
    if(sum[ls[y]]-sum[ls[x]]>=k)  return ask(ls[x],ls[y],l,mid,k);
    else  return ask(rs[x],rs[y],mid+1,r,k-(sum[ls[y]]-sum[ls[x]]));
}
void solve()
{
     int i,k,q;     
     for(i=1;i<=n;i++)  build(1,n,root[i-1],root[i],dfsxu[i]);     
     for(i=1;i<=n;i++)  
     {
         scanf("%d",&k);
         q=w[i];
         if(sd[q]-ft[q]<k)  printf("-1\n");
         else  printf("%d\n",ask(root[ft[q]],root[sd[q]],1,n,k));
     }
}
int main()
{
    init();
    dfs(0);    
    solve();
    system("pause");
    return 0;
}
