#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
struct sth
{
	int a,b,c;
}cft[110];
int n,m,ans;
int f[101][101][101][3];
int main()
{
	int i,k,j,l;
	int a,b,c,A,B,C;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)  scanf("%d%d%d",&cft[i].a,&cft[i].b,&cft[i].c);
	memset(f,-1,sizeof(f));
	f[1][1][1][0]=cft[1].c;
	f[1][1][1][1]=cft[1].b;
	f[1][1][1][2]=cft[1].a;
	f[1][0][1][0]=f[1][0][1][1]=f[1][0][1][2]=0;
	for(i=1;i<n;i++)
	for(j=0;j<=i;j++)
	for(k=1;k<=i;k++)
	for(l=0;l<3;l++)
	if(f[i][j][k][l]!=-1)
	{
		a=cft[i+1].a;b=cft[i+1].b;c=cft[i+1].c;
		A=cft[k].a;B=cft[k].b;C=cft[k].c;
		//什么都不做 
		f[i+1][j][k][l]=max(f[i+1][j][k][l],f[i][j][k][l]);
		//另起一堆 
		f[i+1][j+1][i+1][0]=max(f[i+1][j+1][i+1][0],f[i][j][k][l]+c);
		f[i+1][j+1][i+1][1]=max(f[i+1][j+1][i+1][1],f[i][j][k][l]+b);
		f[i+1][j+1][i+1][2]=max(f[i+1][j+1][i+1][2],f[i][j][k][l]+a);
		//放上去
		if(j!=0)
		{
		if(l==0)
		{
			if((a<=A && b<=B) || (b<=A && a<=B))
		    f[i+1][j][i+1][0]=max(f[i+1][j][i+1][0],f[i][j][k][l]+c);
		    if((a<=A && c<=B) || (c<=A && a<=B))
		    f[i+1][j][i+1][1]=max(f[i+1][j][i+1][1],f[i][j][k][l]+b);
		    if((b<=A && c<=B) || (c<=A && b<=B))
		    f[i+1][j][i+1][2]=max(f[i+1][j][i+1][2],f[i][j][k][l]+a);
	    } 
	    if(l==1)
		{
			if((a<=A && b<=C) || (b<=A && a<=C))
		    f[i+1][j][i+1][0]=max(f[i+1][j][i+1][0],f[i][j][k][l]+c);
		    if((a<=A && c<=C) || (c<=A && a<=C))
		    f[i+1][j][i+1][1]=max(f[i+1][j][i+1][1],f[i][j][k][l]+b);
		    if((b<=A && c<=C) || (c<=A && b<=C))
		    f[i+1][j][i+1][2]=max(f[i+1][j][i+1][2],f[i][j][k][l]+a);
	    }
	    if(l==2)
		{
			if((a<=B && b<=C) || (b<=B && a<=C))
		    f[i+1][j][i+1][0]=max(f[i+1][j][i+1][0],f[i][j][k][l]+c);
		    if((a<=B && c<=C) || (c<=B && a<=C))
		    f[i+1][j][i+1][1]=max(f[i+1][j][i+1][1],f[i][j][k][l]+b);
		    if((b<=B && c<=C) || (c<=B && b<=C))
		    f[i+1][j][i+1][2]=max(f[i+1][j][i+1][2],f[i][j][k][l]+a);
	    }
	    }
	}
	for(i=1;i<=n;i++) for(j=0;j<3;j++) ans=max(ans,f[n][m][i][j]);
	cout<<ans<<endl;
	//system("pause");
	return 0;
}
