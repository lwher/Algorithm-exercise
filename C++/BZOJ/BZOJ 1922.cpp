#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define INF 0x7fffffff
using namespace std;
int n,m,num[3010],d[3010],e[3010];
int sz,to[100010],v[100010],pre[100010],last[3010];
int protect[3010][3010];
bool mark[3010];
void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void init()
{
    int i,j,k,a,b,c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        Ins(a,b,c);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);num[i]=k;
        while(k--)
        {
            scanf("%d",&a);
            protect[a][++protect[a][0]]=i;
        }
    }
}
void dijskstra()
{
    int i,j,k,q;
    for(i=1;i<=n;i++) d[i]=INF;
    d[1]=0;
    int minn,p;
    for(i=1;i<=n;i++)
    {
        minn=INF;p=0;
        for(j=1;j<=n;j++)
        if(!num[j] && !mark[j] && max(d[j],e[j])<minn)
        {
            minn=max(d[j],e[j]);p=j;
        }
        if(p==0)  break;
        mark[p]=1;k=max(d[p],e[p]);
        for(j=1;j<=protect[p][0];j++)  {q=protect[p][j];num[q]--;e[q]=max(e[q],k);}
        for(j=last[p];j;j=pre[j])  if(d[to[j]]>k+v[j]) d[to[j]]=k+v[j];
    }
}
int main()
{
    init(); 
    dijskstra();
    printf("%d\n",max(d[n],e[n]));
    return 0;
}