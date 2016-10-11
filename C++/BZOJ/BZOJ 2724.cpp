#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,num[40010],belong[40010],st[40],ed[40];
int SZ,KSZ,sum[40][40][40010],ans[40][40];
int top,shuzi[40010],tot,shu[40010];
int gs[40010],stack[40010];
inline void swap(int &a,int &b)
{
     int t=a;a=b;b=t;
}
inline int find(int x)
{
     int l=1,r=tot,mid;
     while(l+1<r)
     {
         mid=(l+r)>>1;
         if(shu[mid]==x) return mid;
         if(shu[mid]>x) r=mid;
         else l=mid;
     }
     if(shu[r]==x) return r;return l;
}
void init()
{
     int i,j,k,p,q;
     scanf("%d%d",&n,&m);
     for(i=1;i<=n;i++) 
     {
         scanf("%d",&num[i]);
         shuzi[++top]=num[i];
     }
     sort(shuzi+1,shuzi+1+top);
     shu[++tot]=shuzi[1];
     for(i=2;i<=top;i++) if(shuzi[i]!=shuzi[i-1]) shu[++tot]=shuzi[i];
     for(i=1;i<=n;i++) num[i]=find(num[i]);
     for(KSZ=1;KSZ*KSZ*KSZ<n;KSZ++); KSZ*=KSZ;
     k=KSZ+1;
     for(i=1;i<=n;i++)
     {
         if(k>KSZ)
         {
           SZ++;k=1;
           st[SZ]=i;ed[SZ-1]=i-1;
         }
         belong[i]=SZ;k++;
     }
     ed[SZ]=n;
     for(i=1;i<=SZ;i++) for(j=i;j<=SZ;j++)
     {
         ans[i][j]=n+1;
         for(k=st[i];k<=ed[j];k++)
         {
             p=num[k];q=ans[i][j];
             sum[i][j][num[k]]++;
             if(sum[i][j][p]>sum[i][j][q] || (sum[i][j][p]==sum[i][j][q] && p<q)) ans[i][j]=p;
         }
     }
}
void solve()
{
     int i,j,k,x,y,l,r,L,R,lastans=0,nans;      
     for(i=1;i<=m;i++)
     {
         scanf("%d%d",&l,&r);
         l=(l+lastans-1)%n+1,r=(r+lastans-1)%n+1;
         if(l>r) swap(l,r);
         x=belong[l]+1;y=belong[r]-1;
         nans=ans[x][y];
         top=0;L=l;R=r;
         while(belong[L]==belong[l] && L<=r)
         {
             j=num[L];gs[j]++;
             if(gs[j]==1) stack[++top]=j;
             if(sum[x][y][j]+gs[j]>sum[x][y][nans]+gs[nans] || (sum[x][y][j]+gs[j]==sum[x][y][nans]+gs[nans] && nans>j))
             nans=j;
             L++;
         }
         L--;
         while(belong[R]==belong[r] && R>L)
         {
             j=num[R];gs[j]++;
             if(gs[j]==1) stack[++top]=j;
             if(sum[x][y][j]+gs[j]>sum[x][y][nans]+gs[nans] || (sum[x][y][j]+gs[j]==sum[x][y][nans]+gs[nans] && nans>j))
             nans=j;
             R--;
         }
         printf("%d\n",shu[nans]);
         lastans=shu[nans];
         while(top) {gs[stack[top]]=0;top--;}
     }
}
int main()
{
    init();
    solve();
    return 0;
}