#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct point{
    int x,y;
}p[1010];
int n,L;
point operator -(const point &a,const point &b)
{
    point c;
    c.x=a.x-b.x;c.y=a.y-b.y;
    return c;
}
int operator *(const point &a,const point &b)
{
    return a.x*b.y-a.y*b.x;
}
int turnto(point a,point b,point c) //>0 œÚ”“
{
    return (c-a)*(b-a);
} 
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline bool comp(const point &a,const point &b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}
inline bool cmp(const point &a,const point &b)
{
    if(turnto(p[1],a,b)>0 || (turnto(p[1],a,b)==0 && dist(p[1],a)<dist(p[1],b))) return 1;
    else return 0;    
}
void init()
{
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
}
point tubao[1010];
int top=1;
double ans;
void solve()
{
    sort(p+1,p+1+n,comp);
    sort(p+2,p+1+n,cmp);
    tubao[1]=p[1];
    for(int i=2;i<=n;i++)
    {
        while(top>1 && turnto(tubao[top-1],tubao[top],p[i])<=0) top--;
        tubao[++top]=p[i];
    }
    tubao[++top]=p[1];
    for(int i=1;i<top;i++) ans+=dist(tubao[i],tubao[i+1]);
    ans+=acos(-1.00)*L*2;
    printf("%.0f\n",ans);
}
int main()
{
    init();
    solve();
    return 0;
}