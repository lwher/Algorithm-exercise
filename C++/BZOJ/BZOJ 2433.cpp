#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define eps 1e-10
using namespace std;
struct point
{
    double x,y;
    int id;
}p[8010];
struct xian
{
    point p1,p2;
    double x;
    int id;
    bool isST;
}line[8010];
int n,s,t,psz,lsz;
int sz,to[7000010],pre[7000010],last[8010];
double d[8010],V,v[7000010];
bool mark[8010];
inline void Ins(int a,int b,double c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
inline double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void addline(point a,point b,double x,bool o)
{
    line[++lsz].p1=a;line[lsz].p2=b;line[lsz].x=x;line[lsz].isST=o;line[lsz].id=lsz;
}
void addpoint(double x,double y)
{
    p[++psz].x=x;p[psz].y=y;p[psz].id=psz;
}
inline bool comp(point a,point b)
{
    if(fabs(a.x-b.x)<eps) return a.y<b.y;
    return a.x<b.x;
}
inline bool cmp(xian a,xian b)
{  
    if(fabs(a.x-b.x)<eps) return a.id<b.id;
    return a.x<b.x;
}
point jian(point a,point b)
{
    point c;
    c.x=a.x-b.x;c.y=a.y-b.y;
    return c;
}
double chaji(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
double turnto(point a,point b,point c)
{
    return chaji(jian(c,a),jian(b,a));
}
void init()
{
    int i,j;double x1,x2,y1,y2;
    point low,high;
    scanf("%d",&n);
    for(i=1;i<=n;i++) 
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        addpoint(x1,y2);addpoint(x1,y1);
        addline(p[psz-1],p[psz],x1,0);
        addpoint(x2,y2);addpoint(x2,y1);
        addline(p[psz-1],p[psz],x2,0);
    } 
    scanf("%lf%lf",&x1,&y1);addpoint(x1,y1);
    addline(p[psz],p[0],p[psz].x,1);
    scanf("%lf%lf",&x1,&y1);addpoint(x1,y1);
    addline(p[psz],p[0],p[psz].x,1);
    scanf("%lf",&V);
    n=psz;
    s=n-1;t=n;
    if(p[n-1].x>p[n].x) s=n,t=n-1;    
    sort(p+1,p+1+n,comp);
    sort(line+1,line+1+lsz,cmp);                
    for(i=1;i<=n;i++)
    {
        high.x=low.x=p[i].x;
        high.y=100000;low.y=-100000;
        for(j=1;j<=lsz;j++)
        {
            if(fabs(line[j].x-p[i].x)<eps)
            {
                Ins(p[i].id,line[j].p1.id,dist(p[i],line[j].p1));
                if(!line[j].isST) 
                {
                    Ins(p[i].id,line[j].p2.id,dist(p[i],line[j].p2)); 
                    if(turnto(p[i],high,line[j].p1)>-eps) high=line[j].p1;
                    if(turnto(p[i],low,line[j].p2)<eps) low=line[j].p2;
                }
            } 
            else
            if(line[j].x>p[i].x) 
            {
                if(line[j].isST) 
                {
                   if(turnto(p[i],high,line[j].p1)>-eps && turnto(p[i],low,line[j].p1)<eps) 
                   Ins(p[i].id,line[j].p1.id,dist(p[i],line[j].p1));
                }
                else
                {
                    if(turnto(p[i],high,line[j].p1)>-eps && turnto(p[i],low,line[j].p1)<eps) 
                    Ins(p[i].id,line[j].p1.id,dist(p[i],line[j].p1));
                    if(turnto(p[i],high,line[j].p2)>-eps && turnto(p[i],low,line[j].p2)<eps) 
                    Ins(p[i].id,line[j].p2.id,dist(p[i],line[j].p2));
                    if(turnto(p[i],high,line[j].p1)>-eps) high=line[j].p1;
                    if(turnto(p[i],low,line[j].p2)<eps) low=line[j].p2;
                }
            }
            if(turnto(p[i],low,high)>eps) break;
        }
    }
}
void dij()
{
    int i,j,k;double minn;
    for(i=1;i<=n;i++) d[i]=1e20;
    d[s]=0;
    for(i=1;i<=n;i++)
    {
        k=0;minn=1e20;
        for(j=1;j<=n;j++) if(!mark[j] && d[j]<minn) minn=d[j],k=j;
        mark[k]=1;
        for(j=last[k];j;j=pre[j]) if(!mark[to[j]] && d[to[j]]>d[k]+v[j]) d[to[j]]=d[k]+v[j];
    }
}
int main()
{
    init();    
    dij();
    printf("%.10lf\n",d[t]/V);
    return 0;
}