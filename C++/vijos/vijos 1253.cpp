#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
double l,c,d,p0;
int n;
double way[110],val[110],shen[110],x[110];
int main()
{
	int i=0,j;
	scanf("%lf%lf%lf%lf%d",&l,&c,&d,&p0,&n);
	for(i=1;i<=n;i++)  scanf("%lf%lf",&way[i],&val[i]);
	way[0]=0;val[0]=p0;
	n++;
	way[n]=l;
	val[n]=0;
	l=c*d;
	i=0;
	while(1)
	{
		if(i==n)  break;
		j=i+1;
		if(way[j]-way[i]>l)  {cout<<-1<<endl;return 0;}
		while(way[j]-way[i]<=l)
		{
			if(val[j]<val[i])  break;
			j++;
		}
		if(way[j]-way[i]<=l)
		{
			if(shen[i]*d>=way[j]-way[i])
			{
				shen[j]=shen[i]-(way[j]-way[i])/d;
			}
			else x[i]=(way[j]-way[i])/d-shen[i];
		}
		else
		{
			x[i]=c-shen[i];
			j=i+1;
			shen[j]=c-(way[j]-way[i])/d;
		}
		i=j;
	}
	double ans=0;
	for(i=0;i<n;i++)  ans+=x[i]*val[i];
	printf("%.2lf\n",ans);
	//system("pause");
	return 0;
}
