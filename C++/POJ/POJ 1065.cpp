#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#define N 5004
#define MAX 10000000
using namespace std;
int t,n,best[N],len,ll,rr,mid;
struct xxx
{
    int l,w;
}a[N];
int cmp(xxx aa,xxx bb)
{
    if(aa.l!=bb.l)
        return aa.l<bb.l;
    else
        return aa.w<bb.w;
}
int main()
{
    int i,j;
    int weizhi;
    cin>>t;
    
    for(j=1;j<=t;j++)
    {
		len=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].l,&a[i].w);
        }
        sort(a+1,a+1+n,cmp);
        for(i=1;i<=n;i++)
        {
            ll=0;
            rr=len;
            weizhi=0;
            while(ll<rr)
            {
				if(ll==rr)  {weizhi=rr;break;}
				if(ll+1==rr)
				{
					if(best[rr]>a[i].w)
					weizhi=rr;
					else
					weizhi=ll;
		         break;
				}
				mid=(ll+rr)/2;
				if(best[mid]>a[i].w)
				{
					ll=mid;
				} 
				else
				rr=mid;
		    }
            best[weizhi+1]=a[i].w;
            if(len<weizhi+1)  len=weizhi+1;
        }
        cout<<len<<endl;
    }
   // system("pause");
    return 0;
}
