#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-6
using namespace std;
int n,m,l,sz,t[301][20],fail[301],to[301][20],w[20];
double p[20],a[301][301];
char s[20];
bool v[301];
void Insert(int now,int top,int bh)
{
    if(top==l+1)  {v[now]=1;w[bh]=now;return;}
    int k=s[top]-'A'+1;
    if(!t[now][k])  t[now][k]=++sz;
    Insert(t[now][k],top+1,bh);
}
void getfail()
{
    int i,j,now,k,dui[301],tou=1,wei=1;
    dui[1]=0;fail[0]=-1;
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        for(k=1;k<=m;k++)
        if(t[now][k])
        {
            j=fail[now];
            while(j!=-1)
            {
                if(t[j][k]) {fail[t[now][k]]=t[j][k];break;}
                j=fail[j];
            }
            if(j==-1)  fail[t[now][k]]=0;
            dui[++wei]=t[now][k];
        }
    }
}
void swap(double &a,double &b) {double t=a;a=b;b=t;}
bool gauss(int nm)
{
    int i,j,k,now=1;double tt;
    for(i=1;i<=nm;i++)
    {
        for(j=now;j<=nm;j++)  if(fabs(a[j][i])>eps)   break;
        if(j>nm)  continue;
        if(j!=now)  for(k=1;k<=nm+1;k++)  swap(a[j][k],a[now][k]);
        tt=a[now][i];
        for(k=1;k<=nm+1;k++)   a[now][k]/=tt;
        for(j=1;j<=nm;j++)
        if(j!=now)
        {
            tt=a[j][i];
            for(k=1;k<=nm+1;k++)   a[j][k]-=tt*a[now][k];
        }
        now++;
    }
    for(i=now;i<=nm;i++)  if(fabs(a[i][nm+1])>eps)  return 0;
    return 1;
}
int main()
{
    int i,j,k,pi,qi;
    scanf("%d%d%d",&n,&l,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&pi,&qi);
        if(qi) p[i]=double(pi)/double(qi);  else p[i]=0;
    }   
    for(i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        Insert(0,1,i);
    }   
    getfail();
    for(i=0;i<=sz;i++)
    {
        for(j=1;j<=m;j++)
        {
            k=i;
            while(k!=-1)
            {
                if(t[k][j])  {to[i][j]=t[k][j];break;}
                k=fail[k];
            }
            if(k==-1)  to[i][j]=0;
        }
    }
    for(i=0;i<=sz;i++)
    {
        a[i+1][i+1]-=1;
        if(!v[i])
        {
            for(j=1;j<=m;j++)   a[to[i][j]+1][i+1]+=p[j];
        }
    }
    for(i=1;i<=sz+1;i++)   if(v[i-1]) a[1][i]=1;  else a[1][i]=0;
    a[1][sz+2]=1;
    if(!gauss(sz+1))
    {
        for(i=1;i<=n;i++)  printf("0.00\n");
    }
    else
    for(i=1;i<=n;i++)  
    {
        if(a[w[i]+1][sz+2]>0 && a[w[i]+1][sz+2]<=1)  printf("%.2lf\n",a[w[i]+1][sz+2]);
        else printf("0.00\n");
    }
    //system("pause");
    return 0;
}
