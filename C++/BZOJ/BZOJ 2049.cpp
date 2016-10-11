#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int fa[10010],c[10010][2],stack[10010];
bool fz[10010];
bool isroot(int x)
{
     return (c[fa[x]][0]!=x && c[fa[x]][1]!=x);
}
void swap(int &a,int &b)
{
     int t=a;a=b;b=t;
}
void downput(int x)
{
     int y=c[x][0],z=c[x][1];
     swap(c[x][0],c[x][1]);
     if(y) fz[y]^=1;
     if(z) fz[z]^=1;
     fz[x]=0;
}
void rotate(int x)
{
     int y=fa[x],z=fa[y],p,q;
     if(c[y][0]==x)  p=0; else p=1;
     q=p^1;
     if(!isroot(y))
     {
        if(c[z][0]==y)  c[z][0]=x; else c[z][1]=x;
     }
     fa[x]=z;fa[y]=x;fa[c[x][q]]=y;
     c[y][p]=c[x][q];c[x][q]=y;
}
void splay(int x)
{
     int y,z,top=0;
     z=x;
     while(!isroot(z))
     {
         stack[++top]=z;
         z=fa[z];
     }
     stack[++top]=z;
     while(top)  {if(fz[stack[top]])  downput(stack[top]);top--;}
     while(!isroot(x))
     {
         y=fa[x];z=fa[y];
         if(!isroot(y))
         {
             if((c[y][0]==x) ^ (c[z][0]==y))  rotate(x);
             else  rotate(y);
         }
         rotate(x);
     }
}
void Access(int x)
{
     int V=0;
     while(x!=0)
     {
         splay(x);
         c[x][1]=V;
         V=x;x=fa[x];
     }
}
bool checkAccess(int x,int y)
{
     int V=0;bool flag=0;
     while(x!=0)
     {
         if(x==y) flag=1;
         splay(x);
         c[x][1]=V;
         V=x;x=fa[x];
     }
     return flag;
}
void solve()
{
     int i,x,y;
     char ch[10];
     scanf("%d%d",&n,&m);
     for(i=1;i<=m;i++)
     {
         scanf("%s",ch);scanf("%d%d",&x,&y);
         if(ch[0]=='C')
         {
             Access(y);splay(y);
             fz[y]^=1;fa[y]=x;
         }else
         if(ch[0]=='D')
         {
             Access(x);splay(y);
             if(c[y][1]==x)
             {
                 Access(y);splay(x);fa[x]=0;
             }    
             else  
             {
                 splay(y);fa[y]=0;
             }
         }else
         {
              Access(x);
              if(checkAccess(y,x))  printf("Yes\n");
              else
              {
                  splay(x);
                  if(fa[x]!=0)  printf("Yes\n");
                  else   printf("No\n");
              } 
         }
     
     }
}
int main()
{
    solve();
    system("pause");
    return 0;
}
