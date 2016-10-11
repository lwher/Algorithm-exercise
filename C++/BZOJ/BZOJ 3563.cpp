#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,q,fa[100010];
int K[50010],k[50010],A[500010],B[500010];
int cnt[100010],num[50010];
bool mark[500010];
int getfa(int x)
{
    if(fa[x]==0)  return x;
    return fa[x]=getfa(fa[x]);
}
bool check()
{
    int i,x,y;
    x=getfa(1);
    for(i=2;i<=n;i++)  
    {
        y=getfa(i);
        if(x!=y)  return 0;
    }
    return 1;
}
int main()
{
    int i,a,b,x,y;char ch;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)  scanf("%d%d",&A[i],&B[i]);
    scanf("%d",&q);     
    for(i=1;i<q;i++)
    {
        scanf("%d",&k[i]);ch='a';
        while(ch!='\n')
        {
            ch=getchar();  if(ch=='\n')  break;
            if(ch>='0' && ch<='9') 
            {   
                while(ch>='0' && ch<='9') ch=getchar();
                K[i]++;
            }
        }
    }
    scanf("%d",&k[q]);
    while(scanf("%d",&cnt[++K[q]])!=EOF);
    K[q]--;
    for(i=1;i<=q;i++)  num[i]=(K[i]^k[i]);
    for(i=1;i<q;i++)  if(num[i]==num[i+1])  printf("Disconnected\n"); else printf("Connected\n");
    a=K[q]^k[q];
    for(i=1;i<=K[q];i++)  {cnt[i]^=a;mark[cnt[i]]=1;}
    for(i=1;i<=m;i++)  if(!mark[i])
    {
        x=getfa(A[i]);y=getfa(B[i]);
        if(x!=y)  fa[x]=y;
    }
    if(check())  printf("Connected\n");  else printf("Disconnected\n");
    return 0;
}