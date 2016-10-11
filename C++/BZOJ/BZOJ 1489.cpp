#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n;
int best[2010];
int num[2010];
int main()
{
    int t;
	int i,j,l,r,now,k,mid,wei1,wei2;
	int A,B;
	cin>>t;
	while(t--)
	{
	scanf("%d",&n);
		memset(best,0,sizeof(best));
		best[0]=2147483647;
		for(i=1;i<=n;i++)
		scanf("%d",&num[i]);
		now=0;
		for(i=1;i<=n;i++)
		{
			l=0;r=now;
			while(l<r)
			{
				if(l+1==r) 
				break;
				mid=(l+r)/2;
			    if(best[mid]<num[i])
			    r=mid;
			    else
			    l=mid;
			}
			if(best[r]>=num[i])
			k=r;
			else
			if(best[l]>=num[i])
			k=l;
			if(best[k+1]<num[i])
			{
			best[k+1]=num[i];
		    }
			if(k+1>now)
			{
			now=k+1;
			if(now==2)  wei2=i;
			if(now==1)  wei1=i;
		    }
		}
		if(now>2) printf("No!\n");
		else
		if(now==2)
		{
		A=0;B=0;
		memset(best,0,sizeof(best));
		best[0]=-2147483647;
		now=0;
		for(i=1;i<=wei2-1;i++)
		{
			if(num[i]<num[wei2])
		{	l=0;r=now;
			while(l<r)
			{
				if(l+1==r) 
				break;
				mid=(l+r)/2;
			    if(best[mid]<num[i])
			    l=mid;
			    else
			    r=mid;
			}
			if(best[r]<num[i])
			k=r;
			else
			if(best[l]<num[i])
			k=l;
			if(best[k+1]>num[i])
			{
			best[k+1]=num[i];
		    }
			if(k+1>now)
			{
			now=k+1;
		    }
		}
		}
        A=now+1+n-wei2;
		memset(best,0,sizeof(best));
		best[0]=-2147483647;
		now=0;
		for(i=wei1+1;i<=n;i++)
		{
			if(num[i]>num[wei1])
			{l=0;r=now;
			while(l<r)
			{
				if(l+1==r) 
				break;
				mid=(l+r)/2;
			    if(best[mid]<num[i])
			    l=mid;
			    else
			    r=mid;
			}
			if(best[r]<num[i])
			k=r;
			else
			if(best[l]<num[i])
			k=l;
			if(best[k+1]>num[i])
			{
			best[k+1]=num[i];
		    }
			if(k+1>now)
			{
			now=k+1;
		    }}
		}
		    B=wei1+now;
		    if(A>=n/2 && B>=n/2)
		    printf("Yes!\n");
		    else
		    printf("No!\n");
	}
		else
		printf("Yes!\n");
	}
	
	return 0;
}
 
