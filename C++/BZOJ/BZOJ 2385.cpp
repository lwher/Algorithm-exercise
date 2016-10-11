#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
const int maxn=500010;  
int n,m,o,now,q[maxn],sz;  
int fa[maxn];  
long long ans;  
struct hotel{  
       int c,p;  
}h[maxn];  
struct people{  
       int money,inpeople;  
}d[maxn];  
int shuru() 
{ 
    char ch=getchar(); 
    while(!(ch>='0' && ch<='9'))  ch=getchar(); 
    int x=0; 
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();} 
    return x; 
} 
int getfa (int a)  
{  
    if (a==fa[a])  
      return a;  
    return fa[a]=getfa(fa[a]);  
}  
int find(int k)  
{  
    int l=1,r=n;  
    int mid,temp;  
    while (l<r)  
    {  
      mid=(l+r)>>1;  
      temp=getfa(mid);  
      if (h[temp].p >=k && temp<=n) r=mid;  
      else l=mid+1;  
    }  
    return getfa(l);  
}  
bool cmp1 (hotel a,hotel b)  
{  
     if (a.p!=b.p)  return a.p<b.p;  
     return a.c<b.c;  
}  
bool cmp2 (people a,people b)  
{  
     return a.money>b.money;  
}  
bool cmp3 (int a,int b)  
{  
     return a>b;  
}  
void doing ()  
{  
     int i,k;  
     //scanf("%d%d%d",&n,&m,&o);  
     n=shuru();m=shuru();o=shuru(); 
     for(i=1;i<=n;i++)  
     {  
       //scanf ("%d%d",&h[i].c,&h[i].p); 
       h[i].c=shuru();h[i].p=shuru();  
       fa[i]=i;  
     }  
     fa[n+1]=n+1;  
     for(i=1;i<=m;i++)  
     {d[i].money=shuru();d[i].inpeople=shuru();} 
       //scanf("%d%d",&d[i].money,&d[i].inpeople);  
     sort(h+1,h+1+n,cmp1);  
     sort(d+1,d+1+m,cmp2);  
     for(i=1;i<=m;i++)  
     {  
         k=find(d[i].inpeople);  
         if (k<=n)  
         if  (h[k].p>=d[i].inpeople && h[k].c<d[i].money)  
         {  
           q[++sz]+=d[i].money-h[k].c;  
           fa[k]=k+1;  
         }  
     }  
     sort(q+1,q+1+sz,cmp3);  
     for(i=1;i<=o;i++)   ans+=q[i];  
     cout<<ans<<endl;  
}  
int main()  
{  
    doing();  
   // system ("pause");  
    return 0;  
}