#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int c[60000][2],maxx[60000],fa[60000],add[60000],size[60000],zhi[60000];
bool fz[60000];
int n,m,rot;
void updata(int x)
{
     int y=c[x][0],z=c[x][1];
     size[x]=size[y]+size[z]+1;
     maxx[x]=max(zhi[x],max(maxx[y],maxx[z]));
}
void rotate(int x,int &root)
{
     int y=fa[x],z=fa[y],p,q;
     if(y==root)  root=x;
     if(c[y][0]==x)  p=0;  else p=1;
     q=p^1;
     if(y!=root)
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
              else  rotate(y,root);
         }
         rotate(x,root);
     }
}
void downgo(int x)
{
     if(fz[x])
     {
         int y=c[x][0],z=c[x][1];
         fz[x]^=1;
         if(y)  fz[y]^=1;  if(z) fz[z]^=1;
         c[x][0]=z;c[x][1]=y;
     }
     if(add[x]!=0)
     {
         int y=c[x][0],z=c[x][1];
         if(y) {add[y]+=add[x];zhi[y]+=add[x];maxx[y]+=add[x];}
         if(z) {add[z]+=add[x];zhi[z]+=add[x];maxx[z]+=add[x];}
         add[x]=0;
     }
}
int find(int wei,int x)
{
    downgo(wei);
    int y=c[wei][0],z=c[wei][1];
    if(size[y]+1==x)   return wei;
    else   if(size[y]>=x)   return find(y,x);
    else   return  find(z,x-size[y]-1);
}
void jiashu(int l,int r,int x)
{
     int o=find(rot,l);
     splay(o,rot);
     o=find(rot,r+2);
     splay(o,c[rot][1]);
     o=c[c[rot][1]][0];
     if(o)
     {add[o]+=x;maxx[o]+=x;zhi[o]+=x;}
     updata(c[rot][1]);updata(rot);
}
void fangzhuan(int l,int r)
{
     int o=find(rot,l);
     splay(o,rot);
     o=find(rot,r+2);
     splay(o,c[rot][1]);
     o=c[c[rot][1]][0];
     if(o) fz[o]^=1;
}
void findmaxx(int l,int r)
{
     int o=find(rot,l);
     splay(o,rot);
     o=find(rot,r+2);
     splay(o,c[rot][1]);
     o=c[c[rot][1]][0];
     printf("%d\n",maxx[o]);
}
void build(int l,int r,int last)
{
     if(l>r) return;
     if(l==r) 
     {
              if(l<last)  c[last][0]=l;  else c[last][1]=l;
              fa[l]=last;zhi[l]=0;maxx[l]=0;add[l]=0;fz[l]=0;size[l]=1;return;
     }
     int mid=(l+r)>>1;
     build(l,mid-1,mid);build(mid+1,r,mid);
     if(mid<last)  c[last][0]=mid;  else c[last][1]=mid;
     fa[mid]=last;zhi[mid]=0;add[mid]=0;fz[mid]=0;updata(mid);
}
int main()
{
    scanf("%d%d",&n,&m);
    maxx[0]=-100000000;
    build(1,n+2,0);
    rot=(n+3)>>1;
    maxx[1]=-100000000;maxx[n+1]=-100000000;
    int i,l,r,k,num;    
    for(i=1;i<=m;i++)
    {
       scanf("%d",&k);
       if(k==1)  
       {scanf("%d%d%d",&l,&r,&num);jiashu(l,r,num);}
       else
       if(k==2)
       {scanf("%d%d",&l,&r);fangzhuan(l,r);}
       else
       {scanf("%d%d",&l,&r);findmaxx(l,r);}
    }
    system("pause");
    return 0;
}
