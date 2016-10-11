/*
	爬山法  BZOJ 3680
	设置初始温度T，一开始温度很高，反应很剧烈，答案的变动幅度较大
	随着温度降下来以后，反应减缓，答案变动幅度减小，最后在一定精度内固定在一个点上 
*/
#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 10001
#define eps 1e-9
using namespace std;
struct point{
	double x,y,w;
}p[N],ans;
int n;
inline double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].w);
		ans.x+=p[i].x*p[i].w;ans.y+=p[i].y*p[i].w;
	}
	ans.x/=n;ans.y/=n;
	double T=200000,X,Y;
	while(T>eps){
		X=0;Y=0;
		for(int i=1;i<=n;i++){
			X+=(p[i].x-ans.x)*p[i].w/dist(p[i],ans);
			Y+=(p[i].y-ans.y)*p[i].w/dist(p[i],ans);
		}
		ans.x+=X*T;ans.y+=Y*T;
		T*=0.97;
	}
	printf("%.3lf %.3lf\n",ans.x,ans.y);
	return 0;
}

