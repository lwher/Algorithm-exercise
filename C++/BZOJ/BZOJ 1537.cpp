#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
    int x,y,p;
}cz[100010];
int n,m,K,ans;
int top,tot,shu[100010],num[100010];
int tmax[100010];
inline bool comp(sth a,sth b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
inline int find(int x)
{
    int l=1,r=tot,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(num[mid]==x) return mid;
        if(num[mid]>x) r=mid;
        else l=mid;
    }
    if(num[r]==x) return r; return l;
}
inline void updata(int x,int y)
{
    for(int i=x;i<=tot;i+=(i & (-i)))  tmax[i]=max(tmax[i],y);
}
inline int ask(int x)
{
    int i,tt=0;
    for(i=x;i;i-=(i & (-i))) tt=max(tt,tmax[i]);
    return tt;
}
int main()
{
    int i,p,tmp;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=K;i++)
    {
        scanf("%d%d%d",&cz[i].x,&cz[i].y,&cz[i].p);
        shu[++top]=cz[i].y;
    }
    sort(shu+1,shu+1+top);
    num[++tot]=shu[1];
    for(i=2;i<=top;i++) if(shu[i]!=shu[i-1]) num[++tot]=shu[i];
    sort(cz+1,cz+1+K,comp);
    for(i=1;i<=K;i++)
    {
        p=find(cz[i].y);
        tmp=ask(p)+cz[i].p;
        ans=max(tmp,ans);
        updata(p,tmp);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
