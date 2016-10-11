#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
      int weizhi,shijian;
}a[1010];
int c,h,b;
int f[1010][1010][2];
int lu[1010][1010];
int ans=999999999;
bool mark[1010][1010][2];
int comp(const void *a, const void *b)  
{
    sth *m=(sth *)a,*n=(sth *)b;
	if ( (*m).weizhi<(*n).weizhi ) return -1;	else
		if ( (*m).weizhi>(*n).weizhi ) return 1;
}
int dp(int i,int j,int o)
{
	if(i<1 || j>c)  return 999999999;
	if(i==1 && j==c && o==0)  return max(a[1].weizhi,a[1].shijian);
	if(i==1 && j==c && o==1)  return max(a[c].weizhi,a[c].shijian);
	if(i==0 && j==c && o==0)  return 0;
 	if(mark[i][j][o])  return f[i][j][o];
	
	f[i][j][0]=min(f[i][j][0],min(max(dp(i,j+1,1)+lu[j+1][i],a[i].shijian),max(dp(i-1,j,0)+lu[i-1][i],a[i].shijian)));
    f[i][j][1]=min(f[i][j][1],min(max(dp(i-1,j,0)+lu[i-1][j],a[j].shijian),max(dp(i,j+1,1)+lu[j+1][j],a[j].shijian)));  
    mark[i][j][0]=1;
    mark[i][j][1]=1;
    return f[i][j][o];
}
int main()
{
	memset(f,127,sizeof(f));
    cin>>c>>h>>b;
    int i,j;
    for(i=1;i<=c;i++)
    scanf("%d%d",&a[i].weizhi,&a[i].shijian);
    qsort (a+1,c,sizeof(sth),comp);
    for(i=1;i<=c;i++)
    for(j=1;j<=c;j++)
    lu[i][j]=abs(a[i].weizhi-a[j].weizhi);
	for(i=1;i<=c;i++)
    {
	    if(ans>dp(i,i,0)+abs(a[i].weizhi-b))	ans=dp(i,i,0)+abs(a[i].weizhi-b);
		if(ans>dp(i,i,1)+abs(a[i].weizhi-b))	ans=dp(i,i,1)+abs(a[i].weizhi-b);
    } 
    cout<<ans;
    system("pause");
    return 0;
}
