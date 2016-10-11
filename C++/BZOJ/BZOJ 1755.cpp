#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double n,m,k;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
int main()
{
	n=read();m=read();k=read();
	printf("%d\n",int(m*pow(1+n/100,k)));
	system("pause");
	return 0;
}
