#include<cstdio>   
using namespace std;   
int piles[1005];   
int main()   
{      
	int n,temp,ans,sumcount;       
	while(scanf("%d",&n)!=EOF && n)       
	{           
		sumcount=0;           
		for (int i=0;i<n;i++)           
		{               
			scanf("%d",&piles[i]);           
			}           
			ans=piles[0];           
			for (int i=1;i<n;i++)           
			{               
				ans ^=piles[i];           
			}           
			if(ans==0) {printf("0\n"); continue;}           
			for (int i=0;i<n;i++)           
{           if((ans^piles[i])<=piles[i]) sumcount++;           }           
printf("%d\n",sumcount);       
   
   
}
return 0;
} 

