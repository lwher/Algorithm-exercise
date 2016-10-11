#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 200010
using namespace std;
int n,k,sum,root,ans=N<<1;
int size[N],f[N],deep[N],d[N];
int hash[1000010];
int sz,to[N<<1],pre[N<<1],v[N<<1],last[N];
bool mark[N];
int stack[1000010],top;
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
}
void getroot(int x,int fa)
{
     size[x]=1;f[x]=0;
     int i=last[x];
     while(i>0)
     {
         if(to[i]!=fa && !mark[to[i]])
         {
             getroot(to[i],x);
             size[x]+=size[to[i]];
             f[x]=max(f[x],size[to[i]]);
         }
         i=pre[i];
     }
     f[x]=max(f[x],sum-size[x]);
     if(f[x]<f[root])  root=x;
}
void getsize(int x,int fa)
{
     size[x]=1;
     int i=last[x];
     while(i>0)
     {
         if(!mark[to[i]] && to[i]!=fa)
         {
             getsize(to[i],x); size[x]+=size[to[i]];
         }
         i=pre[i];
     }
}
void dfsans(int x,int fa)
{
     int i=last[x];
     if(d[x]==k)  ans=min(ans,deep[x]);
     if(d[x]<k && hash[k-d[x]]!=-1)   ans=min(ans,deep[x]+hash[k-d[x]]);
     i=last[x];
     while(i>0)
     {
         if(!mark[to[i]] && to[i]!=fa)
         {
              d[to[i]]=d[x]+v[i];
              deep[to[i]]=deep[x]+1;
              dfsans(to[i],x);
         }
         i=pre[i];
     }   
}
void dfshash(int x,int fa)
{
     if(d[x]<k && d[x]!=0)
     {
         if(hash[d[x]]==-1)   {hash[d[x]]=deep[x];stack[++top]=d[x];}
         else  hash[d[x]]=min(hash[d[x]],deep[x]);
     }
     int i=last[x];
     while(i>0)
     {
         if(!mark[to[i]] && fa!=to[i])  dfshash(to[i],x);
         i=pre[i];
     }
}
void calc(int x)
{
     int i=last[x];top=0;
     while(i>0)
     {
         if(!mark[to[i]])
         {
             d[to[i]]=v[i];deep[to[i]]=1;
             dfsans(to[i],x);
             dfshash(to[i],x);
         }
         i=pre[i];
     }
     while(top>0)  hash[stack[top--]]=-1;
}
void work(int x)
{
     calc(x);
     mark[x]=1;
     int i=last[x];
     while(i>0)
     {
         if(!mark[to[i]])
         {
             getsize(to[i],x);
             sum=size[to[i]];
             f[0]=sum;root=0;
             getroot(to[i],x);
             work(root);
         }   
         i=pre[i];
     }
}
int main()
{
    memset(hash,-1,sizeof(hash));
    int i,a,b,c;
    scanf("%d%d",&n,&k);
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        a++;b++;
        Ins(a,b,c);Ins(b,a,c);
    }    
    f[0]=n;root=0;sum=n;
    getroot(1,0);
    work(root);
    if(k==0)  ans=0;
    if(ans==(N<<1))printf("-1\n"); else printf("%d\n",ans);
    system("pause");
    return 0;
}
