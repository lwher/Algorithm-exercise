#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF  12345678
using namespace std;
int n,q,num;
int sz,to[200010],pre[200010],last[100010];
int cnt,d[1100010],pos[100010],color[100010];
int ls[1100010],rs[1100010],la[1100010],lb[1100010],ra[1100010],rb[1100010],dis[1100010];
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dfs(int x)
{
     d[++cnt]=-1;
     d[++cnt]=x;
     pos[x]=cnt;
     int i=last[x];
     while(i>0)
     {
         if(!pos[to[i]])  dfs(to[i]);
         i=pre[i];
     }
     d[++cnt]=-2;
}
void setup(int now,int x)
{
     if(d[x]==-2)  ls[now]=1;
     if(d[x]==-1)  rs[now]=1;
     dis[now]=-INF;
     la[now]=ra[now]=lb[now]=rb[now]=(d[x]>0 && color[d[x]]==0)?0:-INF;  
}
void updata(int x)
{
     int q=x+x,p=x+x+1;
     ls[x]=ls[q]+max(0,ls[p]-rs[q]);
     rs[x]=rs[p]+max(0,rs[q]-ls[p]);
     dis[x]=max(max(dis[q],dis[p]),max(ra[q]+lb[p],rb[q]+la[p]));
     la[x]=max(la[q],max(ls[q]-rs[q]+la[p],ls[q]+rs[q]+lb[p]));
     lb[x]=max(lb[q],rs[q]-ls[q]+lb[p]);
     ra[x]=max(ra[p],max(rs[p]+ls[p]+rb[q],rs[p]-ls[p]+ra[q]));
     rb[x]=max(rb[p],ls[p]-rs[p]+rb[q]);     
}
void build(int k,int l,int r)
{
     if(l==r)
     {
        setup(k,l);return;
     }
     int mid=(l+r)>>1;
     build(k+k,l,mid);build(k+k+1,mid+1,r);
     updata(k);
}
void change(int k,int l,int r,int x)
{
     if(l==r)
     {
        setup(k,l);return;
     }
     int mid=(l+r)>>1;
     if(x<=mid)  change(k+k,l,mid,x);
     else change(k+k+1,mid+1,r,x);
     updata(k);
}
int main()
{
    int i,a,b;
    scanf("%d",&n);num=n;
    for(i=1;i<n;i++)
    {
         scanf("%d%d",&a,&b);
         Ins(a,b);Ins(b,a);
    }
    dfs(1);
    build(1,1,cnt);
    char s[10];
    scanf("%d",&q);
    while(q--)
    {
         scanf("%s",s);
         if(s[0]=='G')
         {
            if(num==0)  printf("-1\n");  else
            if(num==1)  printf("0\n");   else
            printf("%d\n",dis[1]);
         }
         else
         {
             scanf("%d",&a);
             if(color[a]==0)  {num--;}
             else num++;
             color[a]^=1;
             change(1,1,cnt,pos[a]);
         }
    }
    system("pause");
    return 0;
}
