#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define eps 1e-8
using namespace std;
int n,L,R,maxnum,sum,root,size[100010],f[100010],deep[100010],Q[100010],q[100010],from[100010],Q2[100010],dui[100010];
int sz,to[200010],pre[200010],v[200010],last[100010];
double ans,d[100010];
bool mark[100010];
inline int max(int a,int b)
{
    if(a>b) return a; return b;
}
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void getroot(int x,int fa)
{
     size[x]=1;f[x]=0;
     for(int i=last[x];i;i=pre[i])
     {
         if(mark[to[i]] || to[i]==fa)  continue;
         getroot(to[i],x);
         size[x]+=size[to[i]];
         f[x]=max(f[x],size[to[i]]);
     }
     f[x]=max(f[x],sum-size[x]);
     if(f[root]>f[x])  root=x;
}
void getsize(int x,int fa)
{
     size[x]=1;
     for(int i=last[x];i;i=pre[i])
     {
         if(mark[to[i]] || to[i]==fa)  continue;
         getsize(to[i],x);
         size[x]+=size[to[i]];
     }
}
bool check(int x,double mid)
{
     int i,j,top=0,tou,wei,now;
     for(j=last[x];j;j=pre[j])
     {
         if(mark[to[j]])  continue; 
         tou=1;wei=0;
         deep[to[j]]=1;
         d[to[j]]=double(v[j])-mid;
         from[to[j]]=x;
         dui[++wei]=to[j];
         while(tou<=wei)
         {
             now=dui[tou];tou++;
             for(i=last[now];i;i=pre[i])
             {
                 if(mark[to[i]] || to[i]==from[now])  continue;
                 deep[to[i]]=deep[now]+1;
                 d[to[i]]=d[now]+v[i]-mid;
                 from[to[i]]=now;
                 dui[++wei]=to[i];
             }
         }
         int tmp=wei,l=1,r=0;
         wei=top;
         for(i=1;i<=tmp;i++)
         {
             while(wei>0 && deep[dui[i]]+deep[Q[wei]]>=L)  
             {
                while(l<=r && d[q[r]]<d[Q[wei]])  r--;
                q[++r]=Q[wei];
                wei--;
             }
             while(l<=r && deep[dui[i]]+deep[q[l]]>R)  l++;
             if(l<=r && d[q[l]]+d[dui[i]]>-eps)  return 1;
             if(deep[dui[i]]>=L && deep[dui[i]]<=R && d[dui[i]]>-eps)  return 1;
         }
         l=1;r=1;int top1=0;
         while(l<=tmp && r<=top)
         {
             top1++;
             if(deep[Q[r]]<=deep[dui[l]])  {Q2[top1]=Q[r];r++;}
             else  {Q2[top1]=dui[l];l++;}
         }
         while(l<=tmp)
         {
             Q2[++top1]=dui[l];l++;
         }
         while(r<=top)
         {
             Q2[++top1]=Q[r];r++;
         }
         top=top1;
         for(i=1;i<=top;i++)  Q[i]=Q2[i];
     }
     return 0;
}
void calc(int x)
{
     double l=ans,r=maxnum,mid;
     while(r-l>0.00001)
     {
         mid=(l+r)*0.5;
         if(check(x,mid))  l=mid;
         else r=mid;
     }
     ans=l;
}
void work(int x)
{
     calc(x);
     mark[x]=1;
     for(int i=last[x];i;i=pre[i])
     {
         if(mark[to[i]])  continue;
         getsize(to[i],x);
         sum=size[to[i]];f[0]=sum;root=0;
         getroot(to[i],x);
         work(root);
     }
}
int main()
{
    int i,a,b,c;
    scanf("%d%d%d",&n,&L,&R);
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        maxnum=max(maxnum,c);
        Ins(a,b,c);Ins(b,a,c);
    }
    sum=n;f[0]=n;root=0;
    getroot(1,0);
    work(root);
    printf("%.3lf\n",ans);
    system("pause");
    return 0;
}
