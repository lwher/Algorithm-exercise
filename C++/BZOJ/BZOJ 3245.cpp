#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int sz,to[50010],v[50010],l[50010],pre[50010],last[50010];
int n,m,D,fa[151][501],fav[151][501];
int dui[3000010][2],ans[100001];
double d[151][501];
bool mark[151][501];
void Ins(int a,int b,int V,int L)
{
     sz++;to[sz]=b;pre[sz]=last[a];v[sz]=V;l[sz]=L;last[a]=sz;
}
void spfa()
{
     int i,j,now,tou=1,wei=1,V;
     for(i=1;i<=n;i++)   for(j=1;j<=500;j++)  d[i][j]=1e20;
     d[1][70]=0;dui[1][0]=1;dui[1][1]=70;mark[1][70]=1;
     while(tou<=wei)
     {
         now=dui[tou][0];V=dui[tou][1];tou++;
         i=last[now];
         while(i>0)
         {
              if(v[i]==0)   
              {
                  if(d[to[i]][V]>d[now][V]+double(l[i])/double(V))
                  {
                      d[to[i]][V]=d[now][V]+double(l[i])/double(V);
                      fa[to[i]][V]=now;fav[to[i]][V]=V;
                      if(!mark[to[i]][V])  {mark[to[i]][V]=1;dui[++wei][0]=to[i];dui[wei][1]=V;}
                  }
              }
              else
              {
                  if(d[to[i]][v[i]]>d[now][V]+double(l[i])/double(v[i]))
                  {
                      d[to[i]][v[i]]=d[now][V]+double(l[i])/double(v[i]);
                      fa[to[i]][v[i]]=now;fav[to[i]][v[i]]=V;
                      if(!mark[to[i]][v[i]])  {mark[to[i]][v[i]]=1;dui[++wei][0]=to[i];dui[wei][1]=v[i];}
                  }
              }
              i=pre[i];
         }
         mark[now][V]=0;
     }
}
int main()
{
    scanf("%d%d%d",&n,&m,&D);    
    int i,j,k,a,b,V,L;D++;
    for(i=1;i<=m;i++)  
    {
        scanf("%d%d%d%d",&a,&b,&V,&L);a++;b++;
        Ins(a,b,V,L);
    }
    spfa();
    double nans=1e20,tmp;
    for(i=1;i<=500;i++)  if(d[D][i]<nans)  {nans=d[D][i];tmp=i;}
    int A=D,B=tmp,C;    
    
    while(A!=1 || B!=70)
    {
        ans[++ans[0]]=A-1;
        C=A;
        A=fa[A][B];
        B=fav[C][B];
    }    
    ans[++ans[0]]=0;
    for(i=ans[0];i>1;i--)   printf("%d ",ans[i]); printf("%d\n",ans[1]);
    system("pause");
    return 0;
}
