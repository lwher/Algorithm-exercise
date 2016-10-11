#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,sum,ans,root;
int sz,to[20010],pre[20010],last[10010],v[20010];
bool done[10010];
int f[10010],size[10010],d[10010];
int deep[10010];
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void getroot(int x,int fa)
{
     int i=last[x];size[x]=1;f[x]=0;
     while(i>0)
     {
         if(to[i]!=fa && !done[to[i]])
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
void getdep(int x,int fa)
{
     int i=last[x];size[x]=1;
     deep[0]++;deep[deep[0]]=d[x];
     while(i>0)
     {
         if(to[i]!=fa && !done[to[i]])
         {
             d[to[i]]=d[x]+v[i];
             getdep(to[i],x);
             size[x]+=size[to[i]];
         }
         i=pre[i];
     }
}
int calc(int x,int now)
{
     d[x]=now;deep[0]=0;
     getdep(x,0);
     sort(deep+1,deep+deep[0]+1);
     int res=0,l,r;
     for(l=1,r=deep[0];l<r;)
     {
          if(deep[l]+deep[r]<=k)  {res+=r-l;l++;}
          else  r--;
     }
     return res;
}
void work(int x)
{
     ans+=calc(x,0);
     done[x]=1;
     int i=last[x];
     while(i>0)
     {
         if(!done[to[i]])
         {
              ans-=calc(to[i],v[i]);
              sum=size[to[i]];
              f[0]=sum;root=0;
              getroot(to[i],root);
              work(root);
         }
         i=pre[i];
     }
}
int main()
{
    int i,a,b,c;
    while(scanf("%d%d",&n,&k)==2)
    {
        if(n==0 && k==0)  break;
        ans=0;sz=0;
        memset(last,0,sizeof(last));
        memset(done,0,sizeof(done));
        for(i=1;i<n;i++)
        {
           scanf("%d%d%d",&a,&b,&c);
           Ins(a,b,c);
           Ins(b,a,c);
        }
        f[0]=n;sum=n;root=0;
        getroot(1,0);     
        work(root);
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
