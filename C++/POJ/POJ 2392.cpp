#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans;bool f[40001];
int use[40001];
struct data{int h,a,c;}a[401];
inline bool cmp(data a,data b)
{return a.a<b.a;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	 scanf("%d%d%d",&a[i].h,&a[i].a,&a[i].c);
	sort(a+1,a+1+n,cmp);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
	   memset(use,0,sizeof(use));
	   for(int j=a[i].h;j<=a[i].a;j++)
	   {
	      if(!f[j]&&f[j-a[i].h]&&use[j-a[i].h]+1<=a[i].c)
		  {
		     f[j]=1;
		     use[j]=use[j-a[i].h]+1;
		     ans=max(j,ans);
		 }
	   }
    }
    printf("%d",ans);
    return 0;
}