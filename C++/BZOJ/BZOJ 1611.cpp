#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[351][351];
bool mark[351][351],c[351][351];
int n,x,y,t;
int b[1000000][3];
int tou=1,wei=1;
bool o;
int main()
{
    memset(a,127,sizeof(a));
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{scanf("%d%d%d",&x,&y,&t);
	a[x][y]=min(a[x][y],t);mark[x][y]=1;
	if(x>0) {a[x-1][y]=min(a[x-1][y],t);mark[x-1][y]=1;}
    if(x<350){a[x+1][y]=min(a[x+1][y],t);mark[x+1][y]=1;}
    if(y>0) {a[x][y-1]=min(a[x][y-1],t);mark[x][y-1]=1;}
    if(y<350) {a[x][y+1]=min(a[x][y+1],t);mark[x][y+1]=1;}
    }
    b[1][0]=0;b[1][1]=0;b[1][2]=0;c[0][0]=1;
    if(!mark[0][0]) {cout<<0;o=1;}
    else
    while(tou<=wei)
    {
		x=b[tou][1];y=b[tou][2];t=b[tou][0];
		if((x>0)&&(!mark[x-1][y])) {o=1;cout<<t+1<<endl;break;}
		if((x<350)&&(!mark[x+1][y])) {o=1;cout<<t+1<<endl;break;}
		if((y>0)&&(!mark[x][y-1])) {o=1;cout<<t+1<<endl;break;}
		if((y<350)&&(!mark[x][y+1])) {o=1;cout<<t+1<<endl;break;}
		
		if((x>0)&&(t+1<a[x-1][y])&&(!c[x-1][y]))
		{
		c[x-1][y]=1;wei++;
		b[wei][0]=t+1;b[wei][1]=x-1;b[wei][2]=y;
		} 
		if((y<350)&&(t+1<a[x][y+1])&&(!c[x][y+1]))
		{
		c[x][y+1]=1;wei++;
		b[wei][0]=t+1;b[wei][1]=x;b[wei][2]=y+1;
		} 
		if((x<350)&&(t+1<a[x+1][y])&&(!c[x+1][y]))
		{
		c[x+1][y]=1;wei++;
		b[wei][0]=t+1;b[wei][1]=x+1;b[wei][2]=y;
		} 
		if((y>0)&&(t+1<a[x][y-1])&&(!c[x][y-1]))
		{
		c[x][y-1]=1;wei++;
		b[wei][0]=t+1;b[wei][1]=x;b[wei][2]=y-1;
		} 
		tou++;
    }
    
    if(!o) cout<<-1<<endl;
	
	system("pause");
	return 0;
}
