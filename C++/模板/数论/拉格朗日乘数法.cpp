/*
	拉格朗日乘数法  NOI2012川藏骑行
	一般形式:当k元组(x1,x2,x3...xk)，满足g(x1,x2,x3...xk)=E时，求f(x1,x2,x3...xk)的最值 
		
	下面介绍一下拉格朗日乘数法是如何工作的：
　　问题：在g(x1, x2, x3, ..., xn) = c的约束条件下，求f(x1, x2, x3, ..., xn)的最值。
　　我们把问题具体化一下：令g(x, y) = xy = 3，f(x, y) = x2 + y2 ，求f(x, y)的最小值。
　　我们可以猜到，f(x, y)的最小值是6。
　　因为f(x, y)取得最值时受到g(x, y)条件的约束，那么f(x, y)的法向量应当与g(x, y)的法向量相平行。
　　于是我们得到下面的方程组：
　　fx = λgx  ==> 2x = λy
　　fy = λgy  ==> 2y = λx
　　g = 3      ==> xy = 3
　　解得λ = ±2 ，代入方程组解得 (x, y) = (3^(1/2), 3^(1/2)) 或 (x, y) = (-3^(1/2), -3^(1/2))

	此题可表示成:
	f(v1,v2..vn) = sigma(si/vi)
	g(v1,v2..vn) = sigma(ki*si*(vi-vi')^2)-Eu=0
	将其求偏导后乘以λ相加，得到如下方程组
	-s1 / v12 = 2λk1s1(v1-v1')
　　-s2 / v22 = 2λk2s2(v2-v2')
　　...
　　-sn / vn2 = 2λknsn(vn-vn')
　　g(v1,v2,v3...vn) = Eu

	不难发现这里的 λ一定得是负数，而且λ增大，根据λ确定的vi会使得g(v1,v2,v3...vn)增大
	显然Eu都用完才能最优
	那么我们二分λ，根据g与Eu的大小关系调整 
	
	至于求vi,这里λ确定以后，构成了关于vi的一元三次方程，我们肯定取最右边的那个大根
	求导一下搞出极值点，根据vi'的正负来分类讨论，得出右边极值点右边的函数部分单调性，之后就能二分解决了 
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
using namespace std;
int n;
double K[N],S[N],V[N],Eu;
double GetV(int x,double nanda){
	double l=max(0.0,V[x]*2.0/3.0),r=1e8,mid;
	for(int i=1;i<=70;i++){
		mid=(l+r)*0.5;
		if(2*nanda*K[x]*mid*mid*mid-2*nanda*K[x]*V[x]*mid*mid+1>0) l=mid;
		else r=mid;  
	}
	return mid;
}
bool check(double nanda){
	double v,E=0;
	for(int i=1;i<=n;i++){
		v=GetV(i,nanda);
		E+=S[i]*K[i]*(v-V[i])*(v-V[i]);
	}
	return E<Eu;
}
int main(){
	double l,r,mid,ans=0;
	scanf("%d%lf",&n,&Eu);
	for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&S[i],&K[i],&V[i]);
	l=-1e5;r=-1e-9;
	for(int i=1;i<=70;i++){
		mid=(l+r)*0.5;
		if(check(mid)) l=mid;
		else r=mid;
	}
	for(int i=1;i<=n;i++) ans+=S[i]/GetV(i,mid);
	printf("%.8lf\n",ans);
	return 0;
}

