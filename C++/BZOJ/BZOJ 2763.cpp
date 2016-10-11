#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,k,s,t;
int sz,to[300010],pre[300010],v[300010],last[10010];
int d[10010][11],dui[1000010][2];
bool mark[10010][11];
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
int next(int x)
{
    x++;if(x==1000000) x=0; return x; 
}
void spfa()
{
     memset(d,127,sizeof(d));
     int tou=0,wei=1,now,nk,i;
     dui[1][0]=s;dui[1][1]=0;d[s][0]=0;mark[s][0]=1;
     while(tou!=wei)
     {
         tou=next(tou);now=dui[tou][0];nk=dui[tou][1];
         for(i=last[now];i>0;i=pre[i])
         {
             if(d[to[i]][nk]>d[now][nk]+v[i])
             {
                 d[to[i]][nk]=d[now][nk]+v[i];
                 if(!mark[to[i]][nk])
                 {
                     mark[to[i]][nk]=1;wei=next(wei);dui[wei][0]=to[i];dui[wei][1]=nk;
                 }
             }
             if(nk<k && d[to[i]][nk+1]>d[now][nk])
             {
                 d[to[i]][nk+1]=d[now][nk];
                 if(!mark[to[i]][nk+1])
                 {
                     mark[to[i]][nk+1]=1;wei=next(wei);dui[wei][0]=to[i];dui[wei][1]=nk+1;
                 }
             }
         }
         mark[now][nk]=0;
     }
}
int main()
{
    int i,a,b,c;
    scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
    s++;t++;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        a++;b++;
        Ins(a,b,c);Ins(b,a,c);
    }    
    spfa();    
    int ans=0x7fffffff;
    for(i=0;i<=k;i++)  ans=min(ans,d[t][i]);
    cout<<ans<<endl;
    system("pause");
    return 0;
}
