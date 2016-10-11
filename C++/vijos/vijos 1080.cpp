#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int f[21][21][21];
int w(int a,int b,int c)
{
	if(a<=0 || b<=0 || c<=0)  return 1;
	if(a>20 || b>20 || c>20)  return w(20,20,20);
	if(f[a][b][c]!=-1)  return f[a][b][c];
	int t;
	if(a<b && b<c) 
	{
		t=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
		f[a][b][c]=t;
		return t;
    } 
    else
    {
		t=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
		f[a][b][c]=t;
		return t;
	}
}
int main()
{
	memset(f,-1,sizeof(f));
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c))
	{
		if(a==-1 && b==-1 && c==-1)  break;
		printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
	}
	//system("pause");
	return 0;
}