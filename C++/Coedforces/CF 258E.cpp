#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int s[600010],c[600010],ft[100010],sd[100010];
int n,m,sz,tt,sz1;
int to1[500010],pre1[500010],last1[100010];
int to[200010],pre[200010],last[100010];
bool mark[100010];int ans[100010];
void Ins(int a,int b){
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void Ins1(int a,int b){
     sz1++;to1[sz1]=b;pre1[sz1]=last1[a];last1[a]=sz1;
}
void dfs(int x)
{
     int i=last[x];
     mark[x]=1;
     tt++;ft[x]=tt;
     while(i>0){
               if(!mark[to[i]])  dfs(to[i]);
               i=pre[i];
     }
     tt++;sd[x]=tt;
}
void init()
{
     int i,a,b;
     scanf("%d%d",&n,&m);
     for(i=1;i<n;i++)  {
         scanf("%d%d",&a,&b);
         Ins(a,b);Ins(b,a);
     }
     dfs(1);
     memset(mark,0,sizeof(mark));
     for(i=1;i<=m;i++){
         scanf("%d%d",&a,&b);
         Ins1(a,b);Ins1(b,a);
         Ins1(a,a);Ins1(b,b);
     }n*=2;
}
void cover(int l,int r,int k,int zuo,int you,int p)
{
     if(l>=zuo && r<=you){
                if(p==1)   c[k]++;  else   c[k]--;
                if(c[k])   s[k]=r-l+1;  else  {if(l!=r)s[k]=s[k+k]+s[k+k+1]; else s[k]=0;}
                return;
     }
     int mid=(l+r)>>1;
     if(zuo<=mid)  cover(l,mid,k+k,zuo,you,p);
     if(you>mid)   cover(mid+1,r,k+k+1,zuo,you,p);
     if(!c[k])  s[k]=s[k+k]+s[k+k+1];
}
void solve(int x)
{
     mark[x]=1;
     int i=last1[x],g,j;
     while(i>0){
          g=to1[i];
          cover(1,n,1,ft[g],sd[g],1);
          i=pre1[i];
     }
     ans[x]=s[1]/2;
     if(ans[x])  ans[x]--;
     j=last[x];
     while(j>0){
          if(!mark[to[j]])
          solve(to[j]);
          j=pre[j];
     }
     i=last1[x];
     while(i>0){
          g=to1[i];
          cover(1,n,1,ft[g],sd[g],-1);
          i=pre1[i];
     }
}
int main()
{
    init();
    solve(1);
    int i;
    n/=2;
    for(i=1;i<n;i++)
    printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    system("pause");
    return 0;
}
