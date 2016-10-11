/*
	线性同余方程组 
	n % A1 = B1
	n % A2 = B2 ....
	n % An = Bn
	求n的最小正整数解 
*/
/*
	1、中国剩余定理 
	当A1,A2,A3...An互质的时候，可以使用
	对于每个方程 i，求出 k，使得 k是除了Ai以外，其他A的最小公倍数，然后求k 关于Ai的逆元
	得到 p,即 p % Ai = 1 且 p是除了Ai以外，其他A的公倍数
	最后n = p1*B1 + p2*B2 + ... + pn*Bn 
*/
/*
	2、对于A不互质的情况 POJ 2891
	这里我们才用一种不断合并两个方程的一般解法
	当只剩最后一个方程的时候，答案也就出来了
	例如要合并:
	n % A1 = B1
	n % A2 = B2
	则
	n=A1*x+B1=A2*y+B2
	所以 A1*x+A2*y=B2-B1
	设d=gcd(A1,A2)
	如果 (B2-B1)%d!=0 则无解
	a=A1/d;b=A2/d;c=(B2-B1)/d; 
	用exgcd求出x (x'=((x*c)%b+b)%b;)
	此时 n=A1*X+B1 ,X=x'+k*b (k为整数)
	则新的方程可看成 n=A1*x'+A1*b*k+B1 -> n % A1*b = B1+A1*x' 
	当只剩一个方程时，n=B 
	代码如下： 
*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y){
	if(!b){
		x=1;y=0;return a;
	}
	long long d=exgcd(b,a%b,x,y),t=x;
	x=y;y=t-a/b*y;
	return d;
}
int n;
void solve(){
	long long x,y,a,b,c,d,A1,A2,B1,B2;
	bool noans=0;
	cin>>A1>>B1;
	for(int i=2;i<=n;i++){
		cin>>A2>>B2;
		if(noans) continue;
		d=exgcd(A1,A2,x,y);
		if((B2-B1)%d!=0){
			noans=1;continue;
		}
		a=A1/d;b=A2/d;c=(B2-B1)/d;
		exgcd(a,b,x,y);
		x=((x*c)%b+b)%b;
		B1=(B1+A1*x)%(A1*b);A1=A1*b;
	}
	if(noans) cout<<-1<<endl;
	else cout<<B1<<endl;
} 
int main(){
	while(scanf("%d",&n)!=EOF){
		solve();
	}
	return 0;
}

