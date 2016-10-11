#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<cstring>
using namespace std;
bool f[1001];
int ans[1001],son[1001],ed[2001],next[2001],r[2001];
int n,i,j,k,a,b,c;
void dfs(int p)
{
int i;
f[p]=false;
for(i=son[p];i;i=next[i])
if(f[ed[i]])
{
if(r[i]==1)
{
if(ans[p]==1)
ans[ed[i]]=0;
else
ans[ed[i]]=1;
}
else
{
if(ans[p]==1)
ans[ed[i]]=1;
else
ans[ed[i]]=0;
}
dfs(ed[i]);
}
}
int main()
{
scanf("%d",&n);
for(i=2;i<=n;++i)
{
scanf("%d%d%d",&a,&b,&c);
next[i]=son[a];
son[a]=i;
ed[i]=b;
r[i]=c;
next[i+n]=son[b];
son[b]=i+n;
ed[i+n]=a;
r[i+n]=c;
}
memset(f,true,sizeof(f));
f[1]=false;
ans[1]=0;
dfs(1);
printf("%d\n",ans[n]);
system("pause"); 
return 0;
}
