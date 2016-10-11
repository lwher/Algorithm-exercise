#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int vis[50][50],visd[50][50];
char mp[50][50];
int n,m;
int xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
struct que{int x,y;}q[100001];
struct data{int x,y,km,kn;}d[5];
inline bool jud(int x,int y){if(x<1||x>n||y<1||y>m)return 0;return 1;}
int main()
{
	
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&m);
		memset(mp,0,sizeof(mp));
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		memset(visd,0,sizeof(visd));
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=m;j++)
		  {
		    cin>>mp[i][j];
			if(mp[i][j]=='X')vis[i][j]=1;
			else if(mp[i][j]=='S')
			{q[0].x=i;  q[0].y=j;  vis[i][j]=1;}
			else if(mp[i][j]>='a'&&mp[i][j]<='e')
			 { int k=mp[i][j]-'a';
			   d[k].km++;}
		  }
		  
		  
		int nd=1,find=0,t=0,w=1;
		while(nd)
	    {
		 while(t<w&&!find)
		 {
		 	for(int i=0;i<4;i++)
		 	{
		 		int x=q[t].x+xx[i];
		 		int y=q[t].y+yy[i];
		 		if(mp[x][y]=='G')
		 		{
		 			find=1;
		 			break;
		 		}
		 		if(jud(x,y)&&!vis[x][y]&&mp[x][y]!='X')
		 		{
		 			if(mp[x][y]>='A'&&mp[x][y]<='E')
		 			{
		 				visd[x][y]=1;
		 				continue;
		 			}
		 			else if(mp[x][y]>='a'&&mp[x][y]<='e')
		 			{
		 				int k=mp[x][y]-'a';
		 				d[k].kn++;
		 			}
		 			vis[x][y]=1;
		 			q[w].x=x; q[w].y=y;
		 			w++;
		 		}
		 		
		 	}
		 	t++;
		 }
		 if(find)break;
		 nd=0;
		 for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
		   {
		 	int k=mp[i][j]-'A';
			 if(!vis[i][j]&&visd[i][j]&&mp[i][j]>='A'&&mp[i][j]<='E')
		 	  if(d[k].kn==d[k].km&&d[k].km>0)
			   {
			     q[w].x=i;  q[w].y=j;
				 vis[i][j]=1; w++; nd=1;
			   }
		 }
		 
	    }
	    if(find)printf("YES\n");
	    else printf("NO\n");
	}
	return 0;
}