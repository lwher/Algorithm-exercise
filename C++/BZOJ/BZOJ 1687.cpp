#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,t,w=1,bx,by,ex,ey;
int ans,ans1[10001],ans2[10001];
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
bool mp[101][101],mark[101][101];
char ch[101],dir[5]={' ','S','N','E','W'};
struct que{int x,y,from;}q[10001];
void bfs()
{
	q[0].x=bx;q[0].y=by;
	mark[bx][by]=1;
	while(t<w)
	{
		int x=q[t].x,y=q[t].y;
		for(int k=0;k<4;k++)
		{
			int nowx=x+xx[k],nowy=y+yy[k];
			if(!mp[nowx][nowy])continue;
			nowx=nowx+xx[k],nowy=nowy+yy[k];
			if(!mp[nowx][nowy]||mark[nowx][nowy])continue;
			mark[nowx][nowy]=1;
			q[w].x=nowx;q[w].y=nowy;q[w].from=t;w++;
			if(nowx==ex&&nowy==ey)return;
		}
		t++;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n*2;i++)
	{
	   scanf("%s",ch); 
	   for(int j=0;j<m*2-1;j++)
	   {
	   	    if(ch[j]=='.')continue;
	   	    if(ch[j]=='S'){bx=i;by=j+1;}
	   	    if(ch[j]=='E'){ex=i;ey=j+1;}
	   	    mp[i][j+1]=1;
	   }
    }
    bfs();w--;
    int flag=0,d,dis=0;
    while(w)
    {
    	int now=q[w].from;
    	if(q[w].x>q[now].x)d=1;
    	if(q[w].x<q[now].x)d=2;
    	if(q[w].y>q[now].y)d=3;
    	if(q[w].y<q[now].y)d=4;
    	if(d!=flag)
    	{
    		if(flag!=0){ans++;ans1[ans]=flag;ans2[ans]=dis;}
    		dis=1;
    		flag=d;
    	}
    	else dis++;
    	w=now;
    }
    ans++;ans1[ans]=flag;ans2[ans]=dis;
    for(int i=ans;i>0;i--)  printf("%c %d\n",dir[ans1[i]],ans2[i]);
    system("pause");
	return 0;
}
