#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,bla,whi,sz;
int map[201][201];
int id[201][201];
bool vis[25001];
int pipei[25001];
int to[300010],pre[300010],last[25001];
int now;
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
               if(!vis[to[i]])
               {
                  vis[to[i]]=1;
                  if(!pipei[to[i]] || find(pipei[to[i]]))
                  {pipei[to[i]]=x;return 1;}
               }
               i=pre[i];
     }
     return 0;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    char ch;
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) 
    {
       cin>>ch;
       map[i][j]=ch-'0';
       if(!map[i][j])
       {
                    if((i+j)%2==0) {bla++;id[i][j]=bla;}
                    else  {whi++;id[i][j]=whi;}
       }
    }
    
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(!map[i][j] && (i+j)%2==0)
    {
        if(i>1 && j>2 && !map[i-1][j-2])  Ins(id[i][j],id[i-1][j-2]);
        if(i>2 && j>1 && !map[i-2][j-1])  Ins(id[i][j],id[i-2][j-1]);
        if(i>1 && j<n-1 && !map[i-1][j+2])  Ins(id[i][j],id[i-1][j+2]);
        if(i>2 && j<n && !map[i-2][j+1])  Ins(id[i][j],id[i-2][j+1]);
        
        if(i<n && j>2 && !map[i+1][j-2])  Ins(id[i][j],id[i+1][j-2]);
        if(i<n && j<n-1 && !map[i+1][j+2])  Ins(id[i][j],id[i+1][j+2]);
        if(i<n-1 && j>1 && !map[i+2][j-1])  Ins(id[i][j],id[i+2][j-1]);
        if(i<n-1 && j<n && !map[i+2][j+1])  Ins(id[i][j],id[i+2][j+1]);
    }
    
    for(i=1;i<=bla;i++)
    {
    memset(vis,0,sizeof(vis));
    if(find(i))
    now++;
    }
    cout<<bla+whi-now<<endl;
    system("pause");
    return 0;
}
