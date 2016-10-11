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
     int res=0,l,r,i,j;
     for(l=1,r=deep[0];l<r;)
     {
         if(deep[l]+deep[r]==k)
         {
             if(deep[l]==deep[r])
             {
                 res+=(r-l+1)*(r-l)/2;break;
             }
             else
             {
                 i=l; while(deep[l]==deep[i])  i++;
                 j=r; while(deep[r]==deep[j])  j--;
                 res+=(r-j)*(i-l);
                 l=i;r=j;
             }
         }
         else  if(deep[l]+deep[r]<k)  l++;  else r--;
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
bool solve()
{
        ans=0;
        memset(done,0,sizeof(done));
        f[0]=n;sum=n;root=0;
        getroot(1,0);     
        work(root);
        if(ans>0)  return 1; else return 0;
}
int main()
{
    int i,a,b,c;
    while(scanf("%d",&n)!=EOF && n)
    {
        sz=0;
        memset(last,0,sizeof(last));
        
        for(i=1;i<=n;i++)
        {
           while(scanf("%d",&a)!=EOF && a)
           {
               scanf("%d",&c);
               Ins(i,a,c);Ins(a,i,c);
           }
        }
        while(scanf("%d",&a) && a)
        {
            k=a;
            if(solve())  printf("AYE\n"); else printf("NAY\n");
        }
        printf(".\n");
    }
    system("pause");
    return 0;
}
