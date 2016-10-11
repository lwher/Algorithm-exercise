#include<iostream>
#include<stdio.h>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct sth
{
       int l,r,num;
       int size;
       int w,rnd;
}tree[50010];
int sz,root=0;
int n,q;
int ans;
int wen[30010],shu[30010];
int rrand()
{
    int seed=time(NULL);
    srand(seed);
    return rand();
}
void rturn(int &t)
{
   int k=tree[t].l;
   tree[t].l=tree[k].r;
   tree[k].r=t;
   tree[t].size=tree[tree[t].l].size+tree[tree[t].r].size+tree[t].w;
   tree[k].size=tree[tree[k].l].size+tree[tree[k].r].size+tree[k].w;
   t=k;
}
void lturn(int &t)
{
   int k=tree[t].r;
   tree[t].r=tree[k].l;
   tree[k].l=t;
   tree[t].size=tree[tree[t].l].size+tree[tree[t].r].size+tree[t].w;
   tree[k].size=tree[tree[k].l].size+tree[tree[k].r].size+tree[k].w;
   t=k;
}
void Ins(int &wei,int x)
{
     if(wei==0)
     {
         sz++;
         wei=sz;
         tree[wei].num=x;
         tree[wei].w=1;
         tree[wei].size=1;
         tree[wei].rnd=rand();
         return;
     }
     if(x==tree[wei].num)
     {tree[wei].w++;tree[wei].size++;return;}
     else
     if(x<tree[wei].num)
     {
     Ins(tree[wei].l,x);
     if(tree[tree[wei].l].rnd<tree[wei].rnd)
     rturn(wei);
     else
     tree[wei].size++;
     }
     else
     if(x>tree[wei].num)
     {
     Ins(tree[wei].r,x);
     if(tree[tree[wei].r].rnd<tree[wei].rnd)
     lturn(wei);
     else
     tree[wei].size++;
     }
}
void find(int &wei,int x)
{
     if(tree[tree[wei].l].size<x && tree[tree[wei].l].size+tree[wei].w>=x)
     {
       ans=tree[wei].num;
       return;
     }
     if(tree[tree[wei].l].size>=x)
     find(tree[wei].l,x);
     else
     if(tree[tree[wei].l].size+tree[wei].w<x)
     {find(tree[wei].r,x-tree[tree[wei].l].size-tree[wei].w);}
}
int main()
{
    scanf("%d%d",&n,&q);
    int i,j=1;
    for(i=1;i<=n;i++)
    scanf("%d",&shu[i]);
    for(i=1;i<=q;i++)
    scanf("%d",&wen[i]);
    sort(wen+1,wen+1+q);
    for(i=1;i<=n;i++)
    {
       Ins(root,shu[i]);
       while(wen[j]==i &&  j<=q)
       {
          find(root,j);
          printf("%d\n",ans); 
          j++;
       }
    }
  //  system("pause");
    return 0;
}

