#include<iostream>
#include<cmath> 
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p,a,b,c,d;
double Min,ans=0;
int main(){
	scanf("%d%d%d%d%d%d",&p,&a,&b,&c,&d,&n);
	Min=(sin(a*n+b)+cos(c*n+d)+2.00)*p;
	for(int i=n-1;i>0;i--){
		double t=(sin(a*i+b)+cos(c*i+d)+2.00)*p;
		if(ans<t-Min) ans=t-Min;
		if(Min>t) Min=t;
	}
	printf("%.6lf\n",ans);
	return 0;
}

