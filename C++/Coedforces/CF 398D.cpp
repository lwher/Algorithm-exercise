#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,q,size[50010],Ans[50010];
int sz,to[500010],pre[500010],last[50010];
bool on[50010];
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void addage(int a,int b)
{
     if(size[a]>size[b]) swap(a,b);
     size[a]++;
     Ins(a,b);
     if(on[a]) Ans[b]++;
}
void solveonline(int x)
{
     on[x]=1;
     for(int i=last[x];i;i=pre[i]) Ans[to[i]]++;
}
void offline(int x)
{
     on[x]=0;
     for(int i=last[x];i;i=pre[i]) Ans[to[i]]--;
}
int countsum(int x)
{
    int i,res=Ans[x];
    for(i=last[x];i;i=pre[i]) if(on[to[i]]) res++;
    return res;
}
int find(int a,int b)
{
    for(int i=last[a];i;i=pre[i]) if(to[i]==b) return i;
    return -1;
}
void del(int a,int b)
{
    int i;size[a]--;
    if(on[a]) Ans[to[b]]--;
    if(last[a]==b) {last[a]=pre[last[a]];return;}
    for(i=last[a];pre[i]!=b;i=pre[i]);
    pre[i]=pre[pre[i]];
}
void Delage(int a,int b)
{
    int k=find(a,b);
    if(k!=-1) del(a,k);
    else {k=find(b,a);del(b,k);}
}
int main()
{
    int i,x,a,b;
    char ch[3];
    scanf("%d%d%d",&n,&m,&q);
    scanf("%d",&x);
    for(i=1;i<=x;i++) 
    {
       scanf("%d",&a);
       on[a]=1;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        addage(a,b);
    }   
    for(i=1;i<=q;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='O') 
        {
           scanf("%d",&x);solveonline(x);
        } else 
        if(ch[0]=='F')
        {
           scanf("%d",&x);offline(x);        
        } else
        if(ch[0]=='A')
        {
           scanf("%d%d",&a,&b);addage(a,b);
        } else
        if(ch[0]=='D')
        {
           scanf("%d%d",&a,&b);Delage(a,b);
        } else
        {
           scanf("%d",&x);printf("%d\n",countsum(x));
        }
    }    
    system("pause");
    return 0;
}
