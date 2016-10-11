#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int sz,c[3000010][2],size[3000010],fa[3000010],bh[3000010];
bool mark[3000010];
char zf[3000010],s[3000010],ch[15];
int n,now,rot;
void updata(int x)
{
    size[x]=size[c[x][0]]+size[c[x][1]]+1;
}
void rotate(int x,int &root)
{
    int y=fa[x],z=fa[y],p,q;
    if(c[y][0]==x)  p=0; else p=1;
    q=p^1;
    if(y==root)  root=x;
    else
    {
        if(c[z][0]==y)  c[z][0]=x; else c[z][1]=x;
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
void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
void downgo(int x)
{
    if(mark[x])
    {
        int y=c[x][0],z=c[x][1];
        swap(c[x][0],c[x][1]);
        mark[y]^=1;mark[z]^=1;
        mark[x]=0;
    }
}
int find(int x,int k)
{
    downgo(x);
    int y=c[x][0],z=c[x][1];
    if(size[y]+1==k)  return x;  else
    if(size[y]>=k)  return find(y,k); else
    return find(z,k-size[y]-1);
}
void build(int l,int r,int last)
{
    if(l>r) return;
    if(l==r)
    {
        fa[bh[l]]=bh[last];size[bh[l]]=1;mark[bh[l]]=0;zf[bh[l]]=s[l]; 
        if(l<last) c[bh[last]][0]=bh[l]; else c[bh[last]][1]=bh[l];
        return;    
    }
    int mid=(l+r)>>1;
    build(l,mid-1,mid);build(mid+1,r,mid);
    updata(bh[mid]);
    fa[bh[mid]]=bh[last];zf[bh[mid]]=s[mid];
    if(mid<last) c[bh[last]][0]=bh[mid];  else c[bh[last]][1]=bh[mid];
}
void Ins(int k)
{
    int i,x=find(rot,now+1),y=find(rot,now+2);
    splay(x,rot); splay(y,c[x][1]);
    for(i=1;i<=k;i++)  bh[i]=++sz;
    build(1,k,0);
    int w=(1+k)>>1;
    fa[bh[w]]=y;c[y][0]=bh[w];updata(y);updata(x);
}
void shanchu(int k)
{
    int x=find(rot,now+1),y=find(rot,now+2+k);
    splay(x,rot);splay(y,c[x][1]);
    c[y][0]=0;updata(y);updata(x);
}
void fanzhuan(int k)
{
    int x=find(rot,now+1),y=find(rot,now+2+k);
    splay(x,rot);splay(y,c[x][1]);
    if(c[y][0])  mark[c[y][0]]^=1;
}
void print()
{
    int x=find(rot,now+2);
    splay(x,rot);
    printf("%c\n",zf[x]);
}
int main()
{
    int i,k;
    sz++;size[1]=2;rot=1;
    sz++;size[2]=1;c[1][1]=2;fa[2]=1;
    scanf("%d",&n);
    now=0;              
    for(i=1;i<=n;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='M') {scanf("%d",&k);now=k;}  else
        if(ch[0]=='P') now--;  else
        if(ch[0]=='N') now++;  else
        if(ch[0]=='D') {scanf("%d",&k);shanchu(k);} else
        if(ch[0]=='R') {scanf("%d",&k);fanzhuan(k);} else
        if(ch[0]=='G') print(); else
        if(ch[0]=='I')
        {
            scanf("%d%*c",&k);gets(s+1);Ins(k);
        } 
    }
    //system("pause");
    return 0;
}