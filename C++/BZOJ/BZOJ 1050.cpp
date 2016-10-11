#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
struct sth
{
       int from,to,v;
}lu[5010];
int n,m,s,t;
int fa[510];
int na,nb;
bool o;
double nans=1e20;
inline bool comp(sth a,sth b)
{
       return a.v<b.v;
}
void init()
{
     int i;
     scanf("%d%d",&n,&m);
     for(i=1;i<=m;i++)  scanf("%d%d%d",&lu[i].from,&lu[i].to,&lu[i].v);
     sort(lu+1,lu+1+m,comp);
     scanf("%d%d",&s,&t);
}
int getfa(int x)
{
    if(fa[x]==0)  return x;
    else  return fa[x]=getfa(fa[x]);
}
bool check(int l,int r)
{
     if(l>r) return 0;
     int i,x,y;
     memset(fa,0,sizeof(fa));
     for(i=l;i<=r;i++)
     {
         x=getfa(lu[i].from);y=getfa(lu[i].to);
         if(x!=y)  fa[x]=y;
     }
     x=getfa(s);y=getfa(t);
     if(x==y) return 1;  else return 0;
}
void solve()
{
     int l=1,r=1;
     double now;
     while(1)
     {
             if(r>m)  break;
             if(check(l,r))  
             {
                             now=double(lu[r].v)/lu[l].v;
                             if(now<nans)
                             {o=1;nans=now;na=lu[r].v;nb=lu[l].v;}
                             l++;
             }
             else  r++;
     }
}
int gcd(int a,int b)
{
    if(b==0)  return a;
    else return gcd(b,a%b);
}
int main()
{
    init();
    solve();
    if(!o)  printf("IMPOSSIBLE\n");
    else
    {
    if(na%nb==0)  cout<<na/nb<<endl;
    else
    cout<<na/gcd(na,nb)<<"/"<<nb/gcd(na,nb)<<endl;
    }
    system("pause");
    return 0;
}
