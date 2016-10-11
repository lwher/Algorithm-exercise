#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,l,r,mid;
int sz,to[1000010],pre[1000010],last[1010];
char s[2010];
int num[1010],pipei[1010][1010];
bool d[1010];
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
bool find(int x)
{
     int i=last[x],j;
     while(i>0)
     {
         if(!d[to[i]])
         {
             d[to[i]]=1;
             if(num[to[i]]<mid)   
             {
                 pipei[to[i]][++num[to[i]]]=x;return 1;
             }
             for(j=1;j<=num[to[i]];j++)
             {
                 if(find(pipei[to[i]][j]))
                 {
                     pipei[to[i]][j]=x;return 1;
                 }
             }
         }
         i=pre[i];      
     }
     return 0;
}
bool check()
{
     int i;
     memset(num,0,sizeof(num));
     for(i=1;i<=n;i++)
     {
         memset(d,0,sizeof(d));
         if(!find(i))  return 0;
     }
     return 1;
}
int main()
{
    int i,j,k,len;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)  break;
        sz=0;memset(last,0,sizeof(last));
        getchar();
        for(i=1;i<=n;i++)
        {
            gets(s+1);
            int len=strlen(s+1);
            for(j=1;j<=len;j++)
            {
                if(s[j]>='0' && s[j]<='9')
                {
                    k=0;
                    while(s[j]>='0' && s[j]<='9')
                    {
                        k=k*10+s[j++]-'0';
                    }
                    Ins(i,k);
                }
            }
        }
        l=0;r=n;
        while(l+1<r)
        {
            mid=(l+r)>>1;
            if(check())  r=mid;
            else l=mid;
        }
        mid=l;
        if(check())  printf("%d\n",l); else printf("%d\n",r);
    }
    system("pause");
    return 0;
}
