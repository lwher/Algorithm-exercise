#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct sth
{
	int l,r,w;
}dui[100010];
long long tmp,f[100010][2],sum[100010];
int n,K,t,num[100010],p,q;
inline long long calc(int j,int i)
{
	return f[j][q]+(sum[i]-sum[j])*sum[j];
}
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9')) ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9') {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
int main()
{
	int i,k,tou,wei,l,r,mid;
	scanf("%d%d",&n,&K);
	K++;
	q=1;p=0;
	for(i=1;i<=n;i++)   
    {
        num[i]=read();//scanf("%d",&num[i]);
        sum[i]=sum[i-1]+num[i];
    }
	for(k=2;k<=K;k++)
	{
		tou=1;wei=1;
		dui[1].l=k;dui[1].r=n;dui[1].w=k-1;
		for(i=k;i<=n;i++)
		{
			f[i][p]=calc(dui[tou].w,i);
			dui[tou].l++;
			if(dui[tou].l>dui[tou].r)  tou++;
	        while(tou<=wei && calc(dui[wei].w,dui[wei].l)<calc(i,dui[wei].l))  wei--;
			if(tou<=wei)
			{
				l=dui[wei].l;r=dui[wei].r+1;
			    while(l+1<r)
				{
					mid=(l+r)>>1;
					if(calc(dui[wei].w,mid)>calc(i,mid))  l=mid;
						else r=mid;
				}
				dui[wei].r=l;
				if(r<=n) {dui[++wei].l=r;dui[wei].r=n;dui[wei].w=i;}
			}
			else
			{
				dui[++wei].l=i+1;dui[wei].r=n;dui[wei].w=i;
			}
		}
		p^=1;q^=1;
	}
	cout<<f[n][q]<<endl;
	system("pause");
	return 0;
}
