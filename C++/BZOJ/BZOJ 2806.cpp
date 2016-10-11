#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-5
#define N 2300000
using namespace std;
int n,m,tot,S[N],d[N],f[N],q[N];
int sz,last,to[N][3],next[N],step[N];
char s[N];
void add(int id)
{
    int p=last,np=++sz;
    last=np;step[np]=step[p]+1;
    for(;p!=-1 && !to[p][id];p=next[p]) to[p][id]=np;
    if(p==-1)  next[np]=0;
    else
    {
        int q=to[p][id];
        if(step[q]==step[p]+1)  next[np]=q;
        else
        {
            int nq=++sz;
            step[nq]=step[p]+1;
            next[nq]=next[q];
            next[q]=nq;next[np]=nq;
            for(int i=0;i<3;i++)  to[nq][i]=to[q][i];
            for(;p!=-1 && to[p][id]==q;p=next[p]) to[p][id]=nq;
        }
    }  
}
void init()
{
     int i,j,len;
     next[0]=-1;
     scanf("%d%d",&n,&m);
     for(i=1;i<=m;i++)
     {
        scanf("%s",s+1);
        len=strlen(s+1);
        for(j=1;j<=len;j++)  S[++tot]=s[j]-'0';
        S[++tot]=2;
     }
     for(i=1;i<tot;i++) add(S[i]);
}
bool check(int limt,int len)
{
     int tou=1,wei=0,i;
     f[0]=0;
     for(i=1;i<=len;i++)
     {
        if(i-limt>=0)
        {
           while(tou<=wei && f[q[wei]]-q[wei]<f[i-limt]-(i-limt))  wei--;
           q[++wei]=i-limt;
        }
        while(tou<=wei && q[tou]<i-d[i])  tou++;
        f[i]=f[i-1];
        if(tou<=wei && f[i]<f[q[tou]]-q[tou]+i)  f[i]=f[q[tou]]-q[tou]+i;
     }
     double ll=0.9*(double)(len);
     int k=int(ll);
     if(fabs(k*1.0-ll)>eps) k++;
     if(f[len]>=k) return 1; return 0;
}
void solve()
{
     int i,j,k,now,nl,len,l,r,mid;
     while(n--)
     {               
         scanf("%s",s+1);
         len=strlen(s+1);
         now=0;nl=0;         
         for(j=1;j<=len;j++)
         {
            k=s[j]-'0';
            if(to[now][k])  {now=to[now][k];nl++;}
            else
            { 
                for(;now!=-1 && !to[now][k];now=next[now]);
                if(now==-1) {now=0;nl=0;}
                else {nl=step[now]+1;now=to[now][k];}
            }
            d[j]=nl;
         }                  
         if(!check(1,len))  printf("0\n");
         else
         {
             l=1;r=len;
             while(l+1<r)
             {
                 mid=(l+r)>>1;
                 if(check(mid,len))  l=mid;
                 else  r=mid;
             }
             if(check(r,len)) printf("%d\n",r); else printf("%d\n",l);
         }
     }
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
