#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define inf 10001
#define N 300010
using namespace std;
int n,m,k,p,q;
int tot,a[N],w[N],xw[N],len[N];// a 姓+名+询问串  w[i]: a[i]属于哪一个串 w[i]=0：询问串or空
int sa[2][N<<1],rk[2][N<<1],v[N<<1],h[N]; 
int stack[N],top,ans[N];
bool mark[N];
void Calc_SA(int sa[N<<1],int rk[N<<1],int SA[N<<1],int RK[N<<1])
{
     int i;
     for(i=1;i<=tot;i++)  v[rk[sa[i]]]=i;
     for(i=tot;i>=1;i--)  if(sa[i]>k)   SA[v[rk[sa[i]-k]]--]=sa[i]-k; 
     for(i=tot-k+1;i<=tot;i++)  SA[v[rk[i]]--]=i;
     for(i=1;i<=tot;i++)  RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]] || rk[SA[i]+k]!=rk[SA[i-1]+k]);
}
void PX_SA()
{
     int i;p=0;q=1;k=1;a[0]=-1;
     for(i=1;i<=tot;i++) v[a[i]]++;
     for(i=1;i<=10010;i++)  v[i]+=v[i-1];
     for(i=1;i<=tot;i++)  sa[p][v[a[i]]--]=i;
     for(i=1;i<=tot;i++)  rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(a[sa[p][i]]!=a[sa[p][i-1]]);
     while(k<tot)
     {
         Calc_SA(sa[p],rk[p],sa[q],rk[q]);
         p^=1;q^=1;k=k<<1;
     }
}
void getheight()
{
     int i,j;k=0;
     for(i=1;i<=tot;i++)
     {
         if(rk[p][i]==1)  h[rk[p][i]]=0;
         else 
         {
              j=sa[p][rk[p][i]-1];
              while(a[i+k]==a[j+k])  k++;
              h[rk[p][i]]=k;if(k>0) k--;
         }
     }
}
void init()
{
     int i,j,d,s;
     scanf("%d%d",&n,&m);
     for(i=1;i<=n;i++)
     {
        scanf("%d",&s);
        for(j=1;j<=s;j++)  {scanf("%d",&d);d++;a[++tot]=d;w[tot]=i;}
        a[++tot]=inf;w[tot]=0;
        scanf("%d",&s);
        for(j=1;j<=s;j++)  {scanf("%d",&d);d++;a[++tot]=d;w[tot]=i;}
        a[++tot]=inf;w[tot]=0;
     }
     for(i=1;i<=m;i++)
     {
         scanf("%d",&s);
         if(s>0)  {xw[i]=tot+1;len[i]=s;}
         for(j=1;j<=s;j++)  {scanf("%d",&d);d++;a[++tot]=d;w[tot]=0;}
         a[++tot]=inf+1;w[tot]=0;
     }
}
void solve()
{
     PX_SA();
     getheight();
     int i,j,x,tmp;
     for(i=1;i<=m;i++)
     {
         tmp=0;
         if(xw[i]>0)
         {
             j=xw[i];j=rk[p][j];
             x=j-1;
             while(h[x+1]>=len[i])
             {
                 if(w[sa[p][x]]>0 && !mark[w[sa[p][x]]])
                 {
                     tmp++;
                     mark[w[sa[p][x]]]=1;
                     stack[++top]=w[sa[p][x]];
                 }
                 x--;
             }
         }
         printf("%d\n",tmp);
         while(top>0)  {mark[stack[top]]=0;ans[stack[top]]++;top--;}
     }
     for(i=1;i<n;i++)   printf("%d ",ans[i]); printf("%d\n",ans[n]);
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
