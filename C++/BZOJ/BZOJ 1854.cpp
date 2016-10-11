#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,fa[10010];bool vis[10010];
int getfa(int x)
{
    if(fa[x]==0)return x;return fa[x]=getfa(fa[x]);
}
void swap(int &a,int &b)  {int t=a;a=b;b=t;}
int main()
{
    int i,x,y,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        x=getfa(a);y=getfa(b);
        if(x==y)  vis[x]=1;
        else
        {
            if(x<y)  swap(x,y);
            vis[y]=1;fa[y]=x;
        }
    }
    for(i=1;i<=10001;i++)  if(!vis[i])  {printf("%d\n",i-1);break;}
    //system("pause");
    return 0;
}