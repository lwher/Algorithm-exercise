#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
bool mark[100010];
int last[100010],b[10000000],pre[10000000];
int sz;
int n,m,c;
long long k;
int tou,wei,dui[100010],d[100010];
void Ins(int aa,int bb)
{
     sz++;
     b[sz]=bb;
     pre[sz]=last[aa];
     last[aa]=sz;
     sz++;
     b[sz]=aa;
     pre[sz]=last[bb];
     last[bb]=sz;
}
void init()
{
     int i,j;
     int aa,bb;
     scanf("%d%d%d",&n,&m,&c);
     cin>>k;
     for(i=1;i<=m;i++)
     {
      scanf("%d%d",&aa,&bb);
      Ins(aa,bb);
     }
}
void bfs()
{
    int i,now;
     tou=1;wei=1;
     mark[c]=1;
     dui[1]=c;
     d[c]=1;
     while(tou<=wei)
     {
            now=dui[tou];
            i=last[now];
            while(i>0)
            {
                      if(!mark[b[i]])
                      {wei++;dui[wei]=b[i];mark[b[i]]=1;d[b[i]]=d[now]+1;}
                      i=pre[i];
            }       
            tou++; 
     }
     long long ans=0;
     for(i=1;i<=n;i++)
     if(d[i]>ans)  ans=d[i];;
     cout<<ans+k<<endl;
}
int main()
{
    init();
    bfs();
    system("pause");
    return 0;
}
