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
}p[50010]; 
int n,top,tubao[50010];
point jian(point a,point b)
{
    point c;
    c.x=a.x-b.x;c.y=a.y-b.y;
    return c;
}
int sqr(int x) {return x*x;}
int dist(point a,point b)
{
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}
int chaji(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
int turnto(point a,point b,point c)
{
    return chaji(jian(c,a),jian(b,a));
}
inline bool comp(point a,point b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
inline bool cmp(point a,point b)
{
    int k=turnto(p[1],a,b);
    if(k>0 || (k==0 && dist(p[1],a)<dist(p[1],b))) return 1;
    return 0;  
}
void gettubao()
{
    int i;top=0;
    tubao[++top]=1;
    for(i=2;i<=n;i++)
    {
        while(top>1 && turnto(p[tubao[top-1]],p[tubao[top]],p[i])<=0) top--;
        tubao[++top]=i;
    }
}
int getS()
{
    int i,p1=2,q=3,a,b,c,d,next,ans=0;
    for(i=1;i<=top;i++)
    {
        a=tubao[i];b=tubao[p1];
        while(1)
        {
           next=q+1;if(next>top) next=1;
           c=tubao[q];d=tubao[next];
           if(abs(chaji(jian(p[c],p[a]),jian(p[b],p[a])))<abs(chaji(jian(p[d],p[a]),jian(p[b],p[a])))) q=next;
           else break;
        }
        ans=max(ans,abs(chaji(jian(p[c],p[a]),jian(p[b],p[a]))));
        while(1)
        {
           next=p1+1;if(next>top) next=1;
           b=tubao[p1];d=tubao[next];
           if(abs(chaji(jian(p[c],p[a]),jian(p[b],p[a])))<abs(chaji(jian(p[d],p[a]),jian(p[c],p[a])))) p1=next;
           else break;
        }
        ans=max(ans,abs(chaji(jian(p[c],p[a]),jian(p[b],p[a]))));
    }
    return ans;
}
int main()
{
    int i;
    while(scanf("%d",&n) && n!=-1)
    {
        for(i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
        sort(p+1,p+1+n,comp);
        sort(p+2,p+1+n,cmp);
        gettubao();
        printf("%.2lf\n",0.5*getS());
    }
    return 0;
}