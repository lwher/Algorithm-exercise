#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,ans,l,r;
int a[200001];
inline bool jud(int x)
{
    int tot=1,now=1,save=1;
    while (tot<=m)
    {
        while (a[now]-a[save]<x && now<=n) now++;
        if (now>n && tot<m) return 0;
        tot++;save=now;
        if (tot==m) return 1;
    }
    return 1;
}
int main()
{
    n=read();
    m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    l=1;r=1000000000;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (jud(mid)){ans=mid;l=mid+1;}
        else r=mid-1;
    }
    printf("%d",ans);
}