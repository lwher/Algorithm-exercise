#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,p,m;
int map[110][110];
int main()
{
	int i,j,k,a,b,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  map[i][j]=30000;
	for(i=1;i<=n;i++)  map[i][i]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		map[a][b]=1;map[b][a]=1;
	} 
	for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(map[i][j]>map[i][k]+map[k][j])  map[i][j]=map[i][k]+map[k][j];
	scanf("%d",&p);
	for(i=1;i<=p;i++)
    {
		scanf("%d%d",&a,&b);
		ans=0;
		for(j=1;j<=n;j++)  if(map[a][j]+map[j][b]==map[a][b])  ans++;
		printf("%d\n",ans);
	}
	//system("pause");
	return 0;
}
