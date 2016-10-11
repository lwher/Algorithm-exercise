#include<stdio.h>
int main()
{
	  long long  n,m,a,s,d[55];
	while(~scanf("%lld",&n))
	{
		 for(m=1;m<=n;m++)
			scanf("%lld",&d[m]);
			int i;
			int s=d[1];
			for(i=2;i<=n;i++)
					s^=d[i];
					if(s!=0) printf("Yes\n");
					else printf("No\n");

	}
}


