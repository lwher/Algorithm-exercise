/*
	模拟退火  POJ 2420
	和爬坡一样，也是确定一个温度T，然后开始不停地抖动当前点
	区别在于爬坡解决单峰，因此只往更优的地方跳，而模拟退火可以跑跑多峰，因此有一定概率向不优的地方跳跃
	我们去det表示跳跃前后的差值det<0
	首先如果跳过去更优，那就跳
	如果不优，但是e^(det/T) > random(0,1)，我们也选择跳跃
	显然如果前后差距较小或者T比较高时容易跳，如果T降下来了，就不容易跳了 
*/
#include<iostream>
#include<ctime>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 301
#define eps 1e-5
using namespace std;
struct point{
	double x,y;
}p[N],Ans,now;
int n;
double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double calc(point A){
	double res=0;
	for(int i=1;i<=n;i++) res+=dist(A,p[i]);
	return res;
}
void init(){
	for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
}
void solve(){
	double X,Y,T=10000,preD,nextD;
	Ans.x=0;Ans.y=0;
	for(int i=1;i<=n;i++) Ans.x+=p[i].x,Ans.y+=p[i].y;
	Ans.x/=n;Ans.y/=n;
	while(T>eps){
		preD=calc(Ans);
		X=0;Y=0;
		for(int i=1;i<=n;i++){
			X+=(p[i].x-Ans.x)/dist(p[i],Ans);
			Y+=(p[i].y-Ans.y)/dist(p[i],Ans);
		}
		now.x=Ans.x+X*T;
		now.y=Ans.y+Y*T;
		nextD=calc(now);
		if(nextD<preD) Ans=now;
		else{
			double K=(double)(rand()%10001)/10000.00;
			if(exp((preD-nextD)/T)>K) Ans=now;
		}
		T*=0.95;
	}
	printf("%.0lf\n",calc(Ans));
}
int main(){
	srand(time(NULL));
	while(scanf("%d",&n)!=EOF){
		init();
		solve();
	}
	return 0;
}

