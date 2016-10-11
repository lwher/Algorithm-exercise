#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string.h>
#define eps 1e-8
using namespace std;
struct sth
{
       double x1,x2,yy;
       bool jiajian;
}xd[410];
struct aaa
{
       int l,r;
       double y;
       bool kind;
}line[410];
double xx[410],x[410];
double ans;
struct saa
{
       double val;
       int f;
}tree[1000];
int n;
int sz;
int find(double a)
{
    int ll=1,rr=sz,mid;
    while(ll<rr)
    {
       if(ll+1==rr)
       {
        if(fabs(x[ll]-a)<eps)
        return ll;
        else
        return rr;
       }
       mid=(ll+rr)>>1;
       if(x[mid]>a)
       rr=mid;
       else
       ll=mid;
    }
}
void Ins(int left,int right,int zuo,int you,int k,bool o)
{
     if(left>you || right<zuo)
     return;
     if(left>=zuo && right<=you)
     {
        if(o)
        tree[k].f++;
        else
        tree[k].f--;
        if(tree[k].f>0)
        tree[k].val=x[right]-x[left];
        else
        {
           if(left+1<right)
           tree[k].val=tree[k<<1].val+tree[k<<1|1].val;
           else
           tree[k].val=0;
        }
        return;
     }
     int mid=(left+right)>>1;
     if(you<=mid)
     {Ins(left,mid,zuo,you,k<<1,o);}
     else
     if(zuo>=mid)
     {Ins(mid,right,zuo,you,k<<1|1,o);}
     else
     {
        Ins(left,mid,zuo,you,k<<1,o);
        Ins(mid,right,zuo,you,k<<1|1,o);
     }
     if(tree[k].f==0)
     tree[k].val=tree[k<<1].val+tree[k<<1|1].val;
     return;
}
inline bool comp(aaa a,aaa b)
{
       return a.y<b.y;
}
int main()
{
    double a,b,d,c;
    int i,j=1;
    while(scanf("%d",&n))
    {
       if(n==0) break;
       ans=0;
       for(i=1;i<=n;i++)
       {
         scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
         xd[i*2-1].x1=a;xd[i*2-1].x2=c;xd[i*2-1].yy=b;xd[i*2-1].jiajian=1;
         xd[i*2].x1=a;xd[i*2].x2=c;xd[i*2].yy=d;xd[i*2].jiajian=0;
         xx[i*2-1]=a;xx[i*2]=c;
       }
       sort(xx+1,xx+1+2*n);
       x[1]=xx[1];
       sz=1;
       for(i=2;i<=2*n;i++)
       if(fabs(xx[i]-xx[i-1])>eps)
       {sz++;x[sz]=xx[i];}
       for(i=1;i<=2*n;i++)
       {
          line[i].l=find(xd[i].x1);line[i].r=find(xd[i].x2);line[i].y=xd[i].yy;line[i].kind=xd[i].jiajian;
       }
       sort(line+1,line+1+2*n,comp);
       memset(tree,0,sizeof(tree));
       Ins(1,sz,line[1].l,line[1].r,1,line[1].kind);
       double ll=line[1].y;
       for(i=2;i<=2*n;i++)
       {
         ans+=(line[i].y-ll)*tree[1].val;
         ll=line[i].y;
         Ins(1,sz,line[i].l,line[i].r,1,line[i].kind);
       }
       
       printf("Test case #%d\n",j);
       printf("Total explored area: %.2f\n\n",ans);
       j++;
    }
    
    system("pause");
    return 0;
}
