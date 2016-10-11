#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 200010
#define M 1300010
using namespace std;
int n,m,aa[50010],tot,root[N];
int A,B,K,AA;
int sz,size[M],ls[M],rs[M],rad[M],shuzi[M],w[M];
void modify(int x)
{
	size[x]=size[ls[x]]+size[rs[x]]+w[x];
}
void rturn(int &t)
{
	int k=ls[t];
	ls[t]=rs[k];rs[k]=t;
	modify(t);modify(k);
	t=k;
}
void lturn(int &t)
{
	int k=rs[t];
	rs[t]=ls[k];ls[k]=t;
	modify(t);modify(k);
	t=k;
}
void Ins(int &x,int SZ)
{
	if(x==0)
	{
		x=++sz;size[x]=1;ls[x]=0;rs[x]=0;rad[x]=rand();shuzi[x]=SZ;w[x]=1;
		return;
	}
	if(shuzi[x]==SZ)  {w[x]++;size[x]++;return;}
	else
	if(shuzi[x]>SZ)   {Ins(ls[x],SZ);if(rad[ls[x]]<rad[x])  rturn(x);  else size[x]++;}
	else  {Ins(rs[x],SZ);if(rad[rs[x]]<rad[x])  lturn(x);  else size[x]++;}
}
void shanchu(int &x,int SZ)
{
	if(shuzi[x]==SZ)
	{
		if(w[x]>1)  {w[x]--;size[x]--;}
		else
		{
			if(ls[x]*rs[x]==0)   x=ls[x]+rs[x];
			else
			{
				if(rad[ls[x]]<rad[rs[x]])  {int k=ls[x];rturn(x);size[k]--;shanchu(rs[x],SZ);}
				else  {int k=rs[x];lturn(x);size[k]--;shanchu(ls[x],SZ);}
			}
		}
		return;
	}
	if(shuzi[x]>SZ)  {shanchu(ls[x],SZ);size[x]--;}
	else {shanchu(rs[x],SZ);size[x]--;}
}
void updata(int k,int l,int r,int x,int SZ,int op)
{
	shanchu(root[k],op);
	Ins(root[k],SZ);
	if(l==r)  return;
	int mid=(l+r)>>1;
	if(x<=mid)   updata(k+k,l,mid,x,SZ,op);
	else  updata(k+k+1,mid+1,r,x,SZ,op);
}
void build(int k,int l,int r,int x,int SZ)
{
	Ins(root[k],SZ);
	if(l==r)  return;
	int mid=(l+r)>>1;
	if(x<=mid)   build(k+k,l,mid,x,SZ);
	else  build(k+k+1,mid+1,r,x,SZ);
}
void find(int x,int SZ)
{
	if(x==0)  return;
	if(shuzi[x]<=SZ) {AA+=size[ls[x]]+w[x];find(rs[x],SZ);}
	else find(ls[x],SZ);
}
void query(int k,int l,int r,int zuo,int you,int x)
{
	if(l>=zuo && r<=you)  {find(root[k],x);return;}
	int mid=(l+r)>>1;
	if(zuo<=mid)  query(k+k,l,mid,zuo,you,x);
	if(you>mid)  query(k+k+1,mid+1,r,zuo,you,x);  
}
int main()
{
    	int T,i,l,r,mid;char s[3];
    	scanf("%d",&T);
		while(T--)
		{
			memset(root,0,sizeof(root));
			sz=0;
			scanf("%d%d",&n,&m);
		    for(i=1;i<=n;i++)  {scanf("%d",&aa[i]);}
			for(i=1;i<=n;i++)  build(1,1,n,i,aa[i]);				
		    for(i=1;i<=m;i++)
		    {
				scanf("%s",s);
				scanf("%d%d",&A,&B);
				if(s[0]=='C')
				{
					updata(1,1,n,A,B,aa[A]);
					aa[A]=B;
				}
				else
				{
					scanf("%d",&K);
					int l=0,r=1000000001;
					while(l+1<r)
					{
						mid=(l+r)>>1;
						AA=0;query(1,1,n,A,B,mid);
						if(AA>=K) r=mid;
						else l=mid;
					}
					AA=0;query(1,1,n,A,B,l);
					if(AA>=K) printf("%d\n",l); else printf("%d\n",r);
					    
	            }
			}
	    }
	//system("pause");
	return 0;
}

