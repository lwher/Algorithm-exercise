#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,sz,rt,tmp;
ll ans;
int v[100001],l[100001],r[100001],rnd[100001],w[100001];
struct data{int a,b;}a[100001],b[100001];
void init()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].a,&a[i].b);
    for(int i=1;i<=m;i++)scanf("%d%d",&b[i].a,&b[i].b);
}
bool cmp(data a,data b){return a.b>b.b;}
void rturn(int &k)
{int t=l[k];l[k]=r[t];r[t]=k;k=t;}
void lturn(int &k)
{int t=r[k];r[k]=l[t];l[t]=k;k=t;}
void insert(int &k,int x)
{
    if(!k){k=++sz;v[k]=x;w[k]=1;rnd[k]=rand();return;}
    if(x==v[k])w[k]++;
    else if(x<v[k]){insert(l[k],x);if(rnd[l[k]]<rnd[k])rturn(k);}
    else {insert(r[k],x);if(rnd[r[k]]<rnd[k])lturn(k);}
}
void del(int &k,int x)
{
    if(x==v[k])
    {
        if(w[k]>1)w[k]--;
        else if(l[k]*r[k]==0)k=l[k]+r[k];
        else if(rnd[l[k]]<rnd[r[k]]){rturn(k);del(k,x);}
        else {lturn(k);del(k,x);}
    }
    else if(x<v[k])del(l[k],x);
    else del(r[k],x);
}
void find(int k,int x)
{
    if(!k)return;
    if(v[k]>=x){tmp=v[k];find(l[k],x);}
    else find(r[k],x);
}
void solve()
{
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+m+1,cmp);
    int j=1;
    for(int i=1;i<=n;i++)
    {
        tmp=-1;
 
        while(b[j].b>=a[i].b&&j<=m){insert(rt,b[j].a);j++;}
        find(rt,a[i].a);
        if(tmp==-1){puts("-1");return;}
        ans+=tmp;del(rt,tmp);
    }
    printf("%lld\n",ans);
}
int main()
{
    init();
    solve();
    return 0;
}