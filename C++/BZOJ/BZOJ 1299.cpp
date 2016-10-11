#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,p[15];
bool finded;
void dfs(int now,int used,int XOR)
{
    if(XOR==0 && used>0)  {finded=1;return;}
    if(now==n+1)  return;
    dfs(now+1,used,XOR);
    dfs(now+1,used+1,XOR^p[now]);
}
int main()
{
    int i,T=10;
    while(T--)
    {
         scanf("%d",&n);
         for(i=1;i<=n;i++)  scanf("%d",&p[i]);
         finded=0;
         dfs(1,0,0);    
         if(finded) printf("NO\n"); else printf("YES\n");
    }
    //system("pause");
    return 0;
}