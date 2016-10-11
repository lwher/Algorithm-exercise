#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define INF 0x7fffffff
using namespace std;
int c[5010],m[5010];// c:cover  m:max
int sz,f[8500010],s[8500010],ls[8500010],rs[8500010];//  s:cover f:max
int X,Y,n;
void covery(int &rt,int l,int r,int zuo,int you,int num)
{
     if(!rt)  rt=++sz;
     f[rt]=max(f[rt],num);
     if(l>=zuo && r<=you)  {s[rt]=max(s[rt],num);return;}
     int mid=(l+r)>>1;
     if(zuo<=mid)   covery(ls[rt],l,mid,zuo,you,num);
     if(you>mid)  covery(rs[rt],mid+1,r,zuo,you,num);  
}
void coverx(int k,int l,int r,int xz,int xy,int yz,int yy,int num)
{ 
     covery(m[k],1,Y,yz,yy,num);
     if(l>=xz && r<=xy)  {covery(c[k],1,Y,yz,yy,num);return;}
     int mid=(l+r)>>1;
     if(xz<=mid)  coverx(k+k,l,mid,xz,xy,yz,yy,num);
     if(xy>mid)  coverx(k+k+1,mid+1,r,xz,xy,yz,yy,num);
}
int findy(int &rt,int l,int r,int zuo,int you)
{
    if(r<zuo || l>you)  return -INF;
    if(!rt)  rt=++sz;
    if(l>=zuo && r<=you)  return f[rt];
    int mid=(l+r)>>1;
    return max(s[rt],max(findy(ls[rt],l,mid,zuo,you),findy(rs[rt],mid+1,r,zuo,you)));    
}
int findx(int k,int l,int r,int xz,int xy,int yz,int yy)
{
    if(r<xz || l>xy)  return -INF;
    if(l>=xz && r<=xy)  return findy(m[k],1,Y,yz,yy);
    int mid=(l+r)>>1;
    return max(findy(c[k],1,Y,yz,yy),max(findx(k+k,l,mid,xz,xy,yz,yy),findx(k+1+k,mid+1,r,xz,xy,yz,yy)));   
}
int main()
{
    int i,xh,yh,x,y,h,mh;
    scanf("%d%d%d",&X,&Y,&n);
    for(i=1;i<=n;i++)
    {
         scanf("%d%d%d%d%d",&xh,&yh,&h,&x,&y);
         x++;y++;
         mh=findx(1,1,X,x,x+xh-1,y,y+yh-1);
         mh+=h;
         coverx(1,1,X,x,x+xh-1,y,y+yh-1,mh);
    }
    cout<<findx(1,1,X,1,X,1,Y)<<endl;
    system("pause");
    return 0;
}
