#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int c[210],u[210];
int sz,to[50010],v[50010],pre[50010],last[210];
int dui[210],in[210],out[210];
bool mark[210];
void Ins(int a,int b,int cc)
{
     sz++;to[sz]=b;pre[sz]=last[a];v[sz]=cc;last[a]=sz;
}
int main()
{
    int i,a,b,cc,now;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  scanf("%d%d",&c[i],&u[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&cc);
        Ins(a,b,cc);
        in[b]++;out[a]++;
    }
    int tou=1,wei=0;
    
    for(i=1;i<=n;i++) 
    {
       if(!in[i])
       {
                 wei++;dui[wei]=i;mark[i]=1;
       }
    }
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        if(in[now]) c[now]-=u[now];
        if(c[now]>0)
        {
        i=last[now];
        while(i>0)
        {
             c[to[i]]+=c[now]*v[i];
             if(!mark[to[i]])  {wei++;dui[wei]=to[i];mark[to[i]]=1;}
             i=pre[i];
        }
        }
    }
    bool o=0;
    for(i=1;i<=n;i++)
    {
        if(out[i]==0 && c[i]>0)
        {
            o=1;printf("%d %d\n",i,c[i]);
        }
    }
    if(!o)  printf("NULL\n");
    system("pause");
    return 0;
}
