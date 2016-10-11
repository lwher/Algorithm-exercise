#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
struct AC
{
       int ez[26];
       int fail;
       bool mark;
}tree[10000];
int n,m;
int ans;
int sz,chang;
int f[110][10010];
string s;
void add(int x,int top)
{
     if(top==chang)  return;
     int k=int(s[top])-65;
     if(!tree[x].ez[k])
     {
        sz++;
        tree[x].ez[k]=sz;
     }
     if(top==chang-1)
     tree[tree[x].ez[k]].mark=1;
     add(tree[x].ez[k],top+1);
}
void bfs()
{
     int i,j,now;
     int dui[10010];
     int tou=1,wei=1;
     tree[0].fail=-1;
     dui[1]=0;
     while(tou<=wei)
     {
        now=dui[tou];
        for(i=0;i<=25;i++)
        if(tree[now].ez[i])
        {
            j=tree[now].fail;
            while(j!=-1)
            {
               if(tree[j].ez[i])
               {tree[tree[now].ez[i]].fail=tree[j].ez[i];break;}
               j=tree[j].fail;
            }
            if(j==-1)
            tree[tree[now].ez[i]].fail=0;
            wei++;
            dui[wei]=tree[now].ez[i];
        }
        tou++;
     }
}
void dp()
{
     int i,j,k,l;
     f[0][0]=1;
     bool o;
     for(i=0;i<=m-1;i++)
     {
        for(l=0;l<=sz;l++)
        {
        if(f[i][l])
        for(j=0;j<=25;j++)
        {
            o=0;
            k=l;
            while(k>-1)
            {
            if(tree[k].ez[j] && tree[tree[k].ez[j]].mark)  {o=1;break;}
            k=tree[k].fail;
            }
            if(!o)
            {
            k=l;
            while(k>-1)
            {
            if(tree[k].ez[j])  break;
            k=tree[k].fail;
            }
            if(k!=-1)
            {
            f[i+1][tree[k].ez[j]]+=f[i][l];
            f[i+1][tree[k].ez[j]]%=10007;
            }
            if(k==-1)
            {
            f[i+1][0]+=f[i][l];
            f[i+1][0]%=10007;
            }
            }
        }
        }
     }
     ans=1;
     for(i=1;i<=m;i++)
     {ans*=26;ans%=10007;}
     for(i=0;i<=sz;i++)
     {ans-=f[m][i];if(ans<0)  ans+=10007;}
     printf("%d\n",ans);
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {cin>>s;chang=s.size();add(0,0);}
    bfs();
    dp();
    system("pause");
    return 0;
}
