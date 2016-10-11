#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define N 300000
using namespace std;
int c[N][2],maxx[N],minn[N],size[N],zhi[N],fa[N],jia[N];
int sz,n,low,rot,hj,hjw,ss;
void updata(int x)
{
     int y=c[x][0],z=c[x][1];
     size[x]=size[y]+size[z]+1;
     minn[x]=min(min(minn[y],minn[z]),zhi[x]);
     maxx[x]=max(max(maxx[y],maxx[z]),zhi[x]);
}
void rotate(int x,int &root)
{
     int y,z,p,q;
     y=fa[x];z=fa[y];
     if(c[y][0]==x)  p=0; else p=1; 
     q=p^1;
     if(y==root)  root=x;
     else
     {
         if(c[z][0]==y)  c[z][0]=x;
         else c[z][1]=x;
     }
     fa[x]=z;fa[y]=x;fa[c[x][q]]=y;
     c[y][p]=c[x][q];c[x][q]=y;
     updata(y);updata(x);
}
void splay(int x,int &root)
{
     int y,z;
     while(x!=root)
     {
          y=fa[x];z=fa[y];
          if(y!=root)
          {
              if((c[y][0]==x) ^ (c[z][0]==y))  rotate(x,root);
              else rotate(y,root);
          }
          rotate(x,root);
     }
}
void downgo(int x)
{
     int y=c[x][0],z=c[x][1];
     if(y){zhi[y]+=jia[x];maxx[y]+=jia[x];minn[y]+=jia[x];jia[y]+=jia[x];}
     if(z){zhi[z]+=jia[x];maxx[z]+=jia[x];minn[z]+=jia[x];jia[z]+=jia[x];}
     jia[x]=0;
}
void Ins(int &wei,int from,int x)
{
     if(wei==0)
     {
        sz++;wei=sz;
        zhi[sz]=x;
        fa[sz]=from;maxx[sz]=x;minn[sz]=x;size[sz]=1;
        splay(sz,rot);
        return;
     }
     downgo(wei);
     if(zhi[wei]<x)  Ins(c[wei][1],wei,x);
     else Ins(c[wei][0],wei,x); 
}
int findpm(int x,int k)
{
    downgo(x);
    int y=c[x][0],z=c[x][1];
    if(size[y]+1==k) return x;
    else
    if(size[y]>=k) return findpm(y,k);
    else
    return findpm(z,k-size[y]-1);
}
void findhj(int x)
{
    if(x==0)  return;
    downgo(x);
    if(zhi[x]>=low)  {if(zhi[x]<=hj){hjw=x;hj=zhi[x];}findhj(c[x][0]);}
    else   findhj(c[x][1]);   
}
void charu(int x)
{
     if(x<low)  return;
     ss++;
     Ins(rot,-1,x);
}
void jiagz(int x)
{
     if(rot==0)  return;
     jia[rot]+=x;zhi[rot]+=x;maxx[rot]+=x;minn[rot]+=x;
}
void jiangz(int x)
{
     if(rot==0)  return;
     zhi[rot]-=x;minn[rot]-=x;maxx[rot]-=x;jia[rot]-=x;
     if(maxx[rot]<low)   rot=0;
     else
     if(minn[rot]>=low)   return;
     else
     {
         hj=100000000;
         findhj(rot);
         splay(hjw,rot);
         c[rot][0]=0; updata(rot);
     }
}
void ask(int x)
{
     if(size[rot]<x)  printf("-1\n");
     else
     printf("%d\n",zhi[findpm(rot,size[rot]-x+1)]);
}
int main()
{
    maxx[0]=-100000000;minn[0]=100000000;
    scanf("%d%d",&n,&low);
    int i;
    char ch[2];int num;
    for(i=1;i<=n;i++)
    {
        scanf("%s",ch);scanf("%d",&num);
        if(ch[0]=='I')  charu(num);
        else 
        if(ch[0]=='A')  jiagz(num);
        else
        if(ch[0]=='S')  jiangz(num);
        else            ask(num);
    }
    cout<<ss-size[rot]<<endl;
    system("pause");
    return 0;
} 
