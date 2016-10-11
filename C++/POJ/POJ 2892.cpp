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
       int w,rnd;
}tree[80010];
int sz,root=0;
int n,q;
int ans;
int pohuai[50010];
int qq,hj;
int s;
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
   t=k;
}
void lturn(int &t)
{
   int k=tree[t].r;
   tree[t].r=tree[k].l;
   tree[k].l=t;
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
         tree[wei].rnd=rand();
         return;
     }
     if(x==tree[wei].num)
     {tree[wei].w++;return;}
     else
     if(x<tree[wei].num)
     {
     Ins(tree[wei].l,x);
     if(tree[tree[wei].l].rnd<tree[wei].rnd)
     rturn(wei);
     }
     else
     if(x>tree[wei].num)
     {
     Ins(tree[wei].r,x);
     if(tree[tree[wei].r].rnd<tree[wei].rnd)
     lturn(wei);
     }
}
void shanchu(int &wei,int x)
{
     if(tree[wei].num==x)
     {
        if(tree[wei].w>1)
        {tree[wei].w--;return;}
        if(tree[wei].l*tree[wei].r==0)
        {
           wei=tree[wei].l+tree[wei].r;
        }
        else
        if(tree[tree[wei].l].rnd<tree[tree[wei].r].rnd)
        {
           rturn(wei);
           shanchu(wei,x);
        }
        else
        if(tree[tree[wei].l].rnd>=tree[tree[wei].r].rnd)
        {
           lturn(wei);
           shanchu(wei,x);
        }
        return;
     }
     else
     if(tree[wei].num<x)
     shanchu(tree[wei].r,x);
     else
     shanchu(tree[wei].l,x);
}
void find(int &wei,int x)
{
    if(wei==0)
    return;
    if(tree[wei].num>=x && tree[wei].num<hj)
    {hj=tree[wei].num;}
    if(tree[wei].num<=x && tree[wei].num>qq)
    {qq=tree[wei].num;}
    if(tree[wei].num<x)
    {
       find(tree[wei].r,x);
    }
    else
    find(tree[wei].l,x);
}
int main()
{
    scanf("%d%d",&n,&q);
    int i,j=0,a;
    char ch;
    
    Ins(root,0);
    Ins(root,n+1);
    
    for(i=1;i<=q;i++)
    {
       cin>>ch;
       if(ch=='D')
       {
         scanf("%d",&a);
         Ins(root,a);
         j++;
         pohuai[j]=a;
       }
       if(ch=='R')
       {
         shanchu(root,pohuai[j]);
         j--;
       }
       if(ch=='Q')
       {
         scanf("%d",&s);
         qq=0;hj=n+1;
         find(root,s);
         if(qq==s && hj==s)
         printf("0\n");
         else
         printf("%d\n",hj-qq-1);
         
       }
    }
   // system("pause");
    return 0;
}

