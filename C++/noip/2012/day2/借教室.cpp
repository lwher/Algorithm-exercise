#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define N 1000010
using namespace std;
int n,m;
int have[N],need[N];
int L[N],R[N],NEED[N];
bool o;
inline int Read()
{
 char ch = getchar();
 while (!(ch >= '0' && ch <= '9')) ch = getchar();
 int x = 0;
 while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
 return x;
}
bool check(int x)
{
     int i;memset(need,0,sizeof(need));
     for(i=1;i<=x;i++)  {need[L[i]]+=NEED[i];need[R[i]+1]-=NEED[i];}
     for(i=1;i<=n;i++)  {need[i]+=need[i-1]; if(need[i]>have[i]) return 0;}
     return 1;
}
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) 
    {
       have[i]=Read();
    }    
    for(i=1;i<=m;i++)
    {
       NEED[i]=Read();L[i]=Read();R[i]=Read();
       need[L[i]]+=NEED[i];need[R[i]+1]-=NEED[i];
    } 
    for(i=1;i<=n;i++)  
    {need[i]+=need[i-1]; if(need[i]>have[i]) o=1;}
    if(o)
    {
          printf("-1\n");
          int l=1,r=m,mid;
          while(l+1<r)
          {
              mid=(l+r)>>1;
              if(check(mid))  l=mid;
              else r=mid;
          }
          if(!check(l))  printf("%d\n",l);
          else           printf("%d\n",r);
    }
    else printf("0\n");
    system("pause");
    return 0;
}
