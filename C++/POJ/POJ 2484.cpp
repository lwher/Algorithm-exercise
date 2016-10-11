#include<cstdio>
using namespace std;
int n;
int main()
{
	while(scanf("%d",&n) && n)
	{
		if(n>=3)  printf("Bob\n");
		else
		printf("Alice\n");
	}
	//system("pause");

	return 0;
}

