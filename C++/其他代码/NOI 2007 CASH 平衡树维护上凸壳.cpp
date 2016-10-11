#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 100010
#define eps 1e-9
#define INF 1e9
using namespace std;
int fa[N],c[N][2],n,rot;
double lk[N],rk[N],a[N],b[N],rate[N],f[N],x[N],y[N];
void rotate(int x,int &root)
{
     int y=fa[x],z=fa[y],p,q;
     if(c[y][0]==x)  p=0;  else p=1;   q=p^1;
     if(y==root)   root=x;
     else
     {
         if(c[z][0]==y) c[z][0]=x;  else c[z][1]=x;
     }
     fa[x]=z;fa[y]=x;fa[c[x][q]]=y;
     c[y][p]=c[x][q];c[x][q]=y;
}
void splay(int x,int &root)
{
     int y,z;
     while(x!=root)
     {
         y=fa[x];z=fa[y];
         if(y!=root)
         {
             if((c[y][0]==x) ^ (c[z][0]==y))  rotate(x,root);
             else rotate(y,root);
         }
         rotate(x,root);
     }
}
double getk(int a,int b)
{
       if(fabs(x[a]-x[b])<eps)  return INF;
       return (y[b]-y[a])/(x[b]-x[a]);   
}
int find(int x,double k)
{
     if(x==0) return 0;
     if((lk[x]>k || fabs(lk[x]-k)<eps) && (rk[x]<k || fabs(rk[x]-k)<eps))  return x;
     if(lk[x]>k || fabs(lk[x]-k)<eps)  return find(c[x][1],k);
     else return find(c[x][0],k);
}
void Ins(int &wei,int t,int last)
{
     if(wei==0)
     {
               wei=t;fa[t]=last;
               splay(t,rot);
               return;
     }
     if(x[wei]<x[t])  Ins(c[wei][1],t,wei);
     else Ins(c[wei][0],t,wei);
}
int getnext()
{
    int t=c[rot][1],tmp=t;
    double k;
    while(t)
    {
            k=getk(rot,t);
            if(k>rk[t] || fabs(k-rk[t])<eps)  {tmp=t;t=c[t][0];}
            else t=c[t][1];  
    }
    return tmp;
}
int getpre()
{
    int t=c[rot][0],tmp=t;
    double k;
    while(t)
    {
            k=getk(t,rot);
            if(k<lk[t] || fabs(k-lk[t])<eps)  {tmp=t;t=c[t][1];}
            else t=c[t][0];  
    }
    return tmp;
}
void updata()
{
     if(c[rot][0])
     {
        int left=getpre();
        splay(left,c[rot][0]);
        lk[rot]=getk(left,rot);
        rk[left]=getk(left,rot);
        c[left][1]=0;
     }
     else  lk[rot]=INF;
     if(c[rot][1])
     {
         int right=getnext();
         splay(right,c[rot][1]);
         rk[rot]=getk(rot,right);
         lk[right]=getk(rot,right);
         c[right][0]=0;
     }
     else  rk[rot]=-INF;
     if(lk[rot]<rk[rot] || fabs(lk[rot]-rk[rot])<eps)
     {
          c[c[rot][1]][0]=c[rot][0];fa[c[rot][0]]=c[rot][1];rot=c[rot][1];fa[rot]=0;
          lk[rot]=rk[c[rot][0]]=getk(c[rot][0],rot);
     }
}
int main()
{
    freopen("cash.in","r",stdin);
    freopen("cash.out","w",stdout);
    int i,k;
    scanf("%d%lf",&n,&f[0]);
    for(i=1;i<=n;i++)  scanf("%lf%lf%lf",&a[i],&b[i],&rate[i]);
    for(i=1;i<=n;i++)
    {
        k=find(rot,-a[i]/b[i]);
        f[i]=max(f[i-1],x[k]*a[i]+y[k]*b[i]);
        x[i]=f[i]/(rate[i]*a[i]+b[i])*rate[i];
        y[i]=f[i]/(rate[i]*a[i]+b[i]);
        Ins(rot,i,0);
        updata();
    }
    printf("%.3lf\n",f[n]);
    //system("pause");
    return 0;
}
