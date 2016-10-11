#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,num[1000010],ans,f[1000010],g[1000010];
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
inline bool comp(int a,int b)  {return a<b;}
int main()
{
    int i,k;
    n=read();//scanf("%d",&n);
    for(i=1;i<=n;i++)  num[i]=read();//scanf("%d",&num[i]);
    sort(num+1,num+1+n,comp);
    for(i=1;i<=n;i++)
    {
       k=i-num[i];
       if(k>=0) 
       { 
          f[i]=g[k]+1;
          g[i]=g[i-1];
          if(f[i]>g[i])  g[i]=f[i];
       }
    }
    cout<<f[n]<<endl;
    system("pause");
    return 0;
}
