#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int t,n;
int x1,x2,x3,y1,y2,y3;
int ans,on;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int i,j;
    while(scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3))
	{
          if(x1==0&&y1==0&&x2==0&&y2==0&&x3==0&&y3==0)
          break;
          on=0;ans=0;
          
		  if(abs(x1-x2)!=0 && abs(y1-y2)!=0)
		  on+=gcd(abs(x1-x2),abs(y1-y2))-1;
		  else
		  if(abs(x1-x2)==0)
		  on+=abs(y1-y2)-1;
		  else
		  on+=abs(x1-x2)-1;
		  ans+=x1*y2-x2*y1;
		  
		  if(abs(x3-x2)!=0 && abs(y3-y2)!=0)
		  on+=gcd(abs(x3-x2),abs(y3-y2))-1;
		  else
		  if(abs(x3-x2)==0)
		  on+=abs(y3-y2)-1;
		  else
		  on+=abs(x3-x2)-1;
		  ans+=x2*y3-x3*y2;
		  
		  if(abs(x1-x3)!=0 && abs(y1-y3)!=0)
		  on+=gcd(abs(x1-x3),abs(y1-y3))-1;
		  else
		  if(abs(x1-x3)==0)
		  on+=abs(y1-y3)-1;
		  else
		  on+=abs(x1-x3)-1;
		  ans+=x3*y1-x1*y3;
		  ans=abs(ans);
          on+=3;
	      printf("%d\n",(ans-on)/2+1);
	}
	system("pause");
	return 0;
}

