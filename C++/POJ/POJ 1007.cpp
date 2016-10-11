#include<iostream>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;	
int n,m;	
typedef struct  
	{
		string s;  
		int num;  
	}data; 
	data a[100];  	
bool cmp(data a,data b)  
	{  
	    return a.num<b.num;  
	}  	
int main ()
	{
		int i,j,k;
		
		cin>>n>>m;
		for (i=0;i<m;i++)
		{
			cin>>a[i].s;
			a[i].num=0;
			for (j=1;j<n;j++)
			  for (k=0;k<j;k++)
			  {
					if (a[i].s[j]<a[i].s[k])
					  a[i].num++;
		  }
		}
		sort (a,a+m,cmp);
		for (i=0;i<m;i++)
        cout<<a[i].s<<endl;
		//system ("pause");
		return 0;
	}

