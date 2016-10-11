#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
int n,m,cnt,tot,mx,ans;
int a[505],x[1005],y[1005],fa[1005];
struct data{int x,y,v;}e[500005];
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool cmp(data a,data b){return a.v<b.v;}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)  a[i]=read();
	m=read();
	for(int i=1;i<=m;i++)  fa[i]=i,x[i]=read(),y[i]=read();
	for(int i=1;i<=m;i++)
    for(int j=i+1;j<=m;j++)
    {
   	    e[++cnt].x=i;e[cnt].y=j;
   	    e[cnt].v=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    }
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int p=find(e[i].x),q=find(e[i].y);
		if(p!=q)
		{
			fa[p]=fa[q];
			tot++;
			if(tot==m-1){mx=e[i].v;break;}
		}
	}
	for(int i=1;i<=n;i++) if(a[i]*a[i]>=mx) ans++;
	printf("%d\n",ans);
	system("pause");
	return 0;
}
