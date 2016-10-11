#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define sa_size 500001
#define sa_maxlen 255
int lg[sa_size];
void get_lg(int n){int i;for(i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);}
struct suffix_array
{
   char str[sa_size];
   int sa[sa_size],rank[sa_size],trank[sa_size],tsa[sa_size],sum[sa_size],height[sa_size];
   int l;
   void build()
   {
       int i,j,k,p=sa_maxlen;
       for(i=1;i<=p;++i)sum[i]=0;
       for(i=1;i<=l;++i)trank[i]=str[i];
       for(i=1;i<=l;++i)++sum[trank[i]];
       for(i=1;i<=p;++i)sum[i]+=sum[i-1];
       for(i=l;i>=1;--i)sa[sum[trank[i]]--]=i;
       rank[sa[1]]=1;p=1;
       for(i=2;i<=l;++i)
       {
           if(trank[sa[i]]!=trank[sa[i-1]])++p;
           rank[sa[i]]=p;
       }
       for(k=1;k<=l;k*=2)
       {
           for(i=1;i<=p;++i)sum[i]=0;
           for(i=1;i<=l;++i)++sum[rank[i+k]];
           for(i=1;i<=p;++i)sum[i]+=sum[i-1];
           for(i=l;i>=1;--i)tsa[sum[rank[i+k]]--]=i;
           for(i=1;i<=p;++i)sum[i]=0;
           for(i=1;i<=l;++i)++sum[rank[i]];
           for(i=1;i<=p;++i)sum[i]+=sum[i-1];
           for(i=l;i>=1;--i)sa[sum[rank[tsa[i]]]--]=tsa[i];
           trank[sa[1]]=1;p=1;
           for(i=2;i<=l;++i)
           {
               if(rank[sa[i]]!=rank[sa[i-1]]||rank[sa[i]+k]!=rank[sa[i-1]+k])++p;
               trank[sa[i]]=p;
           }
           for(i=1;i<=l;++i)rank[i]=trank[i];
       }
       for (i=1,k=0;i<=l;++i)
       {
           if(rank[i]==1)continue;
           for(;str[i+k]==str[sa[rank[i]-1]+k];)++k;
           height[rank[i]]=k;
           if(k>0)--k;
       }
   }
}a;
#define CartesianTree_size 500001
struct CartesianTree
{
   int num[CartesianTree_size],size[CartesianTree_size];
   int l[CartesianTree_size],r[CartesianTree_size],fa[CartesianTree_size];
   int st[CartesianTree_size];
   int S,root;
   void get_size(int now)
   {
       if(l[now])get_size(l[now]);
       if(r[now])get_size(r[now]);
       size[now]=size[l[now]]+size[r[now]]+1;
   }
   void build()
   {
       int i,top=0;bool dec;
       for(i=1;i<=S;++i)
       {
           dec=false;
           while(top&&num[i]<num[st[top]])
           {
               dec=true;
               --top;
           }
           r[st[top]]=i;
           fa[i]=st[top];
           if(dec)l[i]=st[top+1],fa[st[top+1]]=i;
           ++top;
           st[top]=i;
       }
       root=st[1];
       get_size(root);
   }
}tree;
int i,j,k;
long long ans,tmp,t,t1,t2;
void dfs(int now)
{
   int L=tree.l[now],R=tree.r[now];
   t1=tree.size[L]+1;
   t2=tree.size[R]+1;
   tmp=tree.num[now];
   tmp*=t1*t2;tmp*=2;
   ans-=tmp;
   if(L)dfs(L);
   if(R)dfs(R);
}
int main()
{
   scanf("%s",a.str+1);
   tree.S=a.l=strlen(a.str+1);a.build();
   for(i=1;i<=a.l;++i)tree.num[i]=a.height[i];
   tree.build();
   t1=a.l-1;
   for(t=1;t<=a.l;++t)ans+=t*t1;
   dfs(tree.root);
   printf("%lld\n",ans);
   system("pause");
   return 0;
}
