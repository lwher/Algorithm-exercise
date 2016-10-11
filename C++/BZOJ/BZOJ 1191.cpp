#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m,sz;
int to[3001],pre[3001],last[1001];
int pipei[1001];
bool d[1001];
void Ins(int a,int b)
{
     sz++;
     to[sz]=b;
     pre[sz]=last[a];
     last[a]=sz;
}
bool find(int x)
{
     int i=last[x];
     while(i>0)
     {
               if(!d[to[i]])
               {
                  d[to[i]]=1;
                  if(pipei[to[i]]==-1 || find(pipei[to[i]]))
                  {
                      pipei[to[i]]=x;
                      return 1;
                  }
               }
               i=pre[i];
     }
     return 0;
}
int main() 
{
    scanf("%d%d",&n,&m);
    int i,j,k;
    memset(pipei,-1,sizeof(pipei));
    for(i=1;i<=m;i++)
    {
       scanf("%d",&k); Ins(i,k);
       scanf("%d",&k); Ins(i,k);
    }
    for(i=1;i<=m;i++)
    {
                     memset(d,0,sizeof(d));
                     if(!find(i))
                     break;
    }
    cout << i - 1 << endl;
    system("pause");
    return 0;
}
