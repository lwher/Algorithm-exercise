#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstdlib>
using namespace std;
int w[9][9]={6,6,6,6,6,6,6,6,6,
             6,7,7,7,7,7,7,7,6,
			 6,7,8,8,8,8,8,7,6,
			 6,7,8,9,9,9,8,7,6,
			 6,7,8,9,10,9,8,7,6,
			 6,7,8,9,9,9,8,7,6,
			 6,7,8,8,8,8,8,7,6,
			 6,7,7,7,7,7,7,7,6,
			 6,6,6,6,6,6,6,6,6};
int gz[9][9]={1,1,1,2,2,2,3,3,3,
              1,1,1,2,2,2,3,3,3,
			  1,1,1,2,2,2,3,3,3,
			  4,4,4,5,5,5,6,6,6,
			  4,4,4,5,5,5,6,6,6,
			  4,4,4,5,5,5,6,6,6,
			  7,7,7,8,8,8,9,9,9,
			  7,7,7,8,8,8,9,9,9,
			  7,7,7,8,8,8,9,9,9};
int a[10][10],need,ans=-1,answer=0;
bool hang[10][10],lie[10][10],fg[10][10];
void init()
{
	int i,j;
	for(i=0;i<9;i++)  for(j=0;j<9;j++)   
	{
		scanf("%d",&a[i][j]);
		if(!a[i][j])  {need++;}
		else  
		{
			answer+=a[i][j]*w[i][j];
			hang[i][a[i][j]]=1;lie[j][a[i][j]]=1;fg[gz[i][j]][a[i][j]]=1;
		}
    }
}
int getsum(int x,int y)
{
	int i,sum=0;
	for(i=1;i<=9;i++)
	if(!hang[x][i] && !lie[y][i] && !fg[gz[x][y]][i]) sum++;
	return sum;
}
void dfs(int top,int now)
{
	if(top==need+1)
	{
		if(now>ans)  ans=now;  
		return;
	}
	int i,j,x,y,k,nmin=11;
	for(i=0;i<9;i++)
	for(j=0;j<9;j++)
	{
		if(!a[i][j])
		{
		    k=getsum(i,j);
		    if(k<nmin)  {nmin=k;x=i;y=j;}
	    }
	}
	for(i=1;i<=9;i++)
	{
		if(!hang[x][i] && !lie[y][i] && !fg[gz[x][y]][i])
		{
			a[x][y]=1;hang[x][i]=1;lie[y][i]=1;fg[gz[x][y]][i]=1;
			dfs(top+1,now+i*w[x][y]);
			a[x][y]=0;hang[x][i]=0;lie[y][i]=0;fg[gz[x][y]][i]=0;
		}
	}
}
int main()
{
	init();
	dfs(1,0);
	if(ans==-1)  cout<<-1<<endl;
	else   cout<<ans+answer<<endl;
	system("pause");
	return 0;
}
