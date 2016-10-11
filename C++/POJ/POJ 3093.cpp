#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m,ans,a[1001],s[1001],f[1001];
int main()
{
	scanf("%d",&T);
	for(int l=1;l<=T;l++)
	{
		memset(f,0,sizeof(f));
	    s[0]=ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		    scanf("%d",&a[i]);
		sort(a+1,a+n+1);
	    if(a[1]>m){printf("%d 0\n",l);continue;}
		for(int i=1;i<=n;i++)
	    	s[i]=s[i-1]+a[i];
	    f[0]=1; 
		for(int i=n;i>0;i--)
		{
		    for(int j=max(0,m-s[i]+1);j<=m-s[i-1];j++) 
	            ans+=f[j];
    		for(int j=m;j>=a[i];j--)
		        f[j]+=f[j-a[i]]; 
        }
        printf("%d %d\n",l,ans);
    }
	return 0;
}