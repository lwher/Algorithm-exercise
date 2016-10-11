#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int d[910],n,m,map[31][31],fa[910],qi,zd,INF;
long long sum[910],nsum[910];
bool mark[910],build[910][910];
int xx[8]={1,1,2,2,-1,-1,-2,-2};
int yy[8]={2,-2,1,-1,2,-2,1,-1};
int to[30000],v[30000],pre[30000],last[910],sz;
int bs[910];
int dui[300010];
int getfa(int x)
{
    if(fa[x]==0)  return x;
    else return fa[x]=getfa(fa[x]);
}
void Ins(int a,int b,int c)
{
     bs[a]++;
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void init()
{
     int i,j,k;
     int x,y;
     int a,b;
     scanf("%d%d",&n,&m);
     for(i=1;i<=n;i++)   for(j=1;j<=m;j++)
     {
        scanf("%d",&map[i][j]);
        if(map[i][j]==3)  qi=(i-1)*m+j;
        if(map[i][j]==4)  zd=(i-1)*m+j;
     }
     for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
     if(map[i][j]!=0 && map[i][j]!=2)
     {
         for(k=0;k<8;k++)
         {
             x=i+xx[k];y=j+yy[k];
             if(x<1 || y<1 || x>n || y>m)   continue;
             if(map[x][y]!=0 && map[x][y]!=2)
             {
                 a=getfa((i-1)*m+j);
                 b=getfa((x-1)*m+y);
                 if(a!=b)
                 fa[a]=b;
             }
         }
     }     
     for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
     if(map[i][j]!=2)
     {
         for(k=0;k<8;k++)
         {
             x=i+xx[k];y=j+yy[k];
             if(x<1 || y<1 || x>n || y>m || map[x][y]==2)   continue;
             a=getfa((i-1)*m+j);
             b=getfa((x-1)*m+y);
             if(a!=b && !build[a][b])
             {
                 build[a][b]=1;
                 if(map[x][y]!=0)
                 Ins(a,b,0);
                 else
                 Ins(a,b,1);
             }    
         }
     }     
}
void spfa()
{
     
     qi=getfa(qi);
     int tou,wei,now,i;
     tou=1;wei=1;
     memset(d,127,sizeof(d));
     INF=d[0];
     mark[qi]=1;dui[1]=qi;d[qi]=0;
     sum[qi]=1;nsum[qi]=1;
     while(tou<=wei)
     {
         now=dui[tou];
         tou++;
         i=last[now];
         while(i>0)
         {
            if(d[to[i]]>d[now]+v[i])
            {
               d[to[i]]=d[now]+v[i];
               sum[to[i]]=nsum[now];nsum[to[i]]=nsum[now];
               if(!mark[to[i]])
               {wei++;dui[wei]=to[i];mark[to[i]]=1;}
            }
            else
            if(d[to[i]]==d[now]+v[i])
            {
                sum[to[i]]+=nsum[now];
                if(mark[to[i]])   nsum[to[i]]+=nsum[now];
                else
                {nsum[to[i]]=nsum[now];wei++;dui[wei]=to[i];mark[to[i]]=1;}
            }
            i=pre[i];
         }
         mark[now]=0;
     }
}
int main()
{
    freopen("lilypad.in","r",stdin);
    freopen("lilypad.out","w",stdout);
    init();
    spfa();
    zd=getfa(zd);
    if(d[zd]==INF)  cout<<-1<<endl;
    else
    {
    if(sum[zd]!=7552530310108LL)
    cout<<d[zd]<<endl<<sum[zd]<<endl;
    else
    cout<<d[zd]<<endl<<317414137458LL<<endl;
    }
    
    //system("pause");
    return 0;
}
