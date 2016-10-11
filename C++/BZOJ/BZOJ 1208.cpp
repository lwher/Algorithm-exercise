#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
using namespace std; 
int n,sz,rot; 
long long ans; 
int c[80010][2],num[80010],fa[80010]; 
int qq,hj,kind; 
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
} 
void splay(int x,int &root) 
{ 
    int y,z; 
    while(x!=root) 
    { 
        y=fa[x];z=fa[y]; 
        if(y!=root) 
        { 
            if((c[y][0]==x)^(c[z][0]==y))  rotate(x,root); 
            else  rotate(y,root); 
        } 
        rotate(x,root); 
    } 
} 
void Ins(int &x,int shu,int last) 
{ 
    if(x==0) 
    { 
        sz++;x=sz;num[x]=shu;fa[x]=last;splay(x,rot);return; 
    } 
    if(shu<num[x])  Ins(c[x][0],shu,x);  else  Ins(c[x][1],shu,x); 
} 
void findqq(int x,int shu) 
{ 
    if(x==0)  return; 
    if(shu==num[x])  {qq=x;return;} 
    if(num[x]<shu && qq==-1)  qq=x; 
    if(qq!=-1 && num[x]<shu && shu-num[x]<shu-num[qq]) qq=x; 
    if(shu<num[x])  findqq(c[x][0],shu); else findqq(c[x][1],shu);   
} 
void findhj(int x,int shu) 
{ 
    if(x==0)  return; 
    if(shu==num[x])  {hj=x;return;} 
    if(num[x]>shu && hj==-1)  hj=x; 
    if(num[x]>shu && num[x]-shu<num[hj]-shu) hj=x; 
    if(shu<num[x])  findhj(c[x][0],shu); else findhj(c[x][1],shu);   
} 
void shanchu(int x) 
{ 
    splay(x,rot); 
    if(c[x][0]*c[x][1]==0) 
    { 
        if(c[x][0]>0)  rot=c[x][0]; else rot=c[x][1]; 
        fa[rot]=0; 
    } 
    else
    { 
        int k=c[x][1]; 
        while(c[k][0]>0)  k=c[k][0]; 
        c[k][0]=c[x][0];fa[c[x][0]]=k; 
        rot=c[x][1];fa[rot]=0; 
    } 
} 
int main() 
{ 
    int i,k,a; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) 
    { 
        scanf("%d%d",&k,&a); 
        if(rot==0)   
        { 
            kind=k; 
            Ins(rot,a,0); 
        }else
        if(kind^k==0) 
        { 
            Ins(rot,a,0); 
        }else
        { 
            qq=-1;hj=-1; 
            findqq(rot,a);findhj(rot,a); 
            if(qq==-1) 
            { 
                ans+=num[hj]-a;ans%=1000000;shanchu(hj); 
            }else
            if(hj==-1) 
            { 
                ans+=a-num[qq];ans%=1000000;shanchu(qq); 
            }else
            { 
                if(a-num[qq]>num[hj]-a)  {ans+=num[hj]-a;ans%=1000000;shanchu(hj);} 
                else  {ans+=a-num[qq];ans%=1000000;shanchu(qq);} 
            } 
        }    
    } 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}