#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct point 
{
    int x,y;
}p[100010];
struct line
{
    int k,l,r,t;
}le[300010];
int n,top,num[300010],shu[300010],tot,sz,t[300010];
inline bool cmp1(point a,point b)
{
    if(a.x==b.x)  return a.y<b.y;  return a.x<b.x;
}
inline bool cmp2(point a,point b)
{
    if(a.y==b.y)  return a.x<b.x;  return a.y<b.y;
}
inline bool cmp3(line a,line b)
{
    if(a.t==b.t)  return a.k<b.k;  return a.t<b.t;
}
int find(int x)
{
    int l=1,r=tot,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(num[mid]==x)  return mid;
        if(num[mid]>x) r=mid;
        else l=mid; 
    }
    if(num[l]==x) return l; return r;
}
void addline(int k,int l,int r,int w)
{
    if(k==0)  
    {
        le[++sz].k=0;le[sz].t=w;le[sz].l=l;le[sz].r=r;
    }
    else
    {
        le[++sz].k=1;le[sz].t=l;le[sz].l=w;
        le[++sz].k=-1;le[sz].t=r;le[sz].l=w;
    }
}
void makeline()
{
    int i;
    sort(p+1,p+1+n,cmp1);
    for(i=2;i<=n;i++)  if(p[i].x==p[i-1].x)  addline(0,find(p[i-1].y),find(p[i].y),find(p[i].x));
    sort(p+1,p+1+n,cmp2);
    for(i=2;i<=n;i++)  if(p[i].y==p[i-1].y)  addline(1,find(p[i-1].x),find(p[i].x),find(p[i].y));
}
void add(int x,int q)
{
    while(x<=tot){t[x]+=q;x+=(x & (-x));}
}
int ask(int x)
{
    int sum=0;
    while(x>0) {sum+=t[x];x-=(x & (-x));}
    return sum;
}
int solve()
{
    int i,sum=0;
    sort(le+1,le+1+sz,cmp3);
    for(i=1;i<=sz;i++)
    {
        if(le[i].k==0)  sum+=ask(le[i].r)-ask(le[i].l);
        else  add(le[i].l,le[i].k);
    }
    return sum;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        shu[++top]=p[i].x;shu[++top]=p[i].y;
    }    
    sort(shu+1,shu+1+top);
    num[++tot]=shu[1];
    for(i=2;i<=top;i++)  if(shu[i]!=shu[i-1])  num[++tot]=shu[i];
    makeline(); 
    printf("%d\n",solve()+n);
    //system("pause");
    return 0;
}