#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,ans;
int f[3];
struct data{int x,f;}a[20005];
inline bool operator<(data a,data b)
{return a.x>b.x;}
int main()
{
    n=read();m=read();
    for(int i=1;i<n;i++)
        a[i].x=read(),a[i].f=0;
    for(int i=1;i<m;i++)
        a[i+n-1].x=read(),a[i+n-1].f=1;
    sort(a+1,a+n+m-1);
    f[0]=f[1]=1;
    for(int i=1;i<=n+m-2;i++)
    {
        ans+=f[a[i].f^1]*a[i].x;
        f[a[i].f]++;
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}
