#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
       int x,y;
       int nor,sou;
}dian[300010];
int sz,to[3000010],pre[3000010],last[300010];
int SZ,TO[3000010],PRE[3000010],LAST[300010];
int n,m,A,B;
int zuo[300010],you[300010],dui[300010];
bool mark[300010];
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9')) ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
inline bool cmp(int a,int b)
{
    return dian[a].y>dian[b].y;
}
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void INS(int a,int b)
{
     SZ++;TO[SZ]=b;PRE[SZ]=LAST[a];LAST[a]=SZ;
}
void init()
{
     int i,a,b,k;
     n=read();m=read();A=read();B=read();
     for(i=1;i<=n;i++)  
     {dian[i].x=read();dian[i].y=read();
     dian[i].nor=-1;dian[i].sou=-1;}
     for(i=1;i<=m;i++)
     {
        a=read();b=read();k=read();
        Ins(a,b);INS(b,a);
        if(k==2)
        {Ins(b,a);INS(a,b);}
     }
}
void BFS()
{
     int tou=1,wei=0,now,i;
     memset(mark,0,sizeof(mark));
     for(i=1;i<=n;i++)  if(dian[i].x==0)  {wei++;dui[wei]=i;mark[i]=1;}
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         i=last[now];
         while(i>0)
         {
                   if(!mark[to[i]])
                   {
                        mark[to[i]]=1;wei++;dui[wei]=to[i];
                   }
                   i=pre[i];
         }
     }
}
void bfsnor()
{
     int tou,wei,now,i,k;
     memset(mark,0,sizeof(mark));
     for(k=1;k<=you[0];k++)
     if(!mark[you[k]])
     {
          tou=1;wei=1;dui[1]=you[k];mark[you[k]]=1;
          while(tou<=wei)
          {
             now=dui[tou];tou++;
             i=LAST[now];
             while(i>0)
             {
                   if(!mark[TO[i]])
                   {
                        mark[TO[i]]=1;wei++;dui[wei]=TO[i];dian[TO[i]].nor=k;
                   }
                   i=PRE[i];
             }
     }
     }
}
void bfssou()
{
     int tou,wei,now,i,k;
     memset(mark,0,sizeof(mark));
     for(k=you[0];k>=1;k--)
     if(!mark[you[k]])
     {
          tou=1;wei=1;dui[1]=you[k];mark[you[k]]=1;
          while(tou<=wei)
          {
             now=dui[tou];tou++;
             i=LAST[now];
             while(i>0)
             {
                   if(!mark[TO[i]])
                   {
                        mark[TO[i]]=1;wei++;dui[wei]=TO[i];dian[TO[i]].sou=k;
                   }
                   i=PRE[i];
             }
     }
     }
}
void solve()
{
     int i;
     init();
     BFS();     
     for(i=1;i<=n;i++) 
     {
        if(dian[i].x==0)  {zuo[0]++;zuo[zuo[0]]=i;}
        if(dian[i].x==A && mark[i])  {you[0]++;you[you[0]]=i;}
     }     
     sort(zuo+1,zuo+1+zuo[0],cmp);
     sort(you+1,you+1+you[0],cmp);
     bfsnor();
     bfssou();
     for(i=1;i<=zuo[0];i++)
     {
         if(dian[zuo[i]].nor==-1)  printf("0\n");
         else         printf("%d\n",dian[zuo[i]].sou-dian[zuo[i]].nor+1);
     }
}
int main()
{
    freopen("traffic.in","r",stdin);
    freopen("traffic.out","w",stdout);
    solve();
    //system("pause");
    return 0;
}
/*
5 3 1 3
0 0
0 1
0 2
1 0
1 1
1 4 1
1 5 2
3 5 2
*/
