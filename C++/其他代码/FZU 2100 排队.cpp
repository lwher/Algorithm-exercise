#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define max(a,b)  ((a) < (b) ? (b) : (a))
using namespace std;
struct sth
{
	int l,r,rnd,size,bh;
	int maxx,cd;
}t[100010];
int ans[100010];
int sz;
int a,k,now;
int n,root;
void rturn(int &tt)
{
	int k=t[tt].l;
	t[tt].l=t[k].r;t[k].r=tt;
	t[tt].size=t[t[tt].l].size+t[t[tt].r].size+1;t[k].size=t[t[k].l].size+t[t[k].r].size+1;
	t[tt].maxx=max(t[t[tt].l].maxx,t[t[tt].r].maxx);
	t[tt].maxx=max(t[tt].maxx,t[tt].cd);
	t[k].maxx=max(t[t[k].l].maxx,t[t[k].r].maxx);
	t[k].maxx=max(t[k].maxx,t[k].cd);
	tt=k;
}
void lturn(int &tt)
{
	int k=t[tt].r;
	t[tt].r=t[k].l;t[k].l=tt;
	t[tt].size=t[t[tt].l].size+t[t[tt].r].size+1;t[k].size=t[t[k].l].size+t[t[k].r].size+1;
	t[tt].maxx=max(t[t[tt].l].maxx,t[t[tt].r].maxx);
	t[tt].maxx=max(t[tt].maxx,t[tt].cd);
	t[k].maxx=max(t[t[k].l].maxx,t[t[k].r].maxx);
	t[k].maxx=max(t[k].maxx,t[k].cd);
	tt=k;
}
void Ins(int &wei,int hao)
{
	if(wei==0)
	{
		sz++;
		wei=sz;
		t[sz].bh=hao;
		t[sz].rnd=rand();
		t[sz].l=t[sz].r=0;
		t[sz].size=1;
		t[sz].cd=a;
		t[sz].maxx=a;
		return;
	}
	if(now+t[t[wei].l].size+k<sz)
	{
		now+=t[t[wei].l].size+1;
	    Ins(t[wei].r,hao);if(t[t[wei].r].rnd<t[wei].rnd) lturn(wei);
	    else  { t[wei].size++;t[wei].maxx=max(t[wei].maxx,a); }
        }
	else
	if(t[t[wei].r].maxx>a || t[wei].cd>a)
	{
		now+=t[t[wei].l].size+1;
		Ins(t[wei].r,hao);if(t[t[wei].r].rnd<t[wei].rnd) lturn(wei);
		else  { t[wei].size++;t[wei].maxx=max(t[wei].maxx,a); }
	}
	else
	{
		Ins(t[wei].l,hao);if(t[t[wei].l].rnd<t[wei].rnd) rturn(wei);
		else  { t[wei].size++;t[wei].maxx=max(t[wei].maxx,a); }
	}
}
void print(int &wei)
{
	if(wei==0)  return;
	print(t[wei].l);
	ans[0]++;ans[ans[0]]=t[wei].bh;
	print(t[wei].r);
}
int main()
{
	int t,i,j;
	sz=0;root=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&k);
		now=0;
		Ins(root,i);
	}
	ans[0]=0;
	print(root);
	for(i=1;i<=ans[0]-1;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[ans[0]]);

	//system("pause");
	return 0;
}
