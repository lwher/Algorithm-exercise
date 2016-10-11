#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=2147483648LL;
struct sth
{
    int x,y;
}p[100010];
int n,m,w,K,x[100010],y[100010];
int shu[200010],top,num[200010],tot;
int xgs[200010],ygs[200010],ny[200010];
long long c[100010][11],t[200010],ans;
inline bool comp(sth a,sth b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
int find(int x)
{
    int l=1,r=tot,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(num[mid]==x) return mid;
        if(num[mid]<x)  l=mid;
        else r=mid;
    }
    if(num[l]==x) return l; return r;
}
void init()
{
    int i;
    scanf("%d%d%d",&n,&m,&w);
    for(i=1;i<=w;i++) 
    {
        scanf("%d%d",&x[i],&y[i]);
        shu[++top]=x[i];shu[++top]=y[i];
    }
    sort(shu+1,shu+1+top);
    num[++tot]=shu[1];
    for(i=2;i<=top;i++)  if(shu[i-1]!=shu[i])   num[++tot]=shu[i];
    for(i=1;i<=w;i++)
    {
        p[i].x=find(x[i]);p[i].y=find(y[i]);
        xgs[p[i].x]++;ygs[p[i].y]++;
    }
    scanf("%d",&K);
}
void getC()
{
    c[0][0]=1;
    int i,j,k;
    for(i=1;i<=w;i++)
    {
        c[i][0]=1;k=min(K,i);
        for(j=1;j<=k;j++)  c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
}
void updata(int q,long long zhi)
{
    while(q<=w)
    {
        t[q]=(t[q]+zhi)%mod;
        q+=(q & (-q));
    }
}
long long ask(int q)
{
    long long sum=0;
    while(q>0)
    {
        sum=(sum+t[q])%mod;
        q-=(q & (-q));
    }
    return sum;
}
int main()
{
    init();
    int i,j,k,L=0;
    long long tmp,now;
    sort(p+1,p+1+w,comp);
    getC(); 
    for(i=1;i<=w;i++)
    {
        if(i>1 && p[i].x==p[i-1].x)
        {
            tmp=(ask(p[i].y-1)-ask(p[i-1].y))%mod;
            now=(c[xgs[p[i].x]-L][K]*c[L][K])%mod;
            ans+=(tmp*now)%mod;ans%=mod;
            L++;
        }
        else L=1;
        tmp=(c[ny[p[i].y]+1][K]*c[ygs[p[i].y]-ny[p[i].y]-1][K])%mod;
        now=tmp-(c[ny[p[i].y]][K]*c[ygs[p[i].y]-ny[p[i].y]][K])%mod;
        ny[p[i].y]++;now%=mod;
        updata(p[i].y,now);
    }
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
    //system("pause");
    return 0;
}