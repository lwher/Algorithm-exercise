#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,nm,q,top;
long long A,B,C,D;
int x[25000001],t[25000001],up[5010],down[5010],ans[10010];
void init()
{
     memset(up,127/3,sizeof(up));
     cin>>x[0]>>A>>B>>C>>D;
     cin>>n>>m>>q;
     nm=n*m;
}
void Del(int a,int b)
{
     for(int i=1;i<=n;i++)
     {
         if(i<a) up[i]=min(b,up[i]);
         else if(i>a) down[i]=max(b,down[i]);
     }
}
void solve()
{
     int i,u,v,a,b;
     for(i=1;i<=nm;i++) x[i]=(x[i-1]*(A*x[i-1]+B)+C)%D,t[i]=i;
     for(i=1;i<=nm;i++) swap(t[i],t[(x[i]%i)+1]);
     for(i=1;i<=q;i++)
     {
         scanf("%d%d",&u,&v);
         swap(t[u],t[v]);
     }
     for(i=1;i<=nm;i++) x[t[i]]=i;
     for(i=1;i<=nm;i++)
     {
         if(x[i]%m) a=x[i]/m+1;
         else a=x[i]/m;
         b=x[i]%m; 
         if(!b) b+=m;
         if(b<=up[a] && b>=down[a])
         {
             Del(a,b);
             ans[++top]=i;
             if(top==n+m-1) break;
         }
     }
}
void print()
{
     for(int i=1;i<top;i++) printf("%d ",ans[i]);
     printf("%d",ans[top]);
}
int main()
{
     init();
     solve();
     print();
     return 0;
}