#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int A=2503,B=1314,C=25203,D=100007;
int n,sz,to[2010],pre[2010],last[1010];
bool mark[1010];
int hash(int x)
{
    int i=last[x],q[1010],top=0;
    mark[x]=1;
    while(i>0)
    {
        if(!mark[to[i]])
        {
            q[++top]=hash(to[i]);
        }
        i=pre[i];
    }
    if(top==0)  return A;
    sort(q+1,q+1+top);
    int sum=q[1];
    for(i=2;i<=top;i++)
    {
        sum=(sum*B)%D; sum^=q[i];
    }
    return (sum*C)%D;
}
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
int main()
{
    int t,a,b,i,aa,bb;
    bool o;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&n);
         memset(last,0,sizeof(last));sz=0;
         for(i=1;i<n;i++)
         {
            scanf("%d%d",&a,&b);
            Ins(a,b);Ins(b,a);
         }
         memset(mark,0,sizeof(mark));
         aa=hash(1);
         memset(last,0,sizeof(last));sz=0;
         for(i=1;i<n;i++)
         {
            scanf("%d%d",&a,&b);
            Ins(a,b);Ins(b,a);
         }
         o=0;
         for(i=1;i<=n;i++)
         {
             memset(mark,0,sizeof(mark));
             bb=hash(i);
             if(aa==bb)  {printf("same\n");o=1;break;}
         }
         if(!o) printf("different\n");
    }
    system("pause");
    return 0;
}
