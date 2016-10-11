#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct point
{
    int x,y;
}p[10010];
int n,ans,top,st[10010];
int dist(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
inline bool comp(point a,point b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
point jian(point a,point b)
{
    point c;
    c.x=a.x-b.x;c.y=a.y-b.y;
    return c;
}
int chaji(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
int turnto(point a,point b,point c) // >0  a->b ср ->c 
{ 
    return chaji(jian(c,a),jian(b,a));
}
inline bool cmp(point a,point b)
{
    if(turnto(p[1],a,b)>0 || (turnto(p[1],a,b)==0 && dist(p[1],a)<dist(p[1],b))) return 1;
    else return 0;
}
void solve()
{
    st[++top]=1;
    for(int i=2;i<=n;i++)
    {
        while(top>1 && turnto(p[st[top-1]],p[st[top]],p[i])<=0) top--;
        st[++top]=i;
    }
    st[++top]=st[1];
    for(int i=1;i<top;i++) ans+=chaji(p[st[i]],p[st[i+1]]);
    ans/=100;
    if(ans<0) ans=-ans;
    printf("%d\n",ans);
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
    sort(p+1,p+1+n,comp);
    sort(p+2,p+1+n,cmp);
    solve();
    system("pause");
    return 0;
}
