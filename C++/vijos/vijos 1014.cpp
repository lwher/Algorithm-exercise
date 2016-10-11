#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 1e60
using namespace std;
struct point{
	double x,y;
}p[1010];
inline bool comp(const point &a,const point &b){
	return a.x<b.x;
}
double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double min(double a,double b){
	return a<b?a:b;
}
int n;
double dp[1010][1010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
	sort(p+1,p+1+n,comp);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=INF;
	dp[2][1]=dist(p[1],p[2]);
	for(int i=2;i<n;i++){
		for(int j=1;j<i;j++){
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+dist(p[i],p[i+1]));
			dp[i+1][i]=min(dp[i+1][i],dp[i][j]+dist(p[j],p[i+1]));
		}
	}
	double ans=INF;
	for(int i=1;i<n;i++) ans=min(ans,dp[n][i]+dist(p[i],p[n]));
	printf("%.2lf\n",ans);
	return 0;
}

