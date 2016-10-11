#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct sth
{
       int nian,yu;
}p[50010];
int t[200010];
int n,m;
int maxx;
int find(int x)
{
    int l=1,mid,r=n;
    while(l<r)
    {
       if(l+1==r)  break;
       mid=(l+r)/2;
       if(p[mid].nian<x)
       l=mid;
       else
       r=mid;
    }
    if(p[l].nian==x)
    return l;
    if(p[r].nian==x)
    return r;
    return -1;
}
void add(int k,int l,int r,int x,int shu)
{
     if(l>x || r<x)  return;
     if(l==r)  
     {t[k]=shu;return;}
     int mid=(l+r)>>1;
     add(k*2,l,mid,x,shu);
     add(k*2+1,mid+1,r,x,shu);
     t[k]=max(t[k*2],t[k*2+1]);
}
int ask(int k,int l,int r,int zuo,int you)
{
    if(l>you || r<zuo)  return -1;
    if(l>=zuo && r<=you)  return t[k];
    int mid=(l+r)>>1;
    return max(ask(k*2,l,mid,zuo,you),ask(k*2+1,mid+1,r,zuo,you));
}
int main()
{
    int i,j;
    int a,b;
    int x,y,o;
    int gs;
    
    while(scanf("%d",&n))
    {
    if(n==0)
    {
            scanf("%d",&m);
            if(m==0) break;
            for(i=1;i<=m;i++)
            {scanf("%d%d",&a,&b);
            if(b<=a) printf("false\n");
            else
            printf("maybe\n");}
    }
    memset(t,0,sizeof(t));
    for(i=1;i<=n;i++)
    {scanf("%d%d",&p[i].nian,&p[i].yu);add(1,1,n,i,p[i].yu);}
    scanf("%d",&m);
    
    for(i=1;i<=m;i++)
    {
       scanf("%d%d",&a,&b);
       if(b<=a)  {printf("false\n");continue;}
       x=find(a);
       y=find(b);
       if(x==-1 && y==-1)  {printf("maybe\n");continue;}
       if(x!=-1 && y!=-1)
       if(p[y].yu >p[x].yu)  {printf("false\n");continue;}
       if(x==-1)
       {
          int l=1,mid,r=n;
          while(l<r)
          {
          if(l+1==r)  break;
          mid=(l+r)/2;
          if(p[mid].nian<a)
          l=mid;
          else
          r=mid;
          }     
         
         if(p[l].nian>a)  o=l;
         else
         o=r;
         if(o==n || o==y)  printf("maybe\n");
         else
         {
             maxx=ask(1,1,n,o,y-1);
             if(maxx>=p[y].yu)
             printf("false\n");
             else
             printf("maybe\n");
         }
         continue;
       } 
       if(y==-1)
       {
          int l=1,mid,r=n;
          while(l<r)
          {
          if(l+1==r)  break;
          mid=(l+r)/2;
          if(p[mid].nian<b)
          l=mid;
          else
          r=mid;
          }     
         if(p[r].nian<b)  o=r;
         else
         o=l;
         if(o==x)  printf("maybe\n");
         else
         {
            maxx=ask(1,1,n,x+1,o);
            if(maxx>=p[x].yu)
            printf("false\n");
            else
            printf("maybe\n");
         }
         continue;
       }
       if(y-1==x)  
       {
       if(p[y].nian-p[x].nian==y-x)
       printf("true\n");
       else
       printf("maybe\n");
       continue;}
       maxx=ask(1,1,n,x+1,y-1);
       if(maxx>=p[y].yu)  {printf("false\n");}
       else
       if(p[y].nian-p[x].nian != y-x)
       printf("maybe\n");
       else
       printf("true\n");
    }
    printf("\n");
    }
  //  system("pause");
    return 0;
}

