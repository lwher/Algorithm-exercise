#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 104
using namespace std;
char ss[N];int n,s[N];
struct sth
{
	int l,d,p;
}f[N][N];
void print(int x,int y)
{
	if(x>y) return;
	if(x==y){
		if(ss[x]=='(' || ss[x] ==')')  printf("()");
		else  printf("[]");
		return;
	}
	if(f[x][y].p==-1)
	{
		putchar(ss[x]);print(x+1,y-1);putchar(ss[y]);
		return;
	}
	print(x,f[x][y].p);print(f[x][y].p+1,y);
}
int main()
{
	//freopen("bracket.in","r",stdin);
	//freopen("bracket.out","w",stdout);
	int i,j,k,x,y;
	gets(ss);n=strlen(ss);
	memset(f,-1,sizeof(f));
	for(i=0;i<n;i++)
	{
		f[i][i].d=1;
		f[i][i].l=1;
		f[i+1][i].l=0;
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			x=j;y=i+j;
			if((ss[x]=='('&&ss[y]==')')||(ss[x]=='['&&ss[y]==']'))
			{
				f[x][y].l=f[x+1][y-1].l;
				f[x][y].d=f[x+1][y-1].d+1;
			}
			for(k=x;k<y;k++)
			{
				if(f[x][y].l>f[x][k].l+f[k+1][y].l || f[x][y].l==-1)
				{
					f[x][y].l=f[x][k].l+f[k+1][y].l;
					f[x][y].d=max(f[x][k].d,f[k+1][y].d);
					f[x][y].p=k;
				}
				else if(f[x][y].l==f[x][k].l+f[k+1][y].l)
				{
					if(f[x][y].d>max(f[x][k].d,f[k+1][y].d))
					{
						f[x][y].d=max(f[x][k].d,f[k+1][y].d);
						f[x][y].p=k;
					}
				}
			}
		}
	}
	print(0,n-1);
	puts("");
	return 0;
}


