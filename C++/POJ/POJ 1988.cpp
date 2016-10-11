#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int p;
int fa[30010],len[30010],before[30010];
int getfa(int x)
{
     if(fa[x]==0)  return x;
     getfa(fa[x]);
     before[x]+=before[fa[x]];
     if(fa[fa[x]]!=0) fa[x]=fa[fa[x]];  else fa[x]=fa[x];
     return fa[x];  
}
int main()
{
    int i,a,b,x,y;
    char s[3];
    for(i=1;i<=30000;i++)  {fa[i]=0;len[i]=1;before[i]=0;}
    scanf("%d",&p);     
    for(i=1;i<=p;i++)
    {
        scanf("%s",s);
        if(s[0]=='C')   {scanf("%d",&a);getfa(a);printf("%d\n",before[a]);}
        else
        {
           scanf("%d%d",&a,&b);
           x=getfa(a);y=getfa(b);
           if(x!=y)
           {
                   fa[x]=y;
                   before[x]=len[y];
                   len[y]+=len[x];  
           }
        }
    }
    system("pause");
    return 0;
}
