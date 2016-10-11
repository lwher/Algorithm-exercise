#include<iostream>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct sth
{
       int num,l,r,w;
       int rnd;
}t[1000000];
int sz;
int n,root;
int qq,hj;
long long ans;
int randd()
{
    int seed=time(NULL);
    srand(seed);
    return rand();
}
void RT(int &tt)
{
     int k=t[tt].l;
     t[tt].l=t[k].r;
     t[k].r=tt;
     tt=k;
}
void LT(int &tt)
{
     int k=t[tt].r;
     t[tt].r=t[k].l;
     t[k].l=tt;
     tt=k;
}
void Ins(int &wei,int x)
{
     if(wei==0)
     {
         sz++;
         wei=sz;
         t[wei].num=x;
         t[wei].w=1;
         t[wei].rnd=rand();
         return;
     }
     if(t[wei].num==x)
     {t[wei].w++;return;}
     else
     if(t[wei].num<x)
     {Ins(t[wei].r,x);if(t[t[wei].r].rnd<t[wei].rnd) LT(wei);}
     else
     {Ins(t[wei].l,x);if(t[t[wei].l].rnd<t[wei].rnd) RT(wei);}
}
void find(int &wei,int x)
{
     if(wei==0)
     return;
     if(t[wei].num==x)
     {qq=x;hj=x;return;}
     else
     if(t[wei].num>x)
     {
      if(t[wei].num-x<hj-x)
      hj=t[wei].num;
      find(t[wei].l,x);
     }
     else
     if(t[wei].num<x)
     {
      if(x-t[wei].num<x-qq)
      qq=t[wei].num;
      find(t[wei].r,x);
     }
}
int main()
{
    int shu;
    int i,j;
    randd();
    scanf("%d",&n);
    
    cin>>shu;
    Ins(root,shu);
    ans=shu;
    for(i=2;i<=n;i++)
    {
       if(scanf("%d",&shu)==EOF) shu=0;
       qq=-1200000;hj=1000002;
       find(root,shu);
       ans+=min(abs(shu-qq),abs(shu-hj));
       Ins(root,shu);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
