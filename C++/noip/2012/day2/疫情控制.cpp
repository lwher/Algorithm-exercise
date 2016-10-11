#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
       long long vv;
       int shang,FROM;
}budui[50010]; 
struct aaa
{
       int cbh;
       long long len;
}chengshi[50010];
int n,m,sum;
int sz,to[100010],pre[100010],last[50010];
int wz[50010],shuyu[50010],fa[50010][17];
long long dist[50010],v[100010];
long long l,r,mid;
bool mark[50010],yz[50010];
int bs,cs;
int end[50010];
int chenshi[50010];
inline bool cmp1(int a,int b)
{
       return dist[a]>dist[b];
}
inline bool cmp2(int a,int b)
{
       return dist[a]<dist[b];
}
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
}
void dfs(int x)
{
     int i=last[x];bool o=0;
     mark[x]=1;
     while(i>0)
     {
         if(!mark[to[i]])
         {
             o=1;fa[to[i]][0]=x;dist[to[i]]=dist[x]+v[i];
             dfs(to[i]);
         }
         i=pre[i];
     }
     if(!o)  yz[x]=1;
}
void clfa(int x,int belong)
{
     int i;
     mark[x]=1;shuyu[x]=belong;
     for(i=1;i<=15;i++)
     fa[x][i]=fa[fa[x][i-1]][i-1];
     i=last[x];
     while(i>0)
     {
         if(!mark[to[i]])  
         {
            if(x==1) clfa(to[i],to[i]);
            else     clfa(to[i],belong);
         }
         i=pre[i];
     }
}
void init()
{
     int i,a,b,c;
     scanf("%d",&n);
     for(i=1;i<n;i++)
     {
        scanf("%d%d%d",&a,&b,&c);
        r+=c;
        Ins(a,b,c);Ins(b,a,c);
     }
     scanf("%d",&m);
     for(i=1;i<=m;i++)  scanf("%d",&wz[i]);
}
bool DFS(int x,int from)
{
     if(mark[x])  return 0;
     if(yz[x])    return 1;
     int i=last[x];
     while(i>0)
     {
          if(to[i]!=from)  
          {
              if(DFS(to[i],x))  return 1;
          }
          i=pre[i];
     }
     return 0;
}
bool check(long long kk)
{
     int i,j,k;
     long long shen;
     bs=0;
     memset(mark,0,sizeof(mark));
     for(i=1;i<=m;i++)
     {
         k=wz[i];
         shen=kk;
         for(j=15;j>=0;j--)
         if(fa[k][j] && dist[k]-dist[fa[k][j]]<=shen)
         {
             shen-=dist[k]-dist[fa[k][j]];k=fa[k][j];
         }
         if(k==1)  
         {bs++;budui[bs].vv=shen;budui[bs].FROM=shuyu[wz[i]];}
         else   mark[k]=1;
     }
     cs=0;
     for(i=1;i<=sum;i++)
     if(DFS(chenshi[i],1))  
     {cs++;chengshi[cs].cbh=chenshi[i];chengshi[cs].len=dist[chenshi[i]];}
     if(bs<cs)  return 0;
     memset(mark,0,sizeof(mark));
     memset(end,0,sizeof(end));
     for(i=1;i<=bs;i++)
     {
          budui[i].shang=end[budui[i].FROM];
          end[budui[i].FROM]=i;
     }
     bool flag;
     k=1;
     for(i=1;i<=cs;i++)
     {
         flag=0;
         j=end[chengshi[i].cbh];
         while(j>0)
         {
             if(!mark[j])
             {
                 mark[j]=1;flag=1;break;
             }
             j=budui[j].shang;
         }
         if(!flag)
         {
              while(k<=bs && (mark[k] || budui[k].vv<chengshi[i].len))  k++;
              if(k>bs)  return 0;
              mark[k]=1;k++;
         }
     }
     return 1;
}
void solve()
{
     init();
     dfs(1);
     int i=last[1];
     while(i>0)  {sum++;chenshi[sum]=to[i];i=pre[i];}
     if(sum>m)  {cout<<-1<<endl;return;}
     sort(chenshi+1,chenshi+1+sum,cmp1);
     sort(wz+1,wz+1+m,cmp2);
     memset(mark,0,sizeof(mark));
     clfa(1,n+1);
     while(l+1<r)
     {
        mid=(l+r)>>1;
        if(check(mid))  r=mid;
        else l=mid;
     }
     if(check(l))  cout<<l<<endl;
     else cout<<r<<endl;
}
int main()
{
    //freopen("blockade.in","r",stdin);
   // freopen("blockade.out","w",stdout);
    solve();
    //system("pause");
    return 0;
}
