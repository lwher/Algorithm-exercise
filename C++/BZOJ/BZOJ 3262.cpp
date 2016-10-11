#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct flower
{
    int x,y,z,gs,dj;
}q[100010],p[100010];
inline bool comp(flower a,flower b)
{
    if(a.x==b.x)
    {
       if(a.y==b.y) return a.z<b.z;
       else return a.y<b.y;
    }    
    return a.x<b.x;
}
inline bool cmp(flower a,flower b)
{
    if(a.y==b.y) return a.z<b.z;
    return a.y<b.y;
}
int n,N,K,tsum[200010],ans[100010];
inline void add(int x,int k)
{
     for(int i=x;i<=K;i+=(i & (-i))) tsum[i]+=k;
}
int ask(int x)
{
     int tmp=0;
     for(int i=x;i;i-=(i & (-i))) tmp+=tsum[i];
     return tmp; 
}
void solve(int l,int r)
{
     if(l==r) return;
     int i,j,mid=(l+r)>>1;
     solve(l,mid);solve(mid+1,r);
     sort(p+l,p+mid+1,cmp);
     sort(p+mid+1,p+r+1,cmp);
     i=l;j=mid+1;     
     while(j<=r)
     {
         while(i<=mid && p[i].y<=p[j].y) 
         {
             add(p[i].z,p[i].gs);
             i++;
         }
         p[j].dj+=ask(p[j].z);
         j++;
     }
     for(j=l;j<i;j++) add(p[j].z,-p[j].gs);
}
int main()
{
    int i,ngs=0;
    scanf("%d%d",&N,&K);
    for(i=1;i<=N;i++) scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].z);
    sort(q+1,q+1+N,comp);
    for(i=1;i<=N;i++)
    {
        ngs++;
        if(q[i].x!=q[i+1].x || q[i].y!=q[i+1].y || q[i].z!=q[i+1].z) 
        {
            p[++n]=q[i];
            p[n].gs=ngs;
            ngs=0;
        }
    }        
    solve(1,n);
    for(i=1;i<=n;i++) ans[p[i].dj+p[i].gs-1]+=p[i].gs;
    for(i=0;i<N;i++) printf("%d\n",ans[i]);
    return 0;
}