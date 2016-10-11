#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
struct sth
{
       int a,b,v;
}lu[10010];
int fa[110],n,m,t;
int ans,now,mst[110];
bool o;
int getfa(int x)
{
    if(fa[x]==0)  return x;
    else  return fa[x]=getfa(fa[x]);
}
inline bool comp(sth aa,sth bb)
{
       return aa.v<bb.v;
}
int main()
{
    int i,j,k,x,y;
    scanf("%d",&t);    
    while(t--)
    {
         scanf("%d%d",&n,&m);
         for(i=1;i<=m;i++)  scanf("%d%d%d",&lu[i].a,&lu[i].b,&lu[i].v);
         sort(lu+1,lu+1+m,comp);
         memset(fa,0,sizeof(fa));
         k=0;ans=0;
         for(i=1;i<=m;i++)
         {
             x=getfa(lu[i].a);y=getfa(lu[i].b);
             if(x!=y)
             {
                 ans+=lu[i].v;fa[x]=y;k++;mst[k]=i;
                 if(k==n-1)  break;
             }
         }
         if(k!=n-1)  ans=0;
         o=0; 
         for(i=1;i<=n-1;i++)
         {
             memset(fa,0,sizeof(fa));
             now=0;k=0;
             for(j=1;j<=m;j++)
             if(j!=mst[i])
             {
                  x=getfa(lu[j].a);y=getfa(lu[j].b);
                  if(x!=y)
                  {
                       now+=lu[j].v;fa[x]=y;k++;
                       if(k==n-1)  break;
                  }
             }
             if(k==n-1){
             if(now==ans)  {o=1;break;} 
             }
         }
         if(o)  printf("Not Unique!\n");
         else   printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
