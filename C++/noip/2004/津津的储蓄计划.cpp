#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int ans,now;
int need[13];
bool o;
int main()
{
	int i;
	for(i=1;i<=12;i++)  scanf("%d",&need[i]);
	for(i=1;i<=12;i++)
	{
	    now+=300;
		if(now<need[i])  {o=1;cout<<"-"<<i<<endl;break;}
		now-=need[i];
		if(now/100>0)  {ans+=now/100;now%=100;}	
	}
	if(!o)  {now+=ans*100+ans*20;cout<<now<<endl;}
	//system("pause");
	return 0;
}