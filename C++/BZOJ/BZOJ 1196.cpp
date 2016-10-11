#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
    int u,v,next,first,second;
}e[50000];
int n,m,K,et;
int father[20000];
int getfather(int x)
{
    if(father[x]==x) return x;
    father[x]=getfather(father[x]);
    return father[x];
}
bool check(int lim)
{
    for(int i=1;i<=n;i++) father[i]=i;
    int num=0;
    for(int i=1;i<=et;i++)
        if(e[i].first<=lim)
        {
            int x=getfather(e[i].u),y=getfather(e[i].v);
            if (father[x]!=father[y])
            { 
                father[father[y]]=father[x];
                num++;
            }
        }
    if(num<K) return false;
    for(int i=1;i<=et;i++)
        if(e[i].second<=lim)
        {
            int x=getfather(e[i].u),y=getfather(e[i].v);
            if (father[x]!=father[y])
            { 
                father[father[y]]=father[x];
                num++;
            }
        }
    if (num==n-1) return true;
    else return false;
}
void add_edge(int x,int y,int c1,int c2)
{
    e[++et].u = x;
    e[et].v = y;
    e[et].first = c1;
    e[et].second = c2;
}
int main()
{
    scanf("%d%d%d",&n,&K,&m);
    int l=0,r=0;
    for(int i=1;i<m;i++)
    {
        int x,y,c1,c2;
        scanf("%d%d%d%d",&x,&y,&c1,&c2);
        add_edge(x,y,c1,c2);
        r=max(r,c1);
    }
    while(l<r)
    {
        if(l+1==r)  break;
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(!check(l)) l++;
    cout<<l<<endl;
    return 0;
}