#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 100010
#define eps 1e-10
#define INF 2000000000
using namespace std;
int sz,l[N],r[N],zhong[N],bh[N];
long long zhi[N];
int root,n,zj[N],cj[N],qq1,qq2,hj1,hj2,m;
long long h[N];
long long A,B;
inline long long ABS(long long x)
{
       if(x<0) return -x;else return x;
}
void rturn(int &t)
{
     int k=l[t];l[t]=r[k];r[k]=t;t=k;
}
void lturn(int &t)
{
     int k=r[t];r[t]=l[k];l[k]=t;t=k;
}
void Ins(int &wei,int x,int hao)
{
     if(wei==0)
     {
         sz++;wei=sz;zhong[wei]=rand();zhi[wei]=x;bh[wei]=hao;
         return;
     }
     if(zhi[wei]>x)  {Ins(l[wei],x,hao);if(zhong[wei]>zhong[l[wei]]) rturn(wei);}
     else
     if(zhi[wei]<x)  {Ins(r[wei],x,hao);if(zhong[wei]>zhong[r[wei]]) lturn(wei);}
}
void find(int wei,int x)
{
     if(wei==0)  return;
     if(zhi[wei]>x)  
     {
                     if(zhi[wei]<zhi[hj1])  {hj1=wei;}
                     find(l[wei],x);
     }
     else
     if(zhi[wei]<x)
     {
                     if(zhi[wei]>zhi[qq1])  {qq1=wei;}
                     find(r[wei],x);
     }
     else
     {find(l[wei],x);find(r[wei],x);}
}
void init_and_build()
{
     int i,o;
     scanf("%d",&n);
     zhi[0]=INF;bh[0]=0;
     zhi[n+3]=-INF;bh[n+3]=0;
     for(i=1;i<=n;i++)  scanf("%I64d",&h[i]);       
     for(i=n;i>=1;i--)
     {
          qq1=n+3;hj1=0;
          find(root,h[i]);
          if(ABS(zhi[qq1]-h[i])<=ABS(zhi[hj1]-h[i])) 
          {zj[i]=bh[qq1];hj2=hj1;o=qq1;qq1=n+3;hj1=0;find(root,zhi[o]);hj1=hj2;} 
          else   
          {zj[i]=bh[hj1];qq2=qq1;o=hj1;qq1=n+3;hj1=0;find(root,zhi[o]);qq1=qq2;}
          if(ABS(zhi[qq1]-h[i])<=ABS(zhi[hj1]-h[i])) {cj[i]=bh[qq1];}         
          else   {cj[i]=bh[hj1];}
          Ins(root,h[i],i);
     }
}
void runing(int x,int xx)
{
     int o=0,to,now=x;
     A=0;B=0;
     while(1)
     {
            if(o==0) to=cj[now]; else to=zj[now];
            if(to==0)  break;
            else 
            {
                if(xx<ABS(h[now]-h[to]))  break;
                if(o==0)  {A+=ABS(h[now]-h[to]);}  else {B+=ABS(h[now]-h[to]);}
                xx-=ABS(h[now]-h[to]);
                now=to;o^=1;
            }    
     }
}
void solve()
{
     int i,xx;
     int ans;
     double bi,ansbi=INF+1;
     scanf("%d",&xx);     
     for(i=1;i<=n;i++)
     {
        runing(i,xx);
        if(B==0)  bi=INF;  else  bi=double(A)/B;
        if(fabs(bi-ansbi)<eps) 
        {
            if(h[i]>h[ans])   ans=i;
        }   
        else
        if(bi<ansbi)   {ans=i;ansbi=bi;}
     }
     cout<<ans<<endl;
     scanf("%d",&m);
     int a;int b;
     for(i=1;i<=m;i++)
     {
         scanf("%d%d",&a,&b);
         runing(a,b);
         printf("%I64d %I64d\n",A,B);
     }
}
int main()
{
    init_and_build();
    solve();
    system("pause");
    return 0;
}
