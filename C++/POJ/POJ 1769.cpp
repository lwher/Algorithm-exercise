#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int t[300010],l[500010],r[500010],dp[50010];
int n,m;
void updata(int k,int l,int r,int x,int num)
{
	if(l==r)  {t[k]=num;return;}
	int mid=(l+r)>>1;
	if(x<=mid)  updata(k+k,l,mid,x,num);
	else  updata(k+k+1,mid+1,r,x,num);
	t[k]=min(t[k+k],t[k+1+k]);  
}
int ask(int k,int l,int r,int zuo,int you)
{
	if(l>=zuo && r<=you)  return t[k];
	if(zuo>r || you<l)  return 0x7fffffff;
	int mid=(l+r)>>1;
	return min(ask(k+k,l,mid,zuo,you),ask(k+k+1,mid+1,r,zuo,you));
}
int main()
{
	//freopen("Maximizer.in","r",stdin);
	//freopen("Maximizer.out","w",stdout);
	int i,j,tmp;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)  scanf("%d%d",&l[i],&r[i]);
	memset(dp,127,sizeof(dp));
	memset(t,127,sizeof(t));
	for(i=1;i<=m;i++)  
	{
		if(l[i]==1) 
		{
			dp[r[i]]=1;updata(1,1,n,r[i],1);j=i;
			break;
		}
	}
	for(i=j+1;i<=m;i++)
	{
		if(l[i]==1) 
		{
			dp[r[i]]=1;updata(1,1,n,r[i],1);
		}
		else
		{
		tmp=ask(1,1,n,l[i],r[i]-1)+1;
		if(dp[r[i]]>tmp)
		{
			dp[r[i]]=tmp;
			updata(1,1,n,r[i],tmp);
		}
	    }
	}
	cout<<dp[n]<<endl;
//	system("pause");
	return 0;
}

