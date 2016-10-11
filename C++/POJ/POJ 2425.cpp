#include<iostream>
#include<stack>
using namespace std;
int map[1010][1010];
int SG[1010];
int N;
int DFS(int n) {
	int i;
    if(SG[n]!=-1) return SG[n];
    bool used[1010];
    memset(used,0,sizeof(used));
	for(i=0;i<N;i++)
    {
		if(map[n][i] != -1)
        used[DFS(i)]=true;
    }
    i=0;
    while(used[i]) i++;
    return SG[n]=i;
}
int main()
{
	int i,j,k,t;
	int X;
	int temp,ans;
	while(scanf("%d",&N) != EOF)
	{
		memset(map,255,sizeof(map));
		memset(SG,255,sizeof(SG));
		for(i=0;i<N;i++)
		{
			scanf("%d",&k);
			if(k == 0)
			{
				SG[i] = 0;
			}
			for(j=0;j<k;j++)
			{
				scanf("%d",&t);
				map[i][t] = 1;
			}
		}
		
		while(scanf("%d",&X) != EOF)
		{
			if(X == 0) break;
			ans = 0;
			for(i=0;i<X;i++)
			{
				scanf("%d",&temp);
				ans = ans ^DFS(temp);
			}
			if(ans != 0)
			{
				printf("WIN\n");
			}
			else
			{
				printf("LOSE\n");
			}
		}
	}
	return 0;
}
